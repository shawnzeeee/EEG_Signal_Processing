/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LSTM_classify.c
 *
 * Code generation for function 'LSTM_classify'
 *
 */

/* Include files */
#include "LSTM_classify.h"
#include "LSTM_classify_data.h"
#include "LSTM_classify_emxutil.h"
#include "LSTM_classify_internal_types.h"
#include "LSTM_classify_types.h"
#include "bandpower.h"
#include "diff.h"
#include "indexShapeCheck.h"
#include "postProcessOutputToReturnCategorical.h"
#include "predict.h"
#include "pwelch.h"
#include "rt_nonfinite.h"
#include "std.h"
#include "sumMatrixIncludeNaN.h"
#include "mwmathutil.h"
#include "omp.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static c_coder_internal_ctarget_DeepLe net;

static boolean_T net_not_empty;

static real_T mu[20];

static real_T sigma[20];

static emlrtRSInfo emlrtRSI = {
    10,              /* lineNo */
    "LSTM_classify", /* fcnName */
    "C:"
    "\\Users\\nicho\\OneDrive\\Documents\\Spring2025\\ENSC405\\CapstoneGithub\\"
    "EEG_Signal_Processing\\MatlabNN\\LSTM\\LSTM_classify"
    ".m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    12,              /* lineNo */
    "LSTM_classify", /* fcnName */
    "C:"
    "\\Users\\nicho\\OneDrive\\Documents\\Spring2025\\ENSC405\\CapstoneGithub\\"
    "EEG_Signal_Processing\\MatlabNN\\LSTM\\LSTM_classify"
    ".m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    5,               /* lineNo */
    "LSTM_classify", /* fcnName */
    "C:"
    "\\Users\\nicho\\OneDrive\\Documents\\Spring2025\\ENSC405\\CapstoneGithub\\"
    "EEG_Signal_Processing\\MatlabNN\\LSTM\\LSTM_classify"
    ".m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    70,                        /* lineNo */
    "loadDeepLearningNetwork", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+"
    "coder\\loadDeepLearningNetwork.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    1,                         /* lineNo */
    "loadDeepLearningNetwork", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\dlcoder_base\\dlcoder_base\\+"
    "coder\\+internal\\loadDeepLearningNetwork.p" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    1,                               /* lineNo */
    "DeepLearningNetwork/setAnchor", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024b\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\+ctarget\\@DeepLearningNetwork\\DeepLearningNetwork.p" /* pathName
                                                                     */
};

static emlrtRSInfo h_emlrtRSI = {
    1,                            /* lineNo */
    "DeepLearningNetwork/delete", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024b\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\@DeepLearningNetwork\\DeepLearningNetwork.p" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    16,                  /* lineNo */
    "extractLSTMwindow", /* fcnName */
    "C:"
    "\\Users\\nicho\\OneDrive\\Documents\\Spring2025\\ENSC405\\CapstoneGithub\\"
    "EEG_Signal_Processing\\MatlabNN\\LSTM\\extractLSTMwi"
    "ndow.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    12,                   /* lineNo */
    "extractEEGFeatures", /* fcnName */
    "C:"
    "\\Users\\nicho\\OneDrive\\Documents\\Spring2025\\ENSC405\\CapstoneGithub\\"
    "EEG_Signal_Processing\\MatlabNN\\extractEEGFeatures."
    "m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    15,                   /* lineNo */
    "extractEEGFeatures", /* fcnName */
    "C:"
    "\\Users\\nicho\\OneDrive\\Documents\\Spring2025\\ENSC405\\CapstoneGithub\\"
    "EEG_Signal_Processing\\MatlabNN\\extractEEGFeatures."
    "m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI = {
    18,                   /* lineNo */
    "extractEEGFeatures", /* fcnName */
    "C:"
    "\\Users\\nicho\\OneDrive\\Documents\\Spring2025\\ENSC405\\CapstoneGithub\\"
    "EEG_Signal_Processing\\MatlabNN\\extractEEGFeatures."
    "m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    21,                   /* lineNo */
    "extractEEGFeatures", /* fcnName */
    "C:"
    "\\Users\\nicho\\OneDrive\\Documents\\Spring2025\\ENSC405\\CapstoneGithub\\"
    "EEG_Signal_Processing\\MatlabNN\\extractEEGFeatures."
    "m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    24,                   /* lineNo */
    "extractEEGFeatures", /* fcnName */
    "C:"
    "\\Users\\nicho\\OneDrive\\Documents\\Spring2025\\ENSC405\\CapstoneGithub\\"
    "EEG_Signal_Processing\\MatlabNN\\extractEEGFeatures."
    "m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    25,                   /* lineNo */
    "extractEEGFeatures", /* fcnName */
    "C:"
    "\\Users\\nicho\\OneDrive\\Documents\\Spring2025\\ENSC405\\CapstoneGithub\\"
    "EEG_Signal_Processing\\MatlabNN\\extractEEGFeatures."
    "m" /* pathName */
};

