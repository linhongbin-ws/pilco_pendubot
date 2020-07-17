%%
addpath(genpath('/home/ben/code/dw_foc'))
clear all; clc;
controller = pendubot_controller();
controller = controller.setTaskRecorder(true);
controller = controller.setTaskPlotter(true);
controller = controller.setTaskPrinter(false);
controller = controller.setTaskPID(true);
duration = 20;
controller.maxTor1 = 0.6;
controller.maxTor2 = 0.6;

controller.PID_p1 = 1;
controller.PID_d1 = 0;
controller.PID_p2 = 1;
controller.PID_d2 = 0;

controller.set_zeroTor();
controller = controller.start();
tic
global des_q1 des_dq1_fil des_q2 des_dq2_fil
des_q1 = pi/2;
des_dq1_fil = 0;
des_q2 = pi;
des_dq2_fil = 0;

while (controller.timeNow-controller.timeStart<=duration)
    controller = controller.run();
end
controller.set_zeroTor();
controller.stop();
controller.delete_controller();

toc


