//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pendu_vesc.h
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
#ifndef RTW_HEADER_pendu_vesc_h_
#define RTW_HEADER_pendu_vesc_h_
#include <cmath>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef pendu_vesc_COMMON_INCLUDES_
# define pendu_vesc_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 // pendu_vesc_COMMON_INCLUDES_

#include "pendu_vesc_types.h"

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

// Block states (default storage) for system '<S8>/If Action Subsystem'
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;// '<S8>/If Action Subsystem'
} DW_IfActionSubsystem_pendu_ve_T;

// Block signals (default storage)
typedef struct {
  mc_configuration SFunctionBuilder5_o2;// '<S11>/S-Function Builder5'
  mc_configuration SFunctionBuilder5_o2_b;// '<S10>/S-Function Builder5'
  mc_values SFunctionBuilder5_o1;      // '<S11>/S-Function Builder5'
  mc_values SFunctionBuilder5_o1_c;    // '<S10>/S-Function Builder5'
  real_T dv0[8];
  real_T x_tilda[4];
  real_T Probe[2];                     // '<S13>/Probe'
  real_T Probe_g[2];                   // '<S29>/Probe'
  real_T Probe_l[2];                   // '<S24>/Probe'
  real_T tau_data[2];
  real_T degToRad;                     // '<S9>/degToRad'
  real_T WeightedSampleTime1;          // '<S9>/Weighted Sample Time1'
  real_T Saturation;                   // '<S28>/Saturation'
  real_T degToRad1;                    // '<S9>/degToRad1'
  real_T WeightedSampleTime;           // '<S9>/Weighted Sample Time'
  real_T Saturation_e;                 // '<S33>/Saturation'
  real_T Saturation_b;                 // '<S17>/Saturation'
  real_T Sum;                          // '<S8>/Sum'
  real_T maxcurrent;                   // '<S8>/max. current'
  real_T pos_cmd;                      // '<Root>/Sine Wave'
  real_T y;                            // '<S12>/MATLAB Function'
  real_T y_d;                          // '<Root>/MATLAB Function1'
  real_T y_h;                          // '<Root>/MATLAB Function'
  real_T mode;                         // '<Root>/Control'
  real_T kd;
  real_T M12;
  real_T Integrator_o;                 // '<S33>/Integrator'
  real_T ManualSwitch;                 // '<Root>/Manual Switch'
  real_T ManualSwitch2;                // '<Root>/Manual Switch2'
  uint32_T Switch;                     // '<S11>/Switch'
  uint32_T Switch_d;                   // '<S10>/Switch'
  real32_T current_motor;
  real32_T l_current_max;              // '<S11>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T l_current_min;              // '<S11>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T l_in_current_max;           // '<S11>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T l_in_current_min;           // '<S11>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T l_abs_current_max;          // '<S11>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T p_pid_kp;                   // '<S11>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  real32_T p_pid_ki;                   // '<S11>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  real32_T p_pid_kd;                   // '<S11>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  real32_T p_pid_kd_filter;            // '<S11>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  real32_T p_pid_ang_div;              // '<S11>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  real32_T l_current_max_l;            // '<S10>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T l_current_min_b;            // '<S10>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T l_in_current_max_d;         // '<S10>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T l_in_current_min_p;         // '<S10>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T l_abs_current_max_e;        // '<S10>/BusConversion_InsertedFor_Bus Selector2_at_inport_0' 
  real32_T p_pid_kp_m;                 // '<S10>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  real32_T p_pid_ki_k;                 // '<S10>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  real32_T p_pid_kd_m;                 // '<S10>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  real32_T p_pid_kd_filter_p;          // '<S10>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  real32_T p_pid_ang_div_j;            // '<S10>/BusConversion_InsertedFor_Bus Selector1_at_inport_0' 
  boolean_T SFunctionBuilder5_o3;      // '<S11>/S-Function Builder5'
  boolean_T SFunctionBuilder5_o3_o;    // '<S10>/S-Function Builder5'
} B_pendu_vesc_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  real_T UD1_DSTATE;                   // '<S9>/UD1'
  real_T Integrator_DSTATE;            // '<S28>/Integrator'
  real_T UD_DSTATE;                    // '<S12>/UD'
  real_T UD_DSTATE_i;                  // '<S9>/UD'
  real_T Integrator_DSTATE_c;          // '<S33>/Integrator'
  real_T UnitDelay_DSTATE;             // '<Root>/Unit Delay'
  real_T Integrator_DSTATE_k;          // '<S17>/Integrator'
  real_T UD_DSTATE_a;                  // '<S2>/UD'
  real_T SFunctionBuilder5_DSTATE;     // '<S11>/S-Function Builder5'
  real_T SFunctionBuilder5_DSTATE_i;   // '<S10>/S-Function Builder5'
  real_T pos1;                         // '<S12>/MATLAB Function'
  real_T initpos;                      // '<Root>/MATLAB Function1'
  real_T initpos_d;                    // '<Root>/MATLAB Function'
  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      // '<S9>/Scope1'

  struct {
    void *LoggedData[2];
  } Scope4_PWORK;                      // '<Root>/Scope4'

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       // '<Root>/Scope'

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      // '<Root>/Scope2'

  struct {
    void *LoggedData[4];
  } Scope1_PWORK_i;                    // '<Root>/Scope1'

  struct {
    void *LoggedData[2];
  } Scope_PWORK_i;                     // '<S9>/Scope'

  struct {
    void *LoggedData;
  } Scope2_PWORK_l;                    // '<S9>/Scope2'

  struct {
    void *LoggedData[2];
  } Scope3_PWORK;                      // '<Root>/Scope3'

  struct {
    void *LoggedData;
  } Scope_PWORK_h;                     // '<S12>/Scope'

  void *SFunctionBuilder5_PWORK;       // '<S11>/S-Function Builder5'
  void *SFunctionBuilder5_PWORK_k;     // '<S10>/S-Function Builder5'
  int8_T Integrator_PrevResetState;    // '<S28>/Integrator'
  int8_T Integrator_PrevResetState_j;  // '<S33>/Integrator'
  int8_T Integrator_PrevResetState_c;  // '<S17>/Integrator'
  uint8_T Integrator_IC_LOADING;       // '<S28>/Integrator'
  uint8_T Integrator_IC_LOADING_h;     // '<S33>/Integrator'
  uint8_T Integrator_IC_LOADING_p;     // '<S17>/Integrator'
  DW_IfActionSubsystem_pendu_ve_T IfActionSubsystem1;// '<S8>/If Action Subsystem1' 
  DW_IfActionSubsystem_pendu_ve_T IfActionSubsystem;// '<S8>/If Action Subsystem' 
} DW_pendu_vesc_T;

