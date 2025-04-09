/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * elementwiseOperationInPlace.h
 *
 * Code generation for function 'elementwiseOperationInPlace'
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
void b_lambdaForColumnMajorGeneric(real32_T *X);

void c_lambdaForColumnMajorGeneric(const emlrtStack *sp, real32_T X[32]);

void d_lambdaForColumnMajorGeneric(const emlrtStack *sp, real32_T X[11]);

void lambdaForColumnMajorGeneric(real32_T *X);

/* End of code generation (elementwiseOperationInPlace.h) */
