// Copyright 2020 Kuzhelev Anton

#ifndef MODULES_PRIME_NUMBERS_INCLUDE_TPRIME_NUMS_H_
#define MODULES_PRIME_NUMBERS_INCLUDE_TPRIME_NUMS_H_

#pragma once

#include <utility>

class TPrime_Nums {
 public:
    TPrime_Nums(int left, int right);
    std::pair<int,int> GetPiece();
 private:
    int _left, _right;
};

#endif  // MODULES_PRIME_NUMBERS_INCLUDE_TPRIME_NUMS_H_
