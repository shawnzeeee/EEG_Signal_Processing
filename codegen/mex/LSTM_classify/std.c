/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * std.c
 *
 * Code generation for function 'std'
 *
 */

/* Include files */
#include "std.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "blas.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <stddef.h>

/* Function Definitions */
real_T b_std(const real_T x_data[], int32_T x_size)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  real_T absdiff_data[500];
  real_T dv[2];
  real_T dv1[2];
  real_T y;
  int32_T k;
  if (x_size == 0) {
    y = rtNaN;
  } else if (x_size == 1) {
    if ((!muDoubleScalarIsInf(x_data[0])) &&
        (!muDoubleScalarIsNaN(x_data[0]))) {
      y = 0.0;
    } else {
      y = rtNaN;
    }
  } else {
    int32_T scalarLB;
    int32_T vectorUB;
    y = sumColumnB(x_data, x_size) / (real_T)x_size;
    scalarLB = (x_size / 2) << 1;
    vectorUB = scalarLB - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      __m128d r;
      _mm_storeu_pd(&dv[0],
                    _mm_sub_pd(_mm_loadu_pd(&x_data[k]), _mm_set1_pd(y)));
      dv1[0] = muDoubleScalarAbs(dv[0]);
      dv1[1] = muDoubleScalarAbs(dv[1]);
      r = _mm_loadu_pd(&dv1[0]);
      _mm_storeu_pd(&absdiff_data[k], r);
    }
    for (k = scalarLB; k < x_size; k++) {
      absdiff_data[k] = muDoubleScalarAbs(x_data[k] - y);
    }
    n_t = (ptrdiff_t)x_size;
    incx_t = (ptrdiff_t)1;
    y = dnrm2(&n_t, &absdiff_data[0], &incx_t);
    y /= muDoubleScalarSqrt((real_T)x_size - 1.0);
  }
  return y;
}

/* End of code generation (std.c) */
