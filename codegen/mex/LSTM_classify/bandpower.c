/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bandpower.c
 *
 * Code generation for function 'bandpower'
 *
 */

/* Include files */
#include "bandpower.h"
#include "LSTM_classify_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo gc_emlrtRSI =
    {
        125,            /* lineNo */
        "psdbandpower", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bandpower.m" /* pathName
                                                                       */
};

static emlrtRSInfo hc_emlrtRSI =
    {
        131,            /* lineNo */
        "psdbandpower", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bandpower.m" /* pathName
                                                                       */
};

static emlrtRSInfo ic_emlrtRSI =
    {
        152,            /* lineNo */
        "psdbandpower", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bandpower.m" /* pathName
                                                                       */
};

static emlrtRSInfo jc_emlrtRSI =
    {
        207,            /* lineNo */
        "psdbandpower", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bandpower.m" /* pathName
                                                                       */
};

static emlrtRTEInfo p_emlrtRTEI =
    {
        154,            /* lineNo */
        5,              /* colNo */
        "psdbandpower", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bandpower.m" /* pName
                                                                       */
};

static emlrtBCInfo e_emlrtBCI =
    {
        -1,             /* iFirst */
        -1,             /* iLast */
        161,            /* lineNo */
        12,             /* colNo */
        "",             /* aName */
        "psdbandpower", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bandpower.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtBCInfo f_emlrtBCI =
    {
        -1,             /* iFirst */
        -1,             /* iLast */
        163,            /* lineNo */
        12,             /* colNo */
        "",             /* aName */
        "psdbandpower", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bandpower.m", /* pName
                                                                        */
        0 /* checkKind */
};

static emlrtRTEInfo q_emlrtRTEI = {
    13,                   /* lineNo */
    37,                   /* colNo */
    "validateincreasing", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validateincreasing.m" /* pName */
};

/* Function Definitions */
real_T psdbandpower(const emlrtStack *sp, const real_T Pxx[257],
                    const real_T W[257], const real_T freqrange[2])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  real_T c_y1[257];
  real_T tmp_data[257];
  real_T b_y1[256];
  real_T pwr;
  int32_T i;
  int32_T idx;
  int32_T idx1;
  int32_T ii;
  int16_T ii_data;
  boolean_T x[257];
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &gb_emlrtRSI;
  p = true;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx < 257)) {
    if ((!muDoubleScalarIsInf(Pxx[idx])) && (!muDoubleScalarIsNaN(Pxx[idx]))) {
      idx++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &j_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:bandpower:expectedFinite", 3, 4, 20, "input number 1, Pxx,");
  }
  st.site = &hc_emlrtRSI;
  b_st.site = &gb_emlrtRSI;
  p = true;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx < 257)) {
    if ((!muDoubleScalarIsInf(W[idx])) && (!muDoubleScalarIsNaN(W[idx]))) {
      idx++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &j_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:bandpower:expectedFinite", 3, 4, 18, "input number 2, F,");
  }
  b_st.site = &gb_emlrtRSI;
  p = true;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx < 256)) {
    if (!(W[idx] < W[idx + 1])) {
      p = false;
      exitg1 = true;
    } else {
      idx++;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &q_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedIncreasing",
        "MATLAB:bandpower:expectedIncreasing", 3, 4, 18, "input number 2, F,");
  }
  st.site = &ic_emlrtRSI;
  b_st.site = &gb_emlrtRSI;
  p = true;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx < 2)) {
    if ((!muDoubleScalarIsInf(freqrange[idx])) &&
        (!muDoubleScalarIsNaN(freqrange[idx]))) {
      idx++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &j_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:bandpower:expectedFinite", 3, 4, 26,
        "input number 3, FREQRANGE,");
  }
  b_st.site = &gb_emlrtRSI;
  if (!(freqrange[0] < freqrange[1])) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &q_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedIncreasing",
        "MATLAB:bandpower:expectedIncreasing", 3, 4, 26,
        "input number 3, FREQRANGE,");
  }
  if ((freqrange[0] < W[0]) || (freqrange[1] > W[256])) {
    emlrtErrorWithMessageIdR2018a(sp, &p_emlrtRTEI,
                                  "signal:bandpower:FreqRangeOutOfBounds",
                                  "signal:bandpower:FreqRangeOutOfBounds", 0);
  }
  for (i = 0; i < 257; i++) {
    x[i] = (W[i] <= freqrange[0]);
  }
  idx = 0;
  ii = 257;
  exitg1 = false;
  while ((!exitg1) && (ii > 0)) {
    if (x[ii - 1]) {
      idx = 1;
      ii_data = (int16_T)ii;
      exitg1 = true;
    } else {
      ii--;
    }
  }
  if (idx == 0) {
    emlrtDynamicBoundsCheckR2012b(1, 1, 0, &e_emlrtBCI, (emlrtConstCTX)sp);
  }
  idx1 = ii_data;
  for (i = 0; i < 257; i++) {
    x[i] = (W[i] >= freqrange[1]);
  }
  idx = 0;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 257)) {
    if (x[ii]) {
      idx = 1;
      ii_data = (int16_T)(ii + 1);
      exitg1 = true;
    } else {
      ii++;
    }
  }
  if (idx == 0) {
    emlrtDynamicBoundsCheckR2012b(1, 1, 0, &f_emlrtBCI, (emlrtConstCTX)sp);
  }
  pwr = W[0];
  for (idx = 0; idx < 256; idx++) {
    real_T tmp2;
    tmp2 = pwr;
    pwr = W[idx + 1];
    b_y1[idx] = pwr - tmp2;
  }
  if (idx1 > ii_data) {
    idx1 = 1;
    i = 0;
    idx = 1;
  } else {
    i = ii_data;
    idx = idx1;
  }
  memcpy(&c_y1[0], &b_y1[0], 256U * sizeof(real_T));
  c_y1[256] = 0.0;
  ii = i - idx1;
  for (i = 0; i <= ii; i++) {
    tmp_data[i] = c_y1[(idx1 + i) - 1];
  }
  st.site = &jc_emlrtRSI;
  for (i = 0; i <= ii; i++) {
    c_y1[i] = Pxx[(idx + i) - 1];
  }
  if (ii + 1 < 1) {
    pwr = 0.0;
  } else {
    n_t = (ptrdiff_t)(ii + 1);
    incx_t = (ptrdiff_t)1;
    incy_t = (ptrdiff_t)1;
    pwr = ddot(&n_t, &tmp_data[0], &incx_t, &c_y1[0], &incy_t);
  }
  return pwr;
}

/* End of code generation (bandpower.c) */
