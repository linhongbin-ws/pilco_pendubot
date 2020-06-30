//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pendu_vesc_data.cpp
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

// Block parameters (default storage)
P_pendu_vesc_T pendu_vesc_P = {
  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S2>/UD'

  0.0,

  // Mask Parameter: LowPassFilterDiscreteorContinuo
  //  Referenced by: '<S20>/K'

  1.0,

  // Mask Parameter: LowPassFilterDiscreteorContin_o
  //  Referenced by: '<S21>/K'

  1.0,

  // Mask Parameter: LowPassFilterDiscreteorContin_e
  //  Referenced by: '<S5>/K'

  -1.0,

  // Mask Parameter: LowPassFilterDiscreteorContin_g
  //  Referenced by: '<S24>/Time constant'

  0.01,

  // Mask Parameter: LowPassFilterDiscreteorContin_j
  //  Referenced by: '<S29>/Time constant'

  0.01,

  // Mask Parameter: LowPassFilterDiscreteorConti_jv
  //  Referenced by: '<S13>/Time constant'

  0.025,

  // Expression: 0
  //  Referenced by: '<Root>/Constant6'

  0.0,

  // Expression: 1
  //  Referenced by: '<Root>/Constant1'

  1.0,

  // Expression: 4
  //  Referenced by: '<Root>/Constant3'

  4.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant'

  0.0,

  // Expression: [10 -10 10 -10 10]
  //  Referenced by: '<S10>/PAR_CURR_LIMS'

  { 10.0, -10.0, 10.0, -10.0, 10.0 },

  // Expression: [0 0 0 0.2 1]
  //  Referenced by: '<S10>/PAR_PID_GAINS'

  { 0.0, 0.0, 0.0, 0.2, 1.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Constant5'

  0.0,

  // Expression: [10 -10 10 -10 10]
  //  Referenced by: '<S11>/PAR_CURR_LIMS'

  { 10.0, -10.0, 10.0, -10.0, 10.0 },

  // Expression: [0 0 0 0.2 1]
  //  Referenced by: '<S11>/PAR_PID_GAINS'

  { 0.0, 0.0, 0.0, 0.2, 1.0 },

  // Expression: [1.2 0 0]
  //  Referenced by: '<S3>/Energy Shaping Gain'

  { 1.2, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S26>/Constant'

  0.0,

  // Expression: pi/180
  //  Referenced by: '<S9>/degToRad'

  0.017453292519943295,

  // Expression: 0
  //  Referenced by: '<S9>/UD1'

  0.0,

  // Computed Parameter: WeightedSampleTime1_WtEt
  //  Referenced by: '<S9>/Weighted Sample Time1'

  1000.0,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S28>/Integrator'

  0.001,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S28>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S28>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S28>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S28>/Saturation'

  0.0,

  // Expression: 0
  //  Referenced by: '<S12>/UD'

  0.0,

  // Expression: pi/180
  //  Referenced by: '<S9>/degToRad1'

  0.017453292519943295,

  // Expression: 0
  //  Referenced by: '<S31>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S9>/UD'

  0.0,

  // Computed Parameter: WeightedSampleTime_WtEt
  //  Referenced by: '<S9>/Weighted Sample Time'

  1000.0,

  // Computed Parameter: Integrator_gainval_f
  //  Referenced by: '<S33>/Integrator'

  0.001,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S33>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S33>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S33>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S33>/Saturation'

  0.0,

  // Expression: 15
  //  Referenced by: '<S3>/Window'

  15.0,

  // Expression: 0.06
  //  Referenced by: '<S4>/a'

  0.06,

  // Expression: 0.06
  //  Referenced by: '<S4>/b'

  0.06,

  // Expression: 0.02
  //  Referenced by: '<S4>/p'

  0.02,

  // Expression: 0.02
  //  Referenced by: '<S4>/d'

  0.02,

  // Expression: 0
  //  Referenced by: '<S15>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Unit Delay'

  0.0,

  // Computed Parameter: Integrator_gainval_a
  //  Referenced by: '<S17>/Integrator'

  0.001,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S17>/Integrator'

  0.05,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S17>/Integrator'

  -0.05,

  // Expression: windupUpperLimit
  //  Referenced by: '<S17>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S17>/Saturation'

  0.0,

  // Expression: -1
  //  Referenced by: '<S8>/motor direction'

  -1.0,

  // Expression: 1/(29.2e-3)
  //  Referenced by: '<S8>/1//Torque Const'

  34.246575342465754,

  // Expression: 3
  //  Referenced by: '<S8>/max. current'

  3.0,

  // Expression: -3
  //  Referenced by: '<S8>/max. current'

  -3.0,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S2>/TSamp'

  1000.0,

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
  //  Referenced by: '<S10>/PAR_MASK_MODE'

  0U,

  // Computed Parameter: PAR_MASK_MODE_Value_k
  //  Referenced by: '<S11>/PAR_MASK_MODE'

  0U,

  // Expression: uint8(PAR_VESC_DEV)
  //  Referenced by: '<S10>/S-Function Builder5'

  { 47U, 100U, 101U, 118U, 47U, 85U, 83U, 66U, 95U, 86U, 69U, 83U, 67U, 50U, 0U
  },

  // Expression: uint8(PAR_VESC_DEV)
  //  Referenced by: '<S11>/S-Function Builder5'

  { 47U, 100U, 101U, 118U, 47U, 85U, 83U, 66U, 95U, 86U, 69U, 83U, 67U, 49U, 0U
  },

  // Computed Parameter: ManualSwitch2_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch2'

  0U,

  // Computed Parameter: ManualSwitch_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch'

  1U,

  // Start of '<S8>/If Action Subsystem1'
  {
    // Expression: 0.035
    //  Referenced by: '<S19>/Saturation'

    0.035,

    // Expression: -0.035
    //  Referenced by: '<S19>/Saturation'

    -0.035
  }
  ,

  // End of '<S8>/If Action Subsystem1'

  // Start of '<S8>/If Action Subsystem'
  {
    // Expression: 0.035
    //  Referenced by: '<S18>/Saturation'

    0.035,

    // Expression: -0.035
    //  Referenced by: '<S18>/Saturation'

    -0.035
  }
  // End of '<S8>/If Action Subsystem'
};

//
// File trailer for generated code.
//
// [EOF]
//
