//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pendu_vesc_modified.cpp
//
// Code generated for Simulink model 'pendu_vesc_modified'.
//
// Model version                  : 1.287
// Simulink Coder version         : 9.0 (R2018b) 24-May-2018
// C/C++ source code generated on : Mon Jun 22 13:01:14 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "pendu_vesc_modified.h"
#include "pendu_vesc_modified_private.h"
#include "pendu_vesc_modified_dt.h"

// Block signals (default storage)
B_pendu_vesc_modified_T pendu_vesc_modified_B;

// Block states (default storage)
DW_pendu_vesc_modified_T pendu_vesc_modified_DW;

// Real-time model
RT_MODEL_pendu_vesc_modified_T pendu_vesc_modified_M_;
RT_MODEL_pendu_vesc_modified_T *const pendu_vesc_modified_M =
  &pendu_vesc_modified_M_;

//
// Writes out MAT-file header.  Returns success or failure.
// Returns:
//      0 - success
//      1 - failure
//
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      // end rt_WriteMat4FileHeader

//
// Output and update for action system:
//    '<S6>/If Action Subsystem'
//    '<S6>/If Action Subsystem1'
//
void pendu_vesc_mo_IfActionSubsystem(real_T rtu_In1, real_T *rty_Out1,
  P_IfActionSubsystem_pendu_ves_T *localP)
{
  // Saturate: '<S16>/Saturation'
  if (rtu_In1 > localP->Saturation_UpperSat) {
    *rty_Out1 = localP->Saturation_UpperSat;
  } else if (rtu_In1 < localP->Saturation_LowerSat) {
    *rty_Out1 = localP->Saturation_LowerSat;
  } else {
    *rty_Out1 = rtu_In1;
  }

  // End of Saturate: '<S16>/Saturation'
}

