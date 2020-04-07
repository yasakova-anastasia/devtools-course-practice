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

void TPrime_Nums::SetInterval(std::pair<int, int> interval) {
    if (interval.first < 0 || interval.second < 0
        || interval.first > interval.second) {
        throw -1;
    }
    left_edge = interval.first;
    right_edge = interval.second;
}

std::pair<int, int> TPrime_Nums::GetInterval() {
    return std::make_pair(left_edge, right_edge);
}

std::vector<int> TPrime_Nums::Get_Prime_Nums() {
    std::vector<int> result;

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
