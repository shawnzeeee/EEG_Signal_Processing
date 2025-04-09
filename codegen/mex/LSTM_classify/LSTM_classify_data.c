/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LSTM_classify_data.c
 *
 * Code generation for function 'LSTM_classify_data'
 *
 */

/* Include files */
#include "LSTM_classify_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                               /* bFirstTime */
    false,                                              /* bInitialized */
    131659U,                                            /* fVersionInfo */
    NULL,                                               /* fErrorFunction */
    "LSTM_classify",                                    /* fFunctionName */
    NULL,                                               /* fRTCallStack */
    false,                                              /* bDebugMode */
    {863993249U, 1796024129U, 2942447330U, 263153725U}, /* fSigWrd */
    NULL                                                /* fSigMem */
};

emlrtRSInfo g_emlrtRSI = {
    1,                              /* lineNo */
    "Network/setupAndResetNetwork", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024b\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\+ctarget\\@Network\\Network.p" /* pathName */
};

emlrtRSInfo gb_emlrtRSI = {
    93,                   /* lineNo */
    "validateattributes", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes"
    ".m" /* pathName */
};

emlrtRSInfo hb_emlrtRSI = {
    51,                  /* lineNo */
    "reshapeSizeChecks", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pathName */
};

emlrtRSInfo ge_emlrtRSI = {
    15,    /* lineNo */
    "sum", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" /* pathName
                                                                        */
};

emlrtRSInfo he_emlrtRSI = {
    17,               /* lineNo */
    "cellstr_unique", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "unique.m" /* pathName */
};

emlrtRSInfo ie_emlrtRSI = {
    20,               /* lineNo */
    "cellstr_unique", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "unique.m" /* pathName */
};

emlrtRSInfo je_emlrtRSI = {
    28,               /* lineNo */
    "cellstr_unique", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "unique.m" /* pathName */
};

emlrtRSInfo ke_emlrtRSI = {
    30,               /* lineNo */
    "cellstr_unique", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "unique.m" /* pathName */
};

emlrtRSInfo le_emlrtRSI = {
    37,               /* lineNo */
    "cellstr_unique", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "unique.m" /* pathName */
};

emlrtRSInfo me_emlrtRSI = {
    39,               /* lineNo */
    "cellstr_unique", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "unique.m" /* pathName */
};

emlrtRSInfo pe_emlrtRSI =
    {
        28,      /* lineNo */
        "colon", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pathName
                                                                          */
};

emlrtRSInfo af_emlrtRSI = {
    39,     /* lineNo */
    "find", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pathName
                                                                       */
};

emlrtRSInfo df_emlrtRSI = {
    15,    /* lineNo */
    "min", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\datafun\\min.m" /* pathName
                                                                        */
};

emlrtRSInfo ef_emlrtRSI =
    {
        66,         /* lineNo */
        "minOrMax", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

emlrtRSInfo ff_emlrtRSI =
    {
        112,       /* lineNo */
        "minimum", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

omp_lock_t emlrtLockGlobal;

omp_nest_lock_t LSTM_classify_nestLockGlobal;

emlrtRTEInfo d_emlrtRTEI = {
    80,                  /* lineNo */
    13,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\reshapeSizeChecks.m" /* pName */
};

emlrtRTEInfo i_emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatenonnan", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenonnan.m" /* pName */
};

emlrtRTEInfo j_emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatefinite", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatefinite.m" /* pName */
};

emlrtRTEInfo bb_emlrtRTEI = {
    198,             /* lineNo */
    27,              /* colNo */
    "unaryMinOrMax", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pName */
};

emlrtBCInfo q_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    59,               /* lineNo */
    18,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "unique.m", /* pName */
    0           /* checkKind */
};

emlrtBCInfo r_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    59,               /* lineNo */
    11,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "unique.m", /* pName */
    0           /* checkKind */
};

emlrtECInfo c_emlrtECI = {
    -1,               /* nDims */
    56,               /* lineNo */
    5,                /* colNo */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "unique.m" /* pName */
};

emlrtBCInfo s_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    39,               /* lineNo */
    35,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "unique.m", /* pName */
    0           /* checkKind */
};

emlrtBCInfo t_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    37,               /* lineNo */
    44,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "unique.m", /* pName */
    0           /* checkKind */
};

emlrtBCInfo u_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    37,               /* lineNo */
    35,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "unique.m", /* pName */
    0           /* checkKind */
};

emlrtBCInfo v_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    11,             /* lineNo */
    27,             /* colNo */
    "",             /* aName */
    "cellstr_diff", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "diff.m", /* pName */
    0         /* checkKind */
};

emlrtBCInfo w_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    11,             /* lineNo */
    32,             /* colNo */
    "",             /* aName */
    "cellstr_diff", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "diff.m", /* pName */
    0         /* checkKind */
};

emlrtBCInfo x_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    56,               /* lineNo */
    8,                /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "unique.m", /* pName */
    0           /* checkKind */
};

emlrtBCInfo y_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    59,               /* lineNo */
    21,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "unique.m", /* pName */
    0           /* checkKind */
};

emlrtBCInfo ab_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    39,               /* lineNo */
    30,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "unique.m", /* pName */
    0           /* checkKind */
};

emlrtDCInfo c_emlrtDCI = {
    37,               /* lineNo */
    30,               /* colNo */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "unique.m", /* pName */
    1           /* checkKind */
};

emlrtBCInfo bb_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    37,               /* lineNo */
    30,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "unique.m", /* pName */
    0           /* checkKind */
};

emlrtBCInfo cb_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    39,               /* lineNo */
    16,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "unique.m", /* pName */
    0           /* checkKind */
};

emlrtBCInfo db_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    37,               /* lineNo */
    16,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2024b\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_"
    "unique.m", /* pName */
    0           /* checkKind */
};

emlrtRSInfo nf_emlrtRSI = {
    1,                             /* lineNo */
    "elementwiseOperationInPlace", /* fcnName */
    "C:"
    "\\ProgramData\\MATLAB\\SupportPackages\\R2024b\\toolbox\\shared\\dlcoder_"
    "base\\supportpackages\\shared_dl_targets\\+coder\\+in"
    "ternal\\+layer\\elementwiseOperationInPlace.p" /* pathName */
};

/* End of code generation (LSTM_classify_data.c) */
