//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pendu_vesc_modified_data.cpp
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

// Block parameters (default storage)
P_pendu_vesc_modified_T pendu_vesc_modified_P = {
  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S2>/UD'

  0.0,

  // Mask Parameter: LowPassFilterDiscreteorContinuo
  //  Referenced by: '<S19>/K'

  1.0,

  // Mask Parameter: LowPassFilterDiscreteorContin_c
  //  Referenced by: '<S18>/K'

  1.0,

  // Mask Parameter: LowPassFilterDiscreteorContin_e
  //  Referenced by: '<S3>/K'

  -1.0,

  // Mask Parameter: LowPassFilterDiscreteorContin_j
  //  Referenced by: '<S28>/Time constant'

  0.01,

  // Mask Parameter: LowPassFilterDiscreteorContin_g
  //  Referenced by: '<S23>/Time constant'

  0.01,

  // Mask Parameter: LowPassFilterDiscreteorConti_jv
  //  Referenced by: '<S11>/Time constant'

  0.025,

  // Expression: 0
  //  Referenced by: '<Root>/Constant6'

  0.0,

  // Expression: 1
  //  Referenced by: '<Root>/Constant1'

  1.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant10'

  0.0,

  // Expression: 1
  //  Referenced by: '<Root>/Constant9'

  1.0,

  // Expression: 4
  //  Referenced by: '<Root>/Constant3'

  4.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant8'

  0.0,

  // Expression: [10 -10 10 -10 10]
  //  Referenced by: '<S8>/PAR_CURR_LIMS'

  { 10.0, -10.0, 10.0, -10.0, 10.0 },

  // Expression: [0 0 0 0.2 1]
  //  Referenced by: '<S8>/PAR_PID_GAINS'

  { 0.0, 0.0, 0.0, 0.2, 1.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Constant5'

  0.0,

  // Expression: [10 -10 10 -10 10]
  //  Referenced by: '<S9>/PAR_CURR_LIMS'

  { 10.0, -10.0, 10.0, -10.0, 10.0 },

  // Expression: [0 0 0 0.2 1]
  //  Referenced by: '<S9>/PAR_PID_GAINS'

  { 0.0, 0.0, 0.0, 0.2, 1.0 },

  // Expression: 0.25
  //  Referenced by: '<Root>/Gain'

  0.25,

  // Expression: 0
  //  Referenced by: '<S10>/UD'

  0.0,

  // Expression: pi/180
  //  Referenced by: '<S7>/degToRad1'

  0.017453292519943295,

  // Expression: pi/180
  //  Referenced by: '<S7>/degToRad'

  0.017453292519943295,

  // Expression: 0
  //  Referenced by: '<S30>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S7>/UD'

  0.0,

  // Computed Parameter: WeightedSampleTime_WtEt
  //  Referenced by: '<S7>/Weighted Sample Time'

  20.0,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S32>/Integrator'

  0.05,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S32>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S32>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S32>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S32>/Saturation'

  0.0,

  // Expression: 0
  //  Referenced by: '<S25>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S7>/UD1'

  0.0,

  // Computed Parameter: WeightedSampleTime1_WtEt
  //  Referenced by: '<S7>/Weighted Sample Time1'

  20.0,

  // Computed Parameter: Integrator_gainval_k
  //  Referenced by: '<S27>/Integrator'

  0.05,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S27>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S27>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S27>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S27>/Saturation'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  0.05,

  // Expression: 0
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  0.0,

  // Expression: 0.035
  //  Referenced by: '<Root>/Constant7'

  0.035,

  // Expression: 0
  //  Referenced by: '<S13>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Unit Delay'

  0.0,

  // Computed Parameter: Integrator_gainval_a
  //  Referenced by: '<S15>/Integrator'

  0.05,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S15>/Integrator'

  0.05,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S15>/Integrator'

  -0.05,

  // Expression: windupUpperLimit
  //  Referenced by: '<S15>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S15>/Saturation'

  0.0,

  // Expression: -1
  //  Referenced by: '<S6>/motor direction'

  -1.0,

  // Expression: 1/(29.2e-3)
  //  Referenced by: '<S6>/1//Torque Const'

  34.246575342465754,

  // Expression: 3
  //  Referenced by: '<S6>/max. current'

  3.0,

  // Expression: -3
  //  Referenced by: '<S6>/max. current'

  -3.0,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S2>/TSamp'

  20.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant2'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant4'

  0.0,

  // Expression: 150
  //  Referenced by: '<Root>/Sine Wave'

  150.0,

  // Expression: 10
  //  Referenced by: '<Root>/Sine Wave'

  10.0,

  // Expression: 1
  //  Referenced by: '<Root>/Sine Wave'

  1.0,

  // Expression: 0
  //  Referenced by: '<Root>/Sine Wave'

  0.0,

  // Computed Parameter: PAR_MASK_MODE_Value
  //  Referenced by: '<S8>/PAR_MASK_MODE'

  0U,

  // Computed Parameter: PAR_MASK_MODE_Value_k
  //  Referenced by: '<S9>/PAR_MASK_MODE'

  0U,

  // Expression: uint8(PAR_VESC_DEV)
  //  Referenced by: '<S8>/S-Function Builder5'

  { 47U, 100U, 101U, 118U, 47U, 86U, 69U, 83U, 67U, 50U, 0U },

  // Expression: uint8(PAR_VESC_DEV)
  //  Referenced by: '<S9>/S-Function Builder5'

  { 47U, 100U, 101U, 118U, 47U, 86U, 69U, 83U, 67U, 49U, 0U },

  // Computed Parameter: ManualSwitch_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch'

  1U,

  // Computed Parameter: ManualSwitch2_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch2'

  0U,

  // Computed Parameter: ManualSwitch1_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch1'

  1U,

  // Start of '<S6>/If Action Subsystem1'
  {
    // Expression: 0.035
    //  Referenced by: '<S17>/Saturation'

    0.035,

    // Expression: -0.035
    //  Referenced by: '<S17>/Saturation'

    -0.035
  }
  ,

  // End of '<S6>/If Action Subsystem1'

  // Start of '<S6>/If Action Subsystem'
  {
    // Expression: 0.035
    //  Referenced by: '<S16>/Saturation'

    0.035,

    // Expression: -0.035
    //  Referenced by: '<S16>/Saturation'

    -0.035
  }
  // End of '<S6>/If Action Subsystem'
};

//
// File trailer for generated code.
//
// [EOF]
//
