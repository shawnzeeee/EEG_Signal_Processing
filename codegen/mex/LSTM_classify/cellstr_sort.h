/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cellstr_sort.h
 *
 * Code generation for function 'cellstr_sort'
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
int32_T cellstr_sort(const emlrtStack *sp, const cell_wrap_5 c_data[],
                     int32_T c_size, cell_wrap_5 sorted_data[],
                     int32_T idx_data[], int32_T *idx_size);

/* End of code generation (cellstr_sort.h) */
