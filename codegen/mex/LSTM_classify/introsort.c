/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * introsort.c
 *
 * Code generation for function 'introsort'
 *
 */

/* Include files */
#include "introsort.h"
#include "LSTM_classify_types.h"
#include "insertionsort.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo ve_emlrtRSI = {
    34,          /* lineNo */
    "introsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\introsort.m" /* pathName */
};

/* Function Definitions */
void introsort(const emlrtStack *sp, int32_T x_data[], int32_T xend,
               const cell_wrap_5 cmp_workspace_c_data[],
               int32_T cmp_workspace_c_size)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  if (xend > 1) {
    st.site = &ve_emlrtRSI;
    insertionsort(&st, x_data, xend, cmp_workspace_c_data,
                  cmp_workspace_c_size);
  }
}

/* End of code generation (introsort.c) */
