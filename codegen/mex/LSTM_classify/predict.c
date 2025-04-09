/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * predict.c
 *
 * Code generation for function 'predict'
 *
 */

/* Include files */
#include "predict.h"
#include "LSTM_classify_internal_types.h"
#include "predictForRNN.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo pc_emlrtRSI = {
    1,                             /* lineNo */
    "DeepLearningNetwork/predict", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024b\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\@DeepLearningNetwork\\predict.p" /* pathName */
};

/* Function Definitions */
void DeepLearningNetwork_predict(const emlrtStack *sp,
                                 c_coder_internal_ctarget_DeepLe *obj,
                                 const real_T varargin_1[80],
                                 real32_T varargout_1[11])
{
  cell_wrap_32 r;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  memcpy(&r.f1[0], &varargin_1[0], 80U * sizeof(real_T));
  st.site = &pc_emlrtRSI;
  c_DeepLearningNetwork_predictFo(&st, obj, &r, varargout_1);
}

/* End of code generation (predict.c) */