//
// Output and update for atomic system:
//    '<S7>/MATLAB Function'
//    '<S7>/MATLAB Function1'
//
void pendu_vesc_modif_MATLABFunction(real_T rtu_u, real_T *rty_y)
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
void pendu_vesc_modified_step(void)
{
  // local block i/o variables
  real_T rtb_Gain;
  real_T rtb_uT;
  real_T rtb_uT_h;
  real_T rtb_uT_e;
  real_T rtb_TSamp;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_n;
  boolean_T rtb_Compare_c;
  real_T rtb_Diff;

  // Reset subsysRan breadcrumbs
  srClearBC
    (pendu_vesc_modified_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);

  // ManualSwitch: '<Root>/Manual Switch' incorporates:
  //   Constant: '<Root>/Constant3'
  //   Constant: '<Root>/Constant8'

  if (pendu_vesc_modified_P.ManualSwitch_CurrentSetting == 1) {
    pendu_vesc_modified_B.ManualSwitch = pendu_vesc_modified_P.Constant8_Value;
  } else {
    pendu_vesc_modified_B.ManualSwitch = pendu_vesc_modified_P.Constant3_Value;
  }

  // End of ManualSwitch: '<Root>/Manual Switch'

  // Gain: '<Root>/Gain'
  rtb_Gain = pendu_vesc_modified_P.Gain_Gain *
    pendu_vesc_modified_B.ManualSwitch;

  // ManualSwitch: '<Root>/Manual Switch2' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Constant: '<Root>/Constant6'

  if (pendu_vesc_modified_P.ManualSwitch2_CurrentSetting == 1) {
    pendu_vesc_modified_B.ManualSwitch2 = pendu_vesc_modified_P.Constant1_Value;
  } else {
    pendu_vesc_modified_B.ManualSwitch2 = pendu_vesc_modified_P.Constant6_Value;
  }

  // End of ManualSwitch: '<Root>/Manual Switch2'

  // Outputs for Atomic SubSystem: '<Root>/VESC USB'
  // S-Function (sf_vesc_usb): '<S8>/S-Function Builder5' incorporates:
  //   Constant: '<S8>/PAR_CURR_LIMS'
  //   Constant: '<S8>/PAR_PID_GAINS'

  sf_vesc_usb_Outputs_wrapper(&pendu_vesc_modified_B.SFunctionBuilder5_o1_c,
    &pendu_vesc_modified_B.SFunctionBuilder5_o2_b,
    &pendu_vesc_modified_B.SFunctionBuilder5_o3_o,
    &pendu_vesc_modified_DW.SFunctionBuilder5_DSTATE_i,
    &pendu_vesc_modified_DW.SFunctionBuilder5_PWORK_k,
    pendu_vesc_modified_P.SFunctionBuilder5_P1, 11);

  // SignalConversion: '<S8>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_modified_B.l_current_max_l =
    pendu_vesc_modified_B.SFunctionBuilder5_o2_b.l_current_max;

  // SignalConversion: '<S8>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_modified_B.l_current_min_b =
    pendu_vesc_modified_B.SFunctionBuilder5_o2_b.l_current_min;

  // SignalConversion: '<S8>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_modified_B.l_in_current_max_d =
    pendu_vesc_modified_B.SFunctionBuilder5_o2_b.l_in_current_max;

  // SignalConversion: '<S8>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_modified_B.l_in_current_min_p =
    pendu_vesc_modified_B.SFunctionBuilder5_o2_b.l_in_current_min;

  // SignalConversion: '<S8>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_modified_B.l_abs_current_max_e =
    pendu_vesc_modified_B.SFunctionBuilder5_o2_b.l_abs_current_max;

  // SignalConversion: '<S8>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_modified_B.p_pid_kp_m =
    pendu_vesc_modified_B.SFunctionBuilder5_o2_b.p_pid_kp;

  // SignalConversion: '<S8>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_modified_B.p_pid_ki_k =
    pendu_vesc_modified_B.SFunctionBuilder5_o2_b.p_pid_ki;

  // SignalConversion: '<S8>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_modified_B.p_pid_kd_m =
    pendu_vesc_modified_B.SFunctionBuilder5_o2_b.p_pid_kd;

  // SignalConversion: '<S8>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_modified_B.p_pid_kd_filter_p =
    pendu_vesc_modified_B.SFunctionBuilder5_o2_b.p_pid_kd_filter;

  // SignalConversion: '<S8>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_modified_B.p_pid_ang_div_j =
    pendu_vesc_modified_B.SFunctionBuilder5_o2_b.p_pid_ang_div;

  // Switch: '<S8>/Switch' incorporates:
  //   Constant: '<S8>/PAR_MASK_MODE'
  //   DataTypeConversion: '<Root>/Data Type Conversion'

  if (pendu_vesc_modified_P.PAR_MASK_MODE_Value != 0U) {
    pendu_vesc_modified_B.Switch_d = pendu_vesc_modified_P.PAR_MASK_MODE_Value;
  } else {
    // DataTypeConversion: '<Root>/Data Type Conversion'
    rtb_Diff = std::floor(pendu_vesc_modified_B.ManualSwitch);
    if (rtIsNaN(rtb_Diff) || rtIsInf(rtb_Diff)) {
      rtb_Diff = 0.0;
    } else {
      rtb_Diff = std::fmod(rtb_Diff, 4.294967296E+9);
    }

    pendu_vesc_modified_B.Switch_d = rtb_Diff < 0.0 ? (uint32_T)-(int32_T)
      (uint32_T)-rtb_Diff : (uint32_T)rtb_Diff;
  }

  // End of Switch: '<S8>/Switch'
  // End of Outputs for SubSystem: '<Root>/VESC USB'

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion2'

  if (pendu_vesc_modified_B.ManualSwitch2 != 0.0) {
    pendu_vesc_modified_DW.initpos_d =
      pendu_vesc_modified_B.SFunctionBuilder5_o1_c.pid_pos;
  }

  pendu_vesc_modified_B.y_h =
    pendu_vesc_modified_B.SFunctionBuilder5_o1_c.pid_pos -
    pendu_vesc_modified_DW.initpos_d;
  pendu_vesc_modified_B.y_h -= std::floor(pendu_vesc_modified_B.y_h / 360.0) *
    360.0;

  // End of MATLAB Function: '<Root>/MATLAB Function'

  // Sum: '<S10>/Diff' incorporates:
  //   UnitDelay: '<S10>/UD'
  //
  //  Block description for '<S10>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S10>/UD':
  //
  //   Store in Global RAM

  rtb_Diff = pendu_vesc_modified_B.y_h - pendu_vesc_modified_DW.UD_DSTATE;

  // MATLAB Function: '<S10>/MATLAB Function'
  pendu_vesc_modified_B.u_rev = (real_T)(rtb_Diff >= 0.0) * (360.0 - rtb_Diff) +
    (real_T)(rtb_Diff < 0.0) * (360.0 + rtb_Diff);
  if (std::abs(pendu_vesc_modified_B.u_rev) < std::abs(rtb_Diff)) {
    rtb_Diff = (real_T)(rtb_Diff < 0.0) * pendu_vesc_modified_B.u_rev - (real_T)
      (rtb_Diff >= 0.0) * pendu_vesc_modified_B.u_rev;
  }

  rtb_Diff /= 5.0;
  pendu_vesc_modified_DW.pos1 += rtb_Diff;
  rtb_Diff = pendu_vesc_modified_DW.pos1;
  if ((!rtIsInf(rtb_Diff)) && (!rtIsNaN(rtb_Diff))) {
    if (rtb_Diff == 0.0) {
      pendu_vesc_modified_DW.pos1 = 0.0;
    } else {
      pendu_vesc_modified_DW.pos1 = std::fmod(rtb_Diff, 360.0);
      if (pendu_vesc_modified_DW.pos1 == 0.0) {
        pendu_vesc_modified_DW.pos1 = 0.0;
      } else {
        if (rtb_Diff < 0.0) {
          pendu_vesc_modified_DW.pos1 += 360.0;
        }
      }
    }
  } else {
    pendu_vesc_modified_DW.pos1 = (rtNaN);
  }

  pendu_vesc_modified_B.y = pendu_vesc_modified_DW.pos1;

  // End of MATLAB Function: '<S10>/MATLAB Function'

  // Outputs for Atomic SubSystem: '<Root>/VESC USB1'
  // S-Function (sf_vesc_usb): '<S9>/S-Function Builder5' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<S9>/PAR_CURR_LIMS'
  //   Constant: '<S9>/PAR_PID_GAINS'

  sf_vesc_usb_Outputs_wrapper(&pendu_vesc_modified_B.SFunctionBuilder5_o1,
    &pendu_vesc_modified_B.SFunctionBuilder5_o2,
    &pendu_vesc_modified_B.SFunctionBuilder5_o3,
    &pendu_vesc_modified_DW.SFunctionBuilder5_DSTATE,
    &pendu_vesc_modified_DW.SFunctionBuilder5_PWORK,
    pendu_vesc_modified_P.SFunctionBuilder5_P1_h, 11);

  // SignalConversion: '<S9>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_modified_B.l_current_max =
    pendu_vesc_modified_B.SFunctionBuilder5_o2.l_current_max;

  // SignalConversion: '<S9>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_modified_B.l_current_min =
    pendu_vesc_modified_B.SFunctionBuilder5_o2.l_current_min;

  // SignalConversion: '<S9>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_modified_B.l_in_current_max =
    pendu_vesc_modified_B.SFunctionBuilder5_o2.l_in_current_max;

  // SignalConversion: '<S9>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_modified_B.l_in_current_min =
    pendu_vesc_modified_B.SFunctionBuilder5_o2.l_in_current_min;

  // SignalConversion: '<S9>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  pendu_vesc_modified_B.l_abs_current_max =
    pendu_vesc_modified_B.SFunctionBuilder5_o2.l_abs_current_max;

  // SignalConversion: '<S9>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_modified_B.p_pid_kp =
    pendu_vesc_modified_B.SFunctionBuilder5_o2.p_pid_kp;

  // SignalConversion: '<S9>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_modified_B.p_pid_ki =
    pendu_vesc_modified_B.SFunctionBuilder5_o2.p_pid_ki;

  // SignalConversion: '<S9>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_modified_B.p_pid_kd =
    pendu_vesc_modified_B.SFunctionBuilder5_o2.p_pid_kd;

  // SignalConversion: '<S9>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_modified_B.p_pid_kd_filter =
    pendu_vesc_modified_B.SFunctionBuilder5_o2.p_pid_kd_filter;

  // SignalConversion: '<S9>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  pendu_vesc_modified_B.p_pid_ang_div =
    pendu_vesc_modified_B.SFunctionBuilder5_o2.p_pid_ang_div;

  // Switch: '<S9>/Switch' incorporates:
  //   Constant: '<S9>/PAR_MASK_MODE'
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  if (pendu_vesc_modified_P.PAR_MASK_MODE_Value_k != 0U) {
    pendu_vesc_modified_B.Switch = pendu_vesc_modified_P.PAR_MASK_MODE_Value_k;
  } else {
    // DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
    //   Constant: '<Root>/Constant5'

    rtb_Diff = std::floor(pendu_vesc_modified_P.Constant5_Value);
    if (rtIsNaN(rtb_Diff) || rtIsInf(rtb_Diff)) {
      rtb_Diff = 0.0;
    } else {
      rtb_Diff = std::fmod(rtb_Diff, 4.294967296E+9);
    }

    pendu_vesc_modified_B.Switch = rtb_Diff < 0.0 ? (uint32_T)-(int32_T)
      (uint32_T)-rtb_Diff : (uint32_T)rtb_Diff;
  }

  // End of Switch: '<S9>/Switch'
  // End of Outputs for SubSystem: '<Root>/VESC USB1'

  // MATLAB Function: '<Root>/MATLAB Function1' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion3'

  if (pendu_vesc_modified_B.ManualSwitch2 != 0.0) {
    pendu_vesc_modified_DW.initpos =
      pendu_vesc_modified_B.SFunctionBuilder5_o1.pid_pos;
  }

  pendu_vesc_modified_B.y_d = pendu_vesc_modified_B.SFunctionBuilder5_o1.pid_pos
    - pendu_vesc_modified_DW.initpos;

  // End of MATLAB Function: '<Root>/MATLAB Function1'

  // MATLAB Function: '<S7>/MATLAB Function2'
  rtb_Diff = pendu_vesc_modified_B.y_d + pendu_vesc_modified_B.y;
  if ((!rtIsInf(rtb_Diff)) && (!rtIsNaN(rtb_Diff))) {
    if (rtb_Diff == 0.0) {
      pendu_vesc_modified_B.ManualSwitch2 = 0.0;
    } else {
      pendu_vesc_modified_B.ManualSwitch2 = std::fmod(rtb_Diff, 360.0);
      if (pendu_vesc_modified_B.ManualSwitch2 == 0.0) {
        pendu_vesc_modified_B.ManualSwitch2 = 0.0;
      } else {
        if (rtb_Diff < 0.0) {
          pendu_vesc_modified_B.ManualSwitch2 += 360.0;
        }
      }
    }
  } else {
    pendu_vesc_modified_B.ManualSwitch2 = (rtNaN);
  }

  pendu_vesc_modified_B.q1_out = -(pendu_vesc_modified_B.y - 180.0);
  pendu_vesc_modified_B.q2_out = -(pendu_vesc_modified_B.ManualSwitch2 - 180.0);

  // End of MATLAB Function: '<S7>/MATLAB Function2'

  // Gain: '<S7>/degToRad1'
  pendu_vesc_modified_B.degToRad1 = pendu_vesc_modified_P.degToRad1_Gain *
    pendu_vesc_modified_B.q1_out;

  // Gain: '<S7>/degToRad'
  pendu_vesc_modified_B.degToRad = pendu_vesc_modified_P.degToRad_Gain *
    pendu_vesc_modified_B.q2_out;

  // RelationalOperator: '<S30>/Compare' incorporates:
  //   Constant: '<S28>/Time constant'
  //   Constant: '<S30>/Constant'
  //   Sum: '<S28>/Sum1'

  rtb_Compare = (pendu_vesc_modified_P.LowPassFilterDiscreteorContin_j -
                 pendu_vesc_modified_B.Probe[0] <=
                 pendu_vesc_modified_P.Constant_Value);

  // MATLAB Function: '<S7>/MATLAB Function' incorporates:
  //   Sum: '<S7>/Diff'
  //   UnitDelay: '<S7>/UD'
  //
  //  Block description for '<S7>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S7>/UD':
  //
  //   Store in Global RAM

  pendu_vesc_modif_MATLABFunction(pendu_vesc_modified_B.degToRad1 -
    pendu_vesc_modified_DW.UD_DSTATE_i, &rtb_Diff);

  // SampleTimeMath: '<S7>/Weighted Sample Time'
  //
  //  About '<S7>/Weighted Sample Time':
  //   y = u * K where K = 1 / ( w * Ts )

  pendu_vesc_modified_B.WeightedSampleTime = rtb_Diff *
    pendu_vesc_modified_P.WeightedSampleTime_WtEt;

  // Gain: '<S19>/K'
  pendu_vesc_modified_B.ManualSwitch2 =
    pendu_vesc_modified_P.LowPassFilterDiscreteorContinuo *
    pendu_vesc_modified_B.WeightedSampleTime;

  // DiscreteIntegrator: '<S32>/Integrator'
  if (pendu_vesc_modified_DW.Integrator_IC_LOADING != 0) {
    pendu_vesc_modified_DW.Integrator_DSTATE =
      pendu_vesc_modified_B.ManualSwitch2;
    if (pendu_vesc_modified_DW.Integrator_DSTATE >=
        pendu_vesc_modified_P.Integrator_UpperSat) {
      pendu_vesc_modified_DW.Integrator_DSTATE =
        pendu_vesc_modified_P.Integrator_UpperSat;
    } else {
      if (pendu_vesc_modified_DW.Integrator_DSTATE <=
          pendu_vesc_modified_P.Integrator_LowerSat) {
        pendu_vesc_modified_DW.Integrator_DSTATE =
          pendu_vesc_modified_P.Integrator_LowerSat;
      }
    }
  }

  if (rtb_Compare || (pendu_vesc_modified_DW.Integrator_PrevResetState != 0)) {
    pendu_vesc_modified_DW.Integrator_DSTATE =
      pendu_vesc_modified_B.ManualSwitch2;
    if (pendu_vesc_modified_DW.Integrator_DSTATE >=
        pendu_vesc_modified_P.Integrator_UpperSat) {
      pendu_vesc_modified_DW.Integrator_DSTATE =
        pendu_vesc_modified_P.Integrator_UpperSat;
    } else {
      if (pendu_vesc_modified_DW.Integrator_DSTATE <=
          pendu_vesc_modified_P.Integrator_LowerSat) {
        pendu_vesc_modified_DW.Integrator_DSTATE =
          pendu_vesc_modified_P.Integrator_LowerSat;
      }
    }
  }

  if (pendu_vesc_modified_DW.Integrator_DSTATE >=
      pendu_vesc_modified_P.Integrator_UpperSat) {
    pendu_vesc_modified_DW.Integrator_DSTATE =
      pendu_vesc_modified_P.Integrator_UpperSat;
  } else {
    if (pendu_vesc_modified_DW.Integrator_DSTATE <=
        pendu_vesc_modified_P.Integrator_LowerSat) {
      pendu_vesc_modified_DW.Integrator_DSTATE =
        pendu_vesc_modified_P.Integrator_LowerSat;
    }
  }

  // Saturate: '<S32>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S32>/Integrator'

  if (pendu_vesc_modified_DW.Integrator_DSTATE >
      pendu_vesc_modified_P.Saturation_UpperSat) {
    pendu_vesc_modified_B.Saturation = pendu_vesc_modified_P.Saturation_UpperSat;
  } else if (pendu_vesc_modified_DW.Integrator_DSTATE <
             pendu_vesc_modified_P.Saturation_LowerSat) {
    pendu_vesc_modified_B.Saturation = pendu_vesc_modified_P.Saturation_LowerSat;
  } else {
    pendu_vesc_modified_B.Saturation = pendu_vesc_modified_DW.Integrator_DSTATE;
  }

  // End of Saturate: '<S32>/Saturation'

  // RelationalOperator: '<S25>/Compare' incorporates:
  //   Constant: '<S23>/Time constant'
  //   Constant: '<S25>/Constant'
  //   Sum: '<S23>/Sum1'

  rtb_Compare_n = (pendu_vesc_modified_P.LowPassFilterDiscreteorContin_g -
                   pendu_vesc_modified_B.Probe_l[0] <=
                   pendu_vesc_modified_P.Constant_Value_i);

  // MATLAB Function: '<S7>/MATLAB Function1' incorporates:
  //   Sum: '<S7>/Diff1'
  //   UnitDelay: '<S7>/UD1'
  //
  //  Block description for '<S7>/Diff1':
  //
  //   Add in CPU
  //
  //  Block description for '<S7>/UD1':
  //
  //   Store in Global RAM

  pendu_vesc_modif_MATLABFunction(pendu_vesc_modified_B.degToRad -
    pendu_vesc_modified_DW.UD1_DSTATE, &rtb_Diff);

  // SampleTimeMath: '<S7>/Weighted Sample Time1'
  //
  //  About '<S7>/Weighted Sample Time1':
  //   y = u * K where K = 1 / ( w * Ts )

  pendu_vesc_modified_B.WeightedSampleTime1 = rtb_Diff *
    pendu_vesc_modified_P.WeightedSampleTime1_WtEt;

  // Gain: '<S18>/K'
  pendu_vesc_modified_B.u_rev =
    pendu_vesc_modified_P.LowPassFilterDiscreteorContin_c *
    pendu_vesc_modified_B.WeightedSampleTime1;

  // DiscreteIntegrator: '<S27>/Integrator'
  if (pendu_vesc_modified_DW.Integrator_IC_LOADING_c != 0) {
    pendu_vesc_modified_DW.Integrator_DSTATE_b = pendu_vesc_modified_B.u_rev;
    if (pendu_vesc_modified_DW.Integrator_DSTATE_b >=
        pendu_vesc_modified_P.Integrator_UpperSat_m) {
      pendu_vesc_modified_DW.Integrator_DSTATE_b =
        pendu_vesc_modified_P.Integrator_UpperSat_m;
    } else {
      if (pendu_vesc_modified_DW.Integrator_DSTATE_b <=
          pendu_vesc_modified_P.Integrator_LowerSat_l) {
        pendu_vesc_modified_DW.Integrator_DSTATE_b =
          pendu_vesc_modified_P.Integrator_LowerSat_l;
      }
    }
  }

  if (rtb_Compare_n || (pendu_vesc_modified_DW.Integrator_PrevResetState_p != 0))
  {
    pendu_vesc_modified_DW.Integrator_DSTATE_b = pendu_vesc_modified_B.u_rev;
    if (pendu_vesc_modified_DW.Integrator_DSTATE_b >=
        pendu_vesc_modified_P.Integrator_UpperSat_m) {
      pendu_vesc_modified_DW.Integrator_DSTATE_b =
        pendu_vesc_modified_P.Integrator_UpperSat_m;
    } else {
      if (pendu_vesc_modified_DW.Integrator_DSTATE_b <=
          pendu_vesc_modified_P.Integrator_LowerSat_l) {
        pendu_vesc_modified_DW.Integrator_DSTATE_b =
          pendu_vesc_modified_P.Integrator_LowerSat_l;
      }
    }
  }

  if (pendu_vesc_modified_DW.Integrator_DSTATE_b >=
      pendu_vesc_modified_P.Integrator_UpperSat_m) {
    pendu_vesc_modified_DW.Integrator_DSTATE_b =
      pendu_vesc_modified_P.Integrator_UpperSat_m;
  } else {
    if (pendu_vesc_modified_DW.Integrator_DSTATE_b <=
        pendu_vesc_modified_P.Integrator_LowerSat_l) {
      pendu_vesc_modified_DW.Integrator_DSTATE_b =
        pendu_vesc_modified_P.Integrator_LowerSat_l;
    }
  }

  // Saturate: '<S27>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S27>/Integrator'

  if (pendu_vesc_modified_DW.Integrator_DSTATE_b >
      pendu_vesc_modified_P.Saturation_UpperSat_o) {
    pendu_vesc_modified_B.Saturation_m =
      pendu_vesc_modified_P.Saturation_UpperSat_o;
  } else if (pendu_vesc_modified_DW.Integrator_DSTATE_b <
             pendu_vesc_modified_P.Saturation_LowerSat_d) {
    pendu_vesc_modified_B.Saturation_m =
      pendu_vesc_modified_P.Saturation_LowerSat_d;
  } else {
    pendu_vesc_modified_B.Saturation_m =
      pendu_vesc_modified_DW.Integrator_DSTATE_b;
  }

  // End of Saturate: '<S27>/Saturation'

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
  if ((rtb_Gain <= 0.0) &&
      (pendu_vesc_modified_DW.DiscreteTimeIntegrator_PrevRese == 1)) {
    pendu_vesc_modified_DW.DiscreteTimeIntegrator_DSTATE =
      pendu_vesc_modified_P.DiscreteTimeIntegrator_IC;
  }

  pendu_vesc_modified_B.DiscreteTimeIntegrator =
    pendu_vesc_modified_DW.DiscreteTimeIntegrator_DSTATE;

  // End of DiscreteIntegrator: '<Root>/Discrete-Time Integrator'

  // MATLAB Function: '<Root>/ApplyPolicy'
  pendu_vesc_modified_B.tau1 = 0.0;

  // ManualSwitch: '<Root>/Manual Switch1' incorporates:
  //   Constant: '<Root>/Constant10'
  //   Constant: '<Root>/Constant9'

  if (pendu_vesc_modified_P.ManualSwitch1_CurrentSetting == 1) {
    rtb_Diff = pendu_vesc_modified_P.Constant9_Value;
  } else {
    rtb_Diff = pendu_vesc_modified_P.Constant10_Value;
  }

  // End of ManualSwitch: '<Root>/Manual Switch1'

  // MATLAB Function: '<Root>/ApplyPolicy' incorporates:
  //   Constant: '<Root>/Constant7'

  if (rtb_Diff != 0.0) {
    pendu_vesc_modified_B.tau1 = std::sin
      (pendu_vesc_modified_B.DiscreteTimeIntegrator * 10.0) *
      pendu_vesc_modified_P.Constant7_Value;
  }

  pendu_vesc_modified_B.tau2 = 0.0;

  // SignalConversion: '<Root>/TmpSignal ConversionAtTo FileInport1'
  pendu_vesc_modified_B.TmpSignalConversionAtToFile[0] =
    pendu_vesc_modified_B.degToRad1;
  pendu_vesc_modified_B.TmpSignalConversionAtToFile[1] =
    pendu_vesc_modified_B.degToRad;
  pendu_vesc_modified_B.TmpSignalConversionAtToFile[2] =
    pendu_vesc_modified_B.Saturation_m;
  pendu_vesc_modified_B.TmpSignalConversionAtToFile[3] =
    pendu_vesc_modified_B.Saturation;
  pendu_vesc_modified_B.TmpSignalConversionAtToFile[4] =
    pendu_vesc_modified_B.tau1;
  pendu_vesc_modified_B.TmpSignalConversionAtToFile[5] = rtb_Gain;

  // ToFile: '<Root>/To File'
  {
    if (!(++pendu_vesc_modified_DW.ToFile_IWORK.Decimation % 1) &&
        (pendu_vesc_modified_DW.ToFile_IWORK.Count * (6 + 1)) + 1 < 100000000 )
    {
      FILE *fp = (FILE *) pendu_vesc_modified_DW.ToFile_PWORK.FilePtr;
      if (fp != (NULL)) {
        real_T u[6 + 1];
        pendu_vesc_modified_DW.ToFile_IWORK.Decimation = 0;
        u[0] = ((pendu_vesc_modified_M->Timing.clockTick1) * 0.05);
        u[1] = pendu_vesc_modified_B.TmpSignalConversionAtToFile[0];
        u[2] = pendu_vesc_modified_B.TmpSignalConversionAtToFile[1];
        u[3] = pendu_vesc_modified_B.TmpSignalConversionAtToFile[2];
        u[4] = pendu_vesc_modified_B.TmpSignalConversionAtToFile[3];
        u[5] = pendu_vesc_modified_B.TmpSignalConversionAtToFile[4];
        u[6] = pendu_vesc_modified_B.TmpSignalConversionAtToFile[5];
        if (fwrite(u, sizeof(real_T), 6 + 1, fp) != 6 + 1) {
          rtmSetErrorStatus(pendu_vesc_modified_M,
                            "Error writing to MAT-file pendubot_record.mat");
          return;
        }

        if (((++pendu_vesc_modified_DW.ToFile_IWORK.Count) * (6 + 1))+1 >=
            100000000) {
          (void)fprintf(stdout,
                        "*** The ToFile block will stop logging data before\n"
                        "    the simulation has ended, because it has reached\n"
                        "    the maximum number of elements (100000000)\n"
                        "    allowed in MAT-file pendubot_record.mat.\n");
        }
      }
    }
  }

  // RelationalOperator: '<S13>/Compare' incorporates:
  //   Constant: '<S11>/Time constant'
  //   Constant: '<S13>/Constant'
  //   Sum: '<S11>/Sum1'

  rtb_Compare_c = (pendu_vesc_modified_P.LowPassFilterDiscreteorConti_jv -
                   pendu_vesc_modified_B.Probe_lj[0] <=
                   pendu_vesc_modified_P.Constant_Value_ib);

  // Gain: '<S3>/K' incorporates:
  //   UnitDelay: '<Root>/Unit Delay'

  pendu_vesc_modified_B.K_d =
    pendu_vesc_modified_P.LowPassFilterDiscreteorContin_e *
    pendu_vesc_modified_DW.UnitDelay_DSTATE;

  // DiscreteIntegrator: '<S15>/Integrator'
  if (pendu_vesc_modified_DW.Integrator_IC_LOADING_p != 0) {
    pendu_vesc_modified_DW.Integrator_DSTATE_k = pendu_vesc_modified_B.K_d;
    if (pendu_vesc_modified_DW.Integrator_DSTATE_k >=
        pendu_vesc_modified_P.Integrator_UpperSat_n) {
      pendu_vesc_modified_DW.Integrator_DSTATE_k =
        pendu_vesc_modified_P.Integrator_UpperSat_n;
    } else {
      if (pendu_vesc_modified_DW.Integrator_DSTATE_k <=
          pendu_vesc_modified_P.Integrator_LowerSat_a) {
        pendu_vesc_modified_DW.Integrator_DSTATE_k =
          pendu_vesc_modified_P.Integrator_LowerSat_a;
      }
    }
  }

  if (rtb_Compare_c || (pendu_vesc_modified_DW.Integrator_PrevResetState_c != 0))
  {
    pendu_vesc_modified_DW.Integrator_DSTATE_k = pendu_vesc_modified_B.K_d;
    if (pendu_vesc_modified_DW.Integrator_DSTATE_k >=
        pendu_vesc_modified_P.Integrator_UpperSat_n) {
      pendu_vesc_modified_DW.Integrator_DSTATE_k =
        pendu_vesc_modified_P.Integrator_UpperSat_n;
    } else {
      if (pendu_vesc_modified_DW.Integrator_DSTATE_k <=
          pendu_vesc_modified_P.Integrator_LowerSat_a) {
        pendu_vesc_modified_DW.Integrator_DSTATE_k =
          pendu_vesc_modified_P.Integrator_LowerSat_a;
      }
    }
  }

  if (pendu_vesc_modified_DW.Integrator_DSTATE_k >=
      pendu_vesc_modified_P.Integrator_UpperSat_n) {
    pendu_vesc_modified_DW.Integrator_DSTATE_k =
      pendu_vesc_modified_P.Integrator_UpperSat_n;
  } else {
    if (pendu_vesc_modified_DW.Integrator_DSTATE_k <=
        pendu_vesc_modified_P.Integrator_LowerSat_a) {
      pendu_vesc_modified_DW.Integrator_DSTATE_k =
        pendu_vesc_modified_P.Integrator_LowerSat_a;
    }
  }

  // Saturate: '<S15>/Saturation' incorporates:
  //   DiscreteIntegrator: '<S15>/Integrator'

  if (pendu_vesc_modified_DW.Integrator_DSTATE_k >
      pendu_vesc_modified_P.Saturation_UpperSat_o1) {
    pendu_vesc_modified_B.Saturation_b =
      pendu_vesc_modified_P.Saturation_UpperSat_o1;
  } else if (pendu_vesc_modified_DW.Integrator_DSTATE_k <
             pendu_vesc_modified_P.Saturation_LowerSat_g) {
    pendu_vesc_modified_B.Saturation_b =
      pendu_vesc_modified_P.Saturation_LowerSat_g;
  } else {
    pendu_vesc_modified_B.Saturation_b =
      pendu_vesc_modified_DW.Integrator_DSTATE_k;
  }

  // End of Saturate: '<S15>/Saturation'
  // MinMax: '<S11>/Max' incorporates:
  //   Constant: '<S11>/Time constant'

  if ((pendu_vesc_modified_B.Probe_lj[0] >
       pendu_vesc_modified_P.LowPassFilterDiscreteorConti_jv) || rtIsNaN
      (pendu_vesc_modified_P.LowPassFilterDiscreteorConti_jv)) {
    rtb_Diff = pendu_vesc_modified_B.Probe_lj[0];
  } else {
    rtb_Diff = pendu_vesc_modified_P.LowPassFilterDiscreteorConti_jv;
  }

  // End of MinMax: '<S11>/Max'

  // Product: '<S3>/1//T' incorporates:
  //   Fcn: '<S11>/Avoid Divide by Zero'
  //   Sum: '<S3>/Sum1'

  rtb_uT = 1.0 / ((real_T)(rtb_Diff == 0.0) * 2.2204460492503131e-16 + rtb_Diff)
    * (pendu_vesc_modified_B.K_d - pendu_vesc_modified_B.Saturation_b);

  // Outputs for IfAction SubSystem: '<S6>/If Action Subsystem1' incorporates:
  //   ActionPort: '<S17>/Action Port'

  // If: '<S6>/If'
  pendu_vesc_mo_IfActionSubsystem(pendu_vesc_modified_B.tau1, &rtb_Diff,
    &pendu_vesc_modified_P.IfActionSubsystem1);

  // End of Outputs for SubSystem: '<S6>/If Action Subsystem1'

  // Sum: '<S6>/Sum'
  pendu_vesc_modified_B.Sum = pendu_vesc_modified_B.Saturation_b + rtb_Diff;

  // Gain: '<S6>/1//Torque Const' incorporates:
  //   Gain: '<S6>/motor direction'

  pendu_vesc_modified_B.maxcurrent = pendu_vesc_modified_P.motordirection_Gain *
    pendu_vesc_modified_B.Sum * pendu_vesc_modified_P.uTorqueConst_Gain;

  // Saturate: '<S6>/max. current'
  if (pendu_vesc_modified_B.maxcurrent >
      pendu_vesc_modified_P.maxcurrent_UpperSat) {
    // Gain: '<S6>/1//Torque Const'
    pendu_vesc_modified_B.maxcurrent = pendu_vesc_modified_P.maxcurrent_UpperSat;
  } else {
    if (pendu_vesc_modified_B.maxcurrent <
        pendu_vesc_modified_P.maxcurrent_LowerSat) {
      // Gain: '<S6>/1//Torque Const'
      pendu_vesc_modified_B.maxcurrent =
        pendu_vesc_modified_P.maxcurrent_LowerSat;
    }
  }

  // End of Saturate: '<S6>/max. current'

  // SignalConversion: '<Root>/SigConversion_InsertedFor_Bus Selector_at_outport_1' 
  pendu_vesc_modified_B.current_motor =
    pendu_vesc_modified_B.SFunctionBuilder5_o1_c.current_motor;

  // MinMax: '<S23>/Max' incorporates:
  //   Constant: '<S23>/Time constant'

  if ((pendu_vesc_modified_B.Probe_l[0] >
       pendu_vesc_modified_P.LowPassFilterDiscreteorContin_g) || rtIsNaN
      (pendu_vesc_modified_P.LowPassFilterDiscreteorContin_g)) {
    rtb_Diff = pendu_vesc_modified_B.Probe_l[0];
  } else {
    rtb_Diff = pendu_vesc_modified_P.LowPassFilterDiscreteorContin_g;
  }

  // End of MinMax: '<S23>/Max'

  // Product: '<S18>/1//T' incorporates:
  //   Fcn: '<S23>/Avoid Divide by Zero'
  //   Sum: '<S18>/Sum1'

  rtb_uT_h = 1.0 / ((real_T)(rtb_Diff == 0.0) * 2.2204460492503131e-16 +
                    rtb_Diff) * (pendu_vesc_modified_B.u_rev -
    pendu_vesc_modified_B.Saturation_m);

  // MinMax: '<S28>/Max' incorporates:
  //   Constant: '<S28>/Time constant'

  if ((pendu_vesc_modified_B.Probe[0] >
       pendu_vesc_modified_P.LowPassFilterDiscreteorContin_j) || rtIsNaN
      (pendu_vesc_modified_P.LowPassFilterDiscreteorContin_j)) {
    rtb_Diff = pendu_vesc_modified_B.Probe[0];
  } else {
    rtb_Diff = pendu_vesc_modified_P.LowPassFilterDiscreteorContin_j;
  }

  // End of MinMax: '<S28>/Max'

  // Product: '<S19>/1//T' incorporates:
  //   Fcn: '<S28>/Avoid Divide by Zero'
  //   Sum: '<S19>/Sum1'

  rtb_uT_e = 1.0 / ((real_T)(rtb_Diff == 0.0) * 2.2204460492503131e-16 +
                    rtb_Diff) * (pendu_vesc_modified_B.ManualSwitch2 -
    pendu_vesc_modified_B.Saturation);

  // SampleTimeMath: '<S2>/TSamp'
  //
  //  About '<S2>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_TSamp = pendu_vesc_modified_B.ManualSwitch *
    pendu_vesc_modified_P.TSamp_WtEt;

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

  pendu_vesc_modified_DW.UnitDelay_DSTATE = rtb_TSamp -
    pendu_vesc_modified_DW.UD_DSTATE_a;

  // Sin: '<Root>/Sine Wave'
  pendu_vesc_modified_B.pos_cmd = std::sin(pendu_vesc_modified_P.SineWave_Freq *
    pendu_vesc_modified_M->Timing.t[0] + pendu_vesc_modified_P.SineWave_Phase) *
    pendu_vesc_modified_P.SineWave_Amp + pendu_vesc_modified_P.SineWave_Bias;

  // Update for Atomic SubSystem: '<Root>/VESC USB'
  // Update for S-Function (sf_vesc_usb): '<S8>/S-Function Builder5' incorporates:
  //   Constant: '<S8>/PAR_CURR_LIMS'
  //   Constant: '<S8>/PAR_PID_GAINS'


  // S-Function "sf_vesc_usb_wrapper" Block: <S8>/S-Function Builder5
  sf_vesc_usb_Update_wrapper(&pendu_vesc_modified_B.Switch_d,
    &pendu_vesc_modified_B.pos_cmd, &pendu_vesc_modified_B.maxcurrent,
    pendu_vesc_modified_P.PAR_PID_GAINS_Value,
    pendu_vesc_modified_P.PAR_CURR_LIMS_Value,
    &pendu_vesc_modified_B.SFunctionBuilder5_o1_c,
    &pendu_vesc_modified_B.SFunctionBuilder5_o2_b,
    &pendu_vesc_modified_B.SFunctionBuilder5_o3_o,
    &pendu_vesc_modified_DW.SFunctionBuilder5_DSTATE_i,
    &pendu_vesc_modified_DW.SFunctionBuilder5_PWORK_k,
    pendu_vesc_modified_P.SFunctionBuilder5_P1, 11);

  // End of Update for SubSystem: '<Root>/VESC USB'

  // Update for UnitDelay: '<S10>/UD'
  //
  //  Block description for '<S10>/UD':
  //
  //   Store in Global RAM

  pendu_vesc_modified_DW.UD_DSTATE = pendu_vesc_modified_B.y_h;

  // Update for Atomic SubSystem: '<Root>/VESC USB1'
  // Update for S-Function (sf_vesc_usb): '<S9>/S-Function Builder5' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<S9>/PAR_CURR_LIMS'
  //   Constant: '<S9>/PAR_PID_GAINS'


  // S-Function "sf_vesc_usb_wrapper" Block: <S9>/S-Function Builder5
  sf_vesc_usb_Update_wrapper(&pendu_vesc_modified_B.Switch,
    &pendu_vesc_modified_P.Constant2_Value,
    &pendu_vesc_modified_P.Constant4_Value,
    pendu_vesc_modified_P.PAR_PID_GAINS_Value_l,
    pendu_vesc_modified_P.PAR_CURR_LIMS_Value_i,
    &pendu_vesc_modified_B.SFunctionBuilder5_o1,
    &pendu_vesc_modified_B.SFunctionBuilder5_o2,
    &pendu_vesc_modified_B.SFunctionBuilder5_o3,
    &pendu_vesc_modified_DW.SFunctionBuilder5_DSTATE,
    &pendu_vesc_modified_DW.SFunctionBuilder5_PWORK,
    pendu_vesc_modified_P.SFunctionBuilder5_P1_h, 11);

  // End of Update for SubSystem: '<Root>/VESC USB1'

  // Update for UnitDelay: '<S7>/UD'
  //
  //  Block description for '<S7>/UD':
  //
  //   Store in Global RAM

  pendu_vesc_modified_DW.UD_DSTATE_i = pendu_vesc_modified_B.degToRad1;

  // Update for DiscreteIntegrator: '<S32>/Integrator'
  pendu_vesc_modified_DW.Integrator_IC_LOADING = 0U;
  pendu_vesc_modified_DW.Integrator_DSTATE +=
    pendu_vesc_modified_P.Integrator_gainval * rtb_uT_e;
  if (pendu_vesc_modified_DW.Integrator_DSTATE >=
      pendu_vesc_modified_P.Integrator_UpperSat) {
    pendu_vesc_modified_DW.Integrator_DSTATE =
      pendu_vesc_modified_P.Integrator_UpperSat;
  } else {
    if (pendu_vesc_modified_DW.Integrator_DSTATE <=
        pendu_vesc_modified_P.Integrator_LowerSat) {
      pendu_vesc_modified_DW.Integrator_DSTATE =
        pendu_vesc_modified_P.Integrator_LowerSat;
    }
  }

  pendu_vesc_modified_DW.Integrator_PrevResetState = (int8_T)rtb_Compare;

  // End of Update for DiscreteIntegrator: '<S32>/Integrator'

  // Update for UnitDelay: '<S7>/UD1'
  //
  //  Block description for '<S7>/UD1':
  //
  //   Store in Global RAM

  pendu_vesc_modified_DW.UD1_DSTATE = pendu_vesc_modified_B.degToRad;

  // Update for DiscreteIntegrator: '<S27>/Integrator'
  pendu_vesc_modified_DW.Integrator_IC_LOADING_c = 0U;
  pendu_vesc_modified_DW.Integrator_DSTATE_b +=
    pendu_vesc_modified_P.Integrator_gainval_k * rtb_uT_h;
  if (pendu_vesc_modified_DW.Integrator_DSTATE_b >=
      pendu_vesc_modified_P.Integrator_UpperSat_m) {
    pendu_vesc_modified_DW.Integrator_DSTATE_b =
      pendu_vesc_modified_P.Integrator_UpperSat_m;
  } else {
    if (pendu_vesc_modified_DW.Integrator_DSTATE_b <=
        pendu_vesc_modified_P.Integrator_LowerSat_l) {
      pendu_vesc_modified_DW.Integrator_DSTATE_b =
        pendu_vesc_modified_P.Integrator_LowerSat_l;
    }
  }

  pendu_vesc_modified_DW.Integrator_PrevResetState_p = (int8_T)rtb_Compare_n;

  // End of Update for DiscreteIntegrator: '<S27>/Integrator'

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
  pendu_vesc_modified_DW.DiscreteTimeIntegrator_DSTATE +=
    pendu_vesc_modified_P.DiscreteTimeIntegrator_gainval * rtb_Gain;
  if (rtb_Gain > 0.0) {
    pendu_vesc_modified_DW.DiscreteTimeIntegrator_PrevRese = 1;
  } else if (rtb_Gain < 0.0) {
    pendu_vesc_modified_DW.DiscreteTimeIntegrator_PrevRese = -1;
  } else if (rtb_Gain == 0.0) {
    pendu_vesc_modified_DW.DiscreteTimeIntegrator_PrevRese = 0;
  } else {
    pendu_vesc_modified_DW.DiscreteTimeIntegrator_PrevRese = 2;
  }

  // End of Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator'

  // Update for DiscreteIntegrator: '<S15>/Integrator'
  pendu_vesc_modified_DW.Integrator_IC_LOADING_p = 0U;
  pendu_vesc_modified_DW.Integrator_DSTATE_k +=
    pendu_vesc_modified_P.Integrator_gainval_a * rtb_uT;
  if (pendu_vesc_modified_DW.Integrator_DSTATE_k >=
      pendu_vesc_modified_P.Integrator_UpperSat_n) {
    pendu_vesc_modified_DW.Integrator_DSTATE_k =
      pendu_vesc_modified_P.Integrator_UpperSat_n;
  } else {
    if (pendu_vesc_modified_DW.Integrator_DSTATE_k <=
        pendu_vesc_modified_P.Integrator_LowerSat_a) {
      pendu_vesc_modified_DW.Integrator_DSTATE_k =
        pendu_vesc_modified_P.Integrator_LowerSat_a;
    }
  }

  pendu_vesc_modified_DW.Integrator_PrevResetState_c = (int8_T)rtb_Compare_c;

  // End of Update for DiscreteIntegrator: '<S15>/Integrator'

  // Update for UnitDelay: '<S2>/UD'
  //
  //  Block description for '<S2>/UD':
  //
  //   Store in Global RAM

  pendu_vesc_modified_DW.UD_DSTATE_a = rtb_TSamp;

  // External mode
  rtExtModeUploadCheckTrigger(2);

  {                                    // Sample time: [0.0s, 0.0s]
    rtExtModeUpload(0, (real_T)pendu_vesc_modified_M->Timing.t[0]);
  }

  {                                    // Sample time: [0.05s, 0.0s]
    rtExtModeUpload(1, (real_T)((pendu_vesc_modified_M->Timing.clockTick1) *
      0.05));
  }

  // signal main to stop simulation
  {                                    // Sample time: [0.0s, 0.0s]
    if ((rtmGetTFinal(pendu_vesc_modified_M)!=-1) &&
        !((rtmGetTFinal(pendu_vesc_modified_M)-pendu_vesc_modified_M->Timing.t[0])
          > pendu_vesc_modified_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(pendu_vesc_modified_M, "Simulation finished");
    }

    if (rtmGetStopRequested(pendu_vesc_modified_M)) {
      rtmSetErrorStatus(pendu_vesc_modified_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  pendu_vesc_modified_M->Timing.t[0] =
    (++pendu_vesc_modified_M->Timing.clockTick0) *
    pendu_vesc_modified_M->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.05s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.05, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    pendu_vesc_modified_M->Timing.clockTick1++;
  }
}

// Model initialize function
void pendu_vesc_modified_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // non-finite (run-time) assignments
  pendu_vesc_modified_P.Integrator_UpperSat = rtInf;
  pendu_vesc_modified_P.Integrator_LowerSat = rtMinusInf;
  pendu_vesc_modified_P.Saturation_UpperSat = rtInf;
  pendu_vesc_modified_P.Saturation_LowerSat = rtMinusInf;
  pendu_vesc_modified_P.Integrator_UpperSat_m = rtInf;
  pendu_vesc_modified_P.Integrator_LowerSat_l = rtMinusInf;
  pendu_vesc_modified_P.Saturation_UpperSat_o = rtInf;
  pendu_vesc_modified_P.Saturation_LowerSat_d = rtMinusInf;
  pendu_vesc_modified_P.Saturation_UpperSat_o1 = rtInf;
  pendu_vesc_modified_P.Saturation_LowerSat_g = rtMinusInf;

  // initialize real-time model
  (void) memset((void *)pendu_vesc_modified_M, 0,
                sizeof(RT_MODEL_pendu_vesc_modified_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&pendu_vesc_modified_M->solverInfo,
                          &pendu_vesc_modified_M->Timing.simTimeStep);
    rtsiSetTPtr(&pendu_vesc_modified_M->solverInfo, &rtmGetTPtr
                (pendu_vesc_modified_M));
    rtsiSetStepSizePtr(&pendu_vesc_modified_M->solverInfo,
                       &pendu_vesc_modified_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&pendu_vesc_modified_M->solverInfo,
                          (&rtmGetErrorStatus(pendu_vesc_modified_M)));
    rtsiSetRTModelPtr(&pendu_vesc_modified_M->solverInfo, pendu_vesc_modified_M);
  }

  rtsiSetSimTimeStep(&pendu_vesc_modified_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&pendu_vesc_modified_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(pendu_vesc_modified_M, &pendu_vesc_modified_M->Timing.tArray[0]);
  rtmSetTFinal(pendu_vesc_modified_M, -1);
  pendu_vesc_modified_M->Timing.stepSize0 = 0.05;

  // External mode info
  pendu_vesc_modified_M->Sizes.checksums[0] = (1510491195U);
  pendu_vesc_modified_M->Sizes.checksums[1] = (1687192483U);
  pendu_vesc_modified_M->Sizes.checksums[2] = (18905543U);
  pendu_vesc_modified_M->Sizes.checksums[3] = (4169505437U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[20];
    pendu_vesc_modified_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = (sysRanDType *)
      &pendu_vesc_modified_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &pendu_vesc_modified_DW.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(pendu_vesc_modified_M->extModeInfo,
      &pendu_vesc_modified_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(pendu_vesc_modified_M->extModeInfo,
                        pendu_vesc_modified_M->Sizes.checksums);
    rteiSetTPtr(pendu_vesc_modified_M->extModeInfo, rtmGetTPtr
                (pendu_vesc_modified_M));
  }

  // block I/O
  (void) memset(((void *) &pendu_vesc_modified_B), 0,
                sizeof(B_pendu_vesc_modified_T));

  // states (dwork)
  (void) memset((void *)&pendu_vesc_modified_DW, 0,
                sizeof(DW_pendu_vesc_modified_T));

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    pendu_vesc_modified_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 26;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;

    // Parameters transition table
    dtInfo.PTransTable = &rtPTransTable;
  }

  // Start for Atomic SubSystem: '<Root>/VESC USB'

  // Start for S-Function (sf_vesc_usb): '<S8>/S-Function Builder5' incorporates:
  //   Constant: '<S8>/PAR_CURR_LIMS'
  //   Constant: '<S8>/PAR_PID_GAINS'


  // S-Function Block: <S8>/S-Function Builder5
  sf_vesc_usb_Start_wrapper(&pendu_vesc_modified_DW.SFunctionBuilder5_DSTATE_i,
    &pendu_vesc_modified_DW.SFunctionBuilder5_PWORK_k,
    pendu_vesc_modified_P.SFunctionBuilder5_P1, 11);

  // End of Start for SubSystem: '<Root>/VESC USB'

  // Start for Atomic SubSystem: '<Root>/VESC USB1'

  // Start for S-Function (sf_vesc_usb): '<S9>/S-Function Builder5' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<S9>/PAR_CURR_LIMS'
  //   Constant: '<S9>/PAR_PID_GAINS'


  // S-Function Block: <S9>/S-Function Builder5
  sf_vesc_usb_Start_wrapper(&pendu_vesc_modified_DW.SFunctionBuilder5_DSTATE,
    &pendu_vesc_modified_DW.SFunctionBuilder5_PWORK,
    pendu_vesc_modified_P.SFunctionBuilder5_P1_h, 11);

  // End of Start for SubSystem: '<Root>/VESC USB1'

  // Start for Probe: '<S28>/Probe'
  pendu_vesc_modified_B.Probe[0] = 0.05;
  pendu_vesc_modified_B.Probe[1] = 0.0;

  // Start for Probe: '<S23>/Probe'
  pendu_vesc_modified_B.Probe_l[0] = 0.05;
  pendu_vesc_modified_B.Probe_l[1] = 0.0;

  // Start for ToFile: '<Root>/To File'
  {
    FILE *fp = (NULL);
    char fileName[509] = "pendubot_record.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(pendu_vesc_modified_M,
                        "Error creating .mat file pendubot_record.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 6 + 1, 0, "record_data")) {
      rtmSetErrorStatus(pendu_vesc_modified_M,
                        "Error writing mat file header to file pendubot_record.mat");
      return;
    }

    pendu_vesc_modified_DW.ToFile_IWORK.Count = 0;
    pendu_vesc_modified_DW.ToFile_IWORK.Decimation = -1;
    pendu_vesc_modified_DW.ToFile_PWORK.FilePtr = fp;
  }

  // Start for Probe: '<S11>/Probe'
  pendu_vesc_modified_B.Probe_lj[0] = 0.05;
  pendu_vesc_modified_B.Probe_lj[1] = 0.0;

  // InitializeConditions for UnitDelay: '<S10>/UD'
  //
  //  Block description for '<S10>/UD':
  //
  //   Store in Global RAM

  pendu_vesc_modified_DW.UD_DSTATE = pendu_vesc_modified_P.UD_InitialCondition;

  // InitializeConditions for UnitDelay: '<S7>/UD'
  //
  //  Block description for '<S7>/UD':
  //
  //   Store in Global RAM

  pendu_vesc_modified_DW.UD_DSTATE_i =
    pendu_vesc_modified_P.UD_InitialCondition_d;

  // InitializeConditions for DiscreteIntegrator: '<S32>/Integrator'
  pendu_vesc_modified_DW.Integrator_IC_LOADING = 1U;
  pendu_vesc_modified_DW.Integrator_PrevResetState = 0;

  // InitializeConditions for UnitDelay: '<S7>/UD1'
  //
  //  Block description for '<S7>/UD1':
  //
  //   Store in Global RAM

  pendu_vesc_modified_DW.UD1_DSTATE = pendu_vesc_modified_P.UD1_InitialCondition;

  // InitializeConditions for DiscreteIntegrator: '<S27>/Integrator'
  pendu_vesc_modified_DW.Integrator_IC_LOADING_c = 1U;
  pendu_vesc_modified_DW.Integrator_PrevResetState_p = 0;

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' 
  pendu_vesc_modified_DW.DiscreteTimeIntegrator_DSTATE =
    pendu_vesc_modified_P.DiscreteTimeIntegrator_IC;
  pendu_vesc_modified_DW.DiscreteTimeIntegrator_PrevRese = 2;

  // InitializeConditions for UnitDelay: '<Root>/Unit Delay'
  pendu_vesc_modified_DW.UnitDelay_DSTATE =
    pendu_vesc_modified_P.UnitDelay_InitialCondition;

  // InitializeConditions for DiscreteIntegrator: '<S15>/Integrator'
  pendu_vesc_modified_DW.Integrator_IC_LOADING_p = 1U;
  pendu_vesc_modified_DW.Integrator_PrevResetState_c = 0;

  // InitializeConditions for UnitDelay: '<S2>/UD'
  //
  //  Block description for '<S2>/UD':
  //
  //   Store in Global RAM

  pendu_vesc_modified_DW.UD_DSTATE_a =
    pendu_vesc_modified_P.DiscreteDerivative_ICPrevScaled;

  // SystemInitialize for Atomic SubSystem: '<Root>/VESC USB'

  // InitializeConditions for S-Function (sf_vesc_usb): '<S8>/S-Function Builder5' incorporates:
  //   Constant: '<S8>/PAR_CURR_LIMS'
  //   Constant: '<S8>/PAR_PID_GAINS'


  // S-Function Block: <S8>/S-Function Builder5
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        pendu_vesc_modified_DW.SFunctionBuilder5_DSTATE_i = initVector[0];
      }
    }
  }

  // End of SystemInitialize for SubSystem: '<Root>/VESC USB'

  // SystemInitialize for MATLAB Function: '<Root>/MATLAB Function'
  pendu_vesc_modified_DW.initpos_d = 0.0;

  // SystemInitialize for MATLAB Function: '<S10>/MATLAB Function'
  pendu_vesc_modified_DW.pos1 = 0.0;

  // SystemInitialize for Atomic SubSystem: '<Root>/VESC USB1'

  // InitializeConditions for S-Function (sf_vesc_usb): '<S9>/S-Function Builder5' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<S9>/PAR_CURR_LIMS'
  //   Constant: '<S9>/PAR_PID_GAINS'


  // S-Function Block: <S9>/S-Function Builder5
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        pendu_vesc_modified_DW.SFunctionBuilder5_DSTATE = initVector[0];
      }
    }
  }

  // End of SystemInitialize for SubSystem: '<Root>/VESC USB1'

  // SystemInitialize for MATLAB Function: '<Root>/MATLAB Function1'
  pendu_vesc_modified_DW.initpos = 0.0;
}

