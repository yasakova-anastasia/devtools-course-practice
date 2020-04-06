// Copyright 2020 Kuzhelev Anton

#include <utility>
#include <vector>
#include "include/TPrime_Nums.h"

TPrime_Nums::TPrime_Nums(int left = 0, int right = 0) {
    left_edge = left;
    right_edge = right;
    if (left_edge < 0 || right_edge < 0 || left_edge > right_edge) {
        throw -1;
    }
}

std::pair<int, int> TPrime_Nums::GetInterval() {
    return std::make_pair(left_edge, right_edge);
}

std::vector<int> TPrime_Nums::Get_Prime_Nums() {
    std::vector<int> result;

    if (left_edge < 2) {
        left_edge = 2;
    }

    for (int i = left_edge; i <= right_edge; ++i) {
        int j;
        for (j = 2; j < i; ++j) {
            if (i % j == 0) {
                break;
            }
        }
        if (j == i) {
            result.push_back(i);
        }
    }
    return result;
}
