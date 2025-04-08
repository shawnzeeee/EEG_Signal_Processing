/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * internal_softmax.c
 *
 * Code generation for function 'internal_softmax'
 *
 */

/* Include files */
#include "internal_softmax.h"
#include "LSTM_classify_data.h"
#include "elementwiseOperationInPlace.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "mwmathutil.h"
#include <xmmintrin.h>

/* Function Definitions */
void iComputeSoftmaxForCpu(const emlrtStack *sp, const real32_T xdata[11],
                           real32_T ydata[11])
{
  emlrtStack st;
  int32_T k;
  int32_T nonChannelDimsProductIdx;
  st.prev = sp;
  st.tls = sp->tls;
  for (nonChannelDimsProductIdx = 0; nonChannelDimsProductIdx < 1;
       nonChannelDimsProductIdx++) {
    __m128 r;
    __m128 r1;
    int32_T idx;
    real32_T maxVal;
    real32_T y;
    if (!muSingleScalarIsNaN(xdata[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 12)) {
        if (!muSingleScalarIsNaN(xdata[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      maxVal = xdata[0];
    } else {
      maxVal = xdata[idx - 1];
      idx++;
      for (k = idx; k < 12; k++) {
        y = xdata[k - 1];
        if (maxVal < y) {
          maxVal = y;
        }
      }
    }
    r = _mm_set1_ps(maxVal);
    _mm_storeu_ps(&ydata[0], _mm_sub_ps(_mm_loadu_ps(&xdata[0]), r));
    _mm_storeu_ps(&ydata[4], _mm_sub_ps(_mm_loadu_ps(&xdata[4]), r));
    ydata[8] = xdata[8] - maxVal;
    ydata[9] = xdata[9] - maxVal;
    ydata[10] = xdata[10] - maxVal;
    st.site = &nf_emlrtRSI;
    d_lambdaForColumnMajorGeneric(&st, ydata);
    y = b_sumColumnB(ydata);
    r = _mm_loadu_ps(&ydata[0]);
    r1 = _mm_set1_ps(y);
    _mm_storeu_ps(&ydata[0], _mm_div_ps(r, r1));
    r = _mm_loadu_ps(&ydata[4]);
    _mm_storeu_ps(&ydata[4], _mm_div_ps(r, r1));
    ydata[8] /= y;
    ydata[9] /= y;
    ydata[10] /= y;
  }
}

/* End of code generation (internal_softmax.c) */