static emlrtRSInfo
    p_emlrtRSI =
        {
            39,        /* lineNo */
            "hamming", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\hamming.m" /* pathName
                                                                         */
};

static emlrtRSInfo q_emlrtRSI = {
    21,          /* lineNo */
    "gencoswin", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\gencoswin.m" /* pathName
                                                                            */
};

static emlrtRSInfo r_emlrtRSI = {
    46,          /* lineNo */
    "gencoswin", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\gencoswin.m" /* pathName
                                                                            */
};

static emlrtRSInfo t_emlrtRSI = {
    61,           /* lineNo */
    "sym_window", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\private\\gencoswin.m" /* pathName
                                                                            */
};

static emlrtRSInfo fc_emlrtRSI =
    {
        68,          /* lineNo */
        "bandpower", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\signal\\signal\\bandpower.m" /* pathName
                                                                       */
};

static emlrtRSInfo kc_emlrtRSI = {
    28,    /* lineNo */
    "rms", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\rms.m" /* pathName
                                                                        */
};

static emlrtRSInfo oc_emlrtRSI = {
    1,                              /* lineNo */
    "DeepLearningNetwork/classify", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024b\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\@DeepLearningNetwork\\classify.p" /* pathName */
};

static emlrtECInfo emlrtECI = {
    -1,                  /* nDims */
    20,                  /* lineNo */
    9,                   /* colNo */
    "extractLSTMwindow", /* fName */
    "C:"
    "\\Users\\nicho\\OneDrive\\Documents\\Spring2025\\ENSC405\\CapstoneGithub\\"
    "EEG_Signal_Processing\\MatlabNN\\LSTM\\extractLSTMwi"
    "ndow.m" /* pName */
};

static emlrtRTEInfo emlrtRTEI = {
    13,     /* lineNo */
    9,      /* colNo */
    "sqrt", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" /* pName
                                                                       */
};

static emlrtRTEInfo db_emlrtRTEI = {
    1,               /* lineNo */
    16,              /* colNo */
    "LSTM_classify", /* fName */
    "C:"
    "\\Users\\nicho\\OneDrive\\Documents\\Spring2025\\ENSC405\\CapstoneGithub\\"
    "EEG_Signal_Processing\\MatlabNN\\LSTM\\LSTM_classify"
    ".m" /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    13,                  /* lineNo */
    9,                   /* colNo */
    "extractLSTMwindow", /* fName */
    "C:"
    "\\Users\\nicho\\OneDrive\\Documents\\Spring2025\\ENSC405\\CapstoneGithub\\"
    "EEG_Signal_Processing\\MatlabNN\\LSTM\\extractLSTMwi"
    "ndow.m" /* pName */
};

/* Function Declarations */
static int32_T div_s32(const emlrtStack *sp, int32_T numerator,
                       int32_T denominator);

/* Function Definitions */
static int32_T div_s32(const emlrtStack *sp, int32_T numerator,
                       int32_T denominator)
{
  int32_T quotient;
  if (denominator == 0) {
    emlrtDivisionByZeroErrorR2012b(NULL, (emlrtConstCTX)sp);
  } else {
    uint32_T u;
    uint32_T u1;
    if (numerator < 0) {
      u = ~(uint32_T)numerator + 1U;
    } else {
      u = (uint32_T)numerator;
    }
    if (denominator < 0) {
      u1 = ~(uint32_T)denominator + 1U;
    } else {
      u1 = (uint32_T)denominator;
    }
    u /= u1;
    if ((numerator < 0) != (denominator < 0)) {
      quotient = -(int32_T)u;
    } else {
      quotient = (int32_T)u;
    }
  }
  return quotient;
}

