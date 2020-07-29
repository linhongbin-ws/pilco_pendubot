classdef pendubot_controller
    properties
        % basic param
        motor1
        motor2
        timeStart
        timeNow
        
        %task param
        dT_control = 0.002
        dT_print = 0.02
        dT_plotter = 0.2
        dT_PID = 0.01
        
        
        taskControl
        taskPlotter
        taskPrint
        taskPID
   
        
        isTaskPlotter = false
        isTaskPrinter = false
        isTaskPID = false

        
        % plot param
        FigID = 1
        fixPlotWindowTime = 15
        
        
        % mearsure param
        gearRatio1 = 1/5
        gearRatio2 = 1
        q1_filRatio = 0
        q2_filRatio = 0
        dq1_filRatio = 0.9
        dq2_filRatio = 0.9
        
        isSetOriginMeasure = false
        
        % control param
        PID_p1 = 0.5
        PID_d1 = 0
        PID_p2 = 0.4
        PID_d2 = 0
        
        maxTor1 = 1
        maxTor2 = 1
        
        maxVel1 = 10
        maxVel2 = 10

        
        
        
        % record param
        maxRecordBuffer = 10000
        
    end
    
    methods
        function obj = pendubot_controller()
            obj.motor1 = mx_vesc('/dev/VESC_001');
            obj.motor2 = mx_vesc('/dev/VESC_002');

            
            obj.timeStart = mx_sleep(0);
            obj.timeNow = obj.timeStart;
             
            global RecordCell origin_absPos1 origin_absPos2 isInitPlot desTor1 desTor2  isVelExceed1 isVelExceed2 safeTorTrip

            isVelExceed1 = false;
            isVelExceed2 = false;
            RecordCell = cell(1, 7);
            origin_absPos1 = 0;
            origin_absPos2 = 0;
            isInitPlot = true;
            desTor1 = 0;
            desTor2 = 0; 
            safeTorTrip = true;
        end
        function obj = start(obj)
            
            obj.turnOnSafeTorTrip();
            
            % basic task that must run
            obj.taskControl =  mx_task(@()obj.task_control, obj.dT_control); 
            
            % alternative tasks
            if obj.isTaskPrinter
                obj.taskPrint =  mx_task(@()obj.task_printer, obj.dT_print);
            end
            if obj.isTaskPlotter
                obj.taskPlotter =  mx_task(@()obj.task_plotter, obj.dT_plotter);
                figure(obj.FigID)
            end
            if obj.isTaskPID
                obj.taskPID =  mx_task(@()obj.task_PID, obj.dT_PID);
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
            obj.set_zeroTor();
            obj.motor1.close();
            obj.motor2.close();
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
        
        
        function obj = setTaskPID(obj, isTaskPID)
            obj.isTaskPID = isTaskPID;
            obj.taskPID = mx_task(@()obj.task_PID, obj.dT_PID);
        end
        
        
        function set_measureOrigin(obj)
            global  prevPos1 prevPos2 pos1 pos2 absPos1 absPos2 absC1 absC2   origin_absPos1 origin_absPos2  dq1_fil dq2_fil          
            global prev_q1 q1 prev_q2 q2 q1_fil q2_fil prev_mTime mTime

            absC1 = 0;
            absC2 = 0;
            prevPos1 = 0;
            prevPos2 = 0;
            pos1 = 0;
            pos2 = 0;
            dq1_fil = 0;
            dq2_fil  = 0;
            prev_q1 = 0;
            q1 = 0;;
            prev_q2 = 0;
            q2=0;
            prev_mTime = mx_sleep(0);
            mTime = prev_mTime + obj.dT_control;
            obj.isSetOriginMeasure = true;
 
            % iterate steps to ensure the measurement is steady
            for i = 1:5
                obj.measurement();
            end

            origin_absPos1 = absPos1;
            origin_absPos2 = absPos2;
            dq1_fil = 0;
            dq2_fil = 0;
      
            % update some previous variable like prevPos1
            for i = 1:100
                obj.measurement();
            end
            
            obj.isSetOriginMeasure = false;
        end
        
        
        function set_zeroTor(obj)
            global desTor1 desTor2
            desTor1 = 0;
            desTor2 = 0;
        end
        
      

        
        function obj = measurement(obj)
            global prevPos1 prevPos2 pos1 pos2 absPos1 absPos2 absC1 absC2 relPos1 relPos2 
            global origin_absPos1 origin_absPos2 q1 q2 prev_q1 prev_q2 dq1_fil dq2_fil q1_fil q2_fil dq1 dq2 prev_mTime mTime
            prevPos1 = pos1;
            prevPos2 = pos2;
            prev_q1 = q1;
            prev_q2 = q2;
            prev_mTime = mTime;
            
            angThres = 190;

            obj.motor1.get_sensors();
            obj.motor2.get_sensors();
            mTime = mx_sleep(0);
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
            q2 = q1 + (relPos2 / 180 * pi);
            % velociy
            dt = obj.dT_control;
