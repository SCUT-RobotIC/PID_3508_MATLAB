/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Subsystem.c
 *
 * Code generated for Simulink model 'Subsystem'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Thu Oct 12 16:09:42 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Subsystem.h"
#include "rtwtypes.h"
#include <math.h>

/* Named constants for Chart: '<S3>/Chart1' */
#define IN_ADD                         ((uint8_T)1U)
#define IN_IDLE                        ((uint8_T)2U)
#define IN_SUB                         ((uint8_T)3U)

/* Named constants for Chart: '<S3>/Chart2' */
#define IN_DB                          ((uint8_T)1U)
#define IN_NDB                         ((uint8_T)2U)

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void Subsystem_step(void)
{
  real_T rtb_FilterCoefficient_m;
  real_T rtb_FilterCoefficient_p;
  real_T rtb_Sum1;
  real_T rtb_Sum3;
  real_T rtb_Sum_c;

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Inport: '<Root>/status'
   */
  switch ((int32_T)rtU.status) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/If Action_speed Subsystem' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Sum: '<S2>/Sum' incorporates:
     *  Inport: '<Root>/speed_rpm'
     *  Inport: '<Root>/target'
     */
    rtb_Sum_c = rtU.target - rtU.speed_rpm;

    /* Gain: '<S39>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S31>/Filter'
     *  Gain: '<S30>/Derivative Gain'
     *  Sum: '<S31>/SumD'
     */
    rtb_FilterCoefficient_p = (rtP.Kd_s * rtb_Sum_c - rtDW.Filter_DSTATE_n) *
      100.0;

    /* Sum: '<S45>/Sum' incorporates:
     *  DiscreteIntegrator: '<S36>/Integrator'
     *  Gain: '<S41>/Proportional Gain'
     */
    rtb_Sum3 = (rtP.Kp_s * rtb_Sum_c + rtDW.Integrator_DSTATE_o2) +
      rtb_FilterCoefficient_p;

    /* Saturate: '<S43>/Saturation' */
    if (rtb_Sum3 > 16384.0) {
      /* Outport: '<Root>/SPD_OUT' */
      rtY.SPD_OUT = 16384.0;
    } else if (rtb_Sum3 < -16384.0) {
      /* Outport: '<Root>/SPD_OUT' */
      rtY.SPD_OUT = -16384.0;
    } else {
      /* Outport: '<Root>/SPD_OUT' */
      rtY.SPD_OUT = rtb_Sum3;
    }

    /* End of Saturate: '<S43>/Saturation' */

    /* Update for DiscreteIntegrator: '<S31>/Filter' */
    rtDW.Filter_DSTATE_n += 0.001 * rtb_FilterCoefficient_p;

    /* Update for DiscreteIntegrator: '<S36>/Integrator' incorporates:
     *  Gain: '<S33>/Integral Gain'
     */
    rtDW.Integrator_DSTATE_o2 += rtP.Ki_s * rtb_Sum_c * 0.001;

    /* End of Outputs for SubSystem: '<S1>/If Action_speed Subsystem' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/If Action_speed Subsystem1' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Sum: '<S3>/Sum' incorporates:
     *  Gain: '<S3>/Gain'
     *  Inport: '<Root>/circle'
     *  Inport: '<Root>/ecd'
     *  Inport: '<Root>/target'
     *  Sum: '<S3>/Sum2'
     */
    rtb_Sum_c = rtU.target - (8191.0 * rtU.circle + rtU.ecd);

    /* Gain: '<S139>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S131>/Filter'
     *  Gain: '<S130>/Derivative Gain'
     *  Sum: '<S131>/SumD'
     */
    rtb_FilterCoefficient_p = (rtP.Kd_a * rtb_Sum_c - rtDW.Filter_DSTATE) *
      100.0;

    /* Sum: '<S145>/Sum' incorporates:
     *  DiscreteIntegrator: '<S136>/Integrator'
     *  Gain: '<S141>/Proportional Gain'
     */
    rtb_Sum3 = (rtP.Kp_a * rtb_Sum_c + rtDW.Integrator_DSTATE) +
      rtb_FilterCoefficient_p;

    /* Saturate: '<S143>/Saturation' */
    if (rtb_Sum3 > 16384.0) {
      rtb_Sum3 = 16384.0;
    } else if (rtb_Sum3 < -16384.0) {
      rtb_Sum3 = -16384.0;
    }

    /* Sum: '<S3>/Sum1' incorporates:
     *  Gain: '<S3>/Multiply'
     *  Inport: '<Root>/speed_rpm'
     *  Saturate: '<S143>/Saturation'
     */
    rtb_Sum1 = rtP.trans * rtb_Sum3 - rtU.speed_rpm;

    /* Gain: '<S91>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S83>/Filter'
     *  Gain: '<S82>/Derivative Gain'
     *  Sum: '<S83>/SumD'
     */
    rtb_FilterCoefficient_m = (rtP.Kd_s * rtb_Sum1 - rtDW.Filter_DSTATE_i) *
      100.0;

    /* Switch: '<S3>/Switch' incorporates:
     *  Abs: '<S3>/Abs'
     */
    if (fabs(rtb_Sum_c) > rtP.DeadBand) {
      /* Sum: '<S97>/Sum' incorporates:
       *  DiscreteIntegrator: '<S88>/Integrator'
       *  Gain: '<S93>/Proportional Gain'
       */
      rtb_Sum3 = (rtP.Kp_s * rtb_Sum1 + rtDW.Integrator_DSTATE_o) +
        rtb_FilterCoefficient_m;

      /* Saturate: '<S95>/Saturation' */
      if (rtb_Sum3 > 16384.0) {
        /* Outport: '<Root>/ANG_OUT' */
        rtY.ANG_OUT = 16384.0;
      } else if (rtb_Sum3 < -16384.0) {
        /* Outport: '<Root>/ANG_OUT' */
        rtY.ANG_OUT = -16384.0;
      } else {
        /* Outport: '<Root>/ANG_OUT' */
        rtY.ANG_OUT = rtb_Sum3;
      }

      /* End of Saturate: '<S95>/Saturation' */
    } else {
      /* Outport: '<Root>/ANG_OUT' incorporates:
       *  Constant: '<S3>/Constant'
       */
      rtY.ANG_OUT = 0.0;
    }

    /* End of Switch: '<S3>/Switch' */

    /* Sum: '<S3>/Sum3' incorporates:
     *  Inport: '<Root>/ecd'
     *  Inport: '<Root>/last_ecd'
     */
    rtb_Sum3 = rtU.ecd - rtU.last_ecd;

    /* Chart: '<S3>/Chart1' */
    if (rtDW.is_active_c2_Subsystem == 0U) {
      rtDW.is_active_c2_Subsystem = 1U;
      rtDW.is_c2_Subsystem = IN_IDLE;
    } else {
      switch (rtDW.is_c2_Subsystem) {
       case IN_ADD:
        if (rtb_Sum3 <= -5000.0) {
          rtDW.is_c2_Subsystem = IN_SUB;
          rtDW.u2 = -1.0;
        } else if ((rtb_Sum3 < 5000.0) && (rtb_Sum3 > -5000.0)) {
          rtDW.is_c2_Subsystem = IN_IDLE;
        }
        break;

       case IN_IDLE:
        if (rtb_Sum3 >= 5000.0) {
          rtDW.is_c2_Subsystem = IN_ADD;
          rtDW.u2 = 1.0;
        } else if (rtb_Sum3 <= -5000.0) {
          rtDW.is_c2_Subsystem = IN_SUB;
          rtDW.u2 = -1.0;
        } else {
          rtDW.u2 = 0.0;
        }
        break;

       default:
        /* case IN_SUB: */
        if (rtb_Sum3 >= 5000.0) {
          rtDW.is_c2_Subsystem = IN_ADD;
          rtDW.u2 = 1.0;
        } else if ((rtb_Sum3 < 5000.0) && (rtb_Sum3 > -5000.0)) {
          rtDW.is_c2_Subsystem = IN_IDLE;
        }
        break;
      }
    }

    /* End of Chart: '<S3>/Chart1' */

    /* Outport: '<Root>/circle_out' incorporates:
     *  Inport: '<Root>/circle'
     *  Sum: '<S3>/Sum4'
     */
    rtY.circle_out = rtDW.u2 + rtU.circle;

    /* Chart: '<S3>/Chart2' */
    if (rtDW.is_active_c1_Subsystem == 0U) {
      rtDW.is_active_c1_Subsystem = 1U;
      rtDW.is_c1_Subsystem = IN_DB;
    } else if (rtDW.is_c1_Subsystem == IN_DB) {
      if (rtP.DeadBand <= 0.0) {
        rtDW.is_c1_Subsystem = IN_NDB;
      }

      /* case IN_NDB: */
    } else if (rtP.DeadBand >= 0.0) {
      rtDW.is_c1_Subsystem = IN_DB;
    }

    /* End of Chart: '<S3>/Chart2' */

    /* Update for DiscreteIntegrator: '<S136>/Integrator' incorporates:
     *  Gain: '<S133>/Integral Gain'
     */
    rtDW.Integrator_DSTATE += rtP.Ki_a * rtb_Sum_c * 0.001;
    if (rtDW.Integrator_DSTATE >= 500.0) {
      rtDW.Integrator_DSTATE = 500.0;
    } else if (rtDW.Integrator_DSTATE <= -500.0) {
      rtDW.Integrator_DSTATE = -500.0;
    }

    /* End of Update for DiscreteIntegrator: '<S136>/Integrator' */

    /* Update for DiscreteIntegrator: '<S131>/Filter' */
    rtDW.Filter_DSTATE += 0.001 * rtb_FilterCoefficient_p;

    /* Update for DiscreteIntegrator: '<S83>/Filter' */
    rtDW.Filter_DSTATE_i += 0.001 * rtb_FilterCoefficient_m;

    /* Update for DiscreteIntegrator: '<S88>/Integrator' incorporates:
     *  Gain: '<S85>/Integral Gain'
     */
    rtDW.Integrator_DSTATE_o += rtP.Ki_s * rtb_Sum1 * 0.001;
    if (rtDW.Integrator_DSTATE_o >= 2000.0) {
      rtDW.Integrator_DSTATE_o = 2000.0;
    } else if (rtDW.Integrator_DSTATE_o <= -2000.0) {
      rtDW.Integrator_DSTATE_o = -2000.0;
    }

    /* End of Update for DiscreteIntegrator: '<S88>/Integrator' */
    /* End of Outputs for SubSystem: '<S1>/If Action_speed Subsystem1' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */
}

/* Model initialize function */
void Subsystem_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
