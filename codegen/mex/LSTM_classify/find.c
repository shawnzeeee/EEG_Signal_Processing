/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find.c
 *
 * Code generation for function 'find'
 *
 */

/* Include files */
#include "find.h"
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo bf_emlrtRSI = {
    138,        /* lineNo */
    "eml_find", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pathName
                                                                       */
};

static emlrtRSInfo cf_emlrtRSI = {
    396,                  /* lineNo */
    "find_first_indices", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pathName
                                                                       */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    386,                  /* lineNo */
    1,                    /* colNo */
    "find_first_indices", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pName
                                                                       */
};

/* Function Definitions */
int32_T eml_find(const emlrtStack *sp, const boolean_T x_data[], int32_T x_size,
                 int32_T i_data[])
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i_size;
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  idx = 0;
  i_size = x_size;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= x_size - 1)) {
    if (x_data[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= x_size) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (idx > x_size) {
    emlrtErrorWithMessageIdR2018a(&st, &cb_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (x_size == 1) {
    if (idx == 0) {
      i_size = 0;
    }
  } else {
    int32_T iv[2];
    if (idx < 1) {
      i_size = 0;
    } else {
      i_size = idx;
    }
    iv[0] = 1;
    iv[1] = i_size;
    b_st.site = &cf_emlrtRSI;
    indexShapeCheck(&b_st, x_size, iv);
  }
  return i_size;
}

/* End of code generation (find.c) */
