classdef pendubot_controller
    properties
        % basic param
        motor1
        motor2
        timeStart
        timeNow
        
        %task param
        dT_control = 0.01
        dT_print = 0.1
        dT_plotter = 0.1
        dT_PID = 0.01
        dT_recorder = 0.01
        
        
        taskControl
        taskPlotter
        taskPrint
        taskPID
        taskRecorder
   
        
        isTaskPlotter = false
        isTaskPrinter = false
        isTaskPID = false
        isTaskRecorder = true
        
        % plot param
        FigID = 1
        fixPlotWindowTime = 15
        
        
        % mearsure param
        gearRatio1 = 1
        gearRatio2 = 1
        dq1_filRatio = 0.9
        dq2_filRatio = 0.9

        
        % control param
        PID_p = 0.5
        PID_d = 0
        maxTor1 = 1
        
        % record param
        legendList = ['q1', 'q2', 'Filtered dq1', 'Filtered dq2', 'tau'];
        maxRecordBuffer = 10000
        
    end
    
    methods
        function obj = pendubot_controller()
            obj.motor1 = mx_vesc('/dev/VESC_001');
            obj.motor2 = mx_vesc('/dev/VESC_002');

            
            obj.timeStart = mx_sleep(0);
            obj.timeNow = obj.timeStart;
            
            global RecordCell origin_absPos1 origin_absPos2 isInitPlot desTor1 

            RecordCell = cell(1, 6);
            origin_absPos1 = 0;
            origin_absPos2 = 0;
            isInitPlot = true;
            desTor1 = 0;
        end
        function obj = start(obj)
            
            % basic task that must run
            obj.taskControl =  mx_task(@()obj.task_control, obj.dT_control); 
            
            % alternative tasks
            if obj.isTaskPrinter
                obj.taskPrint =  mx_task(@()obj.task_printer, obj.dT_print);
            end
            if obj.isTaskPlotter
                obj.taskPlotter =  mx_task(@()obj.task_plotter, obj.dT_plotter);
            end
            if obj.isTaskPID
                obj.taskPID =  mx_task(@()obj.task_PID, obj.dT_PID);
            end
            if obj.isTaskRecorder
                obj.taskRecorder = mx_task(@()obj.task_recorder, obj.dT_recorder);
            end

            % start communication
            obj.motor1.open();
            obj.motor2.open();
            
            % set current joint position as origin
            obj.set_measureOrigin();
  
            obj.timeStart = mx_sleep(0);
            obj.timeNow = obj.timeStart;
            
            
        end
      
        
        function stop(obj)
            obj.set_zeroTor()
            obj.motor1.close()
            obj.motor2.close()
        end
        
        function obj = run(obj)
            
            global elapseTime 
            obj.timeNow = mx_sleep(0.00001); % sleeps thread for 10us
            
            % basic task that must run
            obj.taskControl.run(obj.timeNow);
            
            % alternative tasks
            if obj.isTaskPrinter
                obj.taskPrint.run(obj.timeNow);
            end
            if obj.isTaskPlotter
                obj.taskPlotter.run(obj.timeNow);
            end
            if obj.isTaskPID
                obj.taskPID.run(obj.timeNow);
            end
            if obj.isTaskRecorder
                obj.taskRecorder.run(obj.timeNow);
            end
         

            
            
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
        
        function obj = setTaskRecorder(obj, isTaskRecorder)
            obj.isTaskRecorder = isTaskRecorder;
            if(isTaskRecorder)
                obj.taskRecorder =  mx_task(@()obj.task_recorder, obj.dT_recorder);
            end
   
        end
        
        function obj = setTaskPID(obj, isTaskPID)
            obj.isTaskPID = isTaskPID
            obj.taskPID = mx_task(@()obj.task_PID, obj.dT_PID);
        end
        
        
        function set_measureOrigin(obj)
            global absPos1 absPos2 origin_absPos1 origin_absPos2
            
            % iterate steps to ensure the measurement is steady
            for i = 1:5
                obj.firstMeasure();
            end
            origin_absPos1 = absPos1;
            origin_absPos2 = absPos2;
        end
        
        
        function set_zeroTor(obj)
            global desTor1
            desTor1 = 0;
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
            global prevPos1 prevPos2 pos1 pos2 absPos1 absPos2 absC1 absC2 relPos1 relPos2 
            global origin_absPos1 origin_absPos2 q1 q2 prev_q1 prev_q2 dq1_fil dq2_fil actTor1 RecordCell elapseTime 
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
            
            % position
            q1 = (relPos1 +180) / 180 * pi;
            q2 = (q1 + relPos2) / 180 * pi;
            
            % velociy
            dq1 = (q1 - prev_q1) / obj.dT_control;
            dq2 = (q2 - prev_q2) / obj.dT_control;
            
            % filtered velocity
            dq1_fil = obj.dq1_filRatio *  dq1_fil + (1-obj.dq1_filRatio) * dq1;
            dq2_fil = obj.dq2_filRatio *  dq2_fil + (1-obj.dq2_filRatio) * dq2;
            
            % measure torque
            actTor1 = obj.motor1.sensors.current_motor;
            


        end
        
       
        

        
        function send_torque(obj)
            global desTor1                  
            if abs(desTor1) >= obj.maxTor1
                obj.motor1.send_current(sign(desTor1) * obj.maxTor1);
            else
                obj.motor1.send_current(desTor1); % sends current command
            end
   
        end
  
        
        function task_recorder(obj)
            % record data
            global q1 q2 dq1_fil dq2_fil actTor1 elapseTime RecordCell desTor1
            if ~isempty(q1) && ~isempty(q2) && ~isempty(dq1_fil) && ~isempty(dq2_fil) && ~isempty(desTor1) && ~isempty(elapseTime) 
                RecordCell{1} = [RecordCell{1}, q1];
                RecordCell{2} = [RecordCell{2}, q2];
                RecordCell{3} = [RecordCell{3}, dq1_fil];
                RecordCell{4} = [RecordCell{4}, dq2_fil];
                RecordCell{5} = [RecordCell{5}, desTor1];
                RecordCell{6} = [RecordCell{6}, elapseTime];
            end
            
            if obj.maxRecordBuffer < size(RecordCell{1},2)
                for i = 1:6
                    RecordCell{i} = RecordCell{i}(end-obj.maxRecordBuffer);
                end
            end
        end
            
        function task_printer(obj)
             global relPos1 relPos2 absPos1 absPos2  q1 q2 
