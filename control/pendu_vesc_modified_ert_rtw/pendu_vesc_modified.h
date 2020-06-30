//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pendu_vesc_modified.h
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
#ifndef RTW_HEADER_pendu_vesc_modified_h_
#define RTW_HEADER_pendu_vesc_modified_h_
#include <stddef.h>
#include <cmath>
#include <float.h>
#include <string.h>
#ifndef pendu_vesc_modified_COMMON_INCLUDES_
# define pendu_vesc_modified_COMMON_INCLUDES_
#include <stdio.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 // pendu_vesc_modified_COMMON_INCLUDES_

#include "pendu_vesc_modified_types.h"

// Shared type includes
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

// Block states (default storage) for system '<S6>/If Action Subsystem'
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;// '<S6>/If Action Subsystem'
} DW_IfActionSubsystem_pendu_ve_T;

// Block signals (default storage)
typedef struct {
  mc_configuration SFunctionBuilder5_o2;// '<S9>/S-Function Builder5'
  mc_configuration SFunctionBuilder5_o2_b;// '<S8>/S-Function Builder5'
  mc_values SFunctionBuilder5_o1;      // '<S9>/S-Function Builder5'
  mc_values SFunctionBuilder5_o1_c;    // '<S8>/S-Function Builder5'
  real_T TmpSignalConversionAtToFile[6];
  real_T degToRad1;                    // '<S7>/degToRad1'
  real_T degToRad;                     // '<S7>/degToRad'
  real_T Probe[2];                     // '<S28>/Probe'
  real_T WeightedSampleTime;           // '<S7>/Weighted Sample Time'
  real_T Saturation;                   // '<S32>/Saturation'
  real_T Probe_l[2];                   // '<S23>/Probe'
  real_T WeightedSampleTime1;          // '<S7>/Weighted Sample Time1'
  real_T Saturation_m;                 // '<S27>/Saturation'
  real_T DiscreteTimeIntegrator;       // '<Root>/Discrete-Time Integrator'
  real_T Probe_lj[2];                  // '<S11>/Probe'
  real_T Saturation_b;                 // '<S15>/Saturation'
  real_T Sum;                          // '<S6>/Sum'
  real_T maxcurrent;                   // '<S6>/max. current'
  real_T pos_cmd;                      // '<Root>/Sine Wave'
  real_T y;                            // '<S10>/MATLAB Function'
  real_T q1_out;                       // '<S7>/MATLAB Function2'
  real_T q2_out;                       // '<S7>/MATLAB Function2'
  real_T y_d;                          // '<Root>/MATLAB Function1'
  real_T y_h;                          // '<Root>/MATLAB Function'
  real_T tau1;                         // '<Root>/ApplyPolicy'
  real_T tau2;                         // '<Root>/ApplyPolicy'
  real_T u_rev;
  real_T ManualSwitch;                 // '<Root>/Manual Switch'
  real_T K_d;                          // '<S3>/K'
  real_T ManualSwitch2;                // '<Root>/Manual Switch2'
  uint32_T Switch;                     // '<S9>/Switch'
  uint32_T Switch_d;                   // '<S8>/Switch'
  real32_T current_motor;
  real32_T l_current_max;              // '<S9>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T l_current_min;              // '<S9>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T l_in_current_max;           // '<S9>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T l_in_current_min;           // '<S9>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T l_abs_current_max;          // '<S9>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T p_pid_kp;                   // '<S9>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  real32_T p_pid_ki;                   // '<S9>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  real32_T p_pid_kd;                   // '<S9>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  real32_T p_pid_kd_filter;            // '<S9>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  real32_T p_pid_ang_div;              // '<S9>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  real32_T l_current_max_l;            // '<S8>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T l_current_min_b;            // '<S8>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T l_in_current_max_d;         // '<S8>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T l_in_current_min_p;         // '<S8>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T l_abs_current_max_e;        // '<S8>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T p_pid_kp_m;                 // '<S8>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  real32_T p_pid_ki_k;                 // '<S8>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  real32_T p_pid_kd_m;                 // '<S8>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  real32_T p_pid_kd_filter_p;          // '<S8>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  real32_T p_pid_ang_div_j;            // '<S8>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  boolean_T SFunctionBuilder5_o3;      // '<S9>/S-Function Builder5'
  boolean_T SFunctionBuilder5_o3_o;    // '<S8>/S-Function Builder5'
} B_pendu_vesc_modified_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  real_T UD_DSTATE;                    // '<S10>/UD'
  real_T UD_DSTATE_i;                  // '<S7>/UD'
  real_T Integrator_DSTATE;            // '<S32>/Integrator'
  real_T UD1_DSTATE;                   // '<S7>/UD1'
  real_T Integrator_DSTATE_b;          // '<S27>/Integrator'
  real_T DiscreteTimeIntegrator_DSTATE;// '<Root>/Discrete-Time Integrator'
  real_T UnitDelay_DSTATE;             // '<Root>/Unit Delay'
  real_T Integrator_DSTATE_k;          // '<S15>/Integrator'
  real_T UD_DSTATE_a;                  // '<S2>/UD'
  real_T SFunctionBuilder5_DSTATE;     // '<S9>/S-Function Builder5'
  real_T SFunctionBuilder5_DSTATE_i;   // '<S8>/S-Function Builder5'
  real_T pos1;                         // '<S10>/MATLAB Function'
  real_T initpos;                      // '<Root>/MATLAB Function1'
  real_T initpos_d;                    // '<Root>/MATLAB Function'
  struct {
    void *FilePtr;
  } ToFile_PWORK;                      // '<Root>/To File'

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      // '<Root>/Scope2'

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       // '<Root>/Scope'

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      // '<Root>/Scope5'

  struct {
    void *LoggedData;
  } Scope6_PWORK;                      // '<Root>/Scope6'

  struct {
    void *LoggedData[4];
  } Scope1_PWORK;                      // '<Root>/Scope1'

  struct {
    void *LoggedData[2];
  } Scope1_PWORK_a;                    // '<S7>/Scope1'

  struct {
    void *LoggedData[2];
  } Scope_PWORK_i;                     // '<S7>/Scope'

  struct {
    void *LoggedData;
  } Scope2_PWORK_l;                    // '<S7>/Scope2'

  struct {
    void *LoggedData;
  } Scope_PWORK_h;                     // '<S10>/Scope'

  void *SFunctionBuilder5_PWORK;       // '<S9>/S-Function Builder5'
  void *SFunctionBuilder5_PWORK_k;     // '<S8>/S-Function Builder5'
  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK;                      // '<Root>/To File'

  int8_T Integrator_PrevResetState;    // '<S32>/Integrator'
  int8_T Integrator_PrevResetState_p;  // '<S27>/Integrator'
  int8_T DiscreteTimeIntegrator_PrevRese;// '<Root>/Discrete-Time Integrator'
  int8_T Integrator_PrevResetState_c;  // '<S15>/Integrator'
  uint8_T Integrator_IC_LOADING;       // '<S32>/Integrator'
  uint8_T Integrator_IC_LOADING_c;     // '<S27>/Integrator'
  uint8_T Integrator_IC_LOADING_p;     // '<S15>/Integrator'
  DW_IfActionSubsystem_pendu_ve_T IfActionSubsystem1;// '<S6>/If Action Subsystem1' 
  DW_IfActionSubsystem_pendu_ve_T IfActionSubsystem;// '<S6>/If Action Subsystem' 
} DW_pendu_vesc_modified_T;