%            dt = (mTime-prev_mTime);
            dq1 = (q1 - prev_q1) / dt;
            dq2 = (q2 - prev_q2) / dt;
            
            if ~obj.isSetOriginMeasure
                % filtered velocity
                q1_fil = obj.q1_filRatio *  q1_fil + (1-obj.q1_filRatio) * q1;
                q2_fil = obj.q2_filRatio *  q2_fil + (1-obj.q2_filRatio) * q2;
                % filtered velocity
                dq1_fil = obj.dq1_filRatio *  dq1_fil + (1-obj.dq1_filRatio) * dq1;
                dq2_fil = obj.dq2_filRatio *  dq2_fil + (1-obj.dq2_filRatio) * dq2;
            else  
                q1_fil =  q1;
                q2_fil =  q2;
                dq1_fil = 0;
                dq2_fil = 0;           
            end
            

        end
        
       
        

        
        function send_torque(obj)
            global desTor1 desTor2 safeTorTrip isVelExceed1 isVelExceed2
            
            if isVelExceed1 || isVelExceed2
                safeTorTrip = false;
            end
            
            if safeTorTrip
                if abs(desTor1) >= obj.maxTor1
                    obj.motor1.send_current(sign(desTor1) * obj.maxTor1);
                else
                    obj.motor1.send_current(desTor1); % sends current command
                end
                if abs(desTor2) >= obj.maxTor2
                    obj.motor2.send_current(sign(desTor2) * obj.maxTor2);
                else
                    obj.motor2.send_current(desTor2); % sends current command
                end
            else
                obj.motor1.send_current(0);
                obj.motor2.send_current(0);
            end
   
        end
  
        
        function record(obj)
            % record data
            global q1 q2 dq1_fil dq2_fil elapseTime RecordCell desTor1 desTor2 q1_fil q2_fil
            if ~isempty(q1_fil) && ~isempty(q2_fil) && ~isempty(dq1_fil) && ~isempty(dq2_fil) && ~isempty(desTor1) &&  ~isempty(desTor2) && ~isempty(elapseTime) 
                RecordCell{1} = [RecordCell{1}, q1_fil];
                RecordCell{2} = [RecordCell{2}, q2_fil];
                RecordCell{3} = [RecordCell{3}, dq1_fil];
                RecordCell{4} = [RecordCell{4}, dq2_fil];
                RecordCell{5} = [RecordCell{5}, desTor1];
                RecordCell{6} = [RecordCell{6}, desTor2];
                RecordCell{7} = [RecordCell{7}, elapseTime];
            end
            
            if obj.maxRecordBuffer < size(RecordCell{1},2)
                for i = 1:7
                    RecordCell{i} = RecordCell{i}(end-obj.maxRecordBuffer);
                end
            end
        end
            
        function task_printer(obj)
             global q1 q2 dq1_fil dq2_fil desTor1 desTor2
            fprintf("q1: %.2f rad \t q2: %.2f rad \t dq1_fil: %.2f rad\\s \t dq2_fil: %.2f rad\\s \t Tor1: %.2f \t Tor2: %.2f\n", q1, q2, dq1_fil, dq2_fil, desTor1, desTor2);
        end
        
        function task_plotter(obj)
            global RecordCell 
            
            if ~isempty(RecordCell{1})
                figure(obj.FigID);

                for i = 1:6
                    ax = subplot(3,2,i);
                    if size(RecordCell{end},2)<=(obj.fixPlotWindowTime/obj.dT_control)
                        plot(ax, RecordCell{end}, RecordCell{i});
                    else
                        plot(ax, RecordCell{end}(end - obj.fixPlotWindowTime/obj.dT_control:end), RecordCell{i}(end - obj.fixPlotWindowTime/obj.dT_control : end));
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
            obj.updateSafeVelocity();
            obj.send_torque();
            obj.record();
            
        end
        
        function task_PID(obj)
            global q1_fil dq1_fil q2_fil dq2_fil des_q1 des_dq1_fil des_q2 des_dq2_fil desTor1 desTor2 q1 q2 dq1 dq2
            tor1 = (des_q1 - q1_fil) * obj.PID_p1 + (des_dq1_fil - dq1)* obj.PID_d1;
            desTor1 = sign(tor1) * min(abs(tor1), obj.maxTor1);
            
            tor2 = (des_q2 - q2_fil) * obj.PID_p2 + (des_dq2_fil - dq2)* obj.PID_d2;
            desTor2 = sign(tor2) * min(abs(tor2), obj.maxTor2);
        end
    
        
        function obj = delete_controller(obj)
            obj.motor1.delete();
            obj.motor2.delete();
        end
        
        function turnOnSafeTorTrip(obj)
            global safeTorTrip
            safeTorTrip = true;
        end
        
        function updateSafeVelocity(obj)
            global dq1_fil dq2_fil isVelExceed1 isVelExceed2
            if dq1_fil >= obj.maxVel1 
                isVelExceed1 = true;
            else
                isVelExceed1 = false;
            end
            
            if dq2_fil >= obj.maxVel2
                isVelExceed2 = true;
            else
                isVelExceed2 = false;
            end
        end
 
    end
end

