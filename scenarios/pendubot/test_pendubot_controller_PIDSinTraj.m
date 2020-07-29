%%
addpath(genpath('/home/ben/code/dw_foc'))
clear all; clc;
controller = pendubot_controller();
controller = controller.setTaskPlotter(false);
controller = controller.setTaskPrinter(true);
controller = controller.setTaskPID(true);
duration = 15;
controller.maxTor1 = 1.5;
controller.maxTor2 = 1.5;

p2d = 30;
controller.PID_p1 = 10;
controller.PID_d1 = controller.PID_p1 / p2d;
controller.PID_p2 = 10;
controller.PID_d2 = controller.PID_p2 / p2d;

controller.set_zeroTor();
controller = controller.start();
tic
global des_q1 des_dq1_fil des_q2 des_dq2_fil
des_q1 = pi-pi/2;
des_dq1_fil = 0;
des_q2 = pi-pi/2;
des_dq2_fil = 0;
w = 2;
A = pi/4;

while (controller.timeNow-controller.timeStart<=duration)
    t = controller.timeNow-controller.timeStart;
    global des_q1 des_dq1_fil des_q2 des_dq2_fil
    
    des_traj = A *sin(w * t) + pi;
    d_des_traj = A * w * cos(w * t);
    des_q1 = des_traj;
    des_dq1_fil = d_des_traj;
    
    des_q2 = des_traj;
    des_dq2_fil = d_des_traj;
    
    controller = controller.run();
end
controller.stop();
controller.delete_controller();

toc


