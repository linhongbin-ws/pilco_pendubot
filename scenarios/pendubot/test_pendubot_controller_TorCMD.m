%%
clear all; clc;
controller = pendubot_controller();
controller = controller.setTaskMeasure(true);
controller = controller.setTaskPlotter(false);
controller = controller.setTaskPrinter(true);
controller = controller.setTaskTorqueCommand(true);
duration = 20;
controller = controller.start();
tic
cmd = 0.8;
controller.maxTor = cmd; 
while (controller.timeNow-controller.timeStart<=duration)
    global desTor1
    cmd = (1-rand(1)) * cmd *2;
    desTor1 = cmd;
    controller = controller.run();
end
controller.stop();
controller.delete_controller();

toc


