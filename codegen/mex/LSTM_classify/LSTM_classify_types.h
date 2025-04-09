/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LSTM_classify_types.h
 *
 * Code generation for function 'LSTM_classify'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef struct_emxArray_char_T_1x2
#define struct_emxArray_char_T_1x2
struct emxArray_char_T_1x2 {
  char_T data[2];
  int32_T size[2];
};
#endif /* struct_emxArray_char_T_1x2 */
#ifndef typedef_emxArray_char_T_1x2
#define typedef_emxArray_char_T_1x2
typedef struct emxArray_char_T_1x2 emxArray_char_T_1x2;
#endif /* typedef_emxArray_char_T_1x2 */

#ifndef typedef_cell_wrap_5
#define typedef_cell_wrap_5
typedef struct {
  emxArray_char_T_1x2 f1;
} cell_wrap_5;
#endif /* typedef_cell_wrap_5 */

#ifndef typedef_emxArray_cell_wrap_5_11
#define typedef_emxArray_cell_wrap_5_11
typedef struct {
  cell_wrap_5 data[11];
  int32_T size[1];
} emxArray_cell_wrap_5_11;
#endif /* typedef_emxArray_cell_wrap_5_11 */

#ifndef typedef_categorical
#define typedef_categorical
typedef struct {
  uint32_T codes;
  emxArray_cell_wrap_5_11 categoryNames;
} categorical;
#endif /* typedef_categorical */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

/* End of code generation (LSTM_classify_types.h) */
