/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * addBiasApplyActivation.c
 *
 * Code generation for function 'addBiasApplyActivation'
 *
 */

/* Include files */
#include "addBiasApplyActivation.h"
#include "elementwiseOperationInPlace.h"
#include "rt_nonfinite.h"
#include "omp.h"

/* Function Definitions */
void addBiasApplyActivation(const emlrtStack *sp, real32_T X[96],
                            const real32_T bias[96])
{
  jmp_buf emlrtJBEnviron;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack st;
  int32_T addBiasApplyActivation_numThreads;
  int32_T iElem;
  boolean_T emlrtHadParallelError = false;
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  addBiasApplyActivation_numThreads = emlrtAllocRegionTLSs(
      sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(addBiasApplyActivation_numThreads) private(   \
        st, emlrtJBEnviron) firstprivate(emlrtHadParallelError)
  {
    if (setjmp(emlrtJBEnviron) == 0) {
      st.prev = sp;
      st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
      st.site = NULL;
      emlrtSetJmpBuf(&st, &emlrtJBEnviron);
    } else {
      emlrtHadParallelError = true;
    }
#pragma omp for nowait
    for (iElem = 0; iElem < 96; iElem++) {
      if (emlrtHadParallelError) {
        continue;
      }
      if (setjmp(emlrtJBEnviron) == 0) {
        X[iElem] += bias[iElem];
      } else {
        emlrtHadParallelError = true;
      }
    }
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
}

void b_addBiasApplyActivation(const emlrtStack *sp, real32_T X[96],
                              const real32_T bias[96])
{
  jmp_buf emlrtJBEnviron;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack st;
  int32_T b_addBiasApplyActivation_numThreads;
  int32_T iElem;
  boolean_T emlrtHadParallelError = false;
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  b_addBiasApplyActivation_numThreads = emlrtAllocRegionTLSs(
      sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(b_addBiasApplyActivation_numThreads) private( \
        st, emlrtJBEnviron) firstprivate(emlrtHadParallelError)
  {
    if (setjmp(emlrtJBEnviron) == 0) {
      st.prev = sp;
      st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
      st.site = NULL;
      emlrtSetJmpBuf(&st, &emlrtJBEnviron);
    } else {
      emlrtHadParallelError = true;
    }
#pragma omp for nowait
    for (iElem = 0; iElem < 96; iElem++) {
      if (emlrtHadParallelError) {
        continue;
      }
      if (setjmp(emlrtJBEnviron) == 0) {
        X[iElem] += bias[iElem];
        lambdaForColumnMajorGeneric(&X[iElem]);
      } else {
        emlrtHadParallelError = true;
      }
    }
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
}

void c_addBiasApplyActivation(const emlrtStack *sp, real32_T X[32],
                              const real32_T bias[32])
{
  jmp_buf emlrtJBEnviron;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack st;
  int32_T c_addBiasApplyActivation_numThreads;
  int32_T iElem;
  boolean_T emlrtHadParallelError = false;
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  c_addBiasApplyActivation_numThreads = emlrtAllocRegionTLSs(
      sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(c_addBiasApplyActivation_numThreads) private( \
        st, emlrtJBEnviron) firstprivate(emlrtHadParallelError)
  {
    if (setjmp(emlrtJBEnviron) == 0) {
      st.prev = sp;
      st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
      st.site = NULL;
      emlrtSetJmpBuf(&st, &emlrtJBEnviron);
    } else {
      emlrtHadParallelError = true;
    }
#pragma omp for nowait
    for (iElem = 0; iElem < 32; iElem++) {
      if (emlrtHadParallelError) {
        continue;
      }
      if (setjmp(emlrtJBEnviron) == 0) {
        X[iElem] += bias[iElem];
      } else {
        emlrtHadParallelError = true;
      }
    }
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
}

void d_addBiasApplyActivation(const emlrtStack *sp, real32_T X[32],
                              const real32_T bias[32])
{
  jmp_buf emlrtJBEnviron;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack st;
  int32_T d_addBiasApplyActivation_numThreads;
  int32_T iElem;
  boolean_T emlrtHadParallelError = false;
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  d_addBiasApplyActivation_numThreads = emlrtAllocRegionTLSs(
      sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(d_addBiasApplyActivation_numThreads) private( \
        st, emlrtJBEnviron) firstprivate(emlrtHadParallelError)
  {
    if (setjmp(emlrtJBEnviron) == 0) {
      st.prev = sp;
      st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
      st.site = NULL;
      emlrtSetJmpBuf(&st, &emlrtJBEnviron);
    } else {
      emlrtHadParallelError = true;
    }
#pragma omp for nowait
    for (iElem = 0; iElem < 32; iElem++) {
      if (emlrtHadParallelError) {
        continue;
      }
      if (setjmp(emlrtJBEnviron) == 0) {
        X[iElem] += bias[iElem];
        b_lambdaForColumnMajorGeneric(&X[iElem]);
      } else {
        emlrtHadParallelError = true;
      }
    }
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
}

void e_addBiasApplyActivation(const emlrtStack *sp, real32_T X[11],
                              const real32_T bias[11])
{
  jmp_buf emlrtJBEnviron;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack st;
  int32_T e_addBiasApplyActivation_numThreads;
  int32_T iElem;
  boolean_T emlrtHadParallelError = false;
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  e_addBiasApplyActivation_numThreads = emlrtAllocRegionTLSs(
      sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(e_addBiasApplyActivation_numThreads) private( \
        st, emlrtJBEnviron) firstprivate(emlrtHadParallelError)
  {
    if (setjmp(emlrtJBEnviron) == 0) {
      st.prev = sp;
      st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
      st.site = NULL;
      emlrtSetJmpBuf(&st, &emlrtJBEnviron);
    } else {
      emlrtHadParallelError = true;
    }
#pragma omp for nowait
    for (iElem = 0; iElem < 11; iElem++) {
      if (emlrtHadParallelError) {
        continue;
      }
      if (setjmp(emlrtJBEnviron) == 0) {
        X[iElem] += bias[iElem];
      } else {
        emlrtHadParallelError = true;
      }
    }
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
}

/* End of code generation (addBiasApplyActivation.c) */