// Parameters for system: '<S6>/If Action Subsystem'
struct P_IfActionSubsystem_pendu_ves_T_ {
  real_T Saturation_UpperSat;          // Expression: 0.035
                                       //  Referenced by: '<S16>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -0.035
                                       //  Referenced by: '<S16>/Saturation'

};

// Parameters (default storage)
struct P_pendu_vesc_modified_T_ {
  real_T DiscreteDerivative_ICPrevScaled;// Mask Parameter: DiscreteDerivative_ICPrevScaled
                                         //  Referenced by: '<S2>/UD'

  real_T LowPassFilterDiscreteorContinuo;// Mask Parameter: LowPassFilterDiscreteorContinuo
                                         //  Referenced by: '<S19>/K'

  real_T LowPassFilterDiscreteorContin_c;// Mask Parameter: LowPassFilterDiscreteorContin_c
                                         //  Referenced by: '<S18>/K'

  real_T LowPassFilterDiscreteorContin_e;// Mask Parameter: LowPassFilterDiscreteorContin_e
                                         //  Referenced by: '<S3>/K'

  real_T LowPassFilterDiscreteorContin_j;// Mask Parameter: LowPassFilterDiscreteorContin_j
                                         //  Referenced by: '<S28>/Time constant'

  real_T LowPassFilterDiscreteorContin_g;// Mask Parameter: LowPassFilterDiscreteorContin_g
                                         //  Referenced by: '<S23>/Time constant'

