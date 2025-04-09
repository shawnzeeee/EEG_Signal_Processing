/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * postProcessOutputToReturnCategorical.c
 *
 * Code generation for function 'postProcessOutputToReturnCategorical'
 *
 */

/* Include files */
#include "postProcessOutputToReturnCategorical.h"
#include "LSTM_classify_internal_types.h"
#include "LSTM_classify_types.h"
#include "categorical.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo pd_emlrtRSI = {
    1,                                                          /* lineNo */
    "DeepLearningNetwork/postProcessOutputToReturnCategorical", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024b\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\@DeepLearningNetwork\\postProcessOutputToReturnCategorical.p" /* pathName
                                                                            */
};

static emlrtECInfo b_emlrtECI = {
    2,                                                          /* nDims */
    1,                                                          /* lineNo */
    1,                                                          /* colNo */
    "DeepLearningNetwork/postProcessOutputToReturnCategorical", /* fName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024b\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\@DeepLearningNetwork\\postProcessOutputToReturnCategorical.p" /* pName
                                                                            */
};

static emlrtBCInfo
    g_emlrtBCI =
        {
            -1, /* iFirst */
            -1, /* iLast */
            1,  /* lineNo */
            1,  /* colNo */
            "", /* aName */
            "DeepLearningNetwork/postProcessOutputToReturnCategorical", /* fName
                                                                         */
            "C:"
            "\\ProgramData\\MATLAB\\SupportPackages\\R2024b\\toolbox\\shared\\d"
            "lcoder_base\\supportpackages\\shared_dl_targets\\+coder\\+in"
            "ternal\\@"
            "DeepLearningNetwork\\postProcessOutputToReturnCategorical.p", /* pName
                                                                            */
            0 /* checkKind */
};

static emlrtRTEInfo
    t_emlrtRTEI =
        {
            20,         /* lineNo */
            9,          /* colNo */
            "nonzeros", /* fName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\sparfun\\nonzero"
            "s.m" /* pName */
};

/* Function Definitions */
uint32_T
c_DeepLearningNetwork_postProce(const emlrtStack *sp, const cell_wrap_55 scores,
                                cell_wrap_5 c_processedOutput_0_categoryNam[],
                                int32_T *d_processedOutput_0_categoryNam)
{
  static const char_T classNames[22] = {
      '1',    '2',    '3',    '4',    '5',    '6',    '7',    '8',
      '9',    '1',    '1',    '\x00', '\x00', '\x00', '\x00', '\x00',
      '\x00', '\x00', '\x00', '\x00', '0',    '1'};
  cell_wrap_5 predictedClassNames;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_cell_wrap_5_1x11 labelsCells;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  int32_T idx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &pd_emlrtRSI;
  if (!muSingleScalarIsNaN(scores.f1[0])) {
    idx = 1;
  } else {
    boolean_T exitg1;
    idx = 0;
    i = 2;
    exitg1 = false;
    while ((!exitg1) && (i < 12)) {
      if (!muSingleScalarIsNaN(scores.f1[i - 1])) {
        idx = i;
        exitg1 = true;
      } else {
        i++;
      }
    }
  }
  if (idx == 0) {
    idx = 1;
  } else {
    real32_T ex;
    ex = scores.f1[idx - 1];
    b_i = idx + 1;
    for (i = b_i; i < 12; i++) {
      real32_T f;
      f = scores.f1[i - 1];
      if (ex < f) {
        ex = f;
        idx = i;
      }
    }
  }
  labelsCells.size[1] = 0;
  labelsCells.size[0] = 1;
  for (c_i = 0; c_i < 11; c_i++) {
    int32_T n;
    char_T v_data[2];
    char_T s_idx_0;
    char_T s_idx_1;
    c_st.site = &pd_emlrtRSI;
    n = 0;
    s_idx_1 = classNames[c_i];
    s_idx_0 = s_idx_1;
    if (s_idx_1 != 0) {
      n = 1;
    }
    s_idx_1 = classNames[c_i + 11];
    if (s_idx_1 != 0) {
      n++;
    }
    i = 0;
    if (s_idx_0 != 0) {
      i = 1;
      if (n < 1) {
        emlrtErrorWithMessageIdR2018a(&c_st, &t_emlrtRTEI,
                                      "Coder:builtins:AssertionFailed",
                                      "Coder:builtins:AssertionFailed", 0);
      }
      v_data[0] = s_idx_0;
    }
    if (s_idx_1 != 0) {
      i++;
      if (i > n) {
        emlrtErrorWithMessageIdR2018a(&c_st, &t_emlrtRTEI,
                                      "Coder:builtins:AssertionFailed",
                                      "Coder:builtins:AssertionFailed", 0);
      }
      v_data[i - 1] = s_idx_1;
    }
    i = labelsCells.size[1] + 1;
    if (labelsCells.size[1] + 1 > 11) {
      emlrtDimSizeGeqCheckR2012b(11, 12, &b_emlrtECI, &b_st);
    }
    labelsCells.size[1]++;
    labelsCells.data[i - 1].f1.size[0] = 1;
    b_i = labelsCells.size[1] - 1;
    labelsCells.data[labelsCells.size[1] - 1].f1.size[1] = n;
    for (i = 0; i < n; i++) {
      labelsCells.data[b_i].f1.data[i] = v_data[i];
    }
  }
  if (idx - 1 > labelsCells.size[1] - 1) {
    emlrtDynamicBoundsCheckR2012b(idx - 1, 0, labelsCells.size[1] - 1,
                                  &g_emlrtBCI, &b_st);
  }
  predictedClassNames.f1.size[0] = 1;
  i = labelsCells.data[idx - 1].f1.size[1];
  predictedClassNames.f1.size[1] = i;
  for (b_i = 0; b_i < i; b_i++) {
    predictedClassNames.f1.data[b_i] = labelsCells.data[idx - 1].f1.data[b_i];
  }
  c_st.site = &pd_emlrtRSI;
  return categorical_categorical(
      &c_st, predictedClassNames, labelsCells.data, labelsCells.size,
      c_processedOutput_0_categoryNam, d_processedOutput_0_categoryNam);
}

/* End of code generation (postProcessOutputToReturnCategorical.c) */
