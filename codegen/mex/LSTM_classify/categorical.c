/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * categorical.c
 *
 * Code generation for function 'categorical'
 *
 */

/* Include files */
#include "categorical.h"
#include "LSTM_classify_data.h"
#include "LSTM_classify_internal_types.h"
#include "LSTM_classify_types.h"
#include "cellstr_unique.h"
#include "getCodes.h"
#include "rt_nonfinite.h"
#include "strtrim.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo qd_emlrtRSI = {
    243,                       /* lineNo */
    "categorical/categorical", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\c"
    "ategorical.m" /* pathName */
};

static emlrtRSInfo rd_emlrtRSI = {
    191,                       /* lineNo */
    "categorical/categorical", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\c"
    "ategorical.m" /* pathName */
};

static emlrtRSInfo sd_emlrtRSI = {
    179,                       /* lineNo */
    "categorical/categorical", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\c"
    "ategorical.m" /* pathName */
};

static emlrtRSInfo td_emlrtRSI = {
    156,                       /* lineNo */
    "categorical/categorical", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\c"
    "ategorical.m" /* pathName */
};

static emlrtRSInfo ud_emlrtRSI = {
    131,                       /* lineNo */
    "categorical/categorical", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\c"
    "ategorical.m" /* pathName */
};

static emlrtRSInfo vd_emlrtRSI = {
    21,                /* lineNo */
    "cellstr_strtrim", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "strtrim.m" /* pathName */
};

static emlrtRSInfo ee_emlrtRSI = {
    20,                /* lineNo */
    "isMissingValues", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\isMissin"
    "gValues.m" /* pathName */
};

static emlrtRSInfo fe_emlrtRSI = {
    26,                /* lineNo */
    "isMissingValues", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\isMissin"
    "gValues.m" /* pathName */
};

static emlrtRSInfo gf_emlrtRSI = {
    431,                            /* lineNo */
    "categorical/initDataValueSet", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\c"
    "ategorical.m" /* pathName */
};

static emlrtRSInfo hf_emlrtRSI = {
    434,                            /* lineNo */
    "categorical/initDataValueSet", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\c"
    "ategorical.m" /* pathName */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    243,                       /* lineNo */
    21,                        /* colNo */
    "",                        /* aName */
    "categorical/categorical", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\c"
    "ategorical.m", /* pName */
    0               /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    431,                            /* lineNo */
    31,                             /* colNo */
    "",                             /* aName */
    "categorical/initDataValueSet", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\c"
    "ategorical.m", /* pName */
    0               /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    97,                             /* lineNo */
    22,                             /* colNo */
    "",                             /* aName */
    "categorical/getCategoryNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\g"
    "etCategoryNames.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    27,                /* lineNo */
    20,                /* colNo */
    "",                /* aName */
    "isMissingValues", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\isMissin"
    "gValues.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    26,                /* lineNo */
    34,                /* colNo */
    "",                /* aName */
    "isMissingValues", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\isMissin"
    "gValues.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    21,                /* lineNo */
    21,                /* colNo */
    "",                /* aName */
    "cellstr_strtrim", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "strtrim.m", /* pName */
    0            /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    104,                            /* lineNo */
    48,                             /* colNo */
    "",                             /* aName */
    "categorical/getCategoryNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\g"
    "etCategoryNames.m", /* pName */
    0                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    97,                             /* lineNo */
    41,                             /* colNo */
    "",                             /* aName */
    "categorical/getCategoryNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\g"
    "etCategoryNames.m", /* pName */
    0                    /* checkKind */
};

static emlrtRTEInfo u_emlrtRTEI = {
    100,                            /* lineNo */
    35,                             /* colNo */
    "categorical/getCategoryNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\g"
    "etCategoryNames.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    91,                             /* lineNo */
    35,                             /* colNo */
    "categorical/getCategoryNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\g"
    "etCategoryNames.m" /* pName */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,              /* iFirst */
    -1,              /* iLast */
    49,              /* lineNo */
    27,              /* colNo */
    "",              /* aName */
    "isCharStrings", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\isCharSt"
    "rings.m", /* pName */
    0          /* checkKind */
};