// Parameters for system: '<S8>/If Action Subsystem'
struct P_IfActionSubsystem_pendu_ves_T_ {
  real_T Saturation_UpperSat;          // Expression: 0.035
                                       //  Referenced by: '<S18>/Saturation'

  real_T Saturation_LowerSat;          // Expression: -0.035
                                       //  Referenced by: '<S18>/Saturation'

};

// Parameters (default storage)
struct P_pendu_vesc_T_ {
  real_T DiscreteDerivative_ICPrevScaled;// Mask Parameter: DiscreteDerivative_ICPrevScaled
                                         //  Referenced by: '<S2>/UD'

  real_T LowPassFilterDiscreteorContinuo;// Mask Parameter: LowPassFilterDiscreteorContinuo
                                         //  Referenced by: '<S20>/K'

  real_T LowPassFilterDiscreteorContin_o;// Mask Parameter: LowPassFilterDiscreteorContin_o
                                         //  Referenced by: '<S21>/K'

  real_T LowPassFilterDiscreteorContin_e;// Mask Parameter: LowPassFilterDiscreteorContin_e
                                         //  Referenced by: '<S5>/K'

  real_T LowPassFilterDiscreteorContin_g;// Mask Parameter: LowPassFilterDiscreteorContin_g
                                         //  Referenced by: '<S24>/Time constant'

