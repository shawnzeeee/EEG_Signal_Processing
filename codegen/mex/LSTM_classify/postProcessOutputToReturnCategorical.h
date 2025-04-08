/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * postProcessOutputToReturnCategorical.h
 *
 * Code generation for function 'postProcessOutputToReturnCategorical'
 *
 */

#pragma once

/* Include files */
#include "LSTM_classify_internal_types.h"
#include "LSTM_classify_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
uint32_T
c_DeepLearningNetwork_postProce(const emlrtStack *sp, const cell_wrap_55 scores,
                                cell_wrap_5 c_processedOutput_0_categoryNam[],
                                int32_T *d_processedOutput_0_categoryNam);

/* End of code generation (postProcessOutputToReturnCategorical.h) */
