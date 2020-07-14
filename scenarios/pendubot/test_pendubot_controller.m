clear all; clc;
controller = pendubot_controller;
duration = 20;
controller = controller.start();
controller.set_measureOrigin();
tic
while (controller.timeNow-controller.timeStart<=duration)
    controller = controller.run();
end
controller.stop();
controller.delete_controller();

toc