%             fprintf("pos1: %.4f deg \t pos2: %.4f deg\n", absPos1, absPos2); 
            
%             fprintf("pos1: %.4f deg \t pos2: %.4f deg\n", relPos1, relPos2);
            fprintf("pos1: %.4f deg \t pos2: %.4f deg\n", q1, q2);
        end
        
        function task_plotter(obj)
            global RecordCell 
            
            if ~isempty(RecordCell{1})
                figure(obj.FigID);

                for i = 1:5
                    ax = subplot(3,2,i);
                    if size(RecordCell{end},2)<=(obj.fixPlotWindowTime/obj.dT_recorder)
                        plot(ax, RecordCell{end}, RecordCell{i});
                    else
                        plot(ax, RecordCell{end}(end - obj.fixPlotWindowTime/obj.dT_plotter:end), RecordCell{i}(end - obj.fixPlotWindowTime/obj.dT_recorder : end));
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
        
        function task_PID(obj)
            global q1 dq1_fil des_q1 des_dq1_fil desTor1
            tor1 = (des_q1 - q1) * obj.PID_p + (des_dq1_fil - dq1_fil)* obj.PID_d;
            desTor1 = sign(tor1) * min(abs(tor1), obj.maxTor1);
        end
    
        
        function obj = delete_controller(obj)
            obj.motor1.delete();
            obj.motor2.delete();
        end
        
 
    end
end

