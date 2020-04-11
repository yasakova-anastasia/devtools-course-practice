// Copyright 2020 Antipin Alexander

#include "include/d-heap.h"

d_heap::d_heap() : d(2), size(3),
    keys(reinterpret_cast<size_t*>(operator new(sizeof(size_t) * 3))) {}

d_heap::d_heap(const uint8_t d, const size_t size) : d(d), size(size),
    keys(reinterpret_cast<size_t*>(operator new(sizeof(size_t) * size))) {}

d_heap::d_heap(const d_heap& copy) {}

d_heap::d_heap(d_heap&& copy) noexcept {}

d_heap::~d_heap() {
    operator delete(keys);
}

uint8_t d_heap::getD() const {
    return d;
}

size_t& d_heap::operator[](const size_t iter) {
    size_t res = 0;
    return res;
}