  real_T LowPassFilterDiscreteorConti_jv;// Mask Parameter: LowPassFilterDiscreteorConti_jv
                                         //  Referenced by: '<S11>/Time constant'

  real_T Constant6_Value;              // Expression: 0
                                       //  Referenced by: '<Root>/Constant6'

  real_T Constant1_Value;              // Expression: 1
                                       //  Referenced by: '<Root>/Constant1'

  real_T Constant10_Value;             // Expression: 0
                                       //  Referenced by: '<Root>/Constant10'

  real_T Constant9_Value;              // Expression: 1
                                       //  Referenced by: '<Root>/Constant9'

  real_T Constant3_Value;              // Expression: 4
                                       //  Referenced by: '<Root>/Constant3'

  real_T Constant8_Value;              // Expression: 0
                                       //  Referenced by: '<Root>/Constant8'

  real_T PAR_CURR_LIMS_Value[5];       // Expression: [10 -10 10 -10 10]
                                       //  Referenced by: '<S8>/PAR_CURR_LIMS'

  real_T PAR_PID_GAINS_Value[5];       // Expression: [0 0 0 0.2 1]
                                       //  Referenced by: '<S8>/PAR_PID_GAINS'

  real_T Constant5_Value;              // Expression: 0
                                       //  Referenced by: '<Root>/Constant5'

  real_T PAR_CURR_LIMS_Value_i[5];     // Expression: [10 -10 10 -10 10]
                                       //  Referenced by: '<S9>/PAR_CURR_LIMS'

  real_T PAR_PID_GAINS_Value_l[5];     // Expression: [0 0 0 0.2 1]
                                       //  Referenced by: '<S9>/PAR_PID_GAINS'

  real_T Gain_Gain;                    // Expression: 0.25
                                       //  Referenced by: '<Root>/Gain'

  real_T UD_InitialCondition;          // Expression: 0
                                       //  Referenced by: '<S10>/UD'

  real_T degToRad1_Gain;               // Expression: pi/180
                                       //  Referenced by: '<S7>/degToRad1'

  real_T degToRad_Gain;                // Expression: pi/180
                                       //  Referenced by: '<S7>/degToRad'

  real_T Constant_Value;               // Expression: 0
                                       //  Referenced by: '<S30>/Constant'

  real_T UD_InitialCondition_d;        // Expression: 0
                                       //  Referenced by: '<S7>/UD'

  real_T WeightedSampleTime_WtEt;      // Computed Parameter: WeightedSampleTime_WtEt
                                       //  Referenced by: '<S7>/Weighted Sample Time'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                       //  Referenced by: '<S32>/Integrator'

  real_T Integrator_UpperSat;          // Expression: antiwindupUpperLimit
                                       //  Referenced by: '<S32>/Integrator'

  real_T Integrator_LowerSat;          // Expression: antiwindupLowerLimit
                                       //  Referenced by: '<S32>/Integrator'

  real_T Saturation_UpperSat;          // Expression: windupUpperLimit
                                       //  Referenced by: '<S32>/Saturation'

  real_T Saturation_LowerSat;          // Expression: windupLowerLimit
                                       //  Referenced by: '<S32>/Saturation'

  real_T Constant_Value_i;             // Expression: 0
                                       //  Referenced by: '<S25>/Constant'

  real_T UD1_InitialCondition;         // Expression: 0
                                       //  Referenced by: '<S7>/UD1'

  real_T WeightedSampleTime1_WtEt;     // Computed Parameter: WeightedSampleTime1_WtEt
                                       //  Referenced by: '<S7>/Weighted Sample Time1'

  real_T Integrator_gainval_k;         // Computed Parameter: Integrator_gainval_k
                                       //  Referenced by: '<S27>/Integrator'

  real_T Integrator_UpperSat_m;        // Expression: antiwindupUpperLimit
                                       //  Referenced by: '<S27>/Integrator'

  real_T Integrator_LowerSat_l;        // Expression: antiwindupLowerLimit
                                       //  Referenced by: '<S27>/Integrator'

  real_T Saturation_UpperSat_o;        // Expression: windupUpperLimit
                                       //  Referenced by: '<S27>/Saturation'

