/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cellstr_unique.c
 *
 * Code generation for function 'cellstr_unique'
 *
 */

/* Include files */
#include "cellstr_unique.h"
#include "LSTM_classify_data.h"
#include "LSTM_classify_types.h"
#include "cellstr_sort.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
int32_T cellstr_unique(const emlrtStack *sp, const cell_wrap_5 a_data[],
                       int32_T a_size, cell_wrap_5 u_data[])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_cell_wrap_5_11 c;
  int32_T ia_data[11];
  int32_T idx_data[11];
  int32_T ii_data[11];
  int32_T b_i;
  int32_T i;
  int32_T idx_size;
  int32_T k;
  int32_T u_size;
  boolean_T b_d_data[11];
  boolean_T d_data[10];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if (a_size == 0) {
    u_size = 0;
  } else {
    int32_T d_size;
    int32_T loop_ub_tmp;
    int32_T nz;
    st.site = &he_emlrtRSI;
    c.size[0] = cellstr_sort(&st, a_data, a_size, c.data, idx_data, &idx_size);
    st.site = &ie_emlrtRSI;
    d_size = c.size[0] - 1;
    loop_ub_tmp = c.size[0];
    if (loop_ub_tmp - 2 >= 0) {
      memset(&d_data[0], 0, (uint32_T)(loop_ub_tmp - 1) * sizeof(boolean_T));
    }
    for (i = 0; i <= loop_ub_tmp - 2; i++) {
      if (i > d_size) {
        emlrtDynamicBoundsCheckR2012b(i, 0, d_size, &v_emlrtBCI, &st);
      }
      if (i + 1 > d_size) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 0, d_size, &w_emlrtBCI, &st);
      }
      d_data[i] = !b_strcmp(c.data[i].f1.data, c.data[i].f1.size,
                            c.data[i + 1].f1.data, c.data[i + 1].f1.size);
    }
    b_d_data[0] = true;
    if (d_size - 1 >= 0) {
      memcpy(&b_d_data[1], &d_data[0], (uint32_T)d_size * sizeof(boolean_T));
    }
    st.site = &je_emlrtRSI;
    b_st.site = &ge_emlrtRSI;
    nz = b_d_data[0];
    for (k = 2; k <= loop_ub_tmp; k++) {
      nz += b_d_data[k - 1];
    }
    u_size = (int32_T)muDoubleScalarMin(nz, a_size);
    st.site = &ke_emlrtRSI;
    b_st.site = &af_emlrtRSI;
    nz = eml_find(&b_st, b_d_data, c.size[0], ii_data);
    for (i = 0; i < nz; i++) {
      if (i + 1 != nz) {
        real_T y_data[11];
        real_T d;
        int32_T y_size_idx_1;
        st.site = &le_emlrtRSI;
        if (i + 1 > nz) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, nz, &u_emlrtBCI, &st);
        }
        if (i + 2 > nz) {
          emlrtDynamicBoundsCheckR2012b(i + 2, 1, nz, &t_emlrtBCI, &st);
        }
        b_st.site = &pe_emlrtRSI;
        d = (real_T)ii_data[i + 1] - 1.0;
        b_i = ii_data[i];
        if (d < b_i) {
          y_size_idx_1 = 0;
        } else {
          loop_ub_tmp = (int32_T)d - b_i;
          y_size_idx_1 = loop_ub_tmp + 1;
          for (k = 0; k <= loop_ub_tmp; k++) {
            y_data[k] = (real_T)b_i + (real_T)k;
          }
        }
        st.site = &le_emlrtRSI;
        for (b_i = 0; b_i < y_size_idx_1; b_i++) {
          d = y_data[b_i];
          if (d != (int32_T)d) {
            emlrtIntegerCheckR2012b(d, &c_emlrtDCI, &st);
          }
          if (((int32_T)d < 1) || ((int32_T)d > idx_size)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, idx_size, &bb_emlrtBCI,
                                          &st);
          }
        }
        b_st.site = &df_emlrtRSI;
        c_st.site = &ef_emlrtRSI;
        d_st.site = &ff_emlrtRSI;
        if (y_size_idx_1 < 1) {
          emlrtErrorWithMessageIdR2018a(
              &d_st, &bb_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
              "Coder:toolbox:eml_min_or_max_varDimZero", 0);
        }
        loop_ub_tmp = idx_data[(int32_T)y_data[0] - 1];
        for (k = 2; k <= y_size_idx_1; k++) {
          b_i = idx_data[(int32_T)y_data[k - 1] - 1];
          if (loop_ub_tmp > b_i) {
            loop_ub_tmp = b_i;
          }
        }
        if (i + 1 > nz) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, nz, &db_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        ia_data[i] = loop_ub_tmp;
      } else {
        real_T y_data[11];
        int32_T y_size_idx_1;
        st.site = &me_emlrtRSI;
        if (i + 1 > nz) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, nz, &s_emlrtBCI, &st);
        }
        b_st.site = &pe_emlrtRSI;
        b_i = ii_data[i];
        if (idx_size < b_i) {
          y_size_idx_1 = 0;
        } else {
          loop_ub_tmp = idx_size - b_i;
          y_size_idx_1 = loop_ub_tmp + 1;
          for (b_i = 0; b_i <= loop_ub_tmp; b_i++) {
            y_data[b_i] = ii_data[i] + b_i;
          }
        }
        st.site = &me_emlrtRSI;
        for (b_i = 0; b_i < y_size_idx_1; b_i++) {
          k = (int32_T)y_data[b_i];
          if ((k < 1) || (k > idx_size)) {
            emlrtDynamicBoundsCheckR2012b(k, 1, idx_size, &ab_emlrtBCI, &st);
          }
        }
        b_st.site = &df_emlrtRSI;
        c_st.site = &ef_emlrtRSI;
        d_st.site = &ff_emlrtRSI;
        if (y_size_idx_1 < 1) {
          emlrtErrorWithMessageIdR2018a(
              &d_st, &bb_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
              "Coder:toolbox:eml_min_or_max_varDimZero", 0);
        }
        loop_ub_tmp = idx_data[(int32_T)y_data[0] - 1];
        for (k = 2; k <= y_size_idx_1; k++) {
          b_i = idx_data[(int32_T)y_data[k - 1] - 1];
          if (loop_ub_tmp > b_i) {
            loop_ub_tmp = b_i;
          }
        }
        if (i + 1 > nz) {
          emlrtDynamicBoundsCheckR2012b(i + 1, 1, nz, &cb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        ia_data[i] = loop_ub_tmp;
      }
    }
    if (idx_size != c.size[0]) {
      emlrtSubAssignSizeCheck1dR2017a(idx_size, c.size[0], &c_emlrtECI,
                                      (emlrtConstCTX)sp);
    }
    for (b_i = 0; b_i < idx_size; b_i++) {
      k = idx_data[b_i];
      if ((k < 1) || (k > d_size + 1)) {
        emlrtDynamicBoundsCheckR2012b(k, 1, d_size + 1, &x_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
    }
    for (i = 0; i < nz; i++) {
      if (i + 1 > nz) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, nz, &y_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      b_i = ia_data[i];
      if ((b_i - 1 < 0) || (b_i - 1 > a_size - 1)) {
        emlrtDynamicBoundsCheckR2012b(b_i - 1, 0, a_size - 1, &q_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (i > u_size - 1) {
        emlrtDynamicBoundsCheckR2012b(i, 0, u_size - 1, &r_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      u_data[i].f1.size[0] = 1;
      loop_ub_tmp = a_data[b_i - 1].f1.size[1];
      u_data[i].f1.size[1] = loop_ub_tmp;
      for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
        u_data[i].f1.data[b_i] = a_data[ia_data[i] - 1].f1.data[b_i];
      }
    }
  }
  return u_size;
}

/* End of code generation (cellstr_unique.c) */