// Model terminate function
void pendu_vesc_modified_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/VESC USB'

  // Terminate for S-Function (sf_vesc_usb): '<S8>/S-Function Builder5' incorporates:
  //   Constant: '<S8>/PAR_CURR_LIMS'
  //   Constant: '<S8>/PAR_PID_GAINS'


  // S-Function Block: <S8>/S-Function Builder5
  sf_vesc_usb_Terminate_wrapper
    (&pendu_vesc_modified_DW.SFunctionBuilder5_DSTATE_i,
     &pendu_vesc_modified_DW.SFunctionBuilder5_PWORK_k,
     pendu_vesc_modified_P.SFunctionBuilder5_P1, 11);

  // End of Terminate for SubSystem: '<Root>/VESC USB'

  // Terminate for Atomic SubSystem: '<Root>/VESC USB1'

  // Terminate for S-Function (sf_vesc_usb): '<S9>/S-Function Builder5' incorporates:
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<S9>/PAR_CURR_LIMS'
  //   Constant: '<S9>/PAR_PID_GAINS'


  // S-Function Block: <S9>/S-Function Builder5
  sf_vesc_usb_Terminate_wrapper(&pendu_vesc_modified_DW.SFunctionBuilder5_DSTATE,
    &pendu_vesc_modified_DW.SFunctionBuilder5_PWORK,
    pendu_vesc_modified_P.SFunctionBuilder5_P1_h, 11);

  // End of Terminate for SubSystem: '<Root>/VESC USB1'

  // Terminate for ToFile: '<Root>/To File'
  {
    FILE *fp = (FILE *) pendu_vesc_modified_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "pendubot_record.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(pendu_vesc_modified_M,
                          "Error closing MAT-file pendubot_record.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(pendu_vesc_modified_M,
                          "Error reopening MAT-file pendubot_record.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 6 + 1,
           pendu_vesc_modified_DW.ToFile_IWORK.Count, "record_data")) {
        rtmSetErrorStatus(pendu_vesc_modified_M,
                          "Error writing header for record_data to MAT-file pendubot_record.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(pendu_vesc_modified_M,
                          "Error closing MAT-file pendubot_record.mat");
        return;
      }

      pendu_vesc_modified_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
