//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pendu_vesc_types.h
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
#ifndef RTW_HEADER_pendu_vesc_types_h_
#define RTW_HEADER_pendu_vesc_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "datatypes.h"

// Custom Type definition for MATLAB Function: '<Root>/Control'
#ifndef struct_tag_sMJBFn6l8RGboz23ZenDbmD
#define struct_tag_sMJBFn6l8RGboz23ZenDbmD

struct tag_sMJBFn6l8RGboz23ZenDbmD
{
  real_T l1;
  real_T l2;
  real_T lc1;
  real_T lc2;
  real_T m1;
  real_T m2;
  real_T I1;
  real_T I2;
  real_T b1;
  real_T b2;
  real_T B[4];
  real_T wm;
  real_T wc;
  real_T wg;
  real_T wf;
  real_T g;
};

#endif                                 //struct_tag_sMJBFn6l8RGboz23ZenDbmD

#ifndef typedef_sMJBFn6l8RGboz23ZenDbmD_pendu_T
#define typedef_sMJBFn6l8RGboz23ZenDbmD_pendu_T

typedef struct tag_sMJBFn6l8RGboz23ZenDbmD sMJBFn6l8RGboz23ZenDbmD_pendu_T;

#endif                                 //typedef_sMJBFn6l8RGboz23ZenDbmD_pendu_T

// Parameters for system: '<S8>/If Action Subsystem'
typedef struct P_IfActionSubsystem_pendu_ves_T_ P_IfActionSubsystem_pendu_ves_T;

// Parameters (default storage)
typedef struct P_pendu_vesc_T_ P_pendu_vesc_T;

// Forward declaration for rtModel
typedef struct tag_RTM_pendu_vesc_T RT_MODEL_pendu_vesc_T;

#endif                                 // RTW_HEADER_pendu_vesc_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
