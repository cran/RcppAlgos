#ifndef IMPORT_EXPORT_MPZ_H
#define IMPORT_EXPORT_MPZ_H

#include "cpp11/R.hpp"
#include "cpp11/protect.hpp"

#include <string>
#include <gmp.h>
#include <vector>

constexpr std::size_t intSize = sizeof(int);

// Functions for importing/exporting and converting SEXPs to mpz_t

void createMPZArray(SEXP input, mpz_t *myVec, std::size_t vecSize,
                    const std::string &nameOfObject, bool negPoss = false);

int myRaw(char* raw, const mpz_t value, std::size_t totals);

#endif
