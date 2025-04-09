/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * getCodes.h
 *
 * Code generation for function 'getCodes'
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
uint32_T categorical_getCodes(const emlrtStack *sp, const cell_wrap_5 inputData,
                              const cell_wrap_5 valueSet_data[],
                              int32_T valueSet_size);

/* End of code generation (getCodes.h) */
