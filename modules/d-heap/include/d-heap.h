// Copyright 2020 Antipin Alexander

#ifndef MODULES_D_HEAP_INCLUDE_D_HEAP_H_
#define MODULES_D_HEAP_INCLUDE_D_HEAP_H_

#include <stdint.h>
#include <new>
#include <iostream>

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
    size_t minChild(const size_t iter);
    size_t firstChild(const size_t iter);
    size_t lastChild(const size_t iter);
    size_t father(const size_t iter);
    void ascent(const size_t iter); // всполытие
    void immersion(const size_t iter); // погружение
    void insert(const size_t key); // вставка
    void del(const size_t iter); // удаление
    void key_decrease(const size_t iter, const  size_t down_key); // уменьшение ключа
    void hilling(); // окучивание
};

#endif // !MODULES_D-HEAP_INCLUDE_D-HEAP_H_
