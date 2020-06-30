mu0 = [0 0 pi pi]';               % initial state mean
S0 = diag([0.1 0.1 0.01 0.01].^2);% initial state covariance
nc = 200;                         % size of controller training set

policy.fcn = @(policy,m,s)conCat(@congp,@gSat,policy,m,s);% controller 
                                                          % representation
policy.maxU = 3.5;                                        % max. amplitude of 

angi = [3,4]
poli = [1,2,5,6,7,8];
                                                          % torque
[mm ss cc] = gTrig(mu0, S0, angi);                  % represent angles 
mm = [mu0; mm]; cc = S0*cc; ss = [S0 cc; cc' ss];         % in complex plane  
policy.p.inputs = gaussian(mm(poli), ss(poli,poli), nc)'; % init. location of 
                                                          % basis functions
policy.p.targets = 0.1*randn(nc, length(policy.maxU));    % init. policy targets 
                                                          % (close to zero)
policy.p.hyp = log([1 1 0.7 0.7 0.7 0.7 1 0.01]');        % initialize 
                                                          % hyper-parameters
                                                          


q1 = deg2rad(10);
q2 = deg2rad(20);
dq1 = 0;
dq2 = 0;
s = [dq1, dq2, q1, q2].';
sa = gTrig(s, zeros(length(s)), angi);
s = [s; sa];
mean = s(poli);
variance = zeros(length(poli));
a = policy.fcn(policy,mean,variance)
hyp = policy.p.hyp;
inputs = policy.p.inputs ;
targets = policy.p.targets;
b = policy_predict(hyp, inputs, targets, mean,variance, policy.maxU)

fprintf('assert result is: %s\n', string(a==b));

