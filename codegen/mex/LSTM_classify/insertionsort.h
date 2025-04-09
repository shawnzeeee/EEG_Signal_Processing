/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * insertionsort.h
 *
 * Code generation for function 'insertionsort'
 *
 */

#pragma once

/* Include files */
#include "LSTM_classify_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void insertionsort(const emlrtStack *sp, int32_T x_data[], int32_T xend,
                   const cell_wrap_5 cmp_workspace_c_data[],
                   int32_T cmp_workspace_c_size);

/* End of code generation (insertionsort.h) */
