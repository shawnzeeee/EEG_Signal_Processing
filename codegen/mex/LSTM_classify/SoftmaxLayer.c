/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SoftmaxLayer.c
 *
 * Code generation for function 'SoftmaxLayer'
 *
 */

/* Include files */
#include "SoftmaxLayer.h"
#include "internal_softmax.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo pf_emlrtRSI = {
    66,                 /* lineNo */
    "internal_softmax", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\nnet\\deepcoder\\+deep\\+internal\\+"
    "coder\\+dlarray\\internal_softmax.m" /* pathName */
};

/* Function Definitions */
void SoftmaxLayer_predict(const emlrtStack *sp, const real32_T X1_Data[11],
                          real32_T Z1_Data[11])
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pf_emlrtRSI;
  iComputeSoftmaxForCpu(&st, X1_Data, Z1_Data);
}

/* End of code generation (SoftmaxLayer.c) */
