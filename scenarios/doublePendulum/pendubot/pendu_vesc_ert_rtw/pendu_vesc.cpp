//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pendu_vesc.cpp
//
// Code generated for Simulink model 'pendu_vesc'.
//
// Model version                  : 1.79
// Simulink Coder version         : 9.0 (R2018b) 24-May-2018
// C/C++ source code generated on : Mon Jun 15 15:44:10 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "pendu_vesc.h"
#include "pendu_vesc_private.h"
#include "pendu_vesc_dt.h"

// Block signals (default storage)
B_pendu_vesc_T pendu_vesc_B;

// Block states (default storage)
DW_pendu_vesc_T pendu_vesc_DW;

// Real-time model
RT_MODEL_pendu_vesc_T pendu_vesc_M_;
RT_MODEL_pendu_vesc_T *const pendu_vesc_M = &pendu_vesc_M_;

//
// Output and update for action system:
//    '<S8>/If Action Subsystem'
//    '<S8>/If Action Subsystem1'
//
void pendu_vesc_IfActionSubsystem(real_T rtu_In1, real_T *rty_Out1,
  P_IfActionSubsystem_pendu_ves_T *localP)
{
  // Saturate: '<S18>/Saturation'
  if (rtu_In1 > localP->Saturation_UpperSat) {
    *rty_Out1 = localP->Saturation_UpperSat;
  } else if (rtu_In1 < localP->Saturation_LowerSat) {
    *rty_Out1 = localP->Saturation_LowerSat;
  } else {
    *rty_Out1 = rtu_In1;
  }

  // End of Saturate: '<S18>/Saturation'
}

//
// Output and update for atomic system:
//    '<S9>/MATLAB Function'
//    '<S9>/MATLAB Function1'
//
void pendu_vesc_MATLABFunction(real_T rtu_u, real_T *rty_y)
{
  real_T u_rev;
  u_rev = (real_T)(rtu_u >= 0.0) * (6.2831853071795862 - rtu_u) + (real_T)(rtu_u
    < 0.0) * (6.2831853071795862 + rtu_u);
  if (std::abs(u_rev) > std::abs(rtu_u)) {
    *rty_y = rtu_u;
  } else {
    *rty_y = (real_T)(rtu_u < 0.0) * u_rev - (real_T)(rtu_u >= 0.0) * u_rev;
  }
}

