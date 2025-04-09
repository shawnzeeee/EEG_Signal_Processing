/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeperiodogram.c
 *
 * Code generation for function 'computeperiodogram'
 *
 */

/* Include files */
#include "computeperiodogram.h"
#include "LSTM_classify_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo pb_emlrtRSI = {
    64,                   /* lineNo */
    "computeperiodogram", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\computeperiodogra"
    "m.m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI = {
    67,                   /* lineNo */
    "computeperiodogram", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\computeperiodogra"
    "m.m" /* pathName */
};

static emlrtRSInfo rb_emlrtRSI = {
    73,                   /* lineNo */
    "computeperiodogram", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\computeperiodogra"
    "m.m" /* pathName */
};

static emlrtRSInfo sb_emlrtRSI = {
    107,                  /* lineNo */
    "computeperiodogram", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\computeperiodogra"
    "m.m" /* pathName */
};

static emlrtRSInfo tb_emlrtRSI = {
    157,              /* lineNo */
    "validateinputs", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\computeperiodogra"
    "m.m" /* pathName */
};

static emlrtRSInfo
    ub_emlrtRSI =
        {
            45,           /* lineNo */
            "computeDFT", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\computeDF"
            "T.m" /* pathName */
};

static emlrtRSInfo
    vb_emlrtRSI =
        {
            91,                 /* lineNo */
            "computeDFTviaFFT", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\computeDF"
            "T.m" /* pathName */
};

static emlrtRSInfo ec_emlrtRSI =
    {
        69,                  /* lineNo */
        "eml_mtimes_helper", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_"
        "helper.m" /* pathName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    37,    /* lineNo */
    31,    /* colNo */
    "fft", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\fft.m" /* pName
                                                                        */
};

static emlrtRTEInfo l_emlrtRTEI = {
    53,       /* lineNo */
    15,       /* colNo */
    "bsxfun", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\bsxfun.m" /* pName
                                                                         */
};

static emlrtRTEInfo m_emlrtRTEI = {
    173,              /* lineNo */
    1,                /* colNo */
    "validateinputs", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\computeperiodogra"
    "m.m" /* pName */
};

static emlrtRTEInfo n_emlrtRTEI = {
    171,              /* lineNo */
    34,               /* colNo */
    "validateinputs", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\computeperiodogra"
    "m.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    158,              /* lineNo */
    1,                /* colNo */
    "validateinputs", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\computeperiodogra"
    "m.m" /* pName */
};

/* Function Definitions */
void computeperiodogram(const emlrtStack *sp, const real_T x_data[],
                        int32_T x_size, const real_T win_data[],
                        int32_T win_size, real_T Pxx[512])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  creal_T Xx[512];
  real_T xw_data[65];
  real_T y;
  int32_T bcoef;
  int32_T i;
  int32_T k;
  int8_T csz_idx_0;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &tb_emlrtRSI;
  c_st.site = &gb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= x_size - 1)) {
    if ((!muDoubleScalarIsInf(x_data[k])) &&
        (!muDoubleScalarIsNaN(x_data[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &j_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:periodogram:expectedFinite", 3, 4, 1, "x");
  }
  c_st.site = &gb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= x_size - 1)) {
    if (!muDoubleScalarIsNaN(x_data[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &i_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:periodogram:expectedNonNaN", 3, 4, 1, "x");
  }
  if (x_size == 1) {
    emlrtErrorWithMessageIdR2018a(
        &st, &o_emlrtRTEI, "signal:computeperiodogram:NDMatrixUnsupported",
        "signal:computeperiodogram:NDMatrixUnsupported", 0);
  }
  if (x_size != win_size) {
    emlrtErrorWithMessageIdR2018a(
        &st, &n_emlrtRTEI, "signal:computeperiodogram:invalidWindow",
        "signal:computeperiodogram:invalidWindow", 3, 4, 6, "window");
  }
  if (x_size < 2) {
    emlrtErrorWithMessageIdR2018a(
        &st, &m_emlrtRTEI, "signal:computeperiodogram:NDMatrixUnsupported",
        "signal:computeperiodogram:NDMatrixUnsupported", 0);
  }
  st.site = &qb_emlrtRSI;
  if (win_size == 1) {
    csz_idx_0 = (int8_T)x_size;
  } else if (x_size == win_size) {
    csz_idx_0 = (int8_T)x_size;
  } else {
    emlrtErrorWithMessageIdR2018a(&st, &l_emlrtRTEI,
                                  "MATLAB:bsxfun:arrayDimensionsMustMatch",
                                  "MATLAB:bsxfun:arrayDimensionsMustMatch", 0);
  }
  i = csz_idx_0;
  bcoef = (win_size != 1);
  for (k = 0; k < i; k++) {
    xw_data[k] = x_data[k] * win_data[bcoef * k];
  }
  st.site = &rb_emlrtRSI;
  b_st.site = &ub_emlrtRSI;
  c_st.site = &vb_emlrtRSI;
  if (csz_idx_0 == 1) {
    emlrtErrorWithMessageIdR2018a(&c_st, &k_emlrtRTEI,
                                  "Coder:toolbox:autoDimIncompatibility",
                                  "Coder:toolbox:autoDimIncompatibility", 0);
  }
  emlrtFFTWSetNumThreads(4);
  emlrtFFTW_1D_R2C(&xw_data[0], (real_T *)&Xx[0], 1, 512, csz_idx_0, 1, -1);
  st.site = &sb_emlrtRSI;
  b_st.site = &ec_emlrtRSI;
  n_t = (ptrdiff_t)win_size;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  y = ddot(&n_t, (real_T *)&win_data[0], &incx_t, (real_T *)&win_data[0],
           &incy_t);
  for (i = 0; i < 512; i++) {
    real_T Xx_im_tmp;
    real_T Xx_re;
    real_T Xx_re_tmp;
    Xx_re_tmp = Xx[i].re;
    Xx_im_tmp = Xx[i].im;
    Xx_re = Xx_re_tmp * Xx_re_tmp - Xx_im_tmp * -Xx_im_tmp;
    if (Xx_re_tmp * -Xx_im_tmp + Xx_im_tmp * Xx_re_tmp == 0.0) {
      Xx_re /= y;
    } else if (Xx_re == 0.0) {
      Xx_re = 0.0;
    } else {
      Xx_re /= y;
    }
    Pxx[i] = Xx_re;
  }
}

/* End of code generation (computeperiodogram.c) */
