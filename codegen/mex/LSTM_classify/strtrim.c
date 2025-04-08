/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * strtrim.c
 *
 * Code generation for function 'strtrim'
 *
 */

/* Include files */
#include "strtrim.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo wd_emlrtRSI = {
    23,        /* lineNo */
    "strtrim", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\strfun\\strtrim.m" /* pathName
                                                                           */
};

static emlrtRSInfo xd_emlrtRSI = {
    24,        /* lineNo */
    "strtrim", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\strfun\\strtrim.m" /* pathName
                                                                           */
};

static emlrtRSInfo yd_emlrtRSI = {
    32,         /* lineNo */
    "firstcol", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\strfun\\strtrim.m" /* pathName
                                                                           */
};

static emlrtRSInfo ae_emlrtRSI = {
    51,          /* lineNo */
    "allwspace", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\strfun\\strtrim.m" /* pathName
                                                                           */
};

static emlrtRSInfo
    be_emlrtRSI =
        {
            15,          /* lineNo */
            "isstrprop", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\strfun\\isstrpro"
            "p.m" /* pathName */
};

static emlrtRSInfo
    ce_emlrtRSI =
        {
            23,                         /* lineNo */
            "apply_property_predicate", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\strfun\\isstrpro"
            "p.m" /* pathName */
};

static emlrtRSInfo de_emlrtRSI = {
    41,        /* lineNo */
    "lastcol", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\strfun\\strtrim.m" /* pathName
                                                                           */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    15,                      /* lineNo */
    9,                       /* colNo */
    "assertSupportedString", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\assertSupportedString.m" /* pName */
};

/* Function Definitions */
void strtrim(const emlrtStack *sp, const char_T x_data[],
             const int32_T x_size[2], char_T y_data[], int32_T y_size[2])
{
  static const boolean_T bv[128] = {
      false, false, false, false, false, false, false, false, false, true,
      true,  true,  true,  true,  false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, true,  true,
      true,  true,  true,  false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T b_j1;
  int32_T i;
  int32_T j2;
  char_T x;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &wd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_j1 = 0;
  exitg1 = false;
  while ((!exitg1) && (b_j1 + 1 <= x_size[1])) {
    b_st.site = &yd_emlrtRSI;
    c_st.site = &ae_emlrtRSI;
    x = x_data[b_j1];
    d_st.site = &be_emlrtRSI;
    e_st.site = &ce_emlrtRSI;
    if ((uint8_T)x > 127) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &ab_emlrtRTEI, "Coder:toolbox:unsupportedString",
          "Coder:toolbox:unsupportedString", 2, 12, 127);
    }
    if ((!bv[(int32_T)((uint8_T)x & 127U)]) || (x_data[b_j1] == '\x00')) {
      p = false;
    } else {
      p = true;
    }
    if (p) {
      b_j1++;
    } else {
      exitg1 = true;
    }
  }
  st.site = &xd_emlrtRSI;
  j2 = x_size[1] - 1;
  exitg1 = false;
  while ((!exitg1) && (j2 + 1 > 0)) {
    b_st.site = &de_emlrtRSI;
    c_st.site = &ae_emlrtRSI;
    x = x_data[j2];
    d_st.site = &be_emlrtRSI;
    e_st.site = &ce_emlrtRSI;
    if ((uint8_T)x > 127) {
      emlrtErrorWithMessageIdR2018a(
          &e_st, &ab_emlrtRTEI, "Coder:toolbox:unsupportedString",
          "Coder:toolbox:unsupportedString", 2, 12, 127);
    }
    if ((!bv[(int32_T)((uint8_T)x & 127U)]) || (x_data[j2] == '\x00')) {
      p = false;
    } else {
      p = true;
    }
    if (p) {
      j2--;
    } else {
      exitg1 = true;
    }
  }
  if (b_j1 + 1 > j2 + 1) {
    b_j1 = 0;
    j2 = -1;
  }
  y_size[0] = 1;
  j2 -= b_j1;
  y_size[1] = j2 + 1;
  for (i = 0; i <= j2; i++) {
    y_data[i] = x_data[b_j1 + i];
  }
}

/* End of code generation (strtrim.c) */
