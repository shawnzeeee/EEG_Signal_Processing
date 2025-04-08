/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeperiodogram.h
 *
 * Code generation for function 'computeperiodogram'
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
void computeperiodogram(const emlrtStack *sp, const real_T x_data[],
                        int32_T x_size, const real_T win_data[],
                        int32_T win_size, real_T Pxx[512]);

/* End of code generation (computeperiodogram.h) */
