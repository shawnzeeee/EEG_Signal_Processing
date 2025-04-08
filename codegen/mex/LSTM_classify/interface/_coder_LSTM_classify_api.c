/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_LSTM_classify_api.c
 *
 * Code generation for function '_coder_LSTM_classify_api'
 *
 */

/* Include files */
#include "_coder_LSTM_classify_api.h"
#include "LSTM_classify.h"
#include "LSTM_classify_data.h"
#include "LSTM_classify_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2000];

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2000];

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier))[2000];

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const categorical *u);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2000]
{
  real_T(*y)[2000];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2000]
{
  static const int32_T dims[2] = {500, 4};
  real_T(*ret)[2000];
  int32_T iv[2];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret = (real_T(*)[2000])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier))[2000]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[2000];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const categorical *u)
{
  const mxArray *propValues[5];
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *m;
  const mxArray *m1;
  const mxArray *m2;
  const mxArray *m3;
  const mxArray *m4;
  const mxArray *m5;
  const mxArray *y;
  int32_T iv[2];
  int32_T i;
  const char_T *propClasses[5] = {
      "matlab.internal.coder.categorical", "matlab.internal.coder.categorical",
      "matlab.internal.coder.categorical", "matlab.internal.coder.categorical",
      "matlab.internal.coder.categorical"};
  const char_T *propNames[5] = {"codes", "categoryNames", "isProtected",
                                "isOrdinal", "numCategoriesUpperBound"};
  y = NULL;
  m = NULL;
  m1 = NULL;
  m2 = NULL;
  m3 = NULL;
  m4 = NULL;
  emlrtAssign(&y, emlrtCreateClassInstance2022a(
                      (emlrtCTX)sp, "matlab.internal.coder.categorical"));
  m = NULL;
  b_y = NULL;
  m5 = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(uint32_T *)emlrtMxGetData(m5) = u->codes;
  emlrtAssign(&b_y, m5);
  emlrtAssign(&m, b_y);
  propValues[0] = m;
  m1 = NULL;
  c_y = NULL;
  emlrtAssign(&c_y, emlrtCreateCellArrayR2014a(1, &u->categoryNames.size[0]));
  if (u->categoryNames.size[0] > 0) {
    iv[0] = 1;
  }
  for (i = 0; i < u->categoryNames.size[0]; i++) {
    int32_T i1;
    d_y = NULL;
    i1 = u->categoryNames.data[i].f1.size[1];
    iv[1] = i1;
    m5 = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtConstCTX)sp, i1, m5,
                             &u->categoryNames.data[i].f1.data[0]);
    emlrtAssign(&d_y, m5);
    emlrtSetCell(c_y, i, d_y);
  }
  emlrtAssign(&m1, c_y);
  propValues[1] = m1;
  m2 = NULL;
  e_y = NULL;
  m5 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&e_y, m5);
  emlrtAssign(&m2, e_y);
  propValues[2] = m2;
  m3 = NULL;
  f_y = NULL;
  m5 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&f_y, m5);
  emlrtAssign(&m3, f_y);
  propValues[3] = m3;
  m4 = NULL;
  g_y = NULL;
  m5 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m5) = 2147483646;
  emlrtAssign(&g_y, m5);
  emlrtAssign(&m4, g_y);
  propValues[4] = m4;
  emlrtSetAllProperties((emlrtCTX)sp, &y, 0, 5, (const char_T **)&propNames[0],
                        (const char_T **)&propClasses[0], &propValues[0]);
  emlrtAssign(&y, emlrtConvertInstanceToRedirectSource(
                      (emlrtCTX)sp, y, 0, "matlab.internal.coder.categorical"));
  return y;
}

void LSTM_classify_api(const mxArray *prhs, const mxArray **plhs)
{
  categorical out;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*inputWindow)[2000];
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  inputWindow = emlrt_marshallIn(&st, emlrtAlias(prhs), "inputWindow");
  /* Invoke the target function */
  LSTM_classify(&st, *inputWindow, &out);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(&st, &out);
}

/* End of code generation (_coder_LSTM_classify_api.c) */
