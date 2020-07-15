classdef pendubot_controller
    properties
        motor1
        motor2
        taskControl
        taskPlotter
        taskPrint
        timeStart
        timeNow
        gearRatio1 = 1/5
        gearRatio2 = 1
        dT_control = 0.01
        dT_print = 0.1
        dT_plotter = 0.1
        dq1_filRatio = 0.9
        dq2_filRatio = 0.9
        FigID = 1
        fixPlotWindowTime = 10
        isTaskPlotter = false
        isTaskPrinter = false
        maxTor = 0.4
    end
    
    methods
        function obj = pendubot_controller()
            obj.motor1 = mx_vesc('/dev/VESC_001');
            obj.motor2 = mx_vesc('/dev/VESC_002');

            
            obj.timeStart = mx_sleep(0);
            obj.timeNow = obj.timeStart;
            
            global plot_Cell origin_absPos1 origin_absPos2 isInitPlot desTor1

            plot_Cell = {[],[],[],[],[]};
            origin_absPos1 = 0;
            origin_absPos2 = 0;
            isInitPlot = true;
            desTor1 = 0;
        end
        function obj = start(obj)
            if obj.isTaskPrinter
                obj.taskPrint =  mx_task(@()obj.task_printer, obj.dT_print);
            end
            if obj.isTaskPlotter
                obj.taskPlotter =  mx_task(@()obj.task_plotter, obj.dT_plotter);
            end
            obj.taskControl =  mx_task(@()obj.task_control, obj.dT_control);
            
            
            
            obj.motor1.open();
            obj.motor2.open();
            

            obj.set_measureOrigin();
  
            obj.timeStart = mx_sleep(0);
            obj.timeNow = obj.timeStart;
            
            
        end
      
        
        function stop(obj)
            obj.motor1.close()
            obj.motor2.close()
        end
        
        function obj = run(obj)
            
            global elapseTime 
            
            obj.timeNow = mx_sleep(0.00001); % sleeps thread for 10us
            
            
            if obj.isTaskPrinter
                obj.taskPrint.run(obj.timeNow);
            end
            if obj.isTaskPlotter
                obj.taskPlotter.run(obj.timeNow);
            end
         
            obj.taskControl.run(obj.timeNow);
            
            
            elapseTime = obj.timeNow - obj.timeStart;
        end
        
        function obj = setTaskPrinter(obj, isTaskPrinter)
            obj.isTaskPrinter = isTaskPrinter;
            if(isTaskPrinter)
                obj.taskPrint =  mx_task(@()obj.task_printer, obj.dT_print);
            end
   
        end
        
        function obj = setTaskPlotter(obj, isTaskPlotter)
            obj.isTaskPlotter = isTaskPlotter;
            if isTaskPlotter
                obj.taskPlotter =  mx_task(@()obj.task_plotter, obj.dT_plotter);
            end
        end
        
        
        function set_measureOrigin(obj)
            global absPos1 absPos2 origin_absPos1 origin_absPos2
            for i = 1:5
                obj.firstMeasure();
            end
            origin_absPos1 = absPos1;
            origin_absPos2 = absPos2;
        end
        
   
        
        function obj = firstMeasure(obj)
            global prevPos1 prevPos2 pos1 pos2 absPos1 absPos2 absC1 absC2 relPos1 relPos2 origin_absPos1 origin_absPos2 q1 q2 prev_q1 prev_q2 dq1_fil dq2_fil
            absC1 = 0;
            absC2 = 0;
            prevPos1 = 0;
            prevPos2 = 0;
            pos1 = 0;
            pos2 = 0;
            prevPos1 = pos1;
            prevPos2 = pos2;
            prev_q1 = q1;
            prev_q2 = q2;
            dq1_fil = 0;
            dq2_fil  = 0;
            
            angThres = 190;

            
            obj.motor1.get_sensors();
            obj.motor2.get_sensors();
            pos1 = obj.motor1.sensors.pid_pos;
            pos2 = obj.motor2.sensors.pid_pos;
            
            if abs(pos1-prevPos1)>angThres && pos1-prevPos1<0
                absC1 = absC1 +1;
            elseif abs(pos1-prevPos1)>angThres && pos1-prevPos1>0
                absC1 = absC1 -1;
            end
            
            if abs(pos2-prevPos2)>angThres && pos2-prevPos2<0
                absC2 = absC2 +1;
            elseif abs(pos2-prevPos2)>angThres && pos2-prevPos2>0
                absC2 = absC2 -1;
            end
            
            absPos1 = -1 * (pos1 + absC1*360) * obj.gearRatio1;
            absPos2 = -1 * (pos2 + absC2*360) * obj.gearRatio2;
            
            relPos1 = absPos1 - origin_absPos1;
            relPos2 = absPos2 - origin_absPos2;
            
            q1 = (relPos1 +180) / 180 * pi;
            q2 = (q1 + relPos2) / 180 * pi;
            
            dq1 = (q1 - prev_q1) / obj.dT_control;
            dq2 = (q2 - prev_q2) / obj.dT_control;
            
            dq1_fil = obj.dq1_filRatio *  dq1_fil + (1-obj.dq1_filRatio) * dq1;
            dq2_fil = obj.dq2_filRatio *  dq2_fil + (1-obj.dq2_filRatio) * dq2;
        end
        

        
        function obj = measurement(obj)
            global prevPos1 prevPos2 pos1 pos2 absPos1 absPos2 absC1 absC2 relPos1 relPos2 origin_absPos1 origin_absPos2 q1 q2 prev_q1 prev_q2 dq1_fil dq2_fil
            prevPos1 = pos1;
            prevPos2 = pos2;
            prev_q1 = q1;
            prev_q2 = q2;
            
            angThres = 190;

            
            obj.motor1.get_sensors();
            obj.motor2.get_sensors();
            pos1 = obj.motor1.sensors.pid_pos;
            pos2 = obj.motor2.sensors.pid_pos;
            
            if abs(pos1-prevPos1)>angThres && pos1-prevPos1<0
                absC1 = absC1 +1;
            elseif abs(pos1-prevPos1)>angThres && pos1-prevPos1>0
                absC1 = absC1 -1;
            end
            
            if abs(pos2-prevPos2)>angThres && pos2-prevPos2<0
                absC2 = absC2 +1;
            elseif abs(pos2-prevPos2)>angThres && pos2-prevPos2>0
                absC2 = absC2 -1;
            end
            
            absPos1 = -1 * (pos1 + absC1*360) * obj.gearRatio1;
            absPos2 = -1 * (pos2 + absC2*360) * obj.gearRatio2;
            
            relPos1 = absPos1 - origin_absPos1;
            relPos2 = absPos2 - origin_absPos2;
            
            q1 = (relPos1 +180) / 180 * pi;
            q2 = (q1 + relPos2) / 180 * pi;
            
            dq1 = (q1 - prev_q1) / obj.dT_control;
            dq2 = (q2 - prev_q2) / obj.dT_control;
            
            dq1_fil = obj.dq1_filRatio *  dq1_fil + (1-obj.dq1_filRatio) * dq1;
            dq2_fil = obj.dq2_filRatio *  dq2_fil + (1-obj.dq2_filRatio) * dq2;
        end
        

        
        function send_torque(obj)
            global desTor1                  
            if abs(desTor1) >= obj.maxTor
                obj.motor1.send_current(sign(desTor1) * obj.maxTor);
            else
                obj.motor1.send_current(desTor1); % sends current command
            end
   
        end
  
            
        function task_printer(obj)
             global relPos1 relPos2 absPos1 absPos2  q1 q2 
