// Copyright 2020 Antipin Alexander

#ifndef MODULES_D_HEAP_INCLUDE_D_HEAP_H_
#define MODULES_D_HEAP_INCLUDE_D_HEAP_H_

#include <stdint.h>
#include <new>

class d_heap {
 protected:
    uint8_t d;
    size_t size;
    size_t* keys;
 public:
    d_heap();
    d_heap(const uint8_t d, const size_t size);
    d_heap(const d_heap& copy);
    d_heap(d_heap&& copy) noexcept;
    ~d_heap();
    uint8_t getD() const;
    size_t& operator[](const size_t iter);
};

#endif // !MODULES_D-HEAP_INCLUDE_D-HEAP_H_
