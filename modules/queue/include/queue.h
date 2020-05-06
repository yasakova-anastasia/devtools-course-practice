// Copyright 2020 Sinitsina Maria

#ifndef MODULES_QUEUE_INCLUDE_QUEUE_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_H_

#include <iostream>
#include <vector>

class Queue {
 private:
    std::size_t tail_;
    std::size_t head_;
    std::vector<std::size_t> pq_;
    std::size_t size_;
    int count_;

    int GetNextIndex(int index) const;

 public:
    explicit Queue(int s = 10);
    Queue(const Queue &q);

    void Put(int val);
    int Get();
    int TopElem() const;
    int GetCount() const;
};
#endif  // MODULES_QUEUE_INCLUDE_QUEUE_H_
