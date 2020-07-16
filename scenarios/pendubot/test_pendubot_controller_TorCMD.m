%%
addpath(genpath('/home/ben/code/dw_foc'))
clear all; clc;
controller = pendubot_controller();
controller = controller.setTaskPlotter(false);
controller = controller.setTaskPrinter(true);
duration = 20;
controller = controller.start();
tic
cmd = 10;
controller.maxTor = cmd; 
while (controller.timeNow-controller.timeStart<=duration)
    global desTor1
    w = controller.timeNow-controller.timeStart;
    tau = cmd * sin(controller.timeNow-controller.timeStart * w);
    desTor1 = tau;
    controller = controller.run();
end
controller.stop();
controller.delete_controller();

toc