static emlrtRTEInfo x_emlrtRTEI = {
    181,                       /* lineNo */
    21,                        /* colNo */
    "categorical/categorical", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\c"
    "ategorical.m" /* pName */
};

static emlrtRTEInfo y_emlrtRTEI = {
    197,                       /* lineNo */
    43,                        /* colNo */
    "categorical/categorical", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\c"
    "ategorical.m" /* pName */
};

/* Function Definitions */
uint32_T categorical_categorical(const emlrtStack *sp,
                                 const cell_wrap_5 inputData,
                                 const cell_wrap_5 varargin_1_data[],
                                 const int32_T varargin_1_size[2],
                                 cell_wrap_5 b_categoryNames_data[],
                                 int32_T *b_categoryNames_size)
{
  cell_wrap_5 inData;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_cell_wrap_5_11 r1;
  emxArray_cell_wrap_5_1x11 r;
  int32_T b_i;
  int32_T i;
  int32_T n;
  int32_T x_size;
  char_T tmp_data[2];
  int8_T mask_data[11];
  boolean_T bool_data[11];
  boolean_T x_data[11];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  st.site = &ud_emlrtRSI;
  b_st.site = &vd_emlrtRSI;
  strtrim(&b_st, inputData.f1.data, inputData.f1.size, inData.f1.data,
          inData.f1.size);
  st.site = &td_emlrtRSI;
  x_size = varargin_1_size[1];
  r.size[1] = varargin_1_size[1];
  for (i = 0; i < x_size; i++) {
    if (i > r.size[1] - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, r.size[1] - 1, &m_emlrtBCI, &st);
    }
    b_st.site = &vd_emlrtRSI;
    strtrim(&b_st, varargin_1_data[i].f1.data, varargin_1_data[i].f1.size,
            r.data[i].f1.data, r.data[i].f1.size);
  }
  st.site = &td_emlrtRSI;
  b_st.site = &hb_emlrtRSI;
  n = 1;
  if (varargin_1_size[1] > 1) {
    n = varargin_1_size[1];
  }
  if (varargin_1_size[1] > muIntScalarMax_sint32(varargin_1_size[1], n)) {
    emlrtErrorWithMessageIdR2018a(&st, &d_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  st.site = &sd_emlrtRSI;
  b_st.site = &sd_emlrtRSI;
  c_st.site = &ee_emlrtRSI;
  for (i = 0; i < x_size; i++) {
    if (i > x_size - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, x_size - 1, &p_emlrtBCI, &c_st);
    }
  }
  if (x_size - 1 >= 0) {
    memset(&x_data[0], 0, (uint32_T)x_size * sizeof(boolean_T));
  }
  for (i = 0; i < x_size; i++) {
    int32_T tmp_size[2];
    if (i > x_size - 1) {
      emlrtDynamicBoundsCheckR2012b(i, 0, x_size - 1, &l_emlrtBCI, &b_st);
    }
    c_st.site = &fe_emlrtRSI;
    strtrim(&c_st, r.data[i].f1.data, r.data[i].f1.size, tmp_data, tmp_size);
    if ((int8_T)tmp_size[1] == 0) {
      if (i + 1 > x_size) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, x_size, &k_emlrtBCI, &b_st);
      }
      x_data[i] = true;
    }
  }
  b_st.site = &ge_emlrtRSI;
  if (varargin_1_size[1] == 0) {
    n = 0;
  } else {
    n = x_data[0];
    for (i = 2; i <= x_size; i++) {
      n += x_data[i - 1];
    }
  }
  if (n > 1) {
    emlrtErrorWithMessageIdR2018a(
        sp, &x_emlrtRTEI, "MATLAB:categorical:MultipleMissingInValueset",
        "MATLAB:categorical:MultipleMissingInValueset", 0);
  }
  st.site = &rd_emlrtRSI;
  r1.size[0] = cellstr_unique(&st, r.data, varargin_1_size[1], r1.data);
  if (r1.size[0] != varargin_1_size[1]) {
    emlrtErrorWithMessageIdR2018a(sp, &y_emlrtRTEI,
                                  "MATLAB:categorical:DuplicatedValues",
                                  "MATLAB:categorical:DuplicatedValues", 0);
  }
  st.site = &qd_emlrtRSI;
  b_st.site = &gf_emlrtRSI;
  if (varargin_1_size[1] != 0) {
    int8_T uvalueSet_size_idx_0;
    boolean_T exitg1;
    boolean_T y;
    for (i = 0; i < x_size; i++) {
      bool_data[i] = false;
      b_i = r.data[i].f1.size[1];
      if (b_i == 0) {
        bool_data[i] = true;
      } else if (b_i == 0) {
        bool_data[i] = true;
      }
    }
    y = false;
    n = 1;
    exitg1 = false;
    while ((!exitg1) && (n <= x_size)) {
      if (bool_data[n - 1]) {
        y = true;
        exitg1 = true;
      } else {
        n++;
      }
    }
    if (y) {
      emlrtErrorWithMessageIdR2018a(&b_st, &v_emlrtRTEI,
                                    "MATLAB:categorical:EmptyCategoryName",
                                    "MATLAB:categorical:EmptyCategoryName", 0);
    }
    memset(&mask_data[0], 0, (uint32_T)x_size * sizeof(int8_T));
    for (i = 0; i < x_size; i++) {
      if (i > x_size - 1) {
        emlrtDynamicBoundsCheckR2012b(i, 0, x_size - 1, &o_emlrtBCI, &b_st);
      }
      if (i + 1 > x_size) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, x_size, &j_emlrtBCI, &b_st);
      }
      mask_data[i] = 1;
    }
    for (b_i = 0; b_i < x_size; b_i++) {
      x_data[b_i] = (mask_data[b_i] == 1);
    }
    y = true;
    n = 1;
    exitg1 = false;
    while ((!exitg1) && (n <= x_size)) {
      if (!x_data[n - 1]) {
        y = false;
        exitg1 = true;
      } else {
        n++;
      }
    }
    if (!y) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &u_emlrtRTEI, "MATLAB:categorical:CantCreateCategoryNames",
          "MATLAB:categorical:CantCreateCategoryNames", 0);
    }
    uvalueSet_size_idx_0 = (int8_T)varargin_1_size[1];
    *b_categoryNames_size = varargin_1_size[1];
    for (b_i = 0; b_i < uvalueSet_size_idx_0; b_i++) {
      if (b_i > *b_categoryNames_size - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, *b_categoryNames_size - 1,
                                      &i_emlrtBCI, &b_st);
      }
      b_categoryNames_data[b_i].f1.size[0] = 1;
      if (b_i > *b_categoryNames_size - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, *b_categoryNames_size - 1,
                                      &h_emlrtBCI, &b_st);
      }
      b_categoryNames_data[b_i].f1.size[1] = 0;
    }
    for (i = 0; i < x_size; i++) {
      if (i > x_size - 1) {
        emlrtDynamicBoundsCheckR2012b(i, 0, x_size - 1, &n_emlrtBCI, &b_st);
      }
      b_categoryNames_data[i].f1.size[0] = 1;
      n = r.data[i].f1.size[1];
      b_categoryNames_data[i].f1.size[1] = n;
      for (b_i = 0; b_i < n; b_i++) {
        b_categoryNames_data[i].f1.data[b_i] = r.data[i].f1.data[b_i];
      }
    }
  } else {
    *b_categoryNames_size = 0;
  }
  b_st.site = &hf_emlrtRSI;
  return categorical_getCodes(&b_st, inData, r.data, varargin_1_size[1]);
}

/* End of code generation (categorical.c) */
