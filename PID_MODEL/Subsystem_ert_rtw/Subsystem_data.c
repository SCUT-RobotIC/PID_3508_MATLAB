/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem_data.c
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 1.31
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Thu Nov  9 21:28:02 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Subsystem.h"

/* Block parameters (default storage) */
P rtP = {
  /* Variable: DeadBand
   * Referenced by:
   *   '<S3>/Chart2'
   *   '<S3>/Switch1'
   *   '<S3>/Switch2'
   */
  500.0,

  /* Variable: Kd_a
   * Referenced by: '<S130>/Derivative Gain'
   */
  0.0,

  /* Variable: Kd_s
   * Referenced by:
   *   '<S30>/Derivative Gain'
   *   '<S82>/Derivative Gain'
   */
  0.0,

  /* Variable: Ki_a
   * Referenced by: '<S133>/Integral Gain'
   */
  0.0,

  /* Variable: Ki_s
   * Referenced by:
   *   '<S33>/Integral Gain'
   *   '<S85>/Integral Gain'
   */
  0.0,

  /* Variable: Kp_a
   * Referenced by: '<S141>/Proportional Gain'
   */
  0.0,

  /* Variable: Kp_s
   * Referenced by:
   *   '<S41>/Proportional Gain'
   *   '<S93>/Proportional Gain'
   */
  0.0,

  /* Variable: trans
   * Referenced by: '<S3>/Multiply'
   */
  0.5
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
