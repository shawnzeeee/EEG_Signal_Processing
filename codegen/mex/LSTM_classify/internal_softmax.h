/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * internal_softmax.h
 *
 * Code generation for function 'internal_softmax'
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
void iComputeSoftmaxForCpu(const emlrtStack *sp, const real32_T xdata[11],
                           real32_T ydata[11]);

/* End of code generation (internal_softmax.h) */
