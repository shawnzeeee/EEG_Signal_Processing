/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * getCodes.c
 *
 * Code generation for function 'getCodes'
 *
 */

/* Include files */
#include "getCodes.h"
#include "LSTM_classify_data.h"
#include "LSTM_classify_types.h"
#include "cellstr_sort.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo kf_emlrtRSI = {
    53,                     /* lineNo */
    "categorical/getCodes", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\g"
    "etCodes.m" /* pathName */
};

static emlrtRSInfo lf_emlrtRSI = {
    87,                 /* lineNo */
    "cellstr_ismember", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "ismember.m" /* pathName */
};

static emlrtBCInfo hb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    161,                /* lineNo */
    38,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "ismember.m", /* pName */
    0             /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    164,                /* lineNo */
    71,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "ismember.m", /* pName */
    0             /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    167,                /* lineNo */
    58,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "ismember.m", /* pName */
    0             /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    169,                /* lineNo */
    42,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "ismember.m", /* pName */
    0             /* checkKind */
};

/* Function Definitions */
uint32_T categorical_getCodes(const emlrtStack *sp, const cell_wrap_5 inputData,
                              const cell_wrap_5 valueSet_data[],
                              int32_T valueSet_size)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_cell_wrap_5_11 c;
  emxArray_cell_wrap_5_11 uB;
  int32_T ib_data[11];
  int32_T idx_data[11];
  int32_T ii_data[11];
  int32_T b_i;
  int32_T d_size;
  int32_T i;
  int32_T ii_size;
  int32_T k;
  int32_T minSize;
  int32_T n;
  int32_T nz;
  boolean_T b_d_data[11];
  boolean_T d_data[10];
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  b_st.site = &lf_emlrtRSI;
  c_st.site = &hb_emlrtRSI;
  n = valueSet_size;
  if (valueSet_size < 1) {
    n = 1;
  }
  if (valueSet_size > muIntScalarMax_sint32(valueSet_size, n)) {
    emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  b_st.site = &lf_emlrtRSI;
  if (valueSet_size == 0) {
    uB.size[0] = 0;
    ii_size = 0;
  } else {
    c_st.site = &he_emlrtRSI;
    c.size[0] = cellstr_sort(&c_st, valueSet_data, valueSet_size, c.data,
                             idx_data, &minSize);
    c_st.site = &ie_emlrtRSI;
    d_size = c.size[0] - 1;
    n = c.size[0];
    if (n - 2 >= 0) {
      memset(&d_data[0], 0, (uint32_T)(n - 1) * sizeof(boolean_T));
    }
    for (b_i = 0; b_i <= n - 2; b_i++) {
      if (b_i > d_size) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, d_size, &v_emlrtBCI, &c_st);
      }
      if (b_i + 1 > d_size) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 0, d_size, &w_emlrtBCI, &c_st);
      }
      d_data[b_i] = !b_strcmp(c.data[b_i].f1.data, c.data[b_i].f1.size,
                              c.data[b_i + 1].f1.data, c.data[b_i + 1].f1.size);
    }
    b_d_data[0] = true;
    if (d_size - 1 >= 0) {
      memcpy(&b_d_data[1], &d_data[0], (uint32_T)d_size * sizeof(boolean_T));
    }
    c_st.site = &je_emlrtRSI;
    d_st.site = &ge_emlrtRSI;
    nz = b_d_data[0];
    for (k = 2; k <= n; k++) {
      nz += b_d_data[k - 1];
    }
    uB.size[0] = (int32_T)muDoubleScalarMin(nz, valueSet_size);
    c_st.site = &ke_emlrtRSI;
    d_st.site = &af_emlrtRSI;
    ii_size = eml_find(&d_st, b_d_data, c.size[0], ii_data);
    for (b_i = 0; b_i < ii_size; b_i++) {
      if (b_i + 1 != ii_size) {
        real_T y_data[11];
        real_T d;
        c_st.site = &le_emlrtRSI;
        if (b_i + 1 > ii_size) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size, &u_emlrtBCI,
                                        &c_st);
        }
        if (b_i + 2 > ii_size) {
          emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, ii_size, &t_emlrtBCI,
                                        &c_st);
        }
        d_st.site = &pe_emlrtRSI;
        d = (real_T)ii_data[b_i + 1] - 1.0;
        i = ii_data[b_i];
        if (d < i) {
          nz = 0;
        } else {
          n = (int32_T)d - i;
          nz = n + 1;
          for (k = 0; k <= n; k++) {
            y_data[k] = (real_T)i + (real_T)k;
          }
        }
        c_st.site = &le_emlrtRSI;
        for (i = 0; i < nz; i++) {
          d = y_data[i];
          if (d != (int32_T)d) {
            emlrtIntegerCheckR2012b(d, &c_emlrtDCI, &c_st);
          }
          if (((int32_T)d < 1) || ((int32_T)d > minSize)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, minSize, &bb_emlrtBCI,
                                          &c_st);
          }
        }
        d_st.site = &df_emlrtRSI;
        e_st.site = &ef_emlrtRSI;
        f_st.site = &ff_emlrtRSI;
        if (nz < 1) {
          emlrtErrorWithMessageIdR2018a(
              &f_st, &bb_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
              "Coder:toolbox:eml_min_or_max_varDimZero", 0);
        }
        n = idx_data[(int32_T)y_data[0] - 1];
        for (k = 2; k <= nz; k++) {
          i = idx_data[(int32_T)y_data[k - 1] - 1];
          if (n > i) {
            n = i;
          }
        }
        if (b_i + 1 > ii_size) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size, &db_emlrtBCI,
                                        &b_st);
        }
        ib_data[b_i] = n;
      } else {
        real_T y_data[11];
        c_st.site = &me_emlrtRSI;
        if (b_i + 1 > ii_size) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size, &s_emlrtBCI,
                                        &c_st);
        }
        d_st.site = &pe_emlrtRSI;
        i = ii_data[b_i];
        if (minSize < i) {
          nz = 0;
        } else {
          n = minSize - i;
          nz = n + 1;
          for (i = 0; i <= n; i++) {
            y_data[i] = ii_data[b_i] + i;
          }
        }
        c_st.site = &me_emlrtRSI;
        for (i = 0; i < nz; i++) {
          k = (int32_T)y_data[i];
          if ((k < 1) || (k > minSize)) {
            emlrtDynamicBoundsCheckR2012b(k, 1, minSize, &ab_emlrtBCI, &c_st);
          }
        }
        d_st.site = &df_emlrtRSI;
        e_st.site = &ef_emlrtRSI;
        f_st.site = &ff_emlrtRSI;
        if (nz < 1) {
          emlrtErrorWithMessageIdR2018a(
              &f_st, &bb_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
              "Coder:toolbox:eml_min_or_max_varDimZero", 0);
        }
        n = idx_data[(int32_T)y_data[0] - 1];
        for (k = 2; k <= nz; k++) {
          i = idx_data[(int32_T)y_data[k - 1] - 1];
          if (n > i) {
            n = i;
          }
        }
        if (b_i + 1 > ii_size) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size, &cb_emlrtBCI,
                                        &b_st);
        }
        ib_data[b_i] = n;
      }
    }
    if (minSize != c.size[0]) {
      emlrtSubAssignSizeCheck1dR2017a(minSize, c.size[0], &c_emlrtECI, &b_st);
    }
    for (i = 0; i < minSize; i++) {
      k = idx_data[i];
      if ((k < 1) || (k > d_size + 1)) {
        emlrtDynamicBoundsCheckR2012b(k, 1, d_size + 1, &x_emlrtBCI, &b_st);
      }
    }
    for (b_i = 0; b_i < ii_size; b_i++) {
      if (b_i + 1 > ii_size) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size, &y_emlrtBCI, &b_st);
      }
      i = ib_data[b_i];
      if ((i - 1 < 0) || (i - 1 > valueSet_size - 1)) {
        emlrtDynamicBoundsCheckR2012b(i - 1, 0, valueSet_size - 1, &q_emlrtBCI,
                                      &b_st);
      }
      if (b_i > uB.size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, uB.size[0] - 1, &r_emlrtBCI,
                                      &b_st);
      }
      uB.data[b_i].f1.size[0] = 1;
      n = valueSet_data[i - 1].f1.size[1];
      uB.data[b_i].f1.size[1] = n;
      for (i = 0; i < n; i++) {
        uB.data[b_i].f1.data[i] = valueSet_data[ib_data[b_i] - 1].f1.data[i];
      }
    }
  }
  i = 0;
  if (uB.size[0] > 0) {
    boolean_T is_less_than;
    n = 0;
    nz = inputData.f1.size[1];
    minSize =
        muIntScalarMin_sint32(inputData.f1.size[1], uB.data[0].f1.size[1]);
    if (minSize == 0) {
      is_less_than = (inputData.f1.size[1] < uB.data[0].f1.size[1]);
    } else {
      b_i = 0;
      while ((b_i + 1 <= minSize) &&
             (inputData.f1.data[b_i] == uB.data[0].f1.data[b_i])) {
        b_i++;
      }
      if (b_i + 1 == minSize + 1) {
        is_less_than = (inputData.f1.size[1] < uB.data[0].f1.size[1]);
      } else {
        is_less_than = (inputData.f1.data[b_i] < uB.data[0].f1.data[b_i]);
      }
    }
    if (!is_less_than) {
      if (b_strcmp(inputData.f1.data, inputData.f1.size, uB.data[0].f1.data,
                   uB.data[0].f1.size)) {
        if (ii_size < 1) {
          emlrtDynamicBoundsCheckR2012b(1, 1, ii_size, &hb_emlrtBCI, &st);
        }
        i = ib_data[0];
      } else {
        boolean_T exitg1;
        exitg1 = false;
        while ((!exitg1) && (n + 1 <= uB.size[0])) {
          if (n > uB.size[0] - 1) {
            emlrtDynamicBoundsCheckR2012b(n, 0, uB.size[0] - 1, &ib_emlrtBCI,
                                          &st);
          }
          d_size = uB.data[n].f1.size[1];
          minSize = muIntScalarMin_sint32(nz, d_size);
          if (minSize == 0) {
            is_less_than = (inputData.f1.size[1] > d_size);
          } else {
            b_i = 0;
            while ((b_i + 1 <= minSize) &&
                   (inputData.f1.data[b_i] == uB.data[n].f1.data[b_i])) {
              b_i++;
            }
            if (b_i + 1 == minSize + 1) {
              is_less_than = (inputData.f1.size[1] > d_size);
            } else {
              is_less_than = (inputData.f1.data[b_i] > uB.data[n].f1.data[b_i]);
            }
          }
          if (is_less_than) {
            n++;
          } else {
            exitg1 = true;
          }
        }
        if (n + 1 <= uB.size[0]) {
          if (n > uB.size[0] - 1) {
            emlrtDynamicBoundsCheckR2012b(n, 0, uB.size[0] - 1, &jb_emlrtBCI,
                                          &st);
          }
          if (b_strcmp(inputData.f1.data, inputData.f1.size, uB.data[n].f1.data,
                       uB.data[n].f1.size)) {
            if (n + 1 > ii_size) {
              emlrtDynamicBoundsCheckR2012b(n + 1, 1, ii_size, &kb_emlrtBCI,
                                            &st);
            }
            i = ib_data[n];
          }
        }
      }
    }
  }
  if (i < 0) {
    i = 0;
  }
  return (uint32_T)i;
}

/* End of code generation (getCodes.c) */