  real_T Saturation_LowerSat_d;        // Expression: windupLowerLimit
                                       //  Referenced by: '<S27>/Saturation'

  real_T DiscreteTimeIntegrator_gainval;// Computed Parameter: DiscreteTimeIntegrator_gainval
                                        //  Referenced by: '<Root>/Discrete-Time Integrator'

  real_T DiscreteTimeIntegrator_IC;    // Expression: 0
                                       //  Referenced by: '<Root>/Discrete-Time Integrator'

  real_T Constant7_Value;              // Expression: 0.035
                                       //  Referenced by: '<Root>/Constant7'

  real_T Constant_Value_ib;            // Expression: 0
                                       //  Referenced by: '<S13>/Constant'

  real_T UnitDelay_InitialCondition;   // Expression: 0
                                       //  Referenced by: '<Root>/Unit Delay'

  real_T Integrator_gainval_a;         // Computed Parameter: Integrator_gainval_a
                                       //  Referenced by: '<S15>/Integrator'

  real_T Integrator_UpperSat_n;        // Expression: antiwindupUpperLimit
                                       //  Referenced by: '<S15>/Integrator'

  real_T Integrator_LowerSat_a;        // Expression: antiwindupLowerLimit
                                       //  Referenced by: '<S15>/Integrator'

  real_T Saturation_UpperSat_o1;       // Expression: windupUpperLimit
                                       //  Referenced by: '<S15>/Saturation'

  real_T Saturation_LowerSat_g;        // Expression: windupLowerLimit
                                       //  Referenced by: '<S15>/Saturation'

  real_T motordirection_Gain;          // Expression: -1
                                       //  Referenced by: '<S6>/motor direction'

  real_T uTorqueConst_Gain;            // Expression: 1/(29.2e-3)
                                       //  Referenced by: '<S6>/1//Torque Const'

  real_T maxcurrent_UpperSat;          // Expression: 3
                                       //  Referenced by: '<S6>/max. current'

  real_T maxcurrent_LowerSat;          // Expression: -3
                                       //  Referenced by: '<S6>/max. current'

  real_T TSamp_WtEt;                   // Computed Parameter: TSamp_WtEt
                                       //  Referenced by: '<S2>/TSamp'

  real_T Constant2_Value;              // Expression: 0
                                       //  Referenced by: '<Root>/Constant2'

  real_T Constant4_Value;              // Expression: 0
                                       //  Referenced by: '<Root>/Constant4'

  real_T SineWave_Amp;                 // Expression: 150
                                       //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_Bias;                // Expression: 10
                                       //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_Freq;                // Expression: 1
                                       //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_Phase;               // Expression: 0
                                       //  Referenced by: '<Root>/Sine Wave'

  uint32_T PAR_MASK_MODE_Value;        // Computed Parameter: PAR_MASK_MODE_Value
                                       //  Referenced by: '<S8>/PAR_MASK_MODE'

  uint32_T PAR_MASK_MODE_Value_k;      // Computed Parameter: PAR_MASK_MODE_Value_k
                                       //  Referenced by: '<S9>/PAR_MASK_MODE'

  uint8_T SFunctionBuilder5_P1[11];    // Expression: uint8(PAR_VESC_DEV)
                                       //  Referenced by: '<S8>/S-Function Builder5'

  uint8_T SFunctionBuilder5_P1_h[11];  // Expression: uint8(PAR_VESC_DEV)
                                       //  Referenced by: '<S9>/S-Function Builder5'

  uint8_T ManualSwitch_CurrentSetting; // Computed Parameter: ManualSwitch_CurrentSetting
                                       //  Referenced by: '<Root>/Manual Switch'

  uint8_T ManualSwitch2_CurrentSetting;// Computed Parameter: ManualSwitch2_CurrentSetting
                                       //  Referenced by: '<Root>/Manual Switch2'

  uint8_T ManualSwitch1_CurrentSetting;// Computed Parameter: ManualSwitch1_CurrentSetting
                                       //  Referenced by: '<Root>/Manual Switch1'

  P_IfActionSubsystem_pendu_ves_T IfActionSubsystem1;// '<S6>/If Action Subsystem1' 
  P_IfActionSubsystem_pendu_ves_T IfActionSubsystem;// '<S6>/If Action Subsystem' 
};

