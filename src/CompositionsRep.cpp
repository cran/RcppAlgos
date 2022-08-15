#include "Partitions/NextComposition.h"
#include "RMatrix.h"
#include <algorithm>  // std::next_permutation

template <int one_or_zero, typename T>
void CompsGenRep(T* mat, const std::vector<T> &v,
                 std::vector<int> &z, int width, int nRows) {

    for (int count = 0, lastCol = width - 1; count < nRows; ++count,
         NextCompositionRep<one_or_zero>(z, lastCol)) {

        for (int k = 0; k < width; ++k) {
            mat[count + nRows * k] = v[z[k]];
        }
    }
}

template <int one_or_zero, typename T>
void CompsGenRep(RcppParallel::RMatrix<T> &mat, const std::vector<T> &v,
                 std::vector<int> &z, int strt, int width, int nRows) {

    for (int count = strt, lastCol = width - 1; count < nRows; ++count,
         NextCompositionRep<one_or_zero>(z, lastCol)) {

        for (int k = 0; k < width; ++k) {
            mat(count, k) = v[z[k]];
        }
    }
}

template <int one_or_zero>
void CompsRep(int* mat, std::vector<int> &z,
              int width, int nRows) {

    for (int count = 0, lastCol = width - 1; count < nRows; ++count,
         NextCompositionRep<one_or_zero>(z, lastCol)) {

        for (int k = 0; k < width; ++k) {
            mat[count + nRows * k] = z[k];
        }
    }
}

template <int one_or_zero>
void CompsRep(RcppParallel::RMatrix<int> &mat, std::vector<int> &z,
              int strt, int width, int nRows) {

    for (int count = strt, lastCol = width - 1; count < nRows; ++count,
         NextCompositionRep<one_or_zero>(z, lastCol)) {

        for (int k = 0; k < width; ++k) {
            mat(count, k) = z[k];
        }
    }
}

template void CompsGenRep<0>(int*, const std::vector<int>&,
                             std::vector<int>&, int, int);
template void CompsGenRep<0>(double*, const std::vector<double>&,
                             std::vector<int>&, int, int);
template void CompsGenRep<1>(int*, const std::vector<int>&,
                             std::vector<int>&, int, int);
template void CompsGenRep<1>(double*, const std::vector<double>&,
                             std::vector<int>&, int, int);

template void CompsGenRep<0>(RcppParallel::RMatrix<int>&,
                             const std::vector<int>&,
                             std::vector<int>&, int, int, int);
template void CompsGenRep<0>(RcppParallel::RMatrix<double>&,
                             const std::vector<double>&,
                             std::vector<int>&, int, int, int);
template void CompsGenRep<1>(RcppParallel::RMatrix<int>&,
                             const std::vector<int>&,
                             std::vector<int>&, int, int, int);
template void CompsGenRep<1>(RcppParallel::RMatrix<double>&,
                             const std::vector<double>&,
                             std::vector<int>&, int, int, int);

template void CompsRep<0>(int* mat, std::vector<int>&, int, int);
template void CompsRep<1>(int* mat, std::vector<int>&, int, int);

template void CompsRep<0>(RcppParallel::RMatrix<int>&,
                          std::vector<int>&, int, int, int);
template void CompsRep<1>(RcppParallel::RMatrix<int>&,
                          std::vector<int>&, int, int, int);
