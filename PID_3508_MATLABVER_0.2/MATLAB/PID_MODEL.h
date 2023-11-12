/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PID_MODEL.h
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

#ifndef RTW_HEADER_PID_MODEL_h_
#define RTW_HEADER_PID_MODEL_h_
#ifndef PID_MODEL_COMMON_INCLUDES_
#define PID_MODEL_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* PID_MODEL_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define PID_MODEL_M                    (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<S4>/Chart1' */
typedef struct {
  uint8_T is_active_c2_PID_MODEL;      /* '<S4>/Chart1' */
  uint8_T is_c2_PID_MODEL;             /* '<S4>/Chart1' */
} DW_Chart1;

/* Block signals and states (default storage) for system '<S4>/Chart2' */
typedef struct {
  uint8_T is_active_c1_PID_MODEL;      /* '<S4>/Chart2' */
  uint8_T is_c1_PID_MODEL;             /* '<S4>/Chart2' */
} DW_Chart2;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_Chart2 sf_Chart2_i;               /* '<S155>/Chart2' */
  DW_Chart1 sf_Chart1_d;               /* '<S155>/Chart1' */
  DW_Chart2 sf_Chart2;                 /* '<S4>/Chart2' */
  DW_Chart1 sf_Chart1;                 /* '<S4>/Chart1' */
  real_T u2;                           /* '<S155>/Chart1' */
  real_T u2_d;                         /* '<S4>/Chart1' */
  real_T Integrator_DSTATE;            /* '<S288>/Integrator' */
  real_T Filter_DSTATE;                /* '<S283>/Filter' */
  real_T Filter_DSTATE_n;              /* '<S235>/Filter' */
  real_T Integrator_DSTATE_i;          /* '<S240>/Integrator' */
  real_T Filter_DSTATE_k;              /* '<S183>/Filter' */
  real_T Integrator_DSTATE_e;          /* '<S188>/Integrator' */
  real_T Integrator_DSTATE_b;          /* '<S137>/Integrator' */
  real_T Filter_DSTATE_a;              /* '<S132>/Filter' */
  real_T Filter_DSTATE_i;              /* '<S84>/Filter' */
  real_T Integrator_DSTATE_o;          /* '<S89>/Integrator' */
  real_T Filter_DSTATE_nz;             /* '<S32>/Filter' */
  real_T Integrator_DSTATE_o2;         /* '<S37>/Integrator' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T pitch_speed_rpm;              /* '<Root>/pitch_speed_rpm' */
  real_T pitch_target;                 /* '<Root>/pitch_target' */
  real_T pitch_status;                 /* '<Root>/pitch_status' */
  real_T pitch_ecd;                    /* '<Root>/pitch_ecd' */
  real_T pitch_last_ecd;               /* '<Root>/pitch_last_ecd' */
  real_T pitch_circle;                 /* '<Root>/pitch_circle' */
  real_T yaw_speed_rpm;                /* '<Root>/yaw_speed_rpm' */
  real_T yaw_target;                   /* '<Root>/yaw_target' */
  real_T yaw_status;                   /* '<Root>/yaw_status' */
  real_T yaw_ecd;                      /* '<Root>/yaw_ecd' */
  real_T yaw_last_ecd;                 /* '<Root>/yaw_last_ecd' */
  real_T yaw_circle;                   /* '<Root>/yaw_circle' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T pitch_SPD_OUT;                /* '<Root>/pitch_SPD_OUT' */
  real_T pitch_ANG_OUT;                /* '<Root>/pitch_ANG_OUT' */
  real_T pitch_circle_out;             /* '<Root>/pitch_circle_out' */
  real_T yaw_SPD_OUT;                  /* '<Root>/yaw_SPD_OUT' */
  real_T yaw_ANG_OUT;                  /* '<Root>/yaw_ANG_OUT' */
  real_T yaw_circle_out;               /* '<Root>/yaw_circle_out' */
} ExtY;

