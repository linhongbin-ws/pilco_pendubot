function [ m ] = Model()

l1  = 207.5 /1000;
l2  = 161/1000;
lc1 = 66.76/1000;
lc2 = 67.83/1000;
m1  = 125.7/1000;
m2  = 113/1000;
I1=0.001282107;
%I2 = 0.001;
I2=0.0009406602 + 0.000060339;
b1  = 0.015; %0.034;
b2  = 0.0001; %0.02;
%
B   = [1 0; 0 0];
%
% model disturbance
%
wm = 1;
wc = 1;
wg = 1;
wf = 1;
%
% environment parameters
g = 9.81;

l = struct('l1', [l1],'l2',[l2], 'lc1',[lc1],'lc2',[lc2],'m1',[m1],'m2',[m2],...
           'I1',[I1], 'I2',[I2],...
           'b1',[b1],'b2',[b2],'B',[B],...
           'wm',[wm],'wc',[wc],'wg',[wg],'wf',[wf],'g',[g]);

m = l;
end

