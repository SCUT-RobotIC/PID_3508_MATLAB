/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PID_MODEL.c
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
#include "rtwtypes.h"
#include <math.h>

/* Named constants for Chart: '<S4>/Chart1' */
#define IN_ADD                         ((uint8_T)1U)
#define IN_IDLE                        ((uint8_T)2U)
#define IN_SUB                         ((uint8_T)3U)

/* Named constants for Chart: '<S4>/Chart2' */
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
static void Chart1_Init(real_T *rty_u2);
static void Chart1(real_T rtu_u1, real_T *rty_u2, DW_Chart1 *localDW);
static void Chart2_Init(real_T *rty_op);
static void Chart2(real_T rtu_in, real_T rtu_noabsin, real_T *rty_op, DW_Chart2 *
                   localDW);

/*
 * System initialize for atomic system:
 *    '<S4>/Chart1'
 *    '<S155>/Chart1'
 */
static void Chart1_Init(real_T *rty_u2)
{
  *rty_u2 = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S4>/Chart1'
 *    '<S155>/Chart1'
 */
static void Chart1(real_T rtu_u1, real_T *rty_u2, DW_Chart1 *localDW)
{
  /* Chart: '<S4>/Chart1' */
  if (localDW->is_active_c2_PID_MODEL == 0U) {
    localDW->is_active_c2_PID_MODEL = 1U;
    localDW->is_c2_PID_MODEL = IN_IDLE;
  } else {
    switch (localDW->is_c2_PID_MODEL) {
     case IN_ADD:
      if (rtu_u1 <= -5000.0) {
        localDW->is_c2_PID_MODEL = IN_SUB;
        *rty_u2 = -1.0;
      } else if ((rtu_u1 < 5000.0) && (rtu_u1 > -5000.0)) {
        localDW->is_c2_PID_MODEL = IN_IDLE;
      }
      break;

     case IN_IDLE:
      if (rtu_u1 >= 5000.0) {
        localDW->is_c2_PID_MODEL = IN_ADD;
        *rty_u2 = 1.0;
      } else if (rtu_u1 <= -5000.0) {
        localDW->is_c2_PID_MODEL = IN_SUB;
        *rty_u2 = -1.0;
      } else {
        *rty_u2 = 0.0;
      }
      break;

     default:
      /* case IN_SUB: */
      if (rtu_u1 >= 5000.0) {
        localDW->is_c2_PID_MODEL = IN_ADD;
        *rty_u2 = 1.0;
      } else if ((rtu_u1 < 5000.0) && (rtu_u1 > -5000.0)) {
        localDW->is_c2_PID_MODEL = IN_IDLE;
      }
      break;
    }
  }

  /* End of Chart: '<S4>/Chart1' */
}

/*
 * System initialize for atomic system:
 *    '<S4>/Chart2'
 *    '<S155>/Chart2'
 */
static void Chart2_Init(real_T *rty_op)
{
  *rty_op = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S4>/Chart2'
 *    '<S155>/Chart2'
 */
static void Chart2(real_T rtu_in, real_T rtu_noabsin, real_T *rty_op, DW_Chart2 *
                   localDW)
{
  /* Chart: '<S4>/Chart2' */
  if (localDW->is_active_c1_PID_MODEL == 0U) {
    localDW->is_active_c1_PID_MODEL = 1U;
    localDW->is_c1_PID_MODEL = IN_DB;
  } else if (localDW->is_c1_PID_MODEL == IN_DB) {
    if (rtu_in >= rtP.DeadBand) {
      localDW->is_c1_PID_MODEL = IN_NDB;
    } else {
      *rty_op = 0.0;
    }

    /* case IN_NDB: */
  } else if (rtu_in <= rtP.DeadBand) {
    localDW->is_c1_PID_MODEL = IN_DB;
  } else {
    *rty_op = rtu_noabsin;
  }

  /* End of Chart: '<S4>/Chart2' */
}

/* Model step function */
void PID_MODEL_step(void)
{
  real_T op_f;
  real_T rtb_FilterCoefficient_c;
  real_T rtb_FilterCoefficient_j1;
  real_T rtb_FilterCoefficient_p;
  real_T rtb_Sum_c;

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Inport: '<Root>/pitch_status'
   */
  switch ((int32_T)rtU.pitch_status) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/If Action_speed Subsystem' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Sum: '<S3>/Sum' incorporates:
     *  Inport: '<Root>/pitch_speed_rpm'
     *  Inport: '<Root>/pitch_target'
     */
    rtb_Sum_c = rtU.pitch_target - rtU.pitch_speed_rpm;

    /* Gain: '<S40>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S32>/Filter'
     *  Gain: '<S31>/Derivative Gain'
     *  Sum: '<S32>/SumD'
     */
    rtb_FilterCoefficient_p = (rtP.Kd_s_3508 * rtb_Sum_c - rtDW.Filter_DSTATE_nz)
      * 100.0;

    /* Sum: '<S46>/Sum' incorporates:
     *  DiscreteIntegrator: '<S37>/Integrator'
     *  Gain: '<S42>/Proportional Gain'
     */
    op_f = (rtP.Kp_s_3508 * rtb_Sum_c + rtDW.Integrator_DSTATE_o2) +
      rtb_FilterCoefficient_p;

    /* Saturate: '<S44>/Saturation' */
    if (op_f > 16384.0) {
      /* Outport: '<Root>/pitch_SPD_OUT' */
      rtY.pitch_SPD_OUT = 16384.0;
    } else if (op_f < -16384.0) {
      /* Outport: '<Root>/pitch_SPD_OUT' */
      rtY.pitch_SPD_OUT = -16384.0;
    } else {
      /* Outport: '<Root>/pitch_SPD_OUT' */
      rtY.pitch_SPD_OUT = op_f;
    }

    /* End of Saturate: '<S44>/Saturation' */

    /* Update for DiscreteIntegrator: '<S32>/Filter' */
    rtDW.Filter_DSTATE_nz += 0.001 * rtb_FilterCoefficient_p;

    /* Update for DiscreteIntegrator: '<S37>/Integrator' incorporates:
     *  Gain: '<S34>/Integral Gain'
     */
    rtDW.Integrator_DSTATE_o2 += rtP.Ki_s_3508 * rtb_Sum_c * 0.001;

    /* End of Outputs for SubSystem: '<S1>/If Action_speed Subsystem' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/If Action_speed Subsystem1' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Sum: '<S4>/Sum' incorporates:
     *  Gain: '<S4>/Gain'
     *  Inport: '<Root>/pitch_circle'
     *  Inport: '<Root>/pitch_ecd'
     *  Inport: '<Root>/pitch_target'
     *  Sum: '<S4>/Sum2'
     */
    rtb_FilterCoefficient_p = rtU.pitch_target - (8191.0 * rtU.pitch_circle +
      rtU.pitch_ecd);

    /* Abs: '<S4>/Abs' */
    rtb_Sum_c = fabs(rtb_FilterCoefficient_p);

    /* Switch: '<S4>/Switch2' incorporates:
     *  Constant: '<S4>/Constant'
     */
    if (!(rtb_Sum_c > rtP.DeadBand)) {
      rtb_FilterCoefficient_p = 0.0;
    }

    /* End of Switch: '<S4>/Switch2' */

    /* Gain: '<S140>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S132>/Filter'
     *  Gain: '<S131>/Derivative Gain'
     *  Sum: '<S132>/SumD'
     */
    rtb_FilterCoefficient_j1 = (rtP.Kd_a * rtb_FilterCoefficient_p -
      rtDW.Filter_DSTATE_a) * 100.0;

    /* Switch: '<S4>/Switch1' incorporates:
     *  Constant: '<S4>/Constant'
     *  Gain: '<S4>/Multiply'
     *  Inport: '<Root>/pitch_speed_rpm'
     *  Saturate: '<S144>/Saturation'
     *  Sum: '<S4>/Sum1'
     */
    if (rtb_Sum_c > rtP.DeadBand) {
      /* Sum: '<S146>/Sum' incorporates:
       *  DiscreteIntegrator: '<S137>/Integrator'
       *  Gain: '<S142>/Proportional Gain'
       */
      op_f = (rtP.Kp_a * rtb_FilterCoefficient_p + rtDW.Integrator_DSTATE_b) +
        rtb_FilterCoefficient_j1;

      /* Saturate: '<S144>/Saturation' */
      if (op_f > 16384.0) {
        op_f = 16384.0;
      } else if (op_f < -16384.0) {
        op_f = -16384.0;
      }

      rtb_Sum_c = rtP.trans * op_f - rtU.pitch_speed_rpm;
    } else {
      rtb_Sum_c = 0.0;
    }

    /* End of Switch: '<S4>/Switch1' */

    /* Gain: '<S92>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S84>/Filter'
     *  Gain: '<S83>/Derivative Gain'
     *  Sum: '<S84>/SumD'
     */
    rtb_FilterCoefficient_c = (rtP.Kd_s * rtb_Sum_c - rtDW.Filter_DSTATE_i) *
      100.0;

    /* Sum: '<S98>/Sum' incorporates:
     *  DiscreteIntegrator: '<S89>/Integrator'
     *  Gain: '<S94>/Proportional Gain'
     */
    op_f = (rtP.Kp_s * rtb_Sum_c + rtDW.Integrator_DSTATE_o) +
      rtb_FilterCoefficient_c;

    /* Saturate: '<S96>/Saturation' */
    if (op_f > 16384.0) {
      /* Outport: '<Root>/pitch_ANG_OUT' */
      rtY.pitch_ANG_OUT = 16384.0;
    } else if (op_f < -16384.0) {
      /* Outport: '<Root>/pitch_ANG_OUT' */
      rtY.pitch_ANG_OUT = -16384.0;
    } else {
      /* Outport: '<Root>/pitch_ANG_OUT' */
      rtY.pitch_ANG_OUT = op_f;
    }

    /* End of Saturate: '<S96>/Saturation' */

    /* Chart: '<S4>/Chart1' incorporates:
     *  Inport: '<Root>/pitch_ecd'
     *  Inport: '<Root>/pitch_last_ecd'
     *  Sum: '<S4>/Sum3'
     */
    Chart1(rtU.pitch_ecd - rtU.pitch_last_ecd, &rtDW.u2_d, &rtDW.sf_Chart1);

    /* Outport: '<Root>/pitch_circle_out' incorporates:
     *  Inport: '<Root>/pitch_circle'
     *  Sum: '<S4>/Sum4'
     */
    rtY.pitch_circle_out = rtDW.u2_d + rtU.pitch_circle;

    /* Chart: '<S4>/Chart2' */
    Chart2(0.0, 0.0, &op_f, &rtDW.sf_Chart2);

    /* Update for DiscreteIntegrator: '<S137>/Integrator' incorporates:
     *  Gain: '<S134>/Integral Gain'
     */
    rtDW.Integrator_DSTATE_b += rtP.Ki_a * rtb_FilterCoefficient_p * 0.001;

    /* Update for DiscreteIntegrator: '<S132>/Filter' */
    rtDW.Filter_DSTATE_a += 0.001 * rtb_FilterCoefficient_j1;

    /* Update for DiscreteIntegrator: '<S84>/Filter' */
    rtDW.Filter_DSTATE_i += 0.001 * rtb_FilterCoefficient_c;

    /* Update for DiscreteIntegrator: '<S89>/Integrator' incorporates:
     *  Gain: '<S86>/Integral Gain'
     */
    rtDW.Integrator_DSTATE_o += rtP.Ki_s * rtb_Sum_c * 0.001;

    /* End of Outputs for SubSystem: '<S1>/If Action_speed Subsystem1' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* SwitchCase: '<S2>/Switch Case' incorporates:
   *  Inport: '<Root>/yaw_status'
   */
  switch ((int32_T)rtU.yaw_status) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S2>/If Action_speed Subsystem' incorporates:
     *  ActionPort: '<S154>/Action Port'
     */
    /* Sum: '<S154>/Sum' incorporates:
     *  Inport: '<Root>/yaw_speed_rpm'
     *  Inport: '<Root>/yaw_target'
     */
    rtb_Sum_c = rtU.yaw_target - rtU.yaw_speed_rpm;

    /* Gain: '<S191>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S183>/Filter'
     *  Gain: '<S182>/Derivative Gain'
     *  Sum: '<S183>/SumD'
     */
    rtb_FilterCoefficient_p = (rtP.Kd_s * rtb_Sum_c - rtDW.Filter_DSTATE_k) *
      100.0;

    /* Sum: '<S197>/Sum' incorporates:
     *  DiscreteIntegrator: '<S188>/Integrator'
     *  Gain: '<S193>/Proportional Gain'
     */
    op_f = (rtP.Kp_s * rtb_Sum_c + rtDW.Integrator_DSTATE_e) +
      rtb_FilterCoefficient_p;

    /* Saturate: '<S195>/Saturation' */
    if (op_f > 16384.0) {
      /* Outport: '<Root>/yaw_SPD_OUT' */
      rtY.yaw_SPD_OUT = 16384.0;
    } else if (op_f < -16384.0) {
      /* Outport: '<Root>/yaw_SPD_OUT' */
      rtY.yaw_SPD_OUT = -16384.0;
    } else {
      /* Outport: '<Root>/yaw_SPD_OUT' */
      rtY.yaw_SPD_OUT = op_f;
    }

    /* End of Saturate: '<S195>/Saturation' */

    /* Update for DiscreteIntegrator: '<S183>/Filter' */
    rtDW.Filter_DSTATE_k += 0.001 * rtb_FilterCoefficient_p;

    /* Update for DiscreteIntegrator: '<S188>/Integrator' incorporates:
     *  Gain: '<S185>/Integral Gain'
     */
    rtDW.Integrator_DSTATE_e += rtP.Ki_s * rtb_Sum_c * 0.001;

    /* End of Outputs for SubSystem: '<S2>/If Action_speed Subsystem' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S2>/If Action_speed Subsystem1' incorporates:
     *  ActionPort: '<S155>/Action Port'
     */
    /* Sum: '<S155>/Sum' incorporates:
     *  Gain: '<S155>/Gain'
     *  Inport: '<Root>/yaw_circle'
     *  Inport: '<Root>/yaw_ecd'
     *  Inport: '<Root>/yaw_target'
     *  Sum: '<S155>/Sum2'
     */
    rtb_FilterCoefficient_p = rtU.yaw_target - (8191.0 * rtU.yaw_circle +
      rtU.yaw_ecd);

    /* Abs: '<S155>/Abs' */
    rtb_Sum_c = fabs(rtb_FilterCoefficient_p);

    /* Switch: '<S155>/Switch2' incorporates:
     *  Constant: '<S155>/Constant'
     */
    if (!(rtb_Sum_c > rtP.DeadBand)) {
      rtb_FilterCoefficient_p = 0.0;
    }

    /* End of Switch: '<S155>/Switch2' */

    /* Gain: '<S291>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S283>/Filter'
     *  Gain: '<S282>/Derivative Gain'
     *  Sum: '<S283>/SumD'
     */
    rtb_FilterCoefficient_j1 = (rtP.Kd_a * rtb_FilterCoefficient_p -
      rtDW.Filter_DSTATE) * 100.0;

    /* Switch: '<S155>/Switch1' incorporates:
     *  Constant: '<S155>/Constant'
     *  Gain: '<S155>/Multiply'
     *  Inport: '<Root>/yaw_speed_rpm'
     *  Saturate: '<S295>/Saturation'
     *  Sum: '<S155>/Sum1'
     */
    if (rtb_Sum_c > rtP.DeadBand) {
      /* Sum: '<S297>/Sum' incorporates:
       *  DiscreteIntegrator: '<S288>/Integrator'
       *  Gain: '<S293>/Proportional Gain'
       */
      op_f = (rtP.Kp_a * rtb_FilterCoefficient_p + rtDW.Integrator_DSTATE) +
        rtb_FilterCoefficient_j1;

      /* Saturate: '<S295>/Saturation' */
      if (op_f > 16384.0) {
        op_f = 16384.0;
      } else if (op_f < -16384.0) {
        op_f = -16384.0;
      }

      rtb_Sum_c = rtP.trans * op_f - rtU.yaw_speed_rpm;
    } else {
      rtb_Sum_c = 0.0;
    }

    /* End of Switch: '<S155>/Switch1' */

    /* Gain: '<S243>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S235>/Filter'
     *  Gain: '<S234>/Derivative Gain'
     *  Sum: '<S235>/SumD'
     */
    rtb_FilterCoefficient_c = (rtP.Kd_s * rtb_Sum_c - rtDW.Filter_DSTATE_n) *
      100.0;

    /* Sum: '<S249>/Sum' incorporates:
     *  DiscreteIntegrator: '<S240>/Integrator'
     *  Gain: '<S245>/Proportional Gain'
     */
    op_f = (rtP.Kp_s * rtb_Sum_c + rtDW.Integrator_DSTATE_i) +
      rtb_FilterCoefficient_c;

    /* Saturate: '<S247>/Saturation' */
    if (op_f > 16384.0) {
      /* Outport: '<Root>/yaw_ANG_OUT' */
      rtY.yaw_ANG_OUT = 16384.0;
    } else if (op_f < -16384.0) {
      /* Outport: '<Root>/yaw_ANG_OUT' */
      rtY.yaw_ANG_OUT = -16384.0;
    } else {
      /* Outport: '<Root>/yaw_ANG_OUT' */
      rtY.yaw_ANG_OUT = op_f;
    }

    /* End of Saturate: '<S247>/Saturation' */

    /* Chart: '<S155>/Chart1' incorporates:
     *  Inport: '<Root>/yaw_ecd'
     *  Inport: '<Root>/yaw_last_ecd'
     *  Sum: '<S155>/Sum3'
     */
    Chart1(rtU.yaw_ecd - rtU.yaw_last_ecd, &rtDW.u2, &rtDW.sf_Chart1_d);

    /* Outport: '<Root>/yaw_circle_out' incorporates:
     *  Inport: '<Root>/yaw_circle'
     *  Sum: '<S155>/Sum4'
     */
    rtY.yaw_circle_out = rtDW.u2 + rtU.yaw_circle;

    /* Chart: '<S155>/Chart2' */
    Chart2(0.0, 0.0, &op_f, &rtDW.sf_Chart2_i);

    /* Update for DiscreteIntegrator: '<S288>/Integrator' incorporates:
     *  Gain: '<S285>/Integral Gain'
     */
    rtDW.Integrator_DSTATE += rtP.Ki_a * rtb_FilterCoefficient_p * 0.001;

    /* Update for DiscreteIntegrator: '<S283>/Filter' */
    rtDW.Filter_DSTATE += 0.001 * rtb_FilterCoefficient_j1;

    /* Update for DiscreteIntegrator: '<S235>/Filter' */
    rtDW.Filter_DSTATE_n += 0.001 * rtb_FilterCoefficient_c;

    /* Update for DiscreteIntegrator: '<S240>/Integrator' incorporates:
     *  Gain: '<S237>/Integral Gain'
     */
    rtDW.Integrator_DSTATE_i += rtP.Ki_s * rtb_Sum_c * 0.001;

    /* End of Outputs for SubSystem: '<S2>/If Action_speed Subsystem1' */
    break;
  }

  /* End of SwitchCase: '<S2>/Switch Case' */
}

/* Model initialize function */
void PID_MODEL_initialize(void)
{
  {
    real_T op_f;

    /* SystemInitialize for IfAction SubSystem: '<S1>/If Action_speed Subsystem1' */

    /* SystemInitialize for Chart: '<S4>/Chart1' */
    Chart1_Init(&rtDW.u2_d);

    /* SystemInitialize for Chart: '<S4>/Chart2' */
    Chart2_Init(&op_f);

    /* End of SystemInitialize for SubSystem: '<S1>/If Action_speed Subsystem1' */

    /* SystemInitialize for IfAction SubSystem: '<S2>/If Action_speed Subsystem1' */

    /* SystemInitialize for Chart: '<S155>/Chart1' */
    Chart1_Init(&rtDW.u2);

    /* SystemInitialize for Chart: '<S155>/Chart2' */
    Chart2_Init(&op_f);

    /* End of SystemInitialize for SubSystem: '<S2>/If Action_speed Subsystem1' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
