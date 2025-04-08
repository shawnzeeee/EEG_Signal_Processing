/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * predict.h
 *
 * Code generation for function 'predict'
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
void DeepLearningNetwork_predict(const emlrtStack *sp,
                                 c_coder_internal_ctarget_DeepLe *obj,
                                 const real_T varargin_1[80],
                                 real32_T varargout_1[11]);

/* End of code generation (predict.h) */
