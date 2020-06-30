//
//  pendu_vesc_modified_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "pendu_vesc_modified".
//
//  Model version              : 1.287
//  Simulink Coder version : 9.0 (R2018b) 24-May-2018
//  C++ source code generated on : Mon Jun 22 13:01:14 2020
//
//  Target selection: ert.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex
//  Code generation objectives: Unspecified
//  Validation result: Not run


#include "ext_types.h"

// data type size table
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(mc_fault_code),
  sizeof(mc_values),
  sizeof(mc_pwm_mode),
  sizeof(mc_comm_mode),
  sizeof(mc_motor_type),
  sizeof(mc_sensor_mode),
  sizeof(mc_foc_sensor_mode),
  sizeof(sensor_port_mode),
  sizeof(drv8301_oc_mode),
  sizeof(out_aux_mode),
  sizeof(BATTERY_TYPE),
  sizeof(mc_configuration)
};

// data type name table
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "mc_fault_code",
  "mc_values",
  "mc_pwm_mode",
  "mc_comm_mode",
  "mc_motor_type",
  "mc_sensor_mode",
  "mc_foc_sensor_mode",
  "sensor_port_mode",
  "drv8301_oc_mode",
  "out_aux_mode",
  "BATTERY_TYPE",
  "mc_configuration"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&pendu_vesc_modified_B.SFunctionBuilder5_o2), 25, 0, 2 },

  { (char_T *)(&pendu_vesc_modified_B.SFunctionBuilder5_o1), 15, 0, 2 },

  { (char_T *)(&pendu_vesc_modified_B.degToRad1), 0, 0, 24 },

  { (char_T *)(&pendu_vesc_modified_B.Switch), 7, 0, 2 },

  { (char_T *)(&pendu_vesc_modified_B.current_motor), 1, 0, 21 },

  { (char_T *)(&pendu_vesc_modified_B.SFunctionBuilder5_o3), 8, 0, 2 }
  ,

  { (char_T *)(&pendu_vesc_modified_DW.UD_DSTATE), 0, 0, 14 },

  { (char_T *)(&pendu_vesc_modified_DW.ToFile_PWORK.FilePtr), 11, 0, 18 },

  { (char_T *)(&pendu_vesc_modified_DW.ToFile_IWORK.Count), 10, 0, 1 },

  { (char_T *)(&pendu_vesc_modified_DW.Integrator_PrevResetState), 2, 0, 4 },

  { (char_T *)(&pendu_vesc_modified_DW.Integrator_IC_LOADING), 3, 0, 3 },

  { (char_T *)
    (&pendu_vesc_modified_DW.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&pendu_vesc_modified_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC), 2,
    0, 1 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  13U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&pendu_vesc_modified_P.DiscreteDerivative_ICPrevScaled), 0, 0, 75
  },

  { (char_T *)(&pendu_vesc_modified_P.PAR_MASK_MODE_Value), 7, 0, 2 },

  { (char_T *)(&pendu_vesc_modified_P.SFunctionBuilder5_P1[0]), 3, 0, 25 },

  { (char_T *)(&pendu_vesc_modified_P.IfActionSubsystem1.Saturation_UpperSat), 0,
    0, 2 },

  { (char_T *)(&pendu_vesc_modified_P.IfActionSubsystem.Saturation_UpperSat), 0,
    0, 2 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

// [EOF] pendu_vesc_modified_dt.h
