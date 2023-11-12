/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PID_MODEL_data.c
 *
 * Code generated for Simulink model 'PID_MODEL'.
 *
 * Model version                  : 2.6
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Nov 12 23:11:19 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "PID_MODEL.h"

/* Block parameters (default storage) */
P rtP = {
  /* Variable: DeadBand
   * Referenced by:
   *   '<S4>/Chart2'
   *   '<S4>/Switch1'
   *   '<S4>/Switch2'
   *   '<S155>/Chart2'
   *   '<S155>/Switch1'
   *   '<S155>/Switch2'
   */
  500.0,

  /* Variable: Kd_a
   * Referenced by:
   *   '<S131>/Derivative Gain'
   *   '<S282>/Derivative Gain'
   */
  0.0,

  /* Variable: Kd_s
   * Referenced by:
   *   '<S83>/Derivative Gain'
   *   '<S182>/Derivative Gain'
   *   '<S234>/Derivative Gain'
   */
  0.0,

  /* Variable: Kd_s_3508
   * Referenced by: '<S31>/Derivative Gain'
   */
  0.0,

  /* Variable: Ki_a
   * Referenced by:
   *   '<S134>/Integral Gain'
   *   '<S285>/Integral Gain'
   */
  0.0,

  /* Variable: Ki_s
   * Referenced by:
   *   '<S86>/Integral Gain'
   *   '<S185>/Integral Gain'
   *   '<S237>/Integral Gain'
   */
  0.0,

  /* Variable: Ki_s_3508
   * Referenced by: '<S34>/Integral Gain'
   */
  0.0,

  /* Variable: Kp_a
   * Referenced by:
   *   '<S142>/Proportional Gain'
   *   '<S293>/Proportional Gain'
   */
  0.0,

  /* Variable: Kp_s
   * Referenced by:
   *   '<S94>/Proportional Gain'
   *   '<S193>/Proportional Gain'
   *   '<S245>/Proportional Gain'
   */
  0.0,

  /* Variable: Kp_s_3508
   * Referenced by: '<S42>/Proportional Gain'
   */
  0.0,

  /* Variable: trans
   * Referenced by:
   *   '<S4>/Multiply'
   *   '<S155>/Multiply'
   */
  0.5
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
