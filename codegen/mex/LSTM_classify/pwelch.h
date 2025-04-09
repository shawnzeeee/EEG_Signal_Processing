/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pwelch.h
 *
 * Code generation for function 'pwelch'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void pwelch(const emlrtStack *sp, const real_T x_data[], int32_T x_size,
            const real_T varargin_1_data[], int32_T varargin_1_size,
            real_T varargin_2, real_T varargout_1[257],
            real_T varargout_2[257]);

/* End of code generation (pwelch.h) */
