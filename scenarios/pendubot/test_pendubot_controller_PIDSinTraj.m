%%
addpath(genpath('/home/ben/code/dw_foc'))
clear all; clc;
controller = pendubot_controller();
controller = controller.setTaskPlotter(true);
controller = controller.setTaskPrinter(false);
controller = controller.setTaskPID(true);
duration = 1;
controller.maxTor = 10;
controller.PID_p = 2
controller.PID_d = 0.2
controller = controller.start();
tic
global des_q1 des_dq1_fil
des_q1 = pi;
des_dq1_fil = 0;

w = 1;
A = pi/2;

while (controller.timeNow-controller.timeStart<=duration)
    t = controller.timeNow-controller.timeStart;
    global des_q1 des_dq1_fil
    
    des_traj = A *sin(w * t) + pi;
    d_des_traj = A * cos(w * t);
    des_q1 = des_traj;
    des_dq1_fil = d_des_traj;
    
    controller = controller.run();
end
controller.stop();
controller.delete_controller();

toc


