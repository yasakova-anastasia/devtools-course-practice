// Copyright 2020 Antipin Alexander

#include "include/d-heap.h"

d_heap::d_heap() : d(2), size(3),
    keys(reinterpret_cast<size_t*>(operator new(sizeof(size_t) * 3))) {
    for (size_t i = 0; i < size; ++i)
        new(keys + i) size_t(-1);
}

d_heap::d_heap(const uint8_t d, const size_t size) : d(d), size(size),
    keys(reinterpret_cast<size_t*>(operator new(sizeof(size_t) * size))) {
    for (size_t i = 0; i < size; ++i)
        new(keys + i) size_t(-1);
}

d_heap::d_heap(const d_heap& copy) : d(copy.d), size(copy.size),
    keys(reinterpret_cast<size_t*>(operator new(sizeof(size_t) * size))) {
    for (size_t i = 0; i < size; ++i)
        new(keys + i) size_t(*(copy.keys + i));
}

d_heap::d_heap(d_heap&& copy) noexcept : d(copy.d), size(copy.size),
    keys(copy.keys) {
    copy.size = 0;
    copy.keys = nullptr;
}

d_heap::~d_heap() {
    for (size_t i = 0; i < size; ++i)
        (keys + i)->~size_t();
    operator delete(keys);
}

uint8_t d_heap::getD() const {
    return d;
}

size_t& d_heap::operator[](const size_t iter) {
    return *(keys + iter);
}

size_t d_heap::minChild(const size_t iter) {
    if (iter * d + 1 >= size)
        return 0;
    else {
        size_t i = firstChild(iter);
        size_t l = lastChild(iter);
        size_t elem = *(keys + i);
        for (size_t j = i + 1; j <= l; ++j) {
            if (elem > *(keys + j)) {
                elem = *(keys + j);
                i = j;
            }
        }
        return i;
    }
}

size_t d_heap::firstChild(const size_t iter) {
    size_t i = iter * d + 1;
    if (i > size)
        return 0;
    return i;
}

size_t d_heap::lastChild(const size_t iter) {
    size_t i = firstChild(iter);
    if (i == 0)
        return 0;
    else if (i + d - 1 > size)
        return size - 1;
    else
        return i + d - 1;
}

size_t d_heap::father(const size_t iter) {
    size_t i = iter / d;
    if (iter % d == 0)
        return i - 1;
    else
        return i;
}

void d_heap::ascent(const size_t iter) {
    size_t f = father(iter);
    size_t i = iter;
    while (i != 0 && *(keys + i) < *(keys + f)) {
        std::swap(*(keys + i), *(keys + f));
        i = f;
        f = father(i);
    }
}

void d_heap::immersion(const size_t iter) {
    size_t c = minChild(iter);
    size_t i = iter;
    while (c != 0 && *(keys + i) > * (keys + c)) {
        std::swap(*(keys + i), *(keys + c));
        i = c;
        c = minChild(i);
    }
}

void d_heap::insert(const size_t key) {
}

void d_heap::del(const size_t iter) {
}

void d_heap::key_decrease(const size_t iter, const size_t down_key) {
}

void d_heap::hilling() {
}
