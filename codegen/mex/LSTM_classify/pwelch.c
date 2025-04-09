/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pwelch.c
 *
 * Code generation for function 'pwelch'
 *
 */

/* Include files */
#include "pwelch.h"
#include "LSTM_classify_data.h"
#include "LSTM_classify_emxutil.h"
#include "LSTM_classify_types.h"
#include "computeperiodogram.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <math.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo w_emlrtRSI = {
    160,      /* lineNo */
    "pwelch", /* fcnName */
    "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\pwelch.m" /* pathName
                                                                            */
};

static emlrtRSInfo x_emlrtRSI = {
    56,      /* lineNo */
    "welch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\welch.m" /* pathName
                                                                        */
};

static emlrtRSInfo y_emlrtRSI = {
    108,     /* lineNo */
    "welch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\welch.m" /* pathName
                                                                        */
};

static emlrtRSInfo ab_emlrtRSI = {
    133,     /* lineNo */
    "welch", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\welch.m" /* pathName
                                                                        */
};

static emlrtRSInfo bb_emlrtRSI = {
    171,          /* lineNo */
    "welchparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\+signal\\+internal\\+"
    "spectral\\welchparse.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    168,          /* lineNo */
    "welchparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\+signal\\+internal\\+"
    "spectral\\welchparse.m" /* pathName */
};

static emlrtRSInfo db_emlrtRSI = {
    145,          /* lineNo */
    "welchparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\+signal\\+internal\\+"
    "spectral\\welchparse.m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    67,           /* lineNo */
    "welchparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\+signal\\+internal\\+"
    "spectral\\welchparse.m" /* pathName */
};

static emlrtRSInfo fb_emlrtRSI = {
    65,           /* lineNo */
    "welchparse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\+signal\\+internal\\+"
    "spectral\\welchparse.m" /* pathName */
};

static emlrtRSInfo lb_emlrtRSI =
    {
        125,     /* lineNo */
        "colon", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pathName
                                                                          */
};

static emlrtRSInfo mb_emlrtRSI =
    {
        319,               /* lineNo */
        "eml_float_colon", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pathName
                                                                          */
};

static emlrtRSInfo nb_emlrtRSI = {
    385,                   /* lineNo */
    "localComputeSpectra", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\welch.m" /* pathName
                                                                        */
};

static emlrtRSInfo ob_emlrtRSI = {
    392,                   /* lineNo */
    "localComputeSpectra", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\welch.m" /* pathName
                                                                        */
};

static emlrtRTEInfo c_emlrtRTEI = {
    121,          /* lineNo */
    9,            /* colNo */
    "welchparse", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\+signal\\+internal\\+"
    "spectral\\welchparse.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    240,           /* lineNo */
    1,             /* colNo */
    "segmentInfo", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\+signal\\+internal\\+"
    "spectral\\welchparse.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    241,           /* lineNo */
    1,             /* colNo */
    "segmentInfo", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\+signal\\+internal\\+"
    "spectral\\welchparse.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                    /* iFirst */
    -1,                    /* iLast */
    385,                   /* lineNo */
    44,                    /* colNo */
    "",                    /* aName */
    "localComputeSpectra", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\welch.m", /* pName
                                                                         */
    0 /* checkKind */
};

static emlrtRTEInfo g_emlrtRTEI = {
    391,                   /* lineNo */
    18,                    /* colNo */
    "localComputeSpectra", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\welch.m" /* pName
                                                                        */
};

