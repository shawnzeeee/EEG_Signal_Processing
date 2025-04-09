/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LSTM_classify_internal_types.h
 *
 * Code generation for function 'LSTM_classify'
 *
 */

#pragma once

/* Include files */
#include "LSTM_classify_types.h"
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_cell_wrap_2
#define typedef_cell_wrap_2
typedef struct {
  real32_T f1[32];
} cell_wrap_2;
#endif /* typedef_cell_wrap_2 */

#ifndef typedef_cell_wrap_3
#define typedef_cell_wrap_3
typedef struct {
  cell_wrap_2 f1[2];
} cell_wrap_3;
#endif /* typedef_cell_wrap_3 */

#ifndef c_typedef_c_coder_internal_ctar
#define c_typedef_c_coder_internal_ctar
typedef struct {
  boolean_T matlabCodegenIsDeleted;
  cell_wrap_3 InternalState[1];
  boolean_T IsNetworkInitialized;
} c_coder_internal_ctarget_DeepLe;
#endif /* c_typedef_c_coder_internal_ctar */

#ifndef typedef_cell_wrap_55
#define typedef_cell_wrap_55
typedef struct {
  real32_T f1[11];
} cell_wrap_55;
#endif /* typedef_cell_wrap_55 */

#ifndef typedef_cell_wrap_32
#define typedef_cell_wrap_32
typedef struct {
  real_T f1[80];
} cell_wrap_32;
#endif /* typedef_cell_wrap_32 */

#ifndef c_typedef_emxArray_cell_wrap_5_
#define c_typedef_emxArray_cell_wrap_5_
typedef struct {
  cell_wrap_5 data[11];
  int32_T size[2];
} emxArray_cell_wrap_5_1x11;
#endif /* c_typedef_emxArray_cell_wrap_5_ */

#ifndef typedef_rtDesignRangeCheckInfo
#define typedef_rtDesignRangeCheckInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtDesignRangeCheckInfo;
#endif /* typedef_rtDesignRangeCheckInfo */

#ifndef typedef_rtRunTimeErrorInfo
#define typedef_rtRunTimeErrorInfo
typedef struct {
  int32_T lineNo;
  int32_T colNo;
  const char_T *fName;
  const char_T *pName;
} rtRunTimeErrorInfo;
#endif /* typedef_rtRunTimeErrorInfo */

/* End of code generation (LSTM_classify_internal_types.h) */
