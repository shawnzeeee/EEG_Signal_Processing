/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * categorical.h
 *
 * Code generation for function 'categorical'
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
uint32_T categorical_categorical(const emlrtStack *sp,
                                 const cell_wrap_5 inputData,
                                 const cell_wrap_5 varargin_1_data[],
                                 const int32_T varargin_1_size[2],
                                 cell_wrap_5 b_categoryNames_data[],
                                 int32_T *b_categoryNames_size);

/* End of code generation (categorical.h) */
