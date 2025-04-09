/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * addBiasApplyActivation.h
 *
 * Code generation for function 'addBiasApplyActivation'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void addBiasApplyActivation(const emlrtStack *sp, real32_T X[96],
                            const real32_T bias[96]);

void b_addBiasApplyActivation(const emlrtStack *sp, real32_T X[96],
                              const real32_T bias[96]);

void c_addBiasApplyActivation(const emlrtStack *sp, real32_T X[32],
                              const real32_T bias[32]);

void d_addBiasApplyActivation(const emlrtStack *sp, real32_T X[32],
                              const real32_T bias[32]);

void e_addBiasApplyActivation(const emlrtStack *sp, real32_T X[11],
                              const real32_T bias[11]);

/* End of code generation (addBiasApplyActivation.h) */
