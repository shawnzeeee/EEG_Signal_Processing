/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * bandpower.h
 *
 * Code generation for function 'bandpower'
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
real_T psdbandpower(const emlrtStack *sp, const real_T Pxx[257],
                    const real_T W[257], const real_T freqrange[2]);

/* End of code generation (bandpower.h) */