  real_T LowPassFilterDiscreteorContin_j;// Mask Parameter: LowPassFilterDiscreteorContin_j
                                         //  Referenced by: '<S29>/Time constant'

  real_T LowPassFilterDiscreteorConti_jv;// Mask Parameter: LowPassFilterDiscreteorConti_jv
                                         //  Referenced by: '<S13>/Time constant'

  real_T Constant6_Value;              // Expression: 0
                                       //  Referenced by: '<Root>/Constant6'

  real_T Constant1_Value;              // Expression: 1
                                       //  Referenced by: '<Root>/Constant1'

  real_T Constant3_Value;              // Expression: 4
                                       //  Referenced by: '<Root>/Constant3'

  real_T Constant_Value;               // Expression: 0
                                       //  Referenced by: '<Root>/Constant'

  real_T PAR_CURR_LIMS_Value[5];       // Expression: [10 -10 10 -10 10]
                                       //  Referenced by: '<S10>/PAR_CURR_LIMS'

  real_T PAR_PID_GAINS_Value[5];       // Expression: [0 0 0 0.2 1]
                                       //  Referenced by: '<S10>/PAR_PID_GAINS'

  real_T Constant5_Value;              // Expression: 0
                                       //  Referenced by: '<Root>/Constant5'

  real_T PAR_CURR_LIMS_Value_i[5];     // Expression: [10 -10 10 -10 10]
                                       //  Referenced by: '<S11>/PAR_CURR_LIMS'

  real_T PAR_PID_GAINS_Value_l[5];     // Expression: [0 0 0 0.2 1]
                                       //  Referenced by: '<S11>/PAR_PID_GAINS'

  real_T EnergyShapingGain_Value[3];   // Expression: [1.2 0 0]
                                       //  Referenced by: '<S3>/Energy Shaping Gain'

  real_T Constant_Value_i;             // Expression: 0
                                       //  Referenced by: '<S26>/Constant'

  real_T degToRad_Gain;                // Expression: pi/180
                                       //  Referenced by: '<S9>/degToRad'

  real_T UD1_InitialCondition;         // Expression: 0
                                       //  Referenced by: '<S9>/UD1'

  real_T WeightedSampleTime1_WtEt;     // Computed Parameter: WeightedSampleTime1_WtEt
                                       //  Referenced by: '<S9>/Weighted Sample Time1'

  real_T Integrator_gainval;           // Computed Parameter: Integrator_gainval
                                       //  Referenced by: '<S28>/Integrator'

  real_T Integrator_UpperSat;          // Expression: antiwindupUpperLimit
                                       //  Referenced by: '<S28>/Integrator'

  real_T Integrator_LowerSat;          // Expression: antiwindupLowerLimit
                                       //  Referenced by: '<S28>/Integrator'

  real_T Saturation_UpperSat;          // Expression: windupUpperLimit
                                       //  Referenced by: '<S28>/Saturation'

  real_T Saturation_LowerSat;          // Expression: windupLowerLimit
                                       //  Referenced by: '<S28>/Saturation'

  real_T UD_InitialCondition;          // Expression: 0
                                       //  Referenced by: '<S12>/UD'

  real_T degToRad1_Gain;               // Expression: pi/180
                                       //  Referenced by: '<S9>/degToRad1'

  real_T Constant_Value_c;             // Expression: 0
                                       //  Referenced by: '<S31>/Constant'

  real_T UD_InitialCondition_d;        // Expression: 0
                                       //  Referenced by: '<S9>/UD'

  real_T WeightedSampleTime_WtEt;      // Computed Parameter: WeightedSampleTime_WtEt
                                       //  Referenced by: '<S9>/Weighted Sample Time'

  real_T Integrator_gainval_f;         // Computed Parameter: Integrator_gainval_f
                                       //  Referenced by: '<S33>/Integrator'

