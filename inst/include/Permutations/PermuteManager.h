#pragma once

#include "cpp11/R.hpp"

#include "RMatrix.h"
#include <vector>

template <typename T>
void PermuteManager(T* mat, const std::vector<T> &v,
                    std::vector<int> &z, int n, int m, int nRows,
                    int phaseOne, bool generalRet, bool IsMult,
                    bool IsRep, const std::vector<int> &freqs);

template <typename T>
void PermuteParallel(RcppParallel::RMatrix<T> &mat, const std::vector<T> &v,
                     std::vector<int> &z, int n, int m, int strt, int nRows,
                     const std::vector<int> &freqs, bool IsMult, bool IsRep);

void PermuteCharacter(SEXP mat, SEXP v, std::vector<int> &z, int n,
                      int m, int nRows, const std::vector<int> &freqs,
                      bool IsMult, bool IsRep);