static emlrtRTEInfo h_emlrtRTEI =
    {
        419,               /* lineNo */
        15,                /* colNo */
        "assert_pmaxsize", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pName
                                                                          */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                    /* iFirst */
    -1,                    /* iLast */
    385,                   /* lineNo */
    37,                    /* colNo */
    "",                    /* aName */
    "localComputeSpectra", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\welch.m", /* pName
                                                                         */
    0 /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    385,                   /* lineNo */
    37,                    /* colNo */
    "localComputeSpectra", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\welch.m", /* pName
                                                                         */
    1 /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                    /* iFirst */
    -1,                    /* iLast */
    392,                   /* lineNo */
    52,                    /* colNo */
    "",                    /* aName */
    "localComputeSpectra", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\welch.m", /* pName
                                                                         */
    0 /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                    /* iFirst */
    -1,                    /* iLast */
    392,                   /* lineNo */
    45,                    /* colNo */
    "",                    /* aName */
    "localComputeSpectra", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\welch.m", /* pName
                                                                         */
    0 /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    392,                   /* lineNo */
    45,                    /* colNo */
    "localComputeSpectra", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\welch.m", /* pName
                                                                         */
    1 /* checkKind */
};

static emlrtRTEInfo fb_emlrtRTEI = {
    108,     /* lineNo */
    5,       /* colNo */
    "welch", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\welch.m" /* pName
                                                                        */
};

static emlrtRTEInfo gb_emlrtRTEI =
    {
        320,     /* lineNo */
        20,      /* colNo */
        "colon", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pName
                                                                          */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    106,     /* lineNo */
    5,       /* colNo */
    "welch", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\welch.m" /* pName
                                                                        */
};