  real_T Integrator_UpperSat_d;        // Expression: antiwindupUpperLimit
                                       //  Referenced by: '<S33>/Integrator'

  real_T Integrator_LowerSat_k;        // Expression: antiwindupLowerLimit
                                       //  Referenced by: '<S33>/Integrator'

  real_T Saturation_UpperSat_c;        // Expression: windupUpperLimit
                                       //  Referenced by: '<S33>/Saturation'

  real_T Saturation_LowerSat_m;        // Expression: windupLowerLimit
                                       //  Referenced by: '<S33>/Saturation'

  real_T Window_Value;                 // Expression: 15
                                       //  Referenced by: '<S3>/Window'

  real_T a_Value;                      // Expression: 0.06
                                       //  Referenced by: '<S4>/a'

  real_T b_Value;                      // Expression: 0.06
                                       //  Referenced by: '<S4>/b'

  real_T p_Value;                      // Expression: 0.02
                                       //  Referenced by: '<S4>/p'

  real_T d_Value;                      // Expression: 0.02
                                       //  Referenced by: '<S4>/d'

  real_T Constant_Value_ib;            // Expression: 0
                                       //  Referenced by: '<S15>/Constant'

  real_T UnitDelay_InitialCondition;   // Expression: 0
                                       //  Referenced by: '<Root>/Unit Delay'

  real_T Integrator_gainval_a;         // Computed Parameter: Integrator_gainval_a
                                       //  Referenced by: '<S17>/Integrator'

  real_T Integrator_UpperSat_n;        // Expression: antiwindupUpperLimit
                                       //  Referenced by: '<S17>/Integrator'

  real_T Integrator_LowerSat_a;        // Expression: antiwindupLowerLimit
                                       //  Referenced by: '<S17>/Integrator'

  real_T Saturation_UpperSat_o;        // Expression: windupUpperLimit
                                       //  Referenced by: '<S17>/Saturation'

  real_T Saturation_LowerSat_g;        // Expression: windupLowerLimit
                                       //  Referenced by: '<S17>/Saturation'

  real_T motordirection_Gain;          // Expression: -1
                                       //  Referenced by: '<S8>/motor direction'

  real_T uTorqueConst_Gain;            // Expression: 1/(29.2e-3)
                                       //  Referenced by: '<S8>/1//Torque Const'

  real_T maxcurrent_UpperSat;          // Expression: 3
                                       //  Referenced by: '<S8>/max. current'

  real_T maxcurrent_LowerSat;          // Expression: -3
                                       //  Referenced by: '<S8>/max. current'

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
                                       //  Referenced by: '<S10>/PAR_MASK_MODE'

  uint32_T PAR_MASK_MODE_Value_k;      // Computed Parameter: PAR_MASK_MODE_Value_k
                                       //  Referenced by: '<S11>/PAR_MASK_MODE'

  uint8_T SFunctionBuilder5_P1[15];    // Expression: uint8(PAR_VESC_DEV)
                                       //  Referenced by: '<S10>/S-Function Builder5'

  uint8_T SFunctionBuilder5_P1_h[15];  // Expression: uint8(PAR_VESC_DEV)
                                       //  Referenced by: '<S11>/S-Function Builder5'

  uint8_T ManualSwitch2_CurrentSetting;// Computed Parameter: ManualSwitch2_CurrentSetting
                                       //  Referenced by: '<Root>/Manual Switch2'

  uint8_T ManualSwitch_CurrentSetting; // Computed Parameter: ManualSwitch_CurrentSetting
                                       //  Referenced by: '<Root>/Manual Switch'

  P_IfActionSubsystem_pendu_ves_T IfActionSubsystem1;// '<S8>/If Action Subsystem1' 
  P_IfActionSubsystem_pendu_ves_T IfActionSubsystem;// '<S8>/If Action Subsystem' 
};

// Real-time Model Data Structure
struct tag_RTM_pendu_vesc_T {
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

