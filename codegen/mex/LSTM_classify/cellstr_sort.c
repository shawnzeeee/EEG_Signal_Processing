/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cellstr_sort.c
 *
 * Code generation for function 'cellstr_sort'
 *
 */

/* Include files */
#include "cellstr_sort.h"
#include "LSTM_classify_types.h"
#include "introsort.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo oe_emlrtRSI = {
    23,             /* lineNo */
    "cellstr_sort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "sort.m" /* pathName */
};

static emlrtBCInfo eb_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    27,             /* lineNo */
    19,             /* colNo */
    "",             /* aName */
    "cellstr_sort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "sort.m", /* pName */
    0         /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    27,             /* lineNo */
    12,             /* colNo */
    "",             /* aName */
    "cellstr_sort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "sort.m", /* pName */
    0         /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    27,             /* lineNo */
    23,             /* colNo */
    "",             /* aName */
    "cellstr_sort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "sort.m", /* pName */
    0         /* checkKind */
};

/* Function Definitions */
int32_T cellstr_sort(const emlrtStack *sp, const cell_wrap_5 c_data[],
                     int32_T c_size, cell_wrap_5 sorted_data[],
                     int32_T idx_data[], int32_T *idx_size)
{
  emlrtStack st;
  int32_T k;
  int32_T n_tmp_tmp;
  int32_T sorted_size;
  int32_T yk;
  int16_T y_data[11];
  st.prev = sp;
  st.tls = sp->tls;
  n_tmp_tmp = (uint8_T)(c_size - 1) + 1;
  y_data[0] = 1;
  yk = 1;
  for (k = 2; k <= n_tmp_tmp; k++) {
    yk++;
    y_data[k - 1] = (int16_T)yk;
  }
  *idx_size = (uint8_T)(c_size - 1) + 1;
  for (k = 0; k < n_tmp_tmp; k++) {
    idx_data[k] = y_data[k];
  }
  st.site = &oe_emlrtRSI;
  introsort(&st, idx_data, c_size, c_data, c_size);
  sorted_size = c_size;
  for (n_tmp_tmp = 0; n_tmp_tmp < c_size; n_tmp_tmp++) {
    if (n_tmp_tmp + 1 > (uint8_T)(c_size - 1) + 1) {
      emlrtDynamicBoundsCheckR2012b(n_tmp_tmp + 1, 1, (uint8_T)(c_size - 1) + 1,
                                    &gb_emlrtBCI, (emlrtConstCTX)sp);
    }
    k = idx_data[n_tmp_tmp] - 1;
    if ((k < 0) || (k > c_size - 1)) {
      emlrtDynamicBoundsCheckR2012b(k, 0, c_size - 1, &eb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (n_tmp_tmp > c_size - 1) {
      emlrtDynamicBoundsCheckR2012b(n_tmp_tmp, 0, c_size - 1, &fb_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    sorted_data[n_tmp_tmp].f1.size[0] = 1;
    yk = c_data[idx_data[n_tmp_tmp] - 1].f1.size[1];
    sorted_data[n_tmp_tmp].f1.size[1] = yk;
    for (k = 0; k < yk; k++) {
      sorted_data[n_tmp_tmp].f1.data[k] =
          c_data[idx_data[n_tmp_tmp] - 1].f1.data[k];
    }
  }
  return sorted_size;
}

/* End of code generation (cellstr_sort.c) */