void LSTM_classify(const emlrtStack *sp, const real_T inputWindow[2000],
                   categorical *out)
{
  __m128d r1;
  cell_wrap_55 r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_real_T *features;
  real_T signal_data[500];
  real_T x_data[500];
  real_T b_tmp_data[499];
  real_T tmp_data[499];
  real_T input[80];
  real_T w_data[65];
  real_T b_w_data[32];
  real_T b_y_data[32];
  real_T *features_data;
  int32_T iv[2];
  int32_T ch;
  int32_T frameIdx;
  int32_T i;
  int32_T k;
  int32_T loop_ub;
  int32_T tmp_size;
  int8_T y_data[65];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  if (!net_not_empty) {
    st.site = &c_emlrtRSI;
    b_st.site = &d_emlrtRSI;
    c_st.site = &e_emlrtRSI;
    d_st.site = &f_emlrtRSI;
    net.IsNetworkInitialized = false;
    e_st.site = &g_emlrtRSI;
    d_st.site = &f_emlrtRSI;
    e_st.site = &h_emlrtRSI;
    net.matlabCodegenIsDeleted = false;
    net_not_empty = true;
  }
  st.site = &emlrtRSI;
  /*  eeg_window: [500 x 4] EEG data for a 2-second window */
  /*  Fs: sampling frequency (e.g., 250 Hz) */
  /*  Preallocate sequence output: [20 features x 4 frames] */
  i = 20;
  emxInit_real_T(&st, &features, &eb_emlrtRTEI);
  features_data = features->data;
  iv[0] = 1;
  b_st.site = &t_emlrtRSI;
  loop_ub = div_s32(&b_st, -31, -1);
  iv[1] = loop_ub + 1;
  for (tmp_size = 0; tmp_size < 32; tmp_size++) {
    y_data[tmp_size] = (int8_T)tmp_size;
  }
  for (frameIdx = 0; frameIdx < 4; frameIdx++) {
    int32_T frameStart;
    frameStart = frameIdx * 125;
    features->size[0] = 1;
    features->size[1] = 0;
    for (k = 0; k < 32; k++) {
      b_y_data[k] =
          muDoubleScalarCos(6.2831853071795862 * ((real_T)y_data[k] / 63.0));
    }
    for (ch = 0; ch < 4; ch++) {
      real_T accumulatedData;
      real_T alpha_power;
      real_T beta_power;
      real_T complexity;
      real_T mobility;
      memcpy(&signal_data[0], &inputWindow[ch * 500 + frameStart],
             125U * sizeof(real_T));
      b_st.site = &i_emlrtRSI;
      /*  Input: */
      /*  eeg_signal - EEG time-series data (1D array) */
      /*  fs - Sampling frequency (Hz) */
      /*  */
      /*  Output: */
      /*  features - Feature vector containing extracted values */
      /*  Can also try 125 if signal is 125 */
      /*  Power spectral density using Welch's method */
      c_st.site = &j_emlrtRSI;
      d_st.site = &p_emlrtRSI;
      e_st.site = &q_emlrtRSI;
      e_st.site = &r_emlrtRSI;
      for (tmp_size = 0; tmp_size <= 30; tmp_size += 2) {
        r1 = _mm_loadu_pd(&b_y_data[tmp_size]);
        _mm_storeu_pd(
            &b_w_data[tmp_size],
            _mm_sub_pd(_mm_set1_pd(0.54), _mm_mul_pd(_mm_set1_pd(0.46), r1)));
      }
      f_st.site = &t_emlrtRSI;
      indexShapeCheck(&f_st, 32, iv);
      memcpy(&w_data[0], &b_w_data[0], 32U * sizeof(real_T));
      for (tmp_size = 0; tmp_size <= loop_ub; tmp_size++) {
        w_data[tmp_size + 32] = b_w_data[31 - tmp_size];
      }
      real_T f[257];
      real_T pxx[257];
      real_T dv[2];
      c_st.site = &j_emlrtRSI;
      pwelch(&c_st, signal_data, 125, w_data, loop_ub + 33, 32.0, pxx, f);
      /*  Alpha power (8–13 Hz) */
      c_st.site = &k_emlrtRSI;
      dv[0] = 8.0;
      dv[1] = 13.0;
      d_st.site = &fc_emlrtRSI;
      alpha_power = psdbandpower(&d_st, pxx, f, dv);
      /*  Beta power (13–30 Hz) */
      c_st.site = &l_emlrtRSI;
      dv[0] = 13.0;
      dv[1] = 30.0;
      d_st.site = &fc_emlrtRSI;
      beta_power = psdbandpower(&d_st, pxx, f, dv);
      /* Root Mean Square (RMS) */
      c_st.site = &m_emlrtRSI;
      d_st.site = &kc_emlrtRSI;
      for (tmp_size = 0; tmp_size <= 122; tmp_size += 2) {
        k = (frameStart + tmp_size) + 500 * ch;
        _mm_storeu_pd(&x_data[tmp_size],
                      _mm_mul_pd(_mm_loadu_pd(&inputWindow[k]),
                                 _mm_loadu_pd(&inputWindow[k])));
      }
      accumulatedData = inputWindow[(frameStart + 500 * ch) + 124];
      x_data[124] = accumulatedData * accumulatedData;
      accumulatedData = sumColumnB(x_data, 125);
      accumulatedData /= 125.0;
      d_st.site = &kc_emlrtRSI;
      if (accumulatedData < 0.0) {
        emlrtErrorWithMessageIdR2018a(
            &d_st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
            "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
      }
      accumulatedData = muDoubleScalarSqrt(accumulatedData);
      /* Hjorth Parameters */
      c_st.site = &n_emlrtRSI;
      k = diff(&c_st, signal_data, 125, tmp_data);
      c_st.site = &n_emlrtRSI;
      mobility = b_std(tmp_data, k) / b_std(signal_data, 125);
      c_st.site = &o_emlrtRSI;
      k = diff(&c_st, signal_data, 125, tmp_data);
      c_st.site = &o_emlrtRSI;
      tmp_size = diff(&c_st, tmp_data, k, b_tmp_data);
      c_st.site = &o_emlrtRSI;
      k = diff(&c_st, signal_data, 125, tmp_data);
      c_st.site = &o_emlrtRSI;
      complexity = b_std(b_tmp_data, tmp_size) / b_std(tmp_data, k);
      /* Zero Crossing Rate (ZCR) */
      /* ZCR = sum(abs(diff(sign(eeg_signal)))) / length(eeg_signal); */
      /* Kurtosis */
      /* kurtosis_value = kurtosis(eeg_signal); */
      /* Shannon Entropy */
      /* prob_dist = abs(eeg_signal) ./ sum(abs(eeg_signal));  % Normalize */
      /* entropy_value = -sum(prob_dist .* log2(prob_dist + eps));  % Compute
       * entropy */
      /*  Combine features into a vector */
      /*  [5x1] */
      tmp_size = features->size[1];
      k = features->size[0] * features->size[1];
      features->size[1] += 5;
      emxEnsureCapacity_real_T(&st, features, k, &db_emlrtRTEI);
      features_data = features->data;
      features_data[tmp_size] = alpha_power;
      features_data[tmp_size + 1] = beta_power;
      features_data[tmp_size + 2] = accumulatedData;
      features_data[tmp_size + 3] = mobility;
      features_data[tmp_size + 4] = complexity;
      /*  append [1x5] */
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    emlrtSubAssignSizeCheckR2012b(&i, 1, &features->size[1], 1, &emlrtECI, &st);
    for (tmp_size = 0; tmp_size < 20; tmp_size++) {
      input[tmp_size + 20 * frameIdx] = features_data[tmp_size];
    }
    /*  store as [20x1] */
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }
  emxFree_real_T(&st, &features);
  st.site = &b_emlrtRSI;
  for (i = 0; i < 4; i++) {
    for (tmp_size = 0; tmp_size <= 18; tmp_size += 2) {
      __m128d r2;
      __m128d r3;
      k = tmp_size + 20 * i;
      r1 = _mm_loadu_pd(&input[k]);
      r2 = _mm_loadu_pd(&mu[tmp_size]);
      r3 = _mm_loadu_pd(&sigma[tmp_size]);
      _mm_storeu_pd(&input[k], _mm_div_pd(_mm_sub_pd(r1, r2), r3));
    }
  }
  b_st.site = &oc_emlrtRSI;
  DeepLearningNetwork_predict(&b_st, &net, input, r.f1);
  b_st.site = &oc_emlrtRSI;
  out->codes = c_DeepLearningNetwork_postProce(
      &b_st, r, out->categoryNames.data, &out->categoryNames.size[0]);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void LSTM_classify_delete(void)
{
  if (!net.matlabCodegenIsDeleted) {
    net.matlabCodegenIsDeleted = true;
  }
}

void LSTM_classify_init(void)
{
  static const real_T dv[20] = {
      106839.3748285951,   73031.412523202613,  77.669785552748664,
      0.2137090153522766,  0.40211162348480117, 128696.2435523522,
      48971.546922447,     235.7786703772949,   0.1848970781814803,
      0.39123069223105672, 96188.610345952053,  61032.093950871917,
      129.43581089429031,  0.18532602988131619, 0.38345034507876952,
      151168.38456757419,  104516.5929263039,   83.70386529754137,
      0.19881465052015559, 0.42760209504217778};
  static const real_T dv1[20] = {
      2.4674037978060022E+6, 1.7214891883819869E+6, 841.803674967733,
      0.079674496196171132,  0.1143011566007222,    1.5833634050223851E+6,
      1.018357490505234E+6,  1078.904588835911,     0.079640947303683818,
      0.1159487078790758,    2.001427487319347E+6,  1.3813896305340759E+6,
      816.42924694215719,    0.081436217647139514,  0.13198600059995469,
      4.1413027414557459E+6, 2.9282896976636378E+6, 901.58764842760422,
      0.087574628511287431,  0.139343890351274};
  memcpy(&mu[0], &dv[0], 20U * sizeof(real_T));
  memcpy(&sigma[0], &dv1[0], 20U * sizeof(real_T));
  net_not_empty = false;
}

void LSTM_classify_new(void)
{
  net.matlabCodegenIsDeleted = true;
}

emlrtCTX emlrtGetRootTLSGlobal(void)
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

/* End of code generation (LSTM_classify.c) */
