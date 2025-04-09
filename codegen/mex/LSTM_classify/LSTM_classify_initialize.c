/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LSTM_classify_initialize.c
 *
 * Code generation for function 'LSTM_classify_initialize'
 *
 */

/* Include files */
#include "LSTM_classify_initialize.h"
#include "LSTM_classify.h"
#include "LSTM_classify_data.h"
#include "_coder_LSTM_classify_mex.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void LSTM_classify_once(void);

/* Function Definitions */
static void LSTM_classify_once(void)
{
  mex_InitInfAndNan();
  LSTM_classify_new();
  LSTM_classify_init();
}

void LSTM_classify_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "neural_network_toolbox", 2);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "signal_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    LSTM_classify_once();
  }
}

/* End of code generation (LSTM_classify_initialize.c) */
