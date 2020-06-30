function [tau1, tau2] = PD_controller(x1, x2, dx1, dx2, x1_D, x2_D, dx1_D, dx2_D)
    P = 0.1;
    D = 0.01;
    
    tau1 = P * (x1_D - x1) + D * (dx1_D - dx1)
    tau2 = P * (x2_D - x2) + D * (dx2_D - dx2)
    
end