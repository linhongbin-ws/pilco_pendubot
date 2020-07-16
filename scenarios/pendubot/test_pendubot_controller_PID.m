%%
addpath(genpath('/home/ben/code/dw_foc'))
clear all; clc;
controller = pendubot_controller();
controller = controller.setTaskRecorder(true);
controller = controller.setTaskPlotter(true);
controller = controller.setTaskPrinter(true);
controller = controller.setTaskPID(true);
duration = 20;
controller.maxTor1 = 0.6;
controller = controller.start();
tic
global des_q1 des_dq1_fil
des_q1 = pi;
des_dq1_fil = 0;

while (controller.timeNow-controller.timeStart<=duration)
    controller = controller.run();
end
controller.stop();
controller.delete_controller();

toc


