function [tau1,tau2, mode, isLoadPolicy] = test(x1,x2,dx1,dx2,t,maxU, isRandPolicy)
    % % start, policy, H, plant, cost
    % angi = [3,4]

    % 
    % % % 1. Apply policy ... or random actions --------------------------------------
    % % if policy.isRandom
    % %     u = policy.fcn(policy,s(poli),zeros(length(poli)));
    % % else
    % 
%     if isempty('policy')
%         load('pilco_param.mat');
%     end
    load('pilco_param.mat')
    u = 0;
    
    if isempty('policy')
        isLoadPolicy = 0
    else
        isLoadPolicy = 1
    end

    % u = maxU*(2*rand(1,1)-1);
    w = 10;
    if isRandPolicy
        u = maxU*sin(t*w);
    else

        angi = [3,4];
        poli = [1,2,5,6,7,8];
        s = zeros(8,1);
        s(1)= dx1;
        s(2)= dx2;
        s(3)= x1;
        s(4)= x2;
        sa = gTrig(s, zeros(length(s)), angi); 
%         s(5:8) = sa;
        policy.maxU = maxU;
        mean = [s(1:2); sa]
%          variance = zeros(6);
        u = policy.fcn(policy,mean,zeros(6));        
    end
    % % end
        tau1 = u;
        tau2 = 0;
        mode = 0;
end