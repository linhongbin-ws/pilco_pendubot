//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: pendu_vesc_private.h
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
#ifndef RTW_HEADER_pendu_vesc_private_h_
#define RTW_HEADER_pendu_vesc_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "pendu_vesc.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern void sf_vesc_usb_Start_wrapper(real_T *xD,
  void **pW,
  const uint8_T *vesc_dev, const int_T p_width0);
extern void sf_vesc_usb_Outputs_wrapper(mc_values *slx_values,
  mc_configuration *slx_mcconf,
  boolean_T *slx_mcconf_read,
  const real_T *xD,
  void **pW,
  const uint8_T *vesc_dev, const int_T p_width0);
extern void sf_vesc_usb_Update_wrapper(const uint32_T *slx_mode,
  const real_T *slx_pos_cmd,
  const real_T *slx_current_cmd,
  const real_T *slx_pos_pid_gains,
  const real_T *slx_curr_lims,
  mc_values *slx_values,
  mc_configuration *slx_mcconf,
  boolean_T *slx_mcconf_read,
  real_T *xD,
  void **pW,
  const uint8_T *vesc_dev, const int_T p_width0);
extern void sf_vesc_usb_Terminate_wrapper(real_T *xD,
  void **pW,
  const uint8_T *vesc_dev, const int_T p_width0);
extern void pendu_vesc_IfActionSubsystem(real_T rtu_In1, real_T *rty_Out1,
  P_IfActionSubsystem_pendu_ves_T *localP);
extern void pendu_vesc_MATLABFunction(real_T rtu_u, real_T *rty_y);

#endif                                 // RTW_HEADER_pendu_vesc_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
