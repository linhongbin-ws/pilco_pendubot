%%
addpath(genpath('/home/ben/code/dw_foc'))
clear all; clc;
controller = pendubot_controller();
controller = controller.setTaskPlotter(true);
controller = controller.setTaskPrinter(true);
duration = 20;
controller = controller.start();
tic
while (controller.timeNow-controller.timeStart<=duration)
    controller = controller.run();
end
controller.stop();
controller.delete_controller();

toc