// Model step function
void pendu_vesc_step(void)
{
  // local block i/o variables
  real_T rtb_uT;
  real_T rtb_uT_o;
  real_T rtb_uT_e;
  real_T rtb_TSamp;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_o;
  boolean_T rtb_Compare_c;
  static const real_T d[16] = { 56.3272, 49.3325, 11.1626, 4.3446, 49.3325,
    45.0528, 9.9269, 3.866, 11.1626, 9.9269, 2.2983, 0.894, 4.3446, 3.866, 0.894,
    0.3492 };

  real_T rtb_Integrator_p;
  int32_T i;
  int32_T tau_size_idx_1;
  int32_T x_tilda_tmp;

  // Reset subsysRan breadcrumbs
  srClearBC(pendu_vesc_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);

  // RelationalOperator: '<S26>/Compare' incorporates:
  //   Constant: '<S24>/Time constant'
  //   Constant: '<S26>/Constant'
  //   Sum: '<S24>/Sum1'

  rtb_Compare = (pendu_vesc_P.LowPassFilterDiscreteorContin_g -
                 pendu_vesc_B.Probe_l[0] <= pendu_vesc_P.Constant_Value_i);

  // ManualSwitch: '<Root>/Manual Switch2' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Constant: '<Root>/Constant6'

  if (pendu_vesc_P.ManualSwitch2_CurrentSetting == 1) {
    pendu_vesc_B.ManualSwitch2 = pendu_vesc_P.Constant1_Value;
  } else {
    pendu_vesc_B.ManualSwitch2 = pendu_vesc_P.Constant6_Value;
  }

  // End of ManualSwitch: '<Root>/Manual Switch2'

  // ManualSwitch: '<Root>/Manual Switch' incorporates:
  //   Constant: '<Root>/Constant'
  //   Constant: '<Root>/Constant3'

  if (pendu_vesc_P.ManualSwitch_CurrentSetting == 1) {
    pendu_vesc_B.ManualSwitch = pendu_vesc_P.Constant_Value;
  } else {
    pendu_vesc_B.ManualSwitch = pendu_vesc_P.Constant3_Value;
  }

  // End of ManualSwitch: '<Root>/Manual Switch'

  // Outputs for Atomic SubSystem: '<Root>/VESC USB'
  // S-Function (sf_vesc_usb): '<S10>/S-Function Builder5' incorporates:
  //   Constant: '<S10>/PAR_CURR_LIMS'
  //   Constant: '<S10>/PAR_PID_GAINS'

  sf_vesc_usb_Outputs_wrapper(&pendu_vesc_B.SFunctionBuilder5_o1_c,
    &pendu_vesc_B.SFunctionBuilder5_o2_b, &pendu_vesc_B.SFunctionBuilder5_o3_o,
    &pendu_vesc_DW.SFunctionBuilder5_DSTATE_i,
    &pendu_vesc_DW.SFunctionBuilder5_PWORK_k, pendu_vesc_P.SFunctionBuilder5_P1,
    15);

  // SignalConversion: '<S10>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_B.l_current_max_l =
    pendu_vesc_B.SFunctionBuilder5_o2_b.l_current_max;

  // SignalConversion: '<S10>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_B.l_current_min_b =
    pendu_vesc_B.SFunctionBuilder5_o2_b.l_current_min;

  // SignalConversion: '<S10>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_B.l_in_current_max_d =
    pendu_vesc_B.SFunctionBuilder5_o2_b.l_in_current_max;

  // SignalConversion: '<S10>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_B.l_in_current_min_p =
    pendu_vesc_B.SFunctionBuilder5_o2_b.l_in_current_min;

  // SignalConversion: '<S10>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_B.l_abs_current_max_e =
    pendu_vesc_B.SFunctionBuilder5_o2_b.l_abs_current_max;

  // SignalConversion: '<S10>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_B.p_pid_kp_m = pendu_vesc_B.SFunctionBuilder5_o2_b.p_pid_kp;

  // SignalConversion: '<S10>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_B.p_pid_ki_k = pendu_vesc_B.SFunctionBuilder5_o2_b.p_pid_ki;

  // SignalConversion: '<S10>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_B.p_pid_kd_m = pendu_vesc_B.SFunctionBuilder5_o2_b.p_pid_kd;

  // SignalConversion: '<S10>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_B.p_pid_kd_filter_p =
    pendu_vesc_B.SFunctionBuilder5_o2_b.p_pid_kd_filter;

  // SignalConversion: '<S10>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_B.p_pid_ang_div_j =
    pendu_vesc_B.SFunctionBuilder5_o2_b.p_pid_ang_div;

  // Switch: '<S10>/Switch' incorporates:
  //   Constant: '<S10>/PAR_MASK_MODE'
  //   DataTypeConversion: '<Root>/Data Type Conversion'

  if (pendu_vesc_P.PAR_MASK_MODE_Value != 0U) {
    pendu_vesc_B.Switch_d = pendu_vesc_P.PAR_MASK_MODE_Value;
  } else {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    pendu_vesc_B.M12 = std::floor(pendu_vesc_B.ManualSwitch);
    if (rtIsNaN(pendu_vesc_B.M12) || rtIsInf(pendu_vesc_B.M12)) {
      pendu_vesc_B.M12 = 0.0;
    } else {
      pendu_vesc_B.M12 = std::fmod(pendu_vesc_B.M12, 4.294967296E+9);
    }

    pendu_vesc_B.Switch_d = pendu_vesc_B.M12 < 0.0 ? (uint32_T)-(int32_T)
      (uint32_T)-pendu_vesc_B.M12 : (uint32_T)pendu_vesc_B.M12;
  }

  // End of Switch: '<S10>/Switch'
  // End of Outputs for SubSystem: '<Root>/VESC USB'

  // Outputs for Atomic SubSystem: '<Root>/VESC USB1'
  // S-Function (sf_vesc_usb): '<S11>/S-Function Builder5' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<S11>/PAR_CURR_LIMS'
  //   Constant: '<S11>/PAR_PID_GAINS'

  sf_vesc_usb_Outputs_wrapper(&pendu_vesc_B.SFunctionBuilder5_o1,
    &pendu_vesc_B.SFunctionBuilder5_o2, &pendu_vesc_B.SFunctionBuilder5_o3,
    &pendu_vesc_DW.SFunctionBuilder5_DSTATE,
    &pendu_vesc_DW.SFunctionBuilder5_PWORK, pendu_vesc_P.SFunctionBuilder5_P1_h,
    15);

  // SignalConversion: '<S11>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_B.l_current_max = pendu_vesc_B.SFunctionBuilder5_o2.l_current_max;

  // SignalConversion: '<S11>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_B.l_current_min = pendu_vesc_B.SFunctionBuilder5_o2.l_current_min;

  // SignalConversion: '<S11>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_B.l_in_current_max =
    pendu_vesc_B.SFunctionBuilder5_o2.l_in_current_max;

  // SignalConversion: '<S11>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_B.l_in_current_min =
    pendu_vesc_B.SFunctionBuilder5_o2.l_in_current_min;

  // SignalConversion: '<S11>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_B.l_abs_current_max =
    pendu_vesc_B.SFunctionBuilder5_o2.l_abs_current_max;

  // SignalConversion: '<S11>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_B.p_pid_kp = pendu_vesc_B.SFunctionBuilder5_o2.p_pid_kp;

  // SignalConversion: '<S11>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_B.p_pid_ki = pendu_vesc_B.SFunctionBuilder5_o2.p_pid_ki;

  // SignalConversion: '<S11>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_B.p_pid_kd = pendu_vesc_B.SFunctionBuilder5_o2.p_pid_kd;

  // SignalConversion: '<S11>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_B.p_pid_kd_filter =
    pendu_vesc_B.SFunctionBuilder5_o2.p_pid_kd_filter;

  // SignalConversion: '<S11>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_B.p_pid_ang_div = pendu_vesc_B.SFunctionBuilder5_o2.p_pid_ang_div;

  // Switch: '<S11>/Switch' incorporates:
  //   Constant: '<S11>/PAR_MASK_MODE'
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  if (pendu_vesc_P.PAR_MASK_MODE_Value_k != 0U) {
    pendu_vesc_B.Switch = pendu_vesc_P.PAR_MASK_MODE_Value_k;
  } else {
    // DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
    //   Constant: '<Root>/Constant5'

    pendu_vesc_B.M12 = std::floor(pendu_vesc_P.Constant5_Value);
    if (rtIsNaN(pendu_vesc_B.M12) || rtIsInf(pendu_vesc_B.M12)) {
      pendu_vesc_B.M12 = 0.0;
    } else {
      pendu_vesc_B.M12 = std::fmod(pendu_vesc_B.M12, 4.294967296E+9);
    }

    pendu_vesc_B.Switch = pendu_vesc_B.M12 < 0.0 ? (uint32_T)-(int32_T)(uint32_T)
      -pendu_vesc_B.M12 : (uint32_T)pendu_vesc_B.M12;
  }

  // End of Switch: '<S11>/Switch'
  // End of Outputs for SubSystem: '<Root>/VESC USB1'

  // MATLAB Function: '<Root>/MATLAB Function1' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  if (pendu_vesc_B.ManualSwitch2 != 0.0) {
    pendu_vesc_DW.initpos = pendu_vesc_B.SFunctionBuilder5_o1.pid_pos;
  }

  pendu_vesc_B.y_d = pendu_vesc_B.SFunctionBuilder5_o1.pid_pos -
    pendu_vesc_DW.initpos;
  pendu_vesc_B.y_d -= std::floor(pendu_vesc_B.y_d / 360.0) * 360.0;

  // End of MATLAB Function: '<Root>/MATLAB Function1'

  // Gain: '<S9>/degToRad'
  pendu_vesc_B.degToRad = pendu_vesc_P.degToRad_Gain * pendu_vesc_B.y_d;

  // MATLAB Function: '<S9>/MATLAB Function1' incorporates:
  //   Sum: '<S9>/Diff1'
  //   UnitDelay: '<S9>/UD1'
  //
  //  Block description for '<S9>/Diff1':
  //
  //   Add in CPU
  //
  //  Block description for '<S9>/UD1':
  //
  //   Store in Global RAM

  pendu_vesc_MATLABFunction(pendu_vesc_B.degToRad - pendu_vesc_DW.UD1_DSTATE,
    &rtb_Integrator_p);

  // SampleTimeMath: '<S9>/Weighted Sample Time1'
  //
  //  About '<S9>/Weighted Sample Time1':
  //   y = u * K where K = 1 / ( w * Ts )

  pendu_vesc_B.WeightedSampleTime1 = rtb_Integrator_p *
    pendu_vesc_P.WeightedSampleTime1_WtEt;

  // Gain: '<S20>/K'
  rtb_Integrator_p = pendu_vesc_P.LowPassFilterDiscreteorContinuo *
    pendu_vesc_B.WeightedSampleTime1;

  // DiscreteIntegrator: '<S28>/Integrator'
  if (pendu_vesc_DW.Integrator_IC_LOADING != 0) {
    pendu_vesc_DW.Integrator_DSTATE = rtb_Integrator_p;
    if (pendu_vesc_DW.Integrator_DSTATE >= pendu_vesc_P.Integrator_UpperSat) {
      pendu_vesc_DW.Integrator_DSTATE = pendu_vesc_P.Integrator_UpperSat;
    } else {
      if (pendu_vesc_DW.Integrator_DSTATE <= pendu_vesc_P.Integrator_LowerSat) {
        pendu_vesc_DW.Integrator_DSTATE = pendu_vesc_P.Integrator_LowerSat;
      }
    }
  }

  if (rtb_Compare || (pendu_vesc_DW.Integrator_PrevResetState != 0)) {
    pendu_vesc_DW.Integrator_DSTATE = rtb_Integrator_p;
    if (pendu_vesc_DW.Integrator_DSTATE >= pendu_vesc_P.Integrator_UpperSat) {
      pendu_vesc_DW.Integrator_DSTATE = pendu_vesc_P.Integrator_UpperSat;
    } else {
      if (pendu_vesc_DW.Integrator_DSTATE <= pendu_vesc_P.Integrator_LowerSat) {
        pendu_vesc_DW.Integrator_DSTATE = pendu_vesc_P.Integrator_LowerSat;
      }
    }
  }

  if (pendu_vesc_DW.Integrator_DSTATE >= pendu_vesc_P.Integrator_UpperSat) {
    pendu_vesc_DW.Integrator_DSTATE = pendu_vesc_P.Integrator_UpperSat;
  } else {
    if (pendu_vesc_DW.Integrator_DSTATE <= pendu_vesc_P.Integrator_LowerSat) {
      pendu_vesc_DW.Integrator_DSTATE = pendu_vesc_P.Integrator_LowerSat;
    }
  }

  // Saturate: '<S28>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S28>/Integrator'

  if (pendu_vesc_DW.Integrator_DSTATE > pendu_vesc_P.Saturation_UpperSat) {
    pendu_vesc_B.Saturation = pendu_vesc_P.Saturation_UpperSat;
  } else if (pendu_vesc_DW.Integrator_DSTATE < pendu_vesc_P.Saturation_LowerSat)
  {
    pendu_vesc_B.Saturation = pendu_vesc_P.Saturation_LowerSat;
  } else {
    pendu_vesc_B.Saturation = pendu_vesc_DW.Integrator_DSTATE;
  }

  // End of Saturate: '<S28>/Saturation'
  // MinMax: '<S24>/Max' incorporates:
  //   Constant: '<S24>/Time constant'

  if ((pendu_vesc_B.Probe_l[0] > pendu_vesc_P.LowPassFilterDiscreteorContin_g) ||
      rtIsNaN(pendu_vesc_P.LowPassFilterDiscreteorContin_g)) {
    pendu_vesc_B.Integrator_o = pendu_vesc_B.Probe_l[0];
  } else {
    pendu_vesc_B.Integrator_o = pendu_vesc_P.LowPassFilterDiscreteorContin_g;
  }

  // End of MinMax: '<S24>/Max'

  // Product: '<S20>/1//T' incorporates:
  //   Fcn: '<S24>/Avoid Divide by Zero'
  //   Sum: '<S20>/Sum1'

  rtb_uT = 1.0 / ((real_T)(pendu_vesc_B.Integrator_o == 0.0) *
                  2.2204460492503131e-16 + pendu_vesc_B.Integrator_o) *
    (rtb_Integrator_p - pendu_vesc_B.Saturation);

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion2'

  if (pendu_vesc_B.ManualSwitch2 != 0.0) {
    pendu_vesc_DW.initpos_d = pendu_vesc_B.SFunctionBuilder5_o1_c.pid_pos;
  }

  pendu_vesc_B.y_h = pendu_vesc_B.SFunctionBuilder5_o1_c.pid_pos -
    pendu_vesc_DW.initpos_d;
  pendu_vesc_B.y_h -= std::floor(pendu_vesc_B.y_h / 360.0) * 360.0;

  // End of MATLAB Function: '<Root>/MATLAB Function'

  // Sum: '<S12>/Diff' incorporates:
  //   UnitDelay: '<S12>/UD'
  //
  //  Block description for '<S12>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S12>/UD':
  //
  //   Store in Global RAM

  pendu_vesc_B.ManualSwitch2 = pendu_vesc_B.y_h - pendu_vesc_DW.UD_DSTATE;

  // MATLAB Function: '<S12>/MATLAB Function'
  rtb_Integrator_p = (real_T)(pendu_vesc_B.ManualSwitch2 >= 0.0) * (360.0 -
    pendu_vesc_B.ManualSwitch2) + (real_T)(pendu_vesc_B.ManualSwitch2 < 0.0) *
    (360.0 + pendu_vesc_B.ManualSwitch2);
  if (std::abs(rtb_Integrator_p) < std::abs(pendu_vesc_B.ManualSwitch2)) {
    pendu_vesc_B.ManualSwitch2 = (real_T)(pendu_vesc_B.ManualSwitch2 < 0.0) *
      rtb_Integrator_p - (real_T)(pendu_vesc_B.ManualSwitch2 >= 0.0) *
      rtb_Integrator_p;
  }

  pendu_vesc_B.ManualSwitch2 /= 5.0;
  pendu_vesc_DW.pos1 += pendu_vesc_B.ManualSwitch2;
  pendu_vesc_B.ManualSwitch2 = pendu_vesc_DW.pos1;
  if ((!rtIsInf(pendu_vesc_B.ManualSwitch2)) && (!rtIsNaN
       (pendu_vesc_B.ManualSwitch2))) {
    if (pendu_vesc_B.ManualSwitch2 == 0.0) {
      pendu_vesc_DW.pos1 = 0.0;
    } else {
      pendu_vesc_DW.pos1 = std::fmod(pendu_vesc_B.ManualSwitch2, 360.0);
      if (pendu_vesc_DW.pos1 == 0.0) {
        pendu_vesc_DW.pos1 = 0.0;
      } else {
        if (pendu_vesc_B.ManualSwitch2 < 0.0) {
          pendu_vesc_DW.pos1 += 360.0;
        }
      }
    }
  } else {
    pendu_vesc_DW.pos1 = (rtNaN);
  }

  pendu_vesc_B.y = pendu_vesc_DW.pos1;

  // End of MATLAB Function: '<S12>/MATLAB Function'

  // Gain: '<S9>/degToRad1'
  pendu_vesc_B.degToRad1 = pendu_vesc_P.degToRad1_Gain * pendu_vesc_B.y;

  // RelationalOperator: '<S31>/Compare' incorporates:
  //   Constant: '<S29>/Time constant'
  //   Constant: '<S31>/Constant'
  //   Sum: '<S29>/Sum1'

  rtb_Compare_o = (pendu_vesc_P.LowPassFilterDiscreteorContin_j -
                   pendu_vesc_B.Probe_g[0] <= pendu_vesc_P.Constant_Value_c);

  // MATLAB Function: '<S9>/MATLAB Function' incorporates:
  //   Sum: '<S9>/Diff'
  //   UnitDelay: '<S9>/UD'
  //
  //  Block description for '<S9>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S9>/UD':
  //
  //   Store in Global RAM

  pendu_vesc_MATLABFunction(pendu_vesc_B.degToRad1 - pendu_vesc_DW.UD_DSTATE_i,
    &rtb_Integrator_p);

  // SampleTimeMath: '<S9>/Weighted Sample Time'
  //
  //  About '<S9>/Weighted Sample Time':
  //   y = u * K where K = 1 / ( w * Ts )

  pendu_vesc_B.WeightedSampleTime = rtb_Integrator_p *
    pendu_vesc_P.WeightedSampleTime_WtEt;

  // Gain: '<S21>/K'
  pendu_vesc_B.ManualSwitch2 = pendu_vesc_P.LowPassFilterDiscreteorContin_o *
    pendu_vesc_B.WeightedSampleTime;

  // DiscreteIntegrator: '<S33>/Integrator'
  if (pendu_vesc_DW.Integrator_IC_LOADING_h != 0) {
    pendu_vesc_DW.Integrator_DSTATE_c = pendu_vesc_B.ManualSwitch2;
    if (pendu_vesc_DW.Integrator_DSTATE_c >= pendu_vesc_P.Integrator_UpperSat_d)
    {
      pendu_vesc_DW.Integrator_DSTATE_c = pendu_vesc_P.Integrator_UpperSat_d;
    } else {
      if (pendu_vesc_DW.Integrator_DSTATE_c <=
          pendu_vesc_P.Integrator_LowerSat_k) {
        pendu_vesc_DW.Integrator_DSTATE_c = pendu_vesc_P.Integrator_LowerSat_k;
      }
    }
  }

  if (rtb_Compare_o || (pendu_vesc_DW.Integrator_PrevResetState_j != 0)) {
    pendu_vesc_DW.Integrator_DSTATE_c = pendu_vesc_B.ManualSwitch2;
    if (pendu_vesc_DW.Integrator_DSTATE_c >= pendu_vesc_P.Integrator_UpperSat_d)
    {
      pendu_vesc_DW.Integrator_DSTATE_c = pendu_vesc_P.Integrator_UpperSat_d;
    } else {
      if (pendu_vesc_DW.Integrator_DSTATE_c <=
          pendu_vesc_P.Integrator_LowerSat_k) {
        pendu_vesc_DW.Integrator_DSTATE_c = pendu_vesc_P.Integrator_LowerSat_k;
      }
    }
  }

  if (pendu_vesc_DW.Integrator_DSTATE_c >= pendu_vesc_P.Integrator_UpperSat_d) {
    pendu_vesc_DW.Integrator_DSTATE_c = pendu_vesc_P.Integrator_UpperSat_d;
  } else {
    if (pendu_vesc_DW.Integrator_DSTATE_c <= pendu_vesc_P.Integrator_LowerSat_k)
    {
      pendu_vesc_DW.Integrator_DSTATE_c = pendu_vesc_P.Integrator_LowerSat_k;
    }
  }

  // Saturate: '<S33>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S33>/Integrator'

  if (pendu_vesc_DW.Integrator_DSTATE_c > pendu_vesc_P.Saturation_UpperSat_c) {
    pendu_vesc_B.Saturation_e = pendu_vesc_P.Saturation_UpperSat_c;
  } else if (pendu_vesc_DW.Integrator_DSTATE_c <
             pendu_vesc_P.Saturation_LowerSat_m) {
    pendu_vesc_B.Saturation_e = pendu_vesc_P.Saturation_LowerSat_m;
  } else {
    pendu_vesc_B.Saturation_e = pendu_vesc_DW.Integrator_DSTATE_c;
  }

  // End of Saturate: '<S33>/Saturation'

  // MATLAB Function: '<Root>/Control' incorporates:
  //   Constant: '<S3>/Energy Shaping Gain'
  //   Constant: '<S3>/Window'
  //   Constant: '<S4>/a'
  //   Constant: '<S4>/b'
  //   Constant: '<S4>/d'
  //   Constant: '<S4>/p'

  rtb_Integrator_p = pendu_vesc_B.degToRad1 - std::floor(pendu_vesc_B.degToRad1 /
    6.2831853071795862) * 6.2831853071795862;
  pendu_vesc_B.Integrator_o = pendu_vesc_B.degToRad - std::floor
    ((pendu_vesc_B.degToRad + 3.1415926535897931) / 6.2831853071795862) *
    6.2831853071795862;
  pendu_vesc_B.x_tilda[0] = rtb_Integrator_p - 3.1415926535897931;
  pendu_vesc_B.x_tilda[2] = pendu_vesc_B.Saturation_e;
  pendu_vesc_B.x_tilda[1] = pendu_vesc_B.Integrator_o;
  pendu_vesc_B.x_tilda[3] = pendu_vesc_B.Saturation;
  pendu_vesc_B.M12 = 0.0;
  for (i = 0; i < 4; i++) {
    x_tilda_tmp = i << 2;
    pendu_vesc_B.kd = d[x_tilda_tmp + 3] * pendu_vesc_B.Saturation +
      (d[x_tilda_tmp + 2] * pendu_vesc_B.Saturation_e + (d[x_tilda_tmp + 1] *
        pendu_vesc_B.Integrator_o + (rtb_Integrator_p - 3.1415926535897931) *
        d[x_tilda_tmp]));
    pendu_vesc_B.M12 += pendu_vesc_B.kd * pendu_vesc_B.x_tilda[i];
  }

  if (pendu_vesc_B.M12 < pendu_vesc_P.Window_Value) {
    pendu_vesc_B.dv0[0] = -25.3884 * pendu_vesc_P.a_Value;
    pendu_vesc_B.dv0[2] = -24.2524 * pendu_vesc_P.b_Value;
    pendu_vesc_B.dv0[4] = -4.8296 * pendu_vesc_P.p_Value;
    pendu_vesc_B.dv0[6] = -2.955 * pendu_vesc_P.d_Value;
    pendu_vesc_B.dv0[1] = 0.0;
    pendu_vesc_B.dv0[3] = 0.0;
    pendu_vesc_B.dv0[5] = 0.0;
    pendu_vesc_B.dv0[7] = 0.0;
    x_tilda_tmp = 2;
    tau_size_idx_1 = 1;
    for (i = 0; i < 2; i++) {
      pendu_vesc_B.M12 = pendu_vesc_B.dv0[i + 6] * (0.0 -
        pendu_vesc_B.Saturation) + (pendu_vesc_B.dv0[i + 4] * (0.0 -
        pendu_vesc_B.Saturation_e) + (pendu_vesc_B.dv0[i + 2] * (0.0 -
        pendu_vesc_B.Integrator_o) + (3.1415926535897931 - rtb_Integrator_p) *
        pendu_vesc_B.dv0[i]));
      pendu_vesc_B.tau_data[i] = pendu_vesc_B.M12;
    }
  } else {
    x_tilda_tmp = 0;
    tau_size_idx_1 = 0;
  }

  pendu_vesc_B.mode = 1.0;
  if ((x_tilda_tmp == 0) || (tau_size_idx_1 == 0)) {
    pendu_vesc_B.mode = 0.0;
    rtb_Integrator_p = std::cos(pendu_vesc_B.degToRad1);
    pendu_vesc_B.Integrator_o = std::cos(pendu_vesc_B.degToRad);
    pendu_vesc_B.M12 = 0.001590443925 * pendu_vesc_B.Integrator_o + 0.0010009992;
    pendu_vesc_B.kd = pendu_vesc_P.EnergyShapingGain_Value[1] *
      pendu_vesc_P.EnergyShapingGain_Value[0];
    pendu_vesc_B.kd = (3.1415926535897931 - (pendu_vesc_B.degToRad1 - std::floor
      (pendu_vesc_B.degToRad1 / 6.2831853071795862) * 6.2831853071795862)) *
      pendu_vesc_B.kd + (0.0 - pendu_vesc_B.Saturation_e) *
      (pendu_vesc_P.EnergyShapingGain_Value[2] * pendu_vesc_B.kd);
    if (std::abs(pendu_vesc_B.kd) > 1.0) {
      if (pendu_vesc_B.kd < 0.0) {
        pendu_vesc_B.kd = -1.0;
      } else if (pendu_vesc_B.kd > 0.0) {
        pendu_vesc_B.kd = 1.0;
      } else if (pendu_vesc_B.kd == 0.0) {
        pendu_vesc_B.kd = 0.0;
      } else {
        pendu_vesc_B.kd = (rtNaN);
      }
    }

    x_tilda_tmp = 2;
    pendu_vesc_B.tau_data[0] = (0.38753445581999996 - ((((0.00318088785 *
      pendu_vesc_B.Integrator_o + 0.00714846245) * (0.5 *
      pendu_vesc_B.Saturation_e) + 0.5 * pendu_vesc_B.Saturation *
      pendu_vesc_B.M12) * pendu_vesc_B.Saturation_e + (0.5 *
      pendu_vesc_B.Saturation_e * pendu_vesc_B.M12 + 0.5 *
      pendu_vesc_B.Saturation * 0.0010009992) * pendu_vesc_B.Saturation) +
      (-0.08232289092 * rtb_Integrator_p - (std::cos(pendu_vesc_B.degToRad1 +
      pendu_vesc_B.degToRad) * 0.06783 + 0.2075 * rtb_Integrator_p) * 1.10853)))
      * pendu_vesc_P.EnergyShapingGain_Value[0] * pendu_vesc_B.Saturation_e +
      pendu_vesc_B.kd;
    pendu_vesc_B.tau_data[1] = 0.0;
  }

  x_tilda_tmp--;
  for (i = 0; i <= x_tilda_tmp; i++) {
    pendu_vesc_B.tau_data[i] *= 0.2;
  }

  // If: '<S8>/If' incorporates:
  //   MATLAB Function: '<Root>/Control'

  if (pendu_vesc_B.mode > 0.0) {
    // Outputs for IfAction SubSystem: '<S8>/If Action Subsystem' incorporates:
    //   ActionPort: '<S18>/Action Port'

    pendu_vesc_IfActionSubsystem(pendu_vesc_B.tau_data[0], &rtb_Integrator_p,
      &pendu_vesc_P.IfActionSubsystem);

    // End of Outputs for SubSystem: '<S8>/If Action Subsystem'
  } else {
    // Outputs for IfAction SubSystem: '<S8>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S19>/Action Port'

    pendu_vesc_IfActionSubsystem(pendu_vesc_B.tau_data[0], &rtb_Integrator_p,
      &pendu_vesc_P.IfActionSubsystem1);

    // End of Outputs for SubSystem: '<S8>/If Action Subsystem1'
  }

  // End of If: '<S8>/If'

  // RelationalOperator: '<S15>/Compare' incorporates:
  //   Constant: '<S13>/Time constant'
  //   Constant: '<S15>/Constant'
  //   Sum: '<S13>/Sum1'

  rtb_Compare_c = (pendu_vesc_P.LowPassFilterDiscreteorConti_jv -
                   pendu_vesc_B.Probe[0] <= pendu_vesc_P.Constant_Value_ib);

  // Gain: '<S5>/K' incorporates:
  //   UnitDelay: '<Root>/Unit Delay'

  pendu_vesc_B.Integrator_o = pendu_vesc_P.LowPassFilterDiscreteorContin_e *
    pendu_vesc_DW.UnitDelay_DSTATE;

  // DiscreteIntegrator: '<S17>/Integrator'
  if (pendu_vesc_DW.Integrator_IC_LOADING_p != 0) {
    pendu_vesc_DW.Integrator_DSTATE_k = pendu_vesc_B.Integrator_o;
    if (pendu_vesc_DW.Integrator_DSTATE_k >= pendu_vesc_P.Integrator_UpperSat_n)
    {
      pendu_vesc_DW.Integrator_DSTATE_k = pendu_vesc_P.Integrator_UpperSat_n;
    } else {
      if (pendu_vesc_DW.Integrator_DSTATE_k <=
          pendu_vesc_P.Integrator_LowerSat_a) {
        pendu_vesc_DW.Integrator_DSTATE_k = pendu_vesc_P.Integrator_LowerSat_a;
      }
    }
  }

  if (rtb_Compare_c || (pendu_vesc_DW.Integrator_PrevResetState_c != 0)) {
    pendu_vesc_DW.Integrator_DSTATE_k = pendu_vesc_B.Integrator_o;
    if (pendu_vesc_DW.Integrator_DSTATE_k >= pendu_vesc_P.Integrator_UpperSat_n)
    {
      pendu_vesc_DW.Integrator_DSTATE_k = pendu_vesc_P.Integrator_UpperSat_n;
    } else {
      if (pendu_vesc_DW.Integrator_DSTATE_k <=
          pendu_vesc_P.Integrator_LowerSat_a) {
        pendu_vesc_DW.Integrator_DSTATE_k = pendu_vesc_P.Integrator_LowerSat_a;
      }
    }
  }

  if (pendu_vesc_DW.Integrator_DSTATE_k >= pendu_vesc_P.Integrator_UpperSat_n) {
    pendu_vesc_DW.Integrator_DSTATE_k = pendu_vesc_P.Integrator_UpperSat_n;
  } else {
    if (pendu_vesc_DW.Integrator_DSTATE_k <= pendu_vesc_P.Integrator_LowerSat_a)
    {
      pendu_vesc_DW.Integrator_DSTATE_k = pendu_vesc_P.Integrator_LowerSat_a;
    }
  }

  // Saturate: '<S17>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S17>/Integrator'

  if (pendu_vesc_DW.Integrator_DSTATE_k > pendu_vesc_P.Saturation_UpperSat_o) {
    pendu_vesc_B.Saturation_b = pendu_vesc_P.Saturation_UpperSat_o;
  } else if (pendu_vesc_DW.Integrator_DSTATE_k <
             pendu_vesc_P.Saturation_LowerSat_g) {
    pendu_vesc_B.Saturation_b = pendu_vesc_P.Saturation_LowerSat_g;
  } else {
    pendu_vesc_B.Saturation_b = pendu_vesc_DW.Integrator_DSTATE_k;
  }

  // End of Saturate: '<S17>/Saturation'

  // Sum: '<S8>/Sum'
  pendu_vesc_B.Sum = pendu_vesc_B.Saturation_b + rtb_Integrator_p;

  // Gain: '<S8>/1//Torque Const' incorporates:
  //   Gain: '<S8>/motor direction'

  pendu_vesc_B.maxcurrent = pendu_vesc_P.motordirection_Gain * pendu_vesc_B.Sum *
    pendu_vesc_P.uTorqueConst_Gain;

  // Saturate: '<S8>/max. current'
  if (pendu_vesc_B.maxcurrent > pendu_vesc_P.maxcurrent_UpperSat) {
    // Gain: '<S8>/1//Torque Const'
    pendu_vesc_B.maxcurrent = pendu_vesc_P.maxcurrent_UpperSat;
  } else {
    if (pendu_vesc_B.maxcurrent < pendu_vesc_P.maxcurrent_LowerSat) {
      // Gain: '<S8>/1//Torque Const'
      pendu_vesc_B.maxcurrent = pendu_vesc_P.maxcurrent_LowerSat;
    }
  }

  // End of Saturate: '<S8>/max. current'

  // SignalConversion: '<Root>/SigConversion_InsertedFor_Bus Selector_at_outport_1' 
  pendu_vesc_B.current_motor = pendu_vesc_B.SFunctionBuilder5_o1_c.current_motor;

  // MinMax: '<S13>/Max' incorporates:
  //   Constant: '<S13>/Time constant'

  if ((pendu_vesc_B.Probe[0] > pendu_vesc_P.LowPassFilterDiscreteorConti_jv) ||
      rtIsNaN(pendu_vesc_P.LowPassFilterDiscreteorConti_jv)) {
    rtb_Integrator_p = pendu_vesc_B.Probe[0];
  } else {
    rtb_Integrator_p = pendu_vesc_P.LowPassFilterDiscreteorConti_jv;
  }

  // End of MinMax: '<S13>/Max'

  // Product: '<S5>/1//T' incorporates:
  //   Fcn: '<S13>/Avoid Divide by Zero'
  //   Sum: '<S5>/Sum1'

  rtb_uT_o = 1.0 / ((real_T)(rtb_Integrator_p == 0.0) * 2.2204460492503131e-16 +
                    rtb_Integrator_p) * (pendu_vesc_B.Integrator_o -
    pendu_vesc_B.Saturation_b);

  // MinMax: '<S29>/Max' incorporates:
  //   Constant: '<S29>/Time constant'

  if ((pendu_vesc_B.Probe_g[0] > pendu_vesc_P.LowPassFilterDiscreteorContin_j) ||
      rtIsNaN(pendu_vesc_P.LowPassFilterDiscreteorContin_j)) {
    rtb_Integrator_p = pendu_vesc_B.Probe_g[0];
  } else {
    rtb_Integrator_p = pendu_vesc_P.LowPassFilterDiscreteorContin_j;
  }

  // End of MinMax: '<S29>/Max'

  // Product: '<S21>/1//T' incorporates:
  //   Fcn: '<S29>/Avoid Divide by Zero'
  //   Sum: '<S21>/Sum1'

  rtb_uT_e = 1.0 / ((real_T)(rtb_Integrator_p == 0.0) * 2.2204460492503131e-16 +
                    rtb_Integrator_p) * (pendu_vesc_B.ManualSwitch2 -
    pendu_vesc_B.Saturation_e);

  // SampleTimeMath: '<S2>/TSamp'
  //
  //  About '<S2>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_TSamp = pendu_vesc_B.ManualSwitch * pendu_vesc_P.TSamp_WtEt;

  // Sum: '<S2>/Diff' incorporates:
  //   UnitDelay: '<Root>/Unit Delay'
  //   UnitDelay: '<S2>/UD'
  //
  //  Block description for '<S2>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S2>/UD':
  //
  //   Store in Global RAM

  pendu_vesc_DW.UnitDelay_DSTATE = rtb_TSamp - pendu_vesc_DW.UD_DSTATE_a;

  // Sin: '<Root>/Sine Wave'
  pendu_vesc_B.pos_cmd = std::sin(pendu_vesc_P.SineWave_Freq *
    pendu_vesc_M->Timing.t[0] + pendu_vesc_P.SineWave_Phase) *
    pendu_vesc_P.SineWave_Amp + pendu_vesc_P.SineWave_Bias;

  // Update for Atomic SubSystem: '<Root>/VESC USB'
  // Update for S-Function (sf_vesc_usb): '<S10>/S-Function Builder5' incorporates:
  //   Constant: '<S10>/PAR_CURR_LIMS'
  //   Constant: '<S10>/PAR_PID_GAINS'


  // S-Function "sf_vesc_usb_wrapper" Block: <S10>/S-Function Builder5
  sf_vesc_usb_Update_wrapper(&pendu_vesc_B.Switch_d, &pendu_vesc_B.pos_cmd,
    &pendu_vesc_B.maxcurrent, pendu_vesc_P.PAR_PID_GAINS_Value,
    pendu_vesc_P.PAR_CURR_LIMS_Value, &pendu_vesc_B.SFunctionBuilder5_o1_c,
    &pendu_vesc_B.SFunctionBuilder5_o2_b, &pendu_vesc_B.SFunctionBuilder5_o3_o,
    &pendu_vesc_DW.SFunctionBuilder5_DSTATE_i,
    &pendu_vesc_DW.SFunctionBuilder5_PWORK_k, pendu_vesc_P.SFunctionBuilder5_P1,
    15);

  // End of Update for SubSystem: '<Root>/VESC USB'

  // Update for Atomic SubSystem: '<Root>/VESC USB1'
  // Update for S-Function (sf_vesc_usb): '<S11>/S-Function Builder5' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<S11>/PAR_CURR_LIMS'
  //   Constant: '<S11>/PAR_PID_GAINS'


  // S-Function "sf_vesc_usb_wrapper" Block: <S11>/S-Function Builder5
  sf_vesc_usb_Update_wrapper(&pendu_vesc_B.Switch, &pendu_vesc_P.Constant2_Value,
    &pendu_vesc_P.Constant4_Value, pendu_vesc_P.PAR_PID_GAINS_Value_l,
    pendu_vesc_P.PAR_CURR_LIMS_Value_i, &pendu_vesc_B.SFunctionBuilder5_o1,
    &pendu_vesc_B.SFunctionBuilder5_o2, &pendu_vesc_B.SFunctionBuilder5_o3,
    &pendu_vesc_DW.SFunctionBuilder5_DSTATE,
    &pendu_vesc_DW.SFunctionBuilder5_PWORK, pendu_vesc_P.SFunctionBuilder5_P1_h,
    15);

  // End of Update for SubSystem: '<Root>/VESC USB1'

  // Update for UnitDelay: '<S9>/UD1'
  //
  //  Block description for '<S9>/UD1':
  //
  //   Store in Global RAM

  pendu_vesc_DW.UD1_DSTATE = pendu_vesc_B.degToRad;

  // Update for DiscreteIntegrator: '<S28>/Integrator'
  pendu_vesc_DW.Integrator_IC_LOADING = 0U;
  pendu_vesc_DW.Integrator_DSTATE += pendu_vesc_P.Integrator_gainval * rtb_uT;
  if (pendu_vesc_DW.Integrator_DSTATE >= pendu_vesc_P.Integrator_UpperSat) {
    pendu_vesc_DW.Integrator_DSTATE = pendu_vesc_P.Integrator_UpperSat;
  } else {
    if (pendu_vesc_DW.Integrator_DSTATE <= pendu_vesc_P.Integrator_LowerSat) {
      pendu_vesc_DW.Integrator_DSTATE = pendu_vesc_P.Integrator_LowerSat;
    }
  }

  pendu_vesc_DW.Integrator_PrevResetState = (int8_T)rtb_Compare;

  // End of Update for DiscreteIntegrator: '<S28>/Integrator'

  // Update for UnitDelay: '<S12>/UD'
  //
  //  Block description for '<S12>/UD':
  //
  //   Store in Global RAM

  pendu_vesc_DW.UD_DSTATE = pendu_vesc_B.y_h;

  // Update for UnitDelay: '<S9>/UD'
  //
  //  Block description for '<S9>/UD':
  //
  //   Store in Global RAM

  pendu_vesc_DW.UD_DSTATE_i = pendu_vesc_B.degToRad1;

  // Update for DiscreteIntegrator: '<S33>/Integrator'
  pendu_vesc_DW.Integrator_IC_LOADING_h = 0U;
  pendu_vesc_DW.Integrator_DSTATE_c += pendu_vesc_P.Integrator_gainval_f *
    rtb_uT_e;
  if (pendu_vesc_DW.Integrator_DSTATE_c >= pendu_vesc_P.Integrator_UpperSat_d) {
    pendu_vesc_DW.Integrator_DSTATE_c = pendu_vesc_P.Integrator_UpperSat_d;
  } else {
    if (pendu_vesc_DW.Integrator_DSTATE_c <= pendu_vesc_P.Integrator_LowerSat_k)
    {
      pendu_vesc_DW.Integrator_DSTATE_c = pendu_vesc_P.Integrator_LowerSat_k;
    }
  }

  pendu_vesc_DW.Integrator_PrevResetState_j = (int8_T)rtb_Compare_o;

  // End of Update for DiscreteIntegrator: '<S33>/Integrator'

  // Update for DiscreteIntegrator: '<S17>/Integrator'
  pendu_vesc_DW.Integrator_IC_LOADING_p = 0U;
  pendu_vesc_DW.Integrator_DSTATE_k += pendu_vesc_P.Integrator_gainval_a *
    rtb_uT_o;
  if (pendu_vesc_DW.Integrator_DSTATE_k >= pendu_vesc_P.Integrator_UpperSat_n) {
    pendu_vesc_DW.Integrator_DSTATE_k = pendu_vesc_P.Integrator_UpperSat_n;
  } else {
    if (pendu_vesc_DW.Integrator_DSTATE_k <= pendu_vesc_P.Integrator_LowerSat_a)
    {
      pendu_vesc_DW.Integrator_DSTATE_k = pendu_vesc_P.Integrator_LowerSat_a;
    }
  }

  pendu_vesc_DW.Integrator_PrevResetState_c = (int8_T)rtb_Compare_c;

  // End of Update for DiscreteIntegrator: '<S17>/Integrator'

  // Update for UnitDelay: '<S2>/UD'
  //
  //  Block description for '<S2>/UD':
  //
  //   Store in Global RAM

  pendu_vesc_DW.UD_DSTATE_a = rtb_TSamp;

  // External mode
  rtExtModeUploadCheckTrigger(2);

  {                                    // Sample time: [0.0s, 0.0s]
    rtExtModeUpload(0, (real_T)pendu_vesc_M->Timing.t[0]);
  }

  {                                    // Sample time: [0.001s, 0.0s]
    rtExtModeUpload(1, (real_T)((pendu_vesc_M->Timing.clockTick1) * 0.001));
  }

  // signal main to stop simulation
  {                                    // Sample time: [0.0s, 0.0s]
    if ((rtmGetTFinal(pendu_vesc_M)!=-1) &&
        !((rtmGetTFinal(pendu_vesc_M)-pendu_vesc_M->Timing.t[0]) >
          pendu_vesc_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(pendu_vesc_M, "Simulation finished");
    }

    if (rtmGetStopRequested(pendu_vesc_M)) {
      rtmSetErrorStatus(pendu_vesc_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  pendu_vesc_M->Timing.t[0] =
    (++pendu_vesc_M->Timing.clockTick0) * pendu_vesc_M->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.001s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.001, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    pendu_vesc_M->Timing.clockTick1++;
  }
}

// Model initialize function
void pendu_vesc_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  pendu_vesc_P.Integrator_UpperSat = rtInf;
  pendu_vesc_P.Integrator_LowerSat = rtMinusInf;
  pendu_vesc_P.Saturation_UpperSat = rtInf;
  pendu_vesc_P.Saturation_LowerSat = rtMinusInf;
  pendu_vesc_P.Integrator_UpperSat_d = rtInf;
  pendu_vesc_P.Integrator_LowerSat_k = rtMinusInf;
  pendu_vesc_P.Saturation_UpperSat_c = rtInf;
  pendu_vesc_P.Saturation_LowerSat_m = rtMinusInf;
  pendu_vesc_P.Saturation_UpperSat_o = rtInf;
  pendu_vesc_P.Saturation_LowerSat_g = rtMinusInf;

  // initialize real-time model
  (void) memset((void *)pendu_vesc_M, 0,
                sizeof(RT_MODEL_pendu_vesc_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&pendu_vesc_M->solverInfo,
                          &pendu_vesc_M->Timing.simTimeStep);
    rtsiSetTPtr(&pendu_vesc_M->solverInfo, &rtmGetTPtr(pendu_vesc_M));
    rtsiSetStepSizePtr(&pendu_vesc_M->solverInfo,
                       &pendu_vesc_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&pendu_vesc_M->solverInfo, (&rtmGetErrorStatus
      (pendu_vesc_M)));
    rtsiSetRTModelPtr(&pendu_vesc_M->solverInfo, pendu_vesc_M);
  }

  rtsiSetSimTimeStep(&pendu_vesc_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&pendu_vesc_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(pendu_vesc_M, &pendu_vesc_M->Timing.tArray[0]);
  rtmSetTFinal(pendu_vesc_M, -1);
  pendu_vesc_M->Timing.stepSize0 = 0.001;

  // External mode info
  pendu_vesc_M->Sizes.checksums[0] = (3552742990U);
  pendu_vesc_M->Sizes.checksums[1] = (1635791766U);
  pendu_vesc_M->Sizes.checksums[2] = (2702967355U);
  pendu_vesc_M->Sizes.checksums[3] = (3960871734U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[17];
    pendu_vesc_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = (sysRanDType *)
      &pendu_vesc_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &pendu_vesc_DW.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(pendu_vesc_M->extModeInfo,
      &pendu_vesc_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(pendu_vesc_M->extModeInfo, pendu_vesc_M->Sizes.checksums);
    rteiSetTPtr(pendu_vesc_M->extModeInfo, rtmGetTPtr(pendu_vesc_M));
  }

  // block I/O
  (void) memset(((void *) &pendu_vesc_B), 0,
                sizeof(B_pendu_vesc_T));

  // states (dwork)
  (void) memset((void *)&pendu_vesc_DW, 0,
                sizeof(DW_pendu_vesc_T));

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    pendu_vesc_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 26;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;

    // Parameters transition table
    dtInfo.PTransTable = &rtPTransTable;
  }

  // Start for Probe: '<S13>/Probe'
  pendu_vesc_B.Probe[0] = 0.001;
  pendu_vesc_B.Probe[1] = 0.0;

  // Start for Probe: '<S29>/Probe'
  pendu_vesc_B.Probe_g[0] = 0.001;
  pendu_vesc_B.Probe_g[1] = 0.0;

  // Start for Probe: '<S24>/Probe'
  pendu_vesc_B.Probe_l[0] = 0.001;
  pendu_vesc_B.Probe_l[1] = 0.0;

  // Start for Atomic SubSystem: '<Root>/VESC USB'

  // Start for S-Function (sf_vesc_usb): '<S10>/S-Function Builder5' incorporates:
  //   Constant: '<S10>/PAR_CURR_LIMS'
  //   Constant: '<S10>/PAR_PID_GAINS'


  // S-Function Block: <S10>/S-Function Builder5
  sf_vesc_usb_Start_wrapper(&pendu_vesc_DW.SFunctionBuilder5_DSTATE_i,
    &pendu_vesc_DW.SFunctionBuilder5_PWORK_k, pendu_vesc_P.SFunctionBuilder5_P1,
    15);

  // End of Start for SubSystem: '<Root>/VESC USB'

  // Start for Atomic SubSystem: '<Root>/VESC USB1'

  // Start for S-Function (sf_vesc_usb): '<S11>/S-Function Builder5' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<S11>/PAR_CURR_LIMS'
  //   Constant: '<S11>/PAR_PID_GAINS'


  // S-Function Block: <S11>/S-Function Builder5
  sf_vesc_usb_Start_wrapper(&pendu_vesc_DW.SFunctionBuilder5_DSTATE,
    &pendu_vesc_DW.SFunctionBuilder5_PWORK, pendu_vesc_P.SFunctionBuilder5_P1_h,
    15);

  // End of Start for SubSystem: '<Root>/VESC USB1'

  // InitializeConditions for UnitDelay: '<S9>/UD1'
  //
  //  Block description for '<S9>/UD1':
  //
  //   Store in Global RAM

  pendu_vesc_DW.UD1_DSTATE = pendu_vesc_P.UD1_InitialCondition;

  // InitializeConditions for DiscreteIntegrator: '<S28>/Integrator'
  pendu_vesc_DW.Integrator_IC_LOADING = 1U;
  pendu_vesc_DW.Integrator_PrevResetState = 0;

  // InitializeConditions for UnitDelay: '<S12>/UD'
  //
  //  Block description for '<S12>/UD':
  //
  //   Store in Global RAM

  pendu_vesc_DW.UD_DSTATE = pendu_vesc_P.UD_InitialCondition;

  // InitializeConditions for UnitDelay: '<S9>/UD'
  //
  //  Block description for '<S9>/UD':
  //
  //   Store in Global RAM

  pendu_vesc_DW.UD_DSTATE_i = pendu_vesc_P.UD_InitialCondition_d;

  // InitializeConditions for DiscreteIntegrator: '<S33>/Integrator'
  pendu_vesc_DW.Integrator_IC_LOADING_h = 1U;
  pendu_vesc_DW.Integrator_PrevResetState_j = 0;

  // InitializeConditions for UnitDelay: '<Root>/Unit Delay'
  pendu_vesc_DW.UnitDelay_DSTATE = pendu_vesc_P.UnitDelay_InitialCondition;

  // InitializeConditions for DiscreteIntegrator: '<S17>/Integrator'
  pendu_vesc_DW.Integrator_IC_LOADING_p = 1U;
  pendu_vesc_DW.Integrator_PrevResetState_c = 0;

  // InitializeConditions for UnitDelay: '<S2>/UD'
  //
  //  Block description for '<S2>/UD':
  //
  //   Store in Global RAM

  pendu_vesc_DW.UD_DSTATE_a = pendu_vesc_P.DiscreteDerivative_ICPrevScaled;

  // SystemInitialize for Atomic SubSystem: '<Root>/VESC USB'

  // InitializeConditions for S-Function (sf_vesc_usb): '<S10>/S-Function Builder5' incorporates:
  //   Constant: '<S10>/PAR_CURR_LIMS'
  //   Constant: '<S10>/PAR_PID_GAINS'


  // S-Function Block: <S10>/S-Function Builder5
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        pendu_vesc_DW.SFunctionBuilder5_DSTATE_i = initVector[0];
      }
    }
  }

  // End of SystemInitialize for SubSystem: '<Root>/VESC USB'

  // SystemInitialize for Atomic SubSystem: '<Root>/VESC USB1'

  // InitializeConditions for S-Function (sf_vesc_usb): '<S11>/S-Function Builder5' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<S11>/PAR_CURR_LIMS'
  //   Constant: '<S11>/PAR_PID_GAINS'


  // S-Function Block: <S11>/S-Function Builder5
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        pendu_vesc_DW.SFunctionBuilder5_DSTATE = initVector[0];
      }
    }
  }

  // End of SystemInitialize for SubSystem: '<Root>/VESC USB1'

  // SystemInitialize for MATLAB Function: '<Root>/MATLAB Function1'
  pendu_vesc_DW.initpos = 0.0;

  // SystemInitialize for MATLAB Function: '<Root>/MATLAB Function'
  pendu_vesc_DW.initpos_d = 0.0;

  // SystemInitialize for MATLAB Function: '<S12>/MATLAB Function'
  pendu_vesc_DW.pos1 = 0.0;
}

