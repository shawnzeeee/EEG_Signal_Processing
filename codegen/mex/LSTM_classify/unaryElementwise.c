/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * unaryElementwise.c
 *
 * Code generation for function 'unaryElementwise'
 *
 */

/* Include files */
#include "unaryElementwise.h"
#include "LSTM_classify_data.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include <xmmintrin.h>

/* Function Declarations */
static void elementwise_relu(const emlrtStack *sp, const real32_T *inputTensor,
                             real32_T *outputTensor);

/* Function Definitions */
static void elementwise_relu(const emlrtStack *sp, const real32_T *inputTensor,
                             real32_T *outputTensor)
{
  __m128 reg_0;
  __m128 reluZero;
  jmp_buf emlrtJBEnviron;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack st;
  int32_T baseIdx;
  int32_T elementwise_relu_numThreads;
  int32_T simdBlockIdx;
  boolean_T emlrtHadParallelError = false;
  reluZero = _mm_set1_ps(0.0F);
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  elementwise_relu_numThreads = emlrtAllocRegionTLSs(
      sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(elementwise_relu_numThreads) private(         \
        st, emlrtJBEnviron, baseIdx, reg_0)                                    \
    firstprivate(emlrtHadParallelError)
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
    for (simdBlockIdx = 0; simdBlockIdx < 8; simdBlockIdx++) {
      if (emlrtHadParallelError) {
        continue;
      }
      if (setjmp(emlrtJBEnviron) == 0) {
        baseIdx = simdBlockIdx << 2;
        reg_0 = _mm_loadu_ps(&inputTensor[baseIdx]);
        reg_0 = _mm_max_ps(reg_0, reluZero);
        _mm_storeu_ps(&outputTensor[baseIdx], reg_0);
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      } else {
        emlrtHadParallelError = true;
      }
    }
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
}

void unaryElementwise(const emlrtStack *sp, const real32_T X[32],
                      real32_T Z[32])
{
  elementwise_relu(sp, &X[0], &Z[0]);
}

/* End of code generation (unaryElementwise.c) */
