// Copyright 2020 Kuzhelev Anton

#include "include/TPrime_Nums.h"

TPrime_Nums::TPrime_Nums(int left = 0, int right = 0) {
    _left = left;
    _right = right;
    if(_right < 0 || _left > _right){
        throw -1;
    }
    if(_left < 0){
        _left = 0;
    }
}

std::pair<int,int> TPrime_Nums::GetPiece() {
    return std::make_pair(_left,_right);
}
