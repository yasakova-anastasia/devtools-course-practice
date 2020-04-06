// Copyright 2020 Kuzhelev Anton

#include <utility>
#include <vector>
#include "include/TPrime_Nums.h"

TPrime_Nums::TPrime_Nums(int left = 0, int right = 0) {
    _left = left;
    _right = right;
    if (_left < 0 || _right < 0 || _left > _right) {
        throw -1;
    }
}

std::pair<int, int> TPrime_Nums::GetPiece() {
    return std::make_pair(_left, _right);
}

std::vector<int> TPrime_Nums::Get_Prime_Nums() {
    std::vector<int> result;

    if (_left < 2 && _right < 2) {
        return result;
    }

    if (_left < 2) {
        _left = 2;
    }

    bool flag;

    for (int i = _left; i <= _right; ++i) {
        flag = false;
        for (int j = 2; j < i; ++j) {
            if (i % j == 0) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            result.push_back(i);
        }
    }
    return result;
}
