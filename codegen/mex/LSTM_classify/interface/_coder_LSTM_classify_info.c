/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_LSTM_classify_info.c
 *
 * Code generation for function 'LSTM_classify'
 *
 */

/* Include files */
#include "_coder_LSTM_classify_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

/* Function Declarations */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void);

/* Function Definitions */
static const mxArray *c_emlrtMexFcnResolvedFunctionsI(void)
{
  const mxArray *nameCaptureInfo;
  const char_T *data[6] = {
      "789ced57dd6ed330147661a0dd6c9449f0185517b14ae30289b549416a4335b712629e5a"
      "37719b88c40989d39f5d4cbc01afc19bf010dcec51489aa46d3c59a9"
      "284444ec5cf4e4eb17fb3be7d8394e40e57db702003806b11d9ec4fe28c1d5c43f0259e3"
      "f94ae21f7338b527e020332ee5bf255e7328230b16038a6db21ea93b",
      "b6493165fda54b80477cc79a117dc54c4c8bf44d9bc06da046c856b6a83588a8e8ba6910"
      "ed330c6ce019fe26426b1baceb3112e47b90530fdef87af0f7fd2f7a"
      "77bfa997ceff35472fe5af06d7cdd768e013cf47d4d40c077da0a4e59933825a8e16d884"
      "321f41d733e954aa4b67485661f355fd0c35b1eb338792b6c98c608c",
      "64b93d84e694626bd8f31c8df87e38007531b3f058555107f6bbab9f7aed34f535a96663"
      "9657df673be6cbfbcdfd8719fca0f777f41682f976ddaf2f057a558e"
      "87d20554e4f38f33bb4e5a93e5fc13f48deebb4d1cbd1c9dbc3880001735ff9d60fcae75"
      "bc11cc5fe5f82bb9d0e77ea85938e426cb9a9dcd77df7df33c27df94",
      "0fcf4c0f6b2c8a656e52dd99836c1ca33de3782a8c23667427185be4cfadf3ad502fcb17"
      "b8cef74a1cad7551fde8f8fbcf155594de9ba346a348bdd4cadadf5f"
      "08f4aa1cdf682da6fac578e1ccbd4bd85354f7b22343f0d0dfcbfadcefbb6f4e72f24df9"
      "2488305e85601684df3ff1ff65edefffd6397ebfbafc393e12e453d6",
      "fefe43ba3e2d522fb5b2f6f75ddfdf3bb0f3565202bd3ff8723e085c5d356ca3ad94bfbf"
      "ff029d3e592c",
      ""};
  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(&data[0], 4640U, &nameCaptureInfo);
  return nameCaptureInfo;
}

mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[9] = {"Version",
                                    "ResolvedFunctions",
                                    "Checksum",
                                    "EntryPoints",
                                    "CoverageInfo",
                                    "IsPolymorphic",
                                    "PropertyList",
                                    "UUID",
                                    "ClassEntryPointIsHandle"};
  const char_T *epFieldName[8] = {
      "QualifiedName",    "NumberOfInputs", "NumberOfOutputs", "ConstantInputs",
      "ResolvedFilePath", "TimeStamp",      "Constructor",     "Visible"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 8, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 0, "QualifiedName",
                emlrtMxCreateString("LSTM_classify"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "ResolvedFilePath",
      emlrtMxCreateString(
          "C:"
          "\\Users\\nicho\\OneDrive\\Documents\\Spring2025\\ENSC405\\CapstoneGi"
          "thub\\EEG_Signal_Processing\\MatlabNN\\LSTM\\LSTM_classify"
          ".m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739714.82128472219));
  emlrtSetField(xEntryPoints, 0, "Constructor",
                emlrtMxCreateLogicalScalar(false));
  emlrtSetField(xEntryPoints, 0, "Visible", emlrtMxCreateLogicalScalar(true));
  xResult =
      emlrtCreateStructMatrix(1, 1, 9, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("24.2.0.2863752 (R2024b) Update 5"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)c_emlrtMexFcnResolvedFunctionsI());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("DkNyhcZiKbbzgF9Wt2w8bE"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/* End of code generation (_coder_LSTM_classify_info.c) */
