/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * elementwiseOperationInPlace.c
 *
 * Code generation for function 'elementwiseOperationInPlace'
 *
 */

/* Include files */
#include "elementwiseOperationInPlace.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "omp.h"

/* Function Definitions */
void b_lambdaForColumnMajorGeneric(real32_T *X)
{
  *X = muSingleScalarTanh(*X);
}

void c_lambdaForColumnMajorGeneric(const emlrtStack *sp, real32_T X[32])
{
  jmp_buf *volatile emlrtJBStack;
  int32_T c_lambdaForColumnMajorGeneric_numThreads;
  int32_T iElem;
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  c_lambdaForColumnMajorGeneric_numThreads = emlrtAllocRegionTLSs(
      sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(c_lambdaForColumnMajorGeneric_numThreads)

  for (iElem = 0; iElem < 32; iElem++) {
    X[iElem] = muSingleScalarTanh(X[iElem]);
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
}

void d_lambdaForColumnMajorGeneric(const emlrtStack *sp, real32_T X[11])
{
  jmp_buf *volatile emlrtJBStack;
  int32_T d_lambdaForColumnMajorGeneric_numThreads;
  int32_T iElem;
  emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
  emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  d_lambdaForColumnMajorGeneric_numThreads = emlrtAllocRegionTLSs(
      sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(d_lambdaForColumnMajorGeneric_numThreads)

  for (iElem = 0; iElem < 11; iElem++) {
    X[iElem] = muSingleScalarExp(X[iElem]);
  }
  emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
  emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
}

void lambdaForColumnMajorGeneric(real32_T *X)
{
  *X = 1.0F / (muSingleScalarExp(-*X) + 1.0F);
}

/* End of code generation (elementwiseOperationInPlace.c) */
