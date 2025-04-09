/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LSTM_classify.h
 *
 * Code generation for function 'LSTM_classify'
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
void LSTM_classify(const emlrtStack *sp, const real_T inputWindow[2000],
                   categorical *out);

void LSTM_classify_delete(void);

void LSTM_classify_init(void);

void LSTM_classify_new(void);

emlrtCTX emlrtGetRootTLSGlobal(void);

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

/* End of code generation (LSTM_classify.h) */