  extern P_pendu_vesc_T pendu_vesc_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
extern B_pendu_vesc_T pendu_vesc_B;

// Block states (default storage)
extern DW_pendu_vesc_T pendu_vesc_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void pendu_vesc_initialize(void);
  extern void pendu_vesc_step(void);
  extern void pendu_vesc_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_pendu_vesc_T *const pendu_vesc_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/Data Type Duplicate' : Unused code path elimination
//  Block '<S9>/Data Type Duplicate' : Unused code path elimination
//  Block '<S9>/Data Type Duplicate1' : Unused code path elimination
//  Block '<S12>/Data Type Duplicate' : Unused code path elimination
//  Block '<S9>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S9>/Data Type Conversion1' : Eliminate redundant data type conversion


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
//  '<Root>' : 'pendu_vesc'
//  '<S1>'   : 'pendu_vesc/Control'
//  '<S2>'   : 'pendu_vesc/Discrete Derivative'
//  '<S3>'   : 'pendu_vesc/K and wdw'
//  '<S4>'   : 'pendu_vesc/LQRTUNER'
//  '<S5>'   : 'pendu_vesc/Low-Pass Filter (Discrete or Continuous)'
//  '<S6>'   : 'pendu_vesc/MATLAB Function'
//  '<S7>'   : 'pendu_vesc/MATLAB Function1'
//  '<S8>'   : 'pendu_vesc/Motor Layer'
//  '<S9>'   : 'pendu_vesc/Pos'
//  '<S10>'  : 'pendu_vesc/VESC USB'
//  '<S11>'  : 'pendu_vesc/VESC USB1'
//  '<S12>'  : 'pendu_vesc/gear ratio 5'
//  '<S13>'  : 'pendu_vesc/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
//  '<S14>'  : 'pendu_vesc/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
//  '<S15>'  : 'pendu_vesc/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
//  '<S16>'  : 'pendu_vesc/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Continuous'
//  '<S17>'  : 'pendu_vesc/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
//  '<S18>'  : 'pendu_vesc/Motor Layer/If Action Subsystem'
//  '<S19>'  : 'pendu_vesc/Motor Layer/If Action Subsystem1'
//  '<S20>'  : 'pendu_vesc/Pos/Low-Pass Filter (Discrete or Continuous)'
//  '<S21>'  : 'pendu_vesc/Pos/Low-Pass Filter (Discrete or Continuous)1'
//  '<S22>'  : 'pendu_vesc/Pos/MATLAB Function'
//  '<S23>'  : 'pendu_vesc/Pos/MATLAB Function1'
//  '<S24>'  : 'pendu_vesc/Pos/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant'
//  '<S25>'  : 'pendu_vesc/Pos/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)'
//  '<S26>'  : 'pendu_vesc/Pos/Low-Pass Filter (Discrete or Continuous)/Enable//disable time constant/Compare To Zero'
//  '<S27>'  : 'pendu_vesc/Pos/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Continuous'
//  '<S28>'  : 'pendu_vesc/Pos/Low-Pass Filter (Discrete or Continuous)/Integrator (Discrete or Continuous)/Discrete'
//  '<S29>'  : 'pendu_vesc/Pos/Low-Pass Filter (Discrete or Continuous)1/Enable//disable time constant'
//  '<S30>'  : 'pendu_vesc/Pos/Low-Pass Filter (Discrete or Continuous)1/Integrator (Discrete or Continuous)'
//  '<S31>'  : 'pendu_vesc/Pos/Low-Pass Filter (Discrete or Continuous)1/Enable//disable time constant/Compare To Zero'
//  '<S32>'  : 'pendu_vesc/Pos/Low-Pass Filter (Discrete or Continuous)1/Integrator (Discrete or Continuous)/Continuous'
//  '<S33>'  : 'pendu_vesc/Pos/Low-Pass Filter (Discrete or Continuous)1/Integrator (Discrete or Continuous)/Discrete'
//  '<S34>'  : 'pendu_vesc/gear ratio 5/MATLAB Function'

#endif                                 // RTW_HEADER_pendu_vesc_h_

//
// File trailer for generated code.
//
// [EOF]
//