/* Parameters (default storage) */
struct P_ {
  real_T DeadBand;                     /* Variable: DeadBand
                                        * Referenced by:
                                        *   '<S4>/Chart2'
                                        *   '<S4>/Switch1'
                                        *   '<S4>/Switch2'
                                        *   '<S155>/Chart2'
                                        *   '<S155>/Switch1'
                                        *   '<S155>/Switch2'
                                        */
  real_T Kd_a;                         /* Variable: Kd_a
                                        * Referenced by:
                                        *   '<S131>/Derivative Gain'
                                        *   '<S282>/Derivative Gain'
                                        */
  real_T Kd_s;                         /* Variable: Kd_s
                                        * Referenced by:
                                        *   '<S83>/Derivative Gain'
                                        *   '<S182>/Derivative Gain'
                                        *   '<S234>/Derivative Gain'
                                        */
  real_T Kd_s_3508;                    /* Variable: Kd_s_3508
                                        * Referenced by: '<S31>/Derivative Gain'
                                        */
  real_T Ki_a;                         /* Variable: Ki_a
                                        * Referenced by:
                                        *   '<S134>/Integral Gain'
                                        *   '<S285>/Integral Gain'
                                        */
  real_T Ki_s;                         /* Variable: Ki_s
                                        * Referenced by:
                                        *   '<S86>/Integral Gain'
                                        *   '<S185>/Integral Gain'
                                        *   '<S237>/Integral Gain'
                                        */
  real_T Ki_s_3508;                    /* Variable: Ki_s_3508
                                        * Referenced by: '<S34>/Integral Gain'
                                        */
  real_T Kp_a;                         /* Variable: Kp_a
                                        * Referenced by:
                                        *   '<S142>/Proportional Gain'
                                        *   '<S293>/Proportional Gain'
                                        */
  real_T Kp_s;                         /* Variable: Kp_s
                                        * Referenced by:
                                        *   '<S94>/Proportional Gain'
                                        *   '<S193>/Proportional Gain'
                                        *   '<S245>/Proportional Gain'
                                        */
  real_T Kp_s_3508;                    /* Variable: Kp_s_3508
                                        * Referenced by: '<S42>/Proportional Gain'
                                        */
  real_T trans;                        /* Variable: trans
                                        * Referenced by:
                                        *   '<S4>/Multiply'
                                        *   '<S155>/Multiply'
                                        */
};

