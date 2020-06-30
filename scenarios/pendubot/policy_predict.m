function M = policy_predict(hyp, inputs, targets, m, s, maxU)
%% Code

E=length(maxU);   % dimension of control signal
D=length(m);      % dimension of input

% pre-compute some indices
F=D+E; j=D+1:F; i=1:D;
% initialize M and S
M = zeros(F,1); M(i) = m; S = zeros(F); S(i,i) = s;

[M(j), S(j,j), Q] = congp_2(hyp, inputs, targets, m, s);  % compute unsquashed control signal v
q = S(i,i)*Q; S(i,j) = q; S(j,i) = q';  % compute joint covariance S=cov(x,v)
[M, S, R] = gSat_2(M, S, j, maxU);         % compute squashed control signal u
end

function [M, S, C] = congp_2(hyp, inputs, targets, m, s)
%% Code

% % 1. Extract policy parameters
% policy.hyp = policy.p.hyp;
% policy.inputs = policy.p.inputs;
% policy.targets = policy.p.targets;

% fix policy signal and the noise variance 
% (avoids some potential numerical problems)
hyp_ = hyp;
hyp_(end-1,:) = log(1);                  % set signal variance to 1
hyp_(end,:) = log(0.01);                 % set noise standard dev to 0.01


[M, S, C] = gp2_2(hyp_, inputs, targets, m, s);

end
function [M, S, C] = gSat_2(m, v, i, e)
%% Code
d = length(m); I = length(i); i = i(:)';
if nargin < 4; e = ones(1, I); end; e = e(:)';

P = [eye(d); 3*eye(d)];                                        % augment inputs
ma = P*m;    madm = P;
va = P*v*P'; vadv = kron(P,P); va = (va+va')/2;

% do the actual augmentation with the right parameters
[M2, S2, C2] ...
  = gSin_2(ma, va, [i d+i], [9*e e]/8);

P = [eye(I) eye(I)]; Q = [eye(d) 3*eye(d)];
M = P*M2;                                                                % mean
S = P*S2*P'; S = (S+S')/2;                                           % variance
C = Q*C2*P';                                    % inv(v) times input-output cov

end


function [M, V, C] = gSin_2(m, v, i, e)
%% Code

    
d = length(m); I = length(i);
if nargin == 3, e = ones(I,1); else e = e(:); end          % unit column default
mi = zeros(I,1); vii = zeros(I,1)
mi(1:I,1) = m(i); vi = v(i,i); vii(1:I,1) = diag(vi);      % short-hand notation

M = e.*exp(-vii/2).*sin(mi);                                              % mean

lq = -bsxfun(@plus,vii,vii')/2; q = exp(lq);
V = (exp(lq+vi)-q).*cos(bsxfun(@minus,mi,mi')) - ...
                                      (exp(lq-vi)-q).*cos(bsxfun(@plus,mi,mi'));
V = e*e'.*V/2;                                                        % variance

C = zeros(d,I); C(i,:) = diag(e.*exp(-vii/2).*cos(mi));       % inv(v) times cov


end



function [M, S, V] = gp2_2(hyp, inputs, targets, m, s)
%% Code
persistent iK oldX oldIn oldOut beta oldn;
D = size(inputs,2);    % number of examples and dimension of inputs
[n, E] = size(targets);      % number of examples and number of outputs

input = inputs;  target = targets; X = hyp;

% 1) if necessary: re-compute cached variables
% if numel(X) ~= numel(oldX) || isempty(iK) ||  n ~= oldn || ...
%     sum(any(X ~= oldX)) || sum(any(oldIn ~= input)) || ...
%     sum(any(oldOut ~= target))
oldX = X; oldIn = input; oldOut = target; oldn = n;
K = zeros(n,n,E); iK = K; beta = zeros(n,E);

for i=1:E                                              % compute K and inv(K)
inp = bsxfun(@rdivide,inputs,exp(X(1:D,i)'));
K(:,:,i) = exp(2*X(D+1,i)-maha(inp,inp)/2);
L = chol(K(:,:,i) + exp(2*X(D+2,i))*eye(n))';
iK(:,:,i) = L'\(L\eye(n));
beta(:,i) = L'\(L\targets(:,i));
end
% end

k = zeros(n,E); M = zeros(E,1); V = zeros(D,E); S = zeros(E);

inp = bsxfun(@minus,inputs,m');                    % centralize inputs

% 2) Compute predicted mean and inv(s) times input-output covariance
for i=1:E
  iL = diag(exp(-X(1:D,i))); % inverse length-scales
  in = inp*iL;
  B = iL*s*iL+eye(D);
  
  t = in/B;
  l = exp(-sum(in.*t,2)/2); lb = l.*beta(:,i);
  tL = t*iL;
  c = exp(2*X(D+1,i))/sqrt(det(B));
  
  M(i) = sum(lb)*c;                                            % predicted mean
  V(:,i) = tL'*lb*c;                   % inv(s) times input-output covariance
  k(:,i) = 2*X(D+1,i)-sum(in.*in,2)/2;
end

% 3) Compute predictive covariance, non-central moments
for i=1:E
  ii = bsxfun(@rdivide,inp,exp(2*X(1:D,i)'));
  
  for j=1:i
    R = s*diag(exp(-2*X(1:D,i))+exp(-2*X(1:D,j)))+eye(D);
    t = 1/sqrt(det(R));
    ij = bsxfun(@rdivide,inp,exp(2*X(1:D,j)'));
    L = exp(bsxfun(@plus,k(:,i),k(:,j)')+maha(ii,-ij,R\s/2));
    S(i,j) = t*beta(:,i)'*L*beta(:,j); S(j,i) = S(i,j);
  end
  
  S(i,i) = S(i,i) + 1e-6;          % add small jitter for numerical reasons
  
end

% 4) Centralize moments
S = S - M*M';
end
