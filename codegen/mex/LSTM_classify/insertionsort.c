/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * insertionsort.c
 *
 * Code generation for function 'insertionsort'
 *
 */

/* Include files */
#include "insertionsort.h"
#include "LSTM_classify_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo we_emlrtRSI = {
    21,              /* lineNo */
    "insertionsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\insertionsort.m" /* pathName */
};

static emlrtRSInfo xe_emlrtRSI = {
    63,                               /* lineNo */
    "function_handle/parenReference", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\function_"
    "handle.m" /* pathName */
};

static emlrtRSInfo ye_emlrtRSI = {
    23,                               /* lineNo */
    "@(i,j)sortidxCmp(i,j,c,cmpFun)", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "sort.m" /* pathName */
};

static emlrtBCInfo lb_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    40,           /* lineNo */
    17,           /* colNo */
    "",           /* aName */
    "sortidxCmp", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "sort.m", /* pName */
    0         /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    41,           /* lineNo */
    17,           /* colNo */
    "",           /* aName */
    "sortidxCmp", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "sort.m", /* pName */
    0         /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    35,           /* lineNo */
    8,            /* colNo */
    "",           /* aName */
    "sortidxCmp", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "sort.m", /* pName */
    0         /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    36,           /* lineNo */
    8,            /* colNo */
    "",           /* aName */
    "sortidxCmp", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "sort.m", /* pName */
    0         /* checkKind */
};

/* Function Definitions */
void insertionsort(const emlrtStack *sp, int32_T x_data[], int32_T xend,
                   const cell_wrap_5 cmp_workspace_c_data[],
                   int32_T cmp_workspace_c_size)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  for (k = 2; k <= xend; k++) {
    int32_T idx;
    int32_T xc;
    boolean_T exitg1;
    xc = x_data[k - 1] - 1;
    idx = k - 2;
    exitg1 = false;
    while ((!exitg1) && (idx + 1 >= 1)) {
      int32_T b_k;
      int32_T b_n_tmp;
      int32_T j;
      int32_T n;
      int32_T n_tmp;
      boolean_T varargout_1;
      st.site = &we_emlrtRSI;
      j = x_data[idx];
      b_st.site = &xe_emlrtRSI;
      c_st.site = &ye_emlrtRSI;
      if ((xc < 0) || (xc > cmp_workspace_c_size - 1)) {
        emlrtDynamicBoundsCheckR2012b(xc, 0, cmp_workspace_c_size - 1,
                                      &nb_emlrtBCI, &c_st);
      }
      n_tmp = x_data[idx] - 1;
      if ((n_tmp < 0) || (n_tmp > cmp_workspace_c_size - 1)) {
        emlrtDynamicBoundsCheckR2012b(n_tmp, 0, cmp_workspace_c_size - 1,
                                      &ob_emlrtBCI, &c_st);
      }
      n_tmp = cmp_workspace_c_data[xc].f1.size[1];
      b_n_tmp = cmp_workspace_c_data[x_data[idx] - 1].f1.size[1];
      n = (int32_T)muDoubleScalarMin(n_tmp, b_n_tmp);
      varargout_1 = (n_tmp < b_n_tmp);
      b_k = 0;
      int32_T exitg2;
      do {
        exitg2 = 0;
        if (b_k <= n - 1) {
          if (b_k + 1 > n_tmp) {
            emlrtDynamicBoundsCheckR2012b(b_k + 1, 1, n_tmp, &lb_emlrtBCI,
                                          &c_st);
          }
          if (b_k + 1 > b_n_tmp) {
            emlrtDynamicBoundsCheckR2012b(b_k + 1, 1, b_n_tmp, &mb_emlrtBCI,
                                          &c_st);
          }
          if (cmp_workspace_c_data[xc].f1.data[b_k] !=
              cmp_workspace_c_data[x_data[idx] - 1].f1.data[b_k]) {
            varargout_1 = (cmp_workspace_c_data[xc].f1.data[b_k] <
                           cmp_workspace_c_data[x_data[idx] - 1].f1.data[b_k]);
            exitg2 = 1;
          } else {
            b_k++;
          }
        } else {
          if (n_tmp == b_n_tmp) {
            varargout_1 = (xc + 1 < j);
          }
          exitg2 = 1;
        }
      } while (exitg2 == 0);
      if (varargout_1) {
        x_data[idx + 1] = x_data[idx];
        idx--;
      } else {
        exitg1 = true;
      }
    }
    x_data[idx + 1] = xc + 1;
  }
}

/* End of code generation (insertionsort.c) */