// Real-time Model Data Structure
struct tag_RTM_pendu_vesc_modified_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    uint32_T checksums[4];
  } Sizes;

  //
  //  SpecialInfo:
  //  The following substructure contains special information
  //  related to other components that are dependent on RTW.

  struct {
    const void *mappingInfo;
  } SpecialInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_pendu_vesc_modified_T pendu_vesc_modified_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
extern B_pendu_vesc_modified_T pendu_vesc_modified_B;

// Block states (default storage)
extern DW_pendu_vesc_modified_T pendu_vesc_modified_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void pendu_vesc_modified_initialize(void);
  extern void pendu_vesc_modified_step(void);
  extern void pendu_vesc_modified_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_pendu_vesc_modified_T *const pendu_vesc_modified_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/Data Type Duplicate' : Unused code path elimination
//  Block '<S7>/Data Type Duplicate' : Unused code path elimination
//  Block '<S7>/Data Type Duplicate1' : Unused code path elimination
//  Block '<S10>/Data Type Duplicate' : Unused code path elimination
//  Block '<S7>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S7>/Data Type Conversion1' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'pendu_vesc_modified'
//  '<S1>'   : 'pendu_vesc_modified/ApplyPolicy'
//  '<S2>'   : 'pendu_vesc_modified/Discrete Derivative'
//  '<S3>'   : 'pendu_vesc_modified/Low-Pass Filter (Discrete or Continuous)'
//  '<S4>'   : 'pendu_vesc_modified/MATLAB Function'
//  '<S5>'   : 'pendu_vesc_modified/MATLAB Function1'
//  '<S6>'   : 'pendu_vesc_modified/Motor Layer'
//  '<S7>'   : 'pendu_vesc_modified/Pos'
//  '<S8>'   : 'pendu_vesc_modified/VESC USB'
//  '<S9>'   : 'pendu_vesc_modified/VESC USB1'
//  '<S10>'  : 'pendu_vesc_modified/gear ratio 5'
//  '<S11>'  : 'pendu_vesc_modified/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
//  '<S12>'  : 'pendu_vesc_modified/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
//  '<S13>'  : 'pendu_vesc_modified/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
//  '<S14>'  : 'pendu_vesc_modified/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Continuous'
//  '<S15>'  : 'pendu_vesc_modified/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
//  '<S16>'  : 'pendu_vesc_modified/Motor Layer/If Action Subsystem'
//  '<S17>'  : 'pendu_vesc_modified/Motor Layer/If Action Subsystem1'
//  '<S18>'  : 'pendu_vesc_modified/Pos/Low-Pass Filter (Discrete or Continuous)'
//  '<S19>'  : 'pendu_vesc_modified/Pos/Low-Pass Filter (Discrete or Continuous)1'
//  '<S20>'  : 'pendu_vesc_modified/Pos/MATLAB Function'
//  '<S21>'  : 'pendu_vesc_modified/Pos/MATLAB Function1'
//  '<S22>'  : 'pendu_vesc_modified/Pos/MATLAB Function2'
//  '<S23>'  : 'pendu_vesc_modified/Pos/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
//  '<S24>'  : 'pendu_vesc_modified/Pos/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
//  '<S25>'  : 'pendu_vesc_modified/Pos/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
//  '<S26>'  : 'pendu_vesc_modified/Pos/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Continuous'
//  '<S27>'  : 'pendu_vesc_modified/Pos/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
//  '<S28>'  : 'pendu_vesc_modified/Pos/Low-Pass Filter (Discrete or Continuous)1/Enable//disable time constant'
//  '<S29>'  : 'pendu_vesc_modified/Pos/Low-Pass Filter (Discrete or Continuous)1/Integrator (Discrete or Continuous)'
//  '<S30>'  : 'pendu_vesc_modified/Pos/Low-Pass Filter (Discrete or Continuous)1/Enable//disable time constant/Compare To Zero'
//  '<S31>'  : 'pendu_vesc_modified/Pos/Low-Pass Filter (Discrete or Continuous)1/Integrator (Discrete or Continuous)/Continuous'
//  '<S32>'  : 'pendu_vesc_modified/Pos/Low-Pass Filter (Discrete or Continuous)1/Integrator (Discrete or Continuous)/Discrete'
//  '<S33>'  : 'pendu_vesc_modified/gear ratio 5/MATLAB Function'

#endif                                 // RTW_HEADER_pendu_vesc_modified_h_

//
// File trailer for generated code.
//
// [EOF]
//
