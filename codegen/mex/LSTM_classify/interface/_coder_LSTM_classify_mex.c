/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_LSTM_classify_mex.c
 *
 * Code generation for function '_coder_LSTM_classify_mex'
 *
 */

/* Include files */
#include "_coder_LSTM_classify_mex.h"
#include "LSTM_classify.h"
#include "LSTM_classify_data.h"
#include "LSTM_classify_initialize.h"
#include "LSTM_classify_terminate.h"
#include "_coder_LSTM_classify_api.h"
#include "rt_nonfinite.h"
#include "omp.h"

/* Function Definitions */
void LSTM_classify_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
                               const mxArray *prhs[1])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        13, "LSTM_classify");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "LSTM_classify");
  }
  /* Call the function. */
  LSTM_classify_api(prhs[0], &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  static jmp_buf emlrtJBEnviron;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexAtExit(&LSTM_classify_atexit);
  /* Initialize the memory manager. */
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&LSTM_classify_nestLockGlobal);
  LSTM_classify_initialize();
  st.tls = emlrtRootTLSGlobal;
  emlrtSetJmpBuf(&st, &emlrtJBEnviron);
  if (setjmp(emlrtJBEnviron) == 0) {
    LSTM_classify_mexFunction(nlhs, plhs, nrhs, prhs);
    LSTM_classify_terminate();
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&LSTM_classify_nestLockGlobal);
  } else {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&LSTM_classify_nestLockGlobal);
    emlrtReportParallelRunTimeError(&st);
  }
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal,
                           &emlrtLockerFunction, omp_get_num_procs(), NULL,
                           "windows-1252", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_LSTM_classify_mex.c) */
