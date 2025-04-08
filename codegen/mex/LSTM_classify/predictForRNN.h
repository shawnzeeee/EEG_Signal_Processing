/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * predictForRNN.h
 *
 * Code generation for function 'predictForRNN'
 *
 */

#pragma once

/* Include files */
#include "LSTM_classify_internal_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void c_DeepLearningNetwork_predictFo(const emlrtStack *sp,
                                     c_coder_internal_ctarget_DeepLe *obj,
                                     const cell_wrap_32 *inputs,
                                     real32_T outputData[11]);

/* End of code generation (predictForRNN.h) */