/* Function Definitions */
void pwelch(const emlrtStack *sp, const real_T x_data[], int32_T x_size,
            const real_T varargin_1_data[], int32_T varargin_1_size,
            real_T varargin_2, real_T varargout_1[257], real_T varargout_2[257])
{
  __m128d r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_real_T *xStart;
  real_T Sxx1[512];
  real_T Sxxk[512];
  real_T b_x_data[65];
  real_T b;
  real_T k1;
  real_T k1_tmp;
  real_T ndbl;
  real_T *xStart_data;
  int32_T eint;
  int32_T i;
  int32_T k;
  int32_T n;
  int32_T nm1d2;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &w_emlrtRSI;
  b_st.site = &x_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  d_st.site = &gb_emlrtRSI;
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
        &d_st, &i_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:pwelch:expectedNonNaN", 3, 4, 1, "X");
  }
  d_st.site = &gb_emlrtRSI;
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
        &d_st, &j_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:pwelch:expectedFinite", 3, 4, 1, "X");
  }
  c_st.site = &eb_emlrtRSI;
  n = x_size;
  if (x_size < 1) {
    n = 1;
  }
  if (x_size > muIntScalarMax_sint32(x_size, n)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &d_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if ((varargin_1_size == 1) || (varargin_1_size == 0)) {
    emlrtErrorWithMessageIdR2018a(
        &b_st, &c_emlrtRTEI,
        "signal:welchparse:VarSizeWindowMustBeMoreThanOneSampleLong",
        "signal:welchparse:VarSizeWindowMustBeMoreThanOneSampleLong", 0);
  }
  c_st.site = &db_emlrtRSI;
  if (varargin_1_size > x_size) {
    emlrtErrorWithMessageIdR2018a(&c_st, &e_emlrtRTEI,
                                  "signal:welchparse:invalidSegmentLength",
                                  "signal:welchparse:invalidSegmentLength", 0);
  }
  if (varargin_2 >= varargin_1_size) {
    emlrtErrorWithMessageIdR2018a(&c_st, &f_emlrtRTEI,
                                  "signal:welchparse:NoverlapTooBig",
                                  "signal:welchparse:NoverlapTooBig", 0);
  }
  k1_tmp = (real_T)varargin_1_size - varargin_2;
  k1 = trunc(((real_T)x_size - varargin_2) / k1_tmp);
  frexp(varargin_1_size, &nm1d2);
  c_st.site = &cb_emlrtRSI;
  frexp(x_size, &eint);
  c_st.site = &bb_emlrtRSI;
  b_st.site = &y_emlrtRSI;
  b = k1 * k1_tmp;
  emxInit_real_T(&b_st, &xStart, &hb_emlrtRTEI);
  xStart_data = xStart->data;
  if (muDoubleScalarIsNaN(k1_tmp) || muDoubleScalarIsNaN(b)) {
    i = xStart->size[0] * xStart->size[1];
    xStart->size[0] = 1;
    xStart->size[1] = 1;
    emxEnsureCapacity_real_T(&b_st, xStart, i, &fb_emlrtRTEI);
    xStart_data = xStart->data;
    xStart_data[0] = rtNaN;
  } else if ((k1_tmp == 0.0) || ((b > 1.0) && (k1_tmp < 0.0)) ||
             ((b < 1.0) && (k1_tmp > 0.0))) {
    xStart->size[0] = 1;
    xStart->size[1] = 0;
  } else if (muDoubleScalarIsInf(b) && muDoubleScalarIsInf(k1_tmp)) {
    i = xStart->size[0] * xStart->size[1];
    xStart->size[0] = 1;
    xStart->size[1] = 1;
    emxEnsureCapacity_real_T(&b_st, xStart, i, &fb_emlrtRTEI);
    xStart_data = xStart->data;
    xStart_data[0] = rtNaN;
  } else if (muDoubleScalarIsInf(k1_tmp)) {
    i = xStart->size[0] * xStart->size[1];
    xStart->size[0] = 1;
    xStart->size[1] = 1;
    emxEnsureCapacity_real_T(&b_st, xStart, i, &fb_emlrtRTEI);
    xStart_data = xStart->data;
    xStart_data[0] = 1.0;
  } else if (muDoubleScalarFloor(k1_tmp) == k1_tmp) {
    i = xStart->size[0] * xStart->size[1];
    xStart->size[0] = 1;
    nm1d2 = (int32_T)((b - 1.0) / k1_tmp);
    xStart->size[1] = nm1d2 + 1;
    emxEnsureCapacity_real_T(&b_st, xStart, i, &fb_emlrtRTEI);
    xStart_data = xStart->data;
    for (i = 0; i <= nm1d2; i++) {
      xStart_data[i] = k1_tmp * (real_T)i + 1.0;
    }
  } else {
    real_T apnd;
    real_T cdiff;
    c_st.site = &lb_emlrtRSI;
    ndbl = muDoubleScalarFloor((b - 1.0) / k1_tmp + 0.5);
    apnd = ndbl * k1_tmp + 1.0;
    if (k1_tmp > 0.0) {
      cdiff = apnd - b;
    } else {
      cdiff = b - apnd;
    }
    if (muDoubleScalarAbs(cdiff) <
        4.4408920985006262E-16 * muDoubleScalarMax(1.0, muDoubleScalarAbs(b))) {
      ndbl++;
      apnd = b;
    } else if (cdiff > 0.0) {
      apnd = (ndbl - 1.0) * k1_tmp + 1.0;
    } else {
      ndbl++;
    }
    if (ndbl >= 0.0) {
      n = (int32_T)ndbl;
    } else {
      n = 0;
    }
    d_st.site = &mb_emlrtRSI;
    if (ndbl > 2.147483647E+9) {
      emlrtErrorWithMessageIdR2018a(&d_st, &h_emlrtRTEI,
                                    "Coder:MATLAB:pmaxsize",
                                    "Coder:MATLAB:pmaxsize", 0);
    }
    i = xStart->size[0] * xStart->size[1];
    xStart->size[0] = 1;
    xStart->size[1] = n;
    emxEnsureCapacity_real_T(&c_st, xStart, i, &gb_emlrtRTEI);
    xStart_data = xStart->data;
    if (n > 0) {
      xStart_data[0] = 1.0;
      if (n > 1) {
        xStart_data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (k = 0; k <= nm1d2 - 2; k++) {
          ndbl = ((real_T)k + 1.0) * k1_tmp;
          xStart_data[k + 1] = ndbl + 1.0;
          xStart_data[(n - k) - 2] = apnd - ndbl;
        }
        if (nm1d2 << 1 == n - 1) {
          xStart_data[nm1d2] = (apnd + 1.0) / 2.0;
        } else {
          ndbl = (real_T)nm1d2 * k1_tmp;
          xStart_data[nm1d2] = ndbl + 1.0;
          xStart_data[nm1d2 + 1] = apnd - ndbl;
        }
      }
    }
  }
  b_st.site = &ab_emlrtRSI;
  i = xStart->size[1];
  if (xStart->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, xStart->size[1], &emlrtBCI, &b_st);
  }
  ndbl = xStart_data[0];
  nm1d2 = varargin_1_size - 1;
  for (eint = 0; eint <= nm1d2; eint++) {
    b = ndbl + (real_T)eint;
    if (b != (int32_T)muDoubleScalarFloor(b)) {
      emlrtIntegerCheckR2012b(b, &emlrtDCI, &b_st);
    }
    if (((int32_T)b < 1) || ((int32_T)b > x_size)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)b, 1, x_size, &b_emlrtBCI, &b_st);
    }
    b_x_data[eint] = x_data[(int32_T)b - 1];
  }
  c_st.site = &nb_emlrtRSI;
  computeperiodogram(&c_st, b_x_data, varargin_1_size, varargin_1_data,
                     varargin_1_size, Sxx1);
  eint = (int32_T)(k1 - 1.0);
  emlrtForLoopVectorCheckR2021a(2.0, 1.0, k1, mxDOUBLE_CLASS,
                                (int32_T)(k1 - 1.0), &g_emlrtRTEI, &b_st);
  for (n = 0; n < eint; n++) {
    if (((int32_T)((uint32_T)n + 2U) < 1) ||
        ((int32_T)((uint32_T)n + 2U) > i)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)n + 2U), 1, i,
                                    &c_emlrtBCI, &b_st);
    }
    ndbl = xStart_data[n + 1];
    for (k = 0; k <= nm1d2; k++) {
      b = ndbl + (real_T)k;
      if (b != (int32_T)muDoubleScalarFloor(b)) {
        emlrtIntegerCheckR2012b(b, &b_emlrtDCI, &b_st);
      }
      if (((int32_T)b < 1) || ((int32_T)b > x_size)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)b, 1, x_size, &d_emlrtBCI,
                                      &b_st);
      }
      b_x_data[k] = x_data[(int32_T)b - 1];
    }
    c_st.site = &ob_emlrtRSI;
    computeperiodogram(&c_st, b_x_data, varargin_1_size, varargin_1_data,
                       varargin_1_size, Sxxk);
    for (k = 0; k <= 510; k += 2) {
      __m128d r1;
      r = _mm_loadu_pd(&Sxx1[k]);
      r1 = _mm_loadu_pd(&Sxxk[k]);
      _mm_storeu_pd(&Sxx1[k], _mm_add_pd(r, r1));
    }
  }
  emxFree_real_T(&b_st, &xStart);
  for (i = 0; i <= 510; i += 2) {
    r = _mm_loadu_pd(&Sxx1[i]);
    _mm_storeu_pd(&Sxx1[i], _mm_div_pd(r, _mm_set1_pd(k1)));
  }
  memcpy(&varargout_1[0], &Sxx1[0], 257U * sizeof(real_T));
  for (i = 0; i <= 252; i += 2) {
    r = _mm_loadu_pd(&Sxx1[i + 1]);
    _mm_storeu_pd(&varargout_1[i + 1], _mm_mul_pd(_mm_set1_pd(2.0), r));
  }
  varargout_1[255] = 2.0 * Sxx1[255];
  for (i = 0; i < 257; i++) {
    varargout_1[i] /= 250.0;
    varargout_2[i] = 0.48828125 * (real_T)i;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (pwelch.c) */
