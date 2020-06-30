  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (pendu_vesc_modified_P)
    ;%
      section.nData     = 59;
      section.data(59)  = dumData; %prealloc
      
	  ;% pendu_vesc_modified_P.DiscreteDerivative_ICPrevScaled
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendu_vesc_modified_P.LowPassFilterDiscreteorContinuo
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% pendu_vesc_modified_P.LowPassFilterDiscreteorContin_c
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% pendu_vesc_modified_P.LowPassFilterDiscreteorContin_e
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% pendu_vesc_modified_P.LowPassFilterDiscreteorContin_j
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% pendu_vesc_modified_P.LowPassFilterDiscreteorContin_g
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% pendu_vesc_modified_P.LowPassFilterDiscreteorConti_jv
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% pendu_vesc_modified_P.Constant6_Value
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% pendu_vesc_modified_P.Constant1_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% pendu_vesc_modified_P.Constant10_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% pendu_vesc_modified_P.Constant9_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% pendu_vesc_modified_P.Constant3_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% pendu_vesc_modified_P.Constant8_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% pendu_vesc_modified_P.PAR_CURR_LIMS_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% pendu_vesc_modified_P.PAR_PID_GAINS_Value
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 18;
	
	  ;% pendu_vesc_modified_P.Constant5_Value
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 23;
	
	  ;% pendu_vesc_modified_P.PAR_CURR_LIMS_Value_i
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 24;
	
	  ;% pendu_vesc_modified_P.PAR_PID_GAINS_Value_l
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 29;
	
	  ;% pendu_vesc_modified_P.Gain_Gain
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 34;
	
	  ;% pendu_vesc_modified_P.UD_InitialCondition
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 35;
	
	  ;% pendu_vesc_modified_P.degToRad1_Gain
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 36;
	
	  ;% pendu_vesc_modified_P.degToRad_Gain
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 37;
	
	  ;% pendu_vesc_modified_P.Constant_Value
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 38;
	
	  ;% pendu_vesc_modified_P.UD_InitialCondition_d
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 39;
	
	  ;% pendu_vesc_modified_P.WeightedSampleTime_WtEt
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 40;
	
	  ;% pendu_vesc_modified_P.Integrator_gainval
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 41;
	
	  ;% pendu_vesc_modified_P.Integrator_UpperSat
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 42;
	
	  ;% pendu_vesc_modified_P.Integrator_LowerSat
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 43;
	
	  ;% pendu_vesc_modified_P.Saturation_UpperSat
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 44;
	
	  ;% pendu_vesc_modified_P.Saturation_LowerSat
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 45;
	
	  ;% pendu_vesc_modified_P.Constant_Value_i
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 46;
	
	  ;% pendu_vesc_modified_P.UD1_InitialCondition
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 47;
	
	  ;% pendu_vesc_modified_P.WeightedSampleTime1_WtEt
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 48;
	
	  ;% pendu_vesc_modified_P.Integrator_gainval_k
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 49;
	
	  ;% pendu_vesc_modified_P.Integrator_UpperSat_m
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 50;
	
	  ;% pendu_vesc_modified_P.Integrator_LowerSat_l
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 51;
	
	  ;% pendu_vesc_modified_P.Saturation_UpperSat_o
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 52;
	
	  ;% pendu_vesc_modified_P.Saturation_LowerSat_d
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 53;
	
	  ;% pendu_vesc_modified_P.DiscreteTimeIntegrator_gainval
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 54;
	
	  ;% pendu_vesc_modified_P.DiscreteTimeIntegrator_IC
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 55;
	
	  ;% pendu_vesc_modified_P.Constant7_Value
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 56;
	
	  ;% pendu_vesc_modified_P.Constant_Value_ib
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 57;
	
	  ;% pendu_vesc_modified_P.UnitDelay_InitialCondition
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 58;
	
	  ;% pendu_vesc_modified_P.Integrator_gainval_a
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 59;
	
	  ;% pendu_vesc_modified_P.Integrator_UpperSat_n
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 60;
	
	  ;% pendu_vesc_modified_P.Integrator_LowerSat_a
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 61;
	
	  ;% pendu_vesc_modified_P.Saturation_UpperSat_o1
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 62;
	
	  ;% pendu_vesc_modified_P.Saturation_LowerSat_g
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 63;
	
	  ;% pendu_vesc_modified_P.motordirection_Gain
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 64;
	
	  ;% pendu_vesc_modified_P.uTorqueConst_Gain
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 65;
	
	  ;% pendu_vesc_modified_P.maxcurrent_UpperSat
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 66;
	
	  ;% pendu_vesc_modified_P.maxcurrent_LowerSat
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 67;
	
	  ;% pendu_vesc_modified_P.TSamp_WtEt
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 68;
	
	  ;% pendu_vesc_modified_P.Constant2_Value
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 69;
	
	  ;% pendu_vesc_modified_P.Constant4_Value
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 70;
	
	  ;% pendu_vesc_modified_P.SineWave_Amp
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 71;
	
	  ;% pendu_vesc_modified_P.SineWave_Bias
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 72;
	
	  ;% pendu_vesc_modified_P.SineWave_Freq
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 73;
	
	  ;% pendu_vesc_modified_P.SineWave_Phase
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 74;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% pendu_vesc_modified_P.PAR_MASK_MODE_Value
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendu_vesc_modified_P.PAR_MASK_MODE_Value_k
	  section.data(2).logicalSrcIdx = 60;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% pendu_vesc_modified_P.SFunctionBuilder5_P1
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendu_vesc_modified_P.SFunctionBuilder5_P1_h
	  section.data(2).logicalSrcIdx = 62;
	  section.data(2).dtTransOffset = 11;
	
	  ;% pendu_vesc_modified_P.ManualSwitch_CurrentSetting
	  section.data(3).logicalSrcIdx = 63;
	  section.data(3).dtTransOffset = 22;
	
	  ;% pendu_vesc_modified_P.ManualSwitch2_CurrentSetting
	  section.data(4).logicalSrcIdx = 64;
	  section.data(4).dtTransOffset = 23;
	
	  ;% pendu_vesc_modified_P.ManualSwitch1_CurrentSetting
	  section.data(5).logicalSrcIdx = 65;
	  section.data(5).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% pendu_vesc_modified_P.IfActionSubsystem1.Saturation_UpperSat
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendu_vesc_modified_P.IfActionSubsystem1.Saturation_LowerSat
	  section.data(2).logicalSrcIdx = 67;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% pendu_vesc_modified_P.IfActionSubsystem.Saturation_UpperSat
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendu_vesc_modified_P.IfActionSubsystem.Saturation_LowerSat
	  section.data(2).logicalSrcIdx = 69;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (pendu_vesc_modified_B)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% pendu_vesc_modified_B.SFunctionBuilder5_o2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendu_vesc_modified_B.SFunctionBuilder5_o2_b
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% pendu_vesc_modified_B.SFunctionBuilder5_o1
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendu_vesc_modified_B.SFunctionBuilder5_o1_c
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% pendu_vesc_modified_B.degToRad1
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendu_vesc_modified_B.degToRad
	  section.data(2).logicalSrcIdx = 5;
	  section.data(2).dtTransOffset = 1;
	
	  ;% pendu_vesc_modified_B.Probe
	  section.data(3).logicalSrcIdx = 6;
	  section.data(3).dtTransOffset = 2;
	
	  ;% pendu_vesc_modified_B.WeightedSampleTime
	  section.data(4).logicalSrcIdx = 7;
	  section.data(4).dtTransOffset = 4;
	
	  ;% pendu_vesc_modified_B.Saturation
	  section.data(5).logicalSrcIdx = 8;
	  section.data(5).dtTransOffset = 5;
	
	  ;% pendu_vesc_modified_B.Probe_l
	  section.data(6).logicalSrcIdx = 9;
	  section.data(6).dtTransOffset = 6;
	
	  ;% pendu_vesc_modified_B.WeightedSampleTime1
	  section.data(7).logicalSrcIdx = 10;
	  section.data(7).dtTransOffset = 8;
	
	  ;% pendu_vesc_modified_B.Saturation_m
	  section.data(8).logicalSrcIdx = 11;
	  section.data(8).dtTransOffset = 9;
	
	  ;% pendu_vesc_modified_B.DiscreteTimeIntegrator
	  section.data(9).logicalSrcIdx = 12;
	  section.data(9).dtTransOffset = 10;
	
	  ;% pendu_vesc_modified_B.Probe_lj
	  section.data(10).logicalSrcIdx = 13;
	  section.data(10).dtTransOffset = 11;
	
	  ;% pendu_vesc_modified_B.Saturation_b
	  section.data(11).logicalSrcIdx = 14;
	  section.data(11).dtTransOffset = 13;
	
	  ;% pendu_vesc_modified_B.Sum
	  section.data(12).logicalSrcIdx = 15;
	  section.data(12).dtTransOffset = 14;
	
	  ;% pendu_vesc_modified_B.maxcurrent
	  section.data(13).logicalSrcIdx = 16;
	  section.data(13).dtTransOffset = 15;
	
	  ;% pendu_vesc_modified_B.pos_cmd
	  section.data(14).logicalSrcIdx = 17;
	  section.data(14).dtTransOffset = 16;
	
	  ;% pendu_vesc_modified_B.y
	  section.data(15).logicalSrcIdx = 18;
	  section.data(15).dtTransOffset = 17;
	
	  ;% pendu_vesc_modified_B.q1_out
	  section.data(16).logicalSrcIdx = 19;
	  section.data(16).dtTransOffset = 18;
	
	  ;% pendu_vesc_modified_B.q2_out
	  section.data(17).logicalSrcIdx = 20;
	  section.data(17).dtTransOffset = 19;
	
	  ;% pendu_vesc_modified_B.y_d
	  section.data(18).logicalSrcIdx = 21;
	  section.data(18).dtTransOffset = 20;
	
	  ;% pendu_vesc_modified_B.y_h
	  section.data(19).logicalSrcIdx = 22;
	  section.data(19).dtTransOffset = 21;
	
	  ;% pendu_vesc_modified_B.tau1
	  section.data(20).logicalSrcIdx = 23;
	  section.data(20).dtTransOffset = 22;
	
	  ;% pendu_vesc_modified_B.tau2
	  section.data(21).logicalSrcIdx = 24;
	  section.data(21).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% pendu_vesc_modified_B.Switch
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendu_vesc_modified_B.Switch_d
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% pendu_vesc_modified_B.current_motor
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendu_vesc_modified_B.l_current_max
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 1;
	
	  ;% pendu_vesc_modified_B.l_current_min
	  section.data(3).logicalSrcIdx = 29;
	  section.data(3).dtTransOffset = 2;
	
	  ;% pendu_vesc_modified_B.l_in_current_max
	  section.data(4).logicalSrcIdx = 30;
	  section.data(4).dtTransOffset = 3;
	
	  ;% pendu_vesc_modified_B.l_in_current_min
	  section.data(5).logicalSrcIdx = 31;
	  section.data(5).dtTransOffset = 4;
	
	  ;% pendu_vesc_modified_B.l_abs_current_max
	  section.data(6).logicalSrcIdx = 32;
	  section.data(6).dtTransOffset = 5;
	
	  ;% pendu_vesc_modified_B.p_pid_kp
	  section.data(7).logicalSrcIdx = 33;
	  section.data(7).dtTransOffset = 6;
	
	  ;% pendu_vesc_modified_B.p_pid_ki
	  section.data(8).logicalSrcIdx = 34;
	  section.data(8).dtTransOffset = 7;
	
	  ;% pendu_vesc_modified_B.p_pid_kd
	  section.data(9).logicalSrcIdx = 35;
	  section.data(9).dtTransOffset = 8;
	
	  ;% pendu_vesc_modified_B.p_pid_kd_filter
	  section.data(10).logicalSrcIdx = 36;
	  section.data(10).dtTransOffset = 9;
	
	  ;% pendu_vesc_modified_B.p_pid_ang_div
	  section.data(11).logicalSrcIdx = 37;
	  section.data(11).dtTransOffset = 10;
	
	  ;% pendu_vesc_modified_B.l_current_max_l
	  section.data(12).logicalSrcIdx = 38;
	  section.data(12).dtTransOffset = 11;
	
	  ;% pendu_vesc_modified_B.l_current_min_b
	  section.data(13).logicalSrcIdx = 39;
	  section.data(13).dtTransOffset = 12;
	
	  ;% pendu_vesc_modified_B.l_in_current_max_d
	  section.data(14).logicalSrcIdx = 40;
	  section.data(14).dtTransOffset = 13;
	
	  ;% pendu_vesc_modified_B.l_in_current_min_p
	  section.data(15).logicalSrcIdx = 41;
	  section.data(15).dtTransOffset = 14;
	
	  ;% pendu_vesc_modified_B.l_abs_current_max_e
	  section.data(16).logicalSrcIdx = 42;
	  section.data(16).dtTransOffset = 15;
	
	  ;% pendu_vesc_modified_B.p_pid_kp_m
	  section.data(17).logicalSrcIdx = 43;
	  section.data(17).dtTransOffset = 16;
	
	  ;% pendu_vesc_modified_B.p_pid_ki_k
	  section.data(18).logicalSrcIdx = 44;
	  section.data(18).dtTransOffset = 17;
	
	  ;% pendu_vesc_modified_B.p_pid_kd_m
	  section.data(19).logicalSrcIdx = 45;
	  section.data(19).dtTransOffset = 18;
	
	  ;% pendu_vesc_modified_B.p_pid_kd_filter_p
	  section.data(20).logicalSrcIdx = 46;
	  section.data(20).dtTransOffset = 19;
	
	  ;% pendu_vesc_modified_B.p_pid_ang_div_j
	  section.data(21).logicalSrcIdx = 47;
	  section.data(21).dtTransOffset = 20;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% pendu_vesc_modified_B.SFunctionBuilder5_o3
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendu_vesc_modified_B.SFunctionBuilder5_o3_o
	  section.data(2).logicalSrcIdx = 49;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 6;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (pendu_vesc_modified_DW)
    ;%
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% pendu_vesc_modified_DW.UD_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendu_vesc_modified_DW.UD_DSTATE_i
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% pendu_vesc_modified_DW.Integrator_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% pendu_vesc_modified_DW.UD1_DSTATE
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% pendu_vesc_modified_DW.Integrator_DSTATE_b
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% pendu_vesc_modified_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% pendu_vesc_modified_DW.UnitDelay_DSTATE
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% pendu_vesc_modified_DW.Integrator_DSTATE_k
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% pendu_vesc_modified_DW.UD_DSTATE_a
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% pendu_vesc_modified_DW.SFunctionBuilder5_DSTATE
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% pendu_vesc_modified_DW.SFunctionBuilder5_DSTATE_i
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% pendu_vesc_modified_DW.pos1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% pendu_vesc_modified_DW.initpos
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% pendu_vesc_modified_DW.initpos_d
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% pendu_vesc_modified_DW.ToFile_PWORK.FilePtr
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendu_vesc_modified_DW.Scope2_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% pendu_vesc_modified_DW.Scope_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 2;
	
	  ;% pendu_vesc_modified_DW.Scope5_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 4;
	
	  ;% pendu_vesc_modified_DW.Scope6_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 5;
	
	  ;% pendu_vesc_modified_DW.Scope1_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 19;
	  section.data(6).dtTransOffset = 6;
	
	  ;% pendu_vesc_modified_DW.Scope1_PWORK_a.LoggedData
	  section.data(7).logicalSrcIdx = 20;
	  section.data(7).dtTransOffset = 10;
	
	  ;% pendu_vesc_modified_DW.Scope_PWORK_i.LoggedData
	  section.data(8).logicalSrcIdx = 21;
	  section.data(8).dtTransOffset = 12;
	
	  ;% pendu_vesc_modified_DW.Scope2_PWORK_l.LoggedData
	  section.data(9).logicalSrcIdx = 22;
	  section.data(9).dtTransOffset = 14;
	
	  ;% pendu_vesc_modified_DW.Scope_PWORK_h.LoggedData
	  section.data(10).logicalSrcIdx = 23;
	  section.data(10).dtTransOffset = 15;
	
	  ;% pendu_vesc_modified_DW.SFunctionBuilder5_PWORK
	  section.data(11).logicalSrcIdx = 24;
	  section.data(11).dtTransOffset = 16;
	
	  ;% pendu_vesc_modified_DW.SFunctionBuilder5_PWORK_k
	  section.data(12).logicalSrcIdx = 25;
	  section.data(12).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% pendu_vesc_modified_DW.ToFile_IWORK.Count
	  section.data(1).logicalSrcIdx = 26;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% pendu_vesc_modified_DW.Integrator_PrevResetState
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendu_vesc_modified_DW.Integrator_PrevResetState_p
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 1;
	
	  ;% pendu_vesc_modified_DW.DiscreteTimeIntegrator_PrevRese
	  section.data(3).logicalSrcIdx = 29;
	  section.data(3).dtTransOffset = 2;
	
	  ;% pendu_vesc_modified_DW.Integrator_PrevResetState_c
	  section.data(4).logicalSrcIdx = 30;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% pendu_vesc_modified_DW.Integrator_IC_LOADING
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pendu_vesc_modified_DW.Integrator_IC_LOADING_c
	  section.data(2).logicalSrcIdx = 32;
	  section.data(2).dtTransOffset = 1;
	
	  ;% pendu_vesc_modified_DW.Integrator_IC_LOADING_p
	  section.data(3).logicalSrcIdx = 33;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% pendu_vesc_modified_DW.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% pendu_vesc_modified_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1510491195;
  targMap.checksum1 = 1687192483;
  targMap.checksum2 = 18905543;
  targMap.checksum3 = 4169505437;

