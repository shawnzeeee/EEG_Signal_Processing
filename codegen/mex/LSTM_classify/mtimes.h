/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mtimes.h
 *
 * Code generation for function 'mtimes'
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
void b_mtimes(const real32_T B[20], real32_T C[96]);

void c_mtimes(const real32_T A[1024], const real32_T B[32], real32_T C[32]);

void d_mtimes(const real32_T A[640], const real32_T B[20], real32_T C[32]);

void mtimes(const real32_T B[32], real32_T C[96]);

/* End of code generation (mtimes.h) */