%             fprintf("pos1: %.4f deg \t pos2: %.4f deg\n", absPos1, absPos2); 
            
%             fprintf("pos1: %.4f deg \t pos2: %.4f deg\n", relPos1, relPos2);
            fprintf("pos1: %.4f deg \t pos2: %.4f deg\n", q1, q2);
        end
        
        function task_plotter(obj)
            global q1 q2 dq1_fil dq2_fil plot_Cell elapseTime isInitPlot
            
            if ~isempty(q1) && ~isempty(q2) && ~isempty(dq1_fil) && ~isempty(dq2_fil) && ~isempty(elapseTime) 
                plot_Cell{1} = [plot_Cell{1}, q1];
                plot_Cell{2} = [plot_Cell{2}, q2];
                plot_Cell{3} = [plot_Cell{3}, dq1_fil];
                plot_Cell{4} = [plot_Cell{4}, dq2_fil];
                plot_Cell{5} = [plot_Cell{5}, elapseTime];
                legendList = ['q1', 'q2', 'Filtered dq1', 'Filtered dq2'];

                figure(obj.FigID);

                for i = 1:4
                    ax = subplot(2,2,i);
                    if size(plot_Cell{5},2)<=(obj.fixPlotWindowTime/obj.dT_plotter)
                        plot(ax, plot_Cell{5},plot_Cell{i});
                    else
                        plot(ax, plot_Cell{5}(end - obj.fixPlotWindowTime/obj.dT_plotter:end), plot_Cell{i}(end - obj.fixPlotWindowTime/obj.dT_plotter:end));
                    end
%                   legend(legendList(i))
%                     if isInitPlot
%                         hold(ax, 'on')
%                         legend(legendList(i))
%                         hold(ax, 'off')
%                         isInitPlot = false
%                     end
                end
                drawnow
            end
        end
        
        function obj = task_control(obj)
            obj.measurement();
            obj.send_torque();
        end
    
        
        function obj = delete_controller(obj)
            obj.motor1.delete();
            obj.motor2.delete();
        end
        
 
    end
end

