/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sumMatrixIncludeNaN.c
 *
 * Code generation for function 'sumMatrixIncludeNaN'
 *
 */

/* Include files */
#include "sumMatrixIncludeNaN.h"
#include "rt_nonfinite.h"

/* Function Definitions */
real32_T b_sumColumnB(const real32_T x[11])
{
  int32_T k;
  real32_T y;
  y = x[0];
  for (k = 0; k < 10; k++) {
    y += x[k + 1];
  }
  return y;
}

real_T sumColumnB(const real_T x_data[], int32_T vlen)
{
  real_T y;
  int32_T i;
  int32_T k;
  y = x_data[0];
  i = (uint16_T)(vlen - 1);
  for (k = 0; k < i; k++) {
    y += x_data[k + 1];
  }
  return y;
}

/* End of code generation (sumMatrixIncludeNaN.c) */