/* Parameters (default storage) */
typedef struct P_ P;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P rtP;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void PID_MODEL_initialize(void);
extern void PID_MODEL_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PID_MODEL'
 * '<S1>'   : 'PID_MODEL/Pitch'
 * '<S2>'   : 'PID_MODEL/Yaw'
 * '<S3>'   : 'PID_MODEL/Pitch/If Action_speed Subsystem'
 * '<S4>'   : 'PID_MODEL/Pitch/If Action_speed Subsystem1'
 * '<S5>'   : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1'
 * '<S6>'   : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Anti-windup'
 * '<S7>'   : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/D Gain'
 * '<S8>'   : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Filter'
 * '<S9>'   : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Filter ICs'
 * '<S10>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/I Gain'
 * '<S11>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Ideal P Gain'
 * '<S12>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S13>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Integrator'
 * '<S14>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Integrator ICs'
 * '<S15>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/N Copy'
 * '<S16>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/N Gain'
 * '<S17>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/P Copy'
 * '<S18>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Parallel P Gain'
 * '<S19>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Reset Signal'
 * '<S20>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Saturation'
 * '<S21>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Saturation Fdbk'
 * '<S22>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Sum'
 * '<S23>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Sum Fdbk'
 * '<S24>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Tracking Mode'
 * '<S25>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Tracking Mode Sum'
 * '<S26>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Tsamp - Integral'
 * '<S27>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Tsamp - Ngain'
 * '<S28>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/postSat Signal'
 * '<S29>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/preSat Signal'
 * '<S30>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S31>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S32>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S33>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S34>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S35>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S36>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S37>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Integrator/Discrete'
 * '<S38>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S39>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/N Copy/Disabled'
 * '<S40>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/N Gain/Internal Parameters'
 * '<S41>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/P Copy/Disabled'
 * '<S42>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S43>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S44>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Saturation/Enabled'
 * '<S45>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S46>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Sum/Sum_PID'
 * '<S47>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S48>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S49>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S50>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S51>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S52>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S53>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S54>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Chart1'
 * '<S55>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Chart2'
 * '<S56>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller'
 * '<S57>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1'
 * '<S58>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Anti-windup'
 * '<S59>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/D Gain'
 * '<S60>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Filter'
 * '<S61>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Filter ICs'
 * '<S62>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/I Gain'
 * '<S63>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Ideal P Gain'
 * '<S64>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S65>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Integrator'
 * '<S66>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Integrator ICs'
 * '<S67>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/N Copy'
 * '<S68>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/N Gain'
 * '<S69>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/P Copy'
 * '<S70>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Parallel P Gain'
 * '<S71>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Reset Signal'
 * '<S72>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Saturation'
 * '<S73>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Saturation Fdbk'
 * '<S74>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Sum'
 * '<S75>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Sum Fdbk'
 * '<S76>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Tracking Mode'
 * '<S77>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Tracking Mode Sum'
 * '<S78>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Tsamp - Integral'
 * '<S79>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Tsamp - Ngain'
 * '<S80>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/postSat Signal'
 * '<S81>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/preSat Signal'
 * '<S82>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S83>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S84>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S85>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S86>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S87>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S88>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S89>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Integrator/Discrete'
 * '<S90>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S91>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/N Copy/Disabled'
 * '<S92>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S93>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/P Copy/Disabled'
 * '<S94>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S95>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Reset Signal/Disabled'
 * '<S96>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Saturation/Enabled'
 * '<S97>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S98>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Sum/Sum_PID'
 * '<S99>'  : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S100>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S101>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S102>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S103>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S104>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S105>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S106>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Anti-windup'
 * '<S107>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/D Gain'
 * '<S108>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Filter'
 * '<S109>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Filter ICs'
 * '<S110>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/I Gain'
 * '<S111>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Ideal P Gain'
 * '<S112>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S113>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Integrator'
 * '<S114>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Integrator ICs'
 * '<S115>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/N Copy'
 * '<S116>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/N Gain'
 * '<S117>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/P Copy'
 * '<S118>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Parallel P Gain'
 * '<S119>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Reset Signal'
 * '<S120>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Saturation'
 * '<S121>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Saturation Fdbk'
 * '<S122>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Sum'
 * '<S123>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Sum Fdbk'
 * '<S124>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Tracking Mode'
 * '<S125>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Tracking Mode Sum'
 * '<S126>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Tsamp - Integral'
 * '<S127>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Tsamp - Ngain'
 * '<S128>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/postSat Signal'
 * '<S129>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/preSat Signal'
 * '<S130>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S131>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S132>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S133>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S134>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S135>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S136>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S137>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Integrator/Discrete'
 * '<S138>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S139>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/N Copy/Disabled'
 * '<S140>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/N Gain/Internal Parameters'
 * '<S141>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/P Copy/Disabled'
 * '<S142>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S143>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S144>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Saturation/Enabled'
 * '<S145>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S146>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Sum/Sum_PID'
 * '<S147>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S148>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S149>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S150>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S151>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S152>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S153>' : 'PID_MODEL/Pitch/If Action_speed Subsystem1/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S154>' : 'PID_MODEL/Yaw/If Action_speed Subsystem'
 * '<S155>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1'
 * '<S156>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1'
 * '<S157>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Anti-windup'
 * '<S158>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/D Gain'
 * '<S159>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Filter'
 * '<S160>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Filter ICs'
 * '<S161>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/I Gain'
 * '<S162>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Ideal P Gain'
 * '<S163>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S164>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Integrator'
 * '<S165>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Integrator ICs'
 * '<S166>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/N Copy'
 * '<S167>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/N Gain'
 * '<S168>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/P Copy'
 * '<S169>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Parallel P Gain'
 * '<S170>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Reset Signal'
 * '<S171>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Saturation'
 * '<S172>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Saturation Fdbk'
 * '<S173>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Sum'
 * '<S174>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Sum Fdbk'
 * '<S175>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Tracking Mode'
 * '<S176>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Tracking Mode Sum'
 * '<S177>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Tsamp - Integral'
 * '<S178>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Tsamp - Ngain'
 * '<S179>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/postSat Signal'
 * '<S180>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/preSat Signal'
 * '<S181>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S182>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S183>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S184>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S185>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S186>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S187>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S188>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Integrator/Discrete'
 * '<S189>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S190>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/N Copy/Disabled'
 * '<S191>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/N Gain/Internal Parameters'
 * '<S192>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/P Copy/Disabled'
 * '<S193>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S194>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S195>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Saturation/Enabled'
 * '<S196>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S197>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Sum/Sum_PID'
 * '<S198>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S199>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S200>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S201>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S202>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S203>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S204>' : 'PID_MODEL/Yaw/If Action_speed Subsystem/Discrete PID Controller1/preSat Signal/Forward_Path'
 * '<S205>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Chart1'
 * '<S206>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Chart2'
 * '<S207>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller'
 * '<S208>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1'
 * '<S209>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Anti-windup'
 * '<S210>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/D Gain'
 * '<S211>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Filter'
 * '<S212>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Filter ICs'
 * '<S213>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/I Gain'
 * '<S214>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Ideal P Gain'
 * '<S215>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S216>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Integrator'
 * '<S217>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Integrator ICs'
 * '<S218>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/N Copy'
 * '<S219>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/N Gain'
 * '<S220>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/P Copy'
 * '<S221>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Parallel P Gain'
 * '<S222>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Reset Signal'
 * '<S223>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Saturation'
 * '<S224>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Saturation Fdbk'
 * '<S225>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Sum'
 * '<S226>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Sum Fdbk'
 * '<S227>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Tracking Mode'
 * '<S228>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Tracking Mode Sum'
 * '<S229>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Tsamp - Integral'
 * '<S230>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Tsamp - Ngain'
 * '<S231>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/postSat Signal'
 * '<S232>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/preSat Signal'
 * '<S233>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S234>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S235>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S236>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S237>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S238>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S239>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S240>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Integrator/Discrete'
 * '<S241>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S242>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/N Copy/Disabled'
 * '<S243>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S244>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/P Copy/Disabled'
 * '<S245>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S246>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Reset Signal/Disabled'
 * '<S247>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Saturation/Enabled'
 * '<S248>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S249>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Sum/Sum_PID'
 * '<S250>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S251>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S252>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S253>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S254>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S255>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S256>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S257>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Anti-windup'
 * '<S258>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/D Gain'
 * '<S259>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Filter'
 * '<S260>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Filter ICs'
 * '<S261>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/I Gain'
 * '<S262>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Ideal P Gain'
 * '<S263>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Ideal P Gain Fdbk'
 * '<S264>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Integrator'
 * '<S265>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Integrator ICs'
 * '<S266>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/N Copy'
 * '<S267>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/N Gain'
 * '<S268>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/P Copy'
 * '<S269>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Parallel P Gain'
 * '<S270>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Reset Signal'
 * '<S271>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Saturation'
 * '<S272>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Saturation Fdbk'
 * '<S273>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Sum'
 * '<S274>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Sum Fdbk'
 * '<S275>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Tracking Mode'
 * '<S276>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Tracking Mode Sum'
 * '<S277>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Tsamp - Integral'
 * '<S278>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Tsamp - Ngain'
 * '<S279>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/postSat Signal'
 * '<S280>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/preSat Signal'
 * '<S281>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Anti-windup/Passthrough'
 * '<S282>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/D Gain/Internal Parameters'
 * '<S283>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Filter/Disc. Forward Euler Filter'
 * '<S284>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Filter ICs/Internal IC - Filter'
 * '<S285>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/I Gain/Internal Parameters'
 * '<S286>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Ideal P Gain/Passthrough'
 * '<S287>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S288>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Integrator/Discrete'
 * '<S289>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Integrator ICs/Internal IC'
 * '<S290>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/N Copy/Disabled'
 * '<S291>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/N Gain/Internal Parameters'
 * '<S292>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/P Copy/Disabled'
 * '<S293>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Parallel P Gain/Internal Parameters'
 * '<S294>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Reset Signal/Disabled'
 * '<S295>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Saturation/Enabled'
 * '<S296>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Saturation Fdbk/Disabled'
 * '<S297>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Sum/Sum_PID'
 * '<S298>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Sum Fdbk/Disabled'
 * '<S299>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Tracking Mode/Disabled'
 * '<S300>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Tracking Mode Sum/Passthrough'
 * '<S301>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S302>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/Tsamp - Ngain/Passthrough'
 * '<S303>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/postSat Signal/Forward_Path'
 * '<S304>' : 'PID_MODEL/Yaw/If Action_speed Subsystem1/Discrete PID Controller1/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_PID_MODEL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