// Model terminate function
void pendu_vesc_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/VESC USB'

  // Terminate for S-Function (sf_vesc_usb): '<S10>/S-Function Builder5' incorporates:
  //   Constant: '<S10>/PAR_CURR_LIMS'
  //   Constant: '<S10>/PAR_PID_GAINS'


  // S-Function Block: <S10>/S-Function Builder5
  sf_vesc_usb_Terminate_wrapper(&pendu_vesc_DW.SFunctionBuilder5_DSTATE_i,
    &pendu_vesc_DW.SFunctionBuilder5_PWORK_k, pendu_vesc_P.SFunctionBuilder5_P1,
    15);

  // End of Terminate for SubSystem: '<Root>/VESC USB'

  // Terminate for Atomic SubSystem: '<Root>/VESC USB1'

  // Terminate for S-Function (sf_vesc_usb): '<S11>/S-Function Builder5' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<S11>/PAR_CURR_LIMS'
  //   Constant: '<S11>/PAR_PID_GAINS'


  // S-Function Block: <S11>/S-Function Builder5
  sf_vesc_usb_Terminate_wrapper(&pendu_vesc_DW.SFunctionBuilder5_DSTATE,
    &pendu_vesc_DW.SFunctionBuilder5_PWORK, pendu_vesc_P.SFunctionBuilder5_P1_h,
    15);

  // End of Terminate for SubSystem: '<Root>/VESC USB1'
}

//
// File trailer for generated code.
//
// [EOF]
//
