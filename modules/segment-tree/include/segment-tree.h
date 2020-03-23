// Copyright 2020 Devlikamov Vladislav

#ifndef MODULES_SEGMENT_TREE_INCLUDE_SEGMENT_TREE_H_
#define MODULES_SEGMENT_TREE_INCLUDE_SEGMENT_TREE_H_

#include <vector>

class SegmentTree {
 private:
    std::vector <int> tree;
    int _size;
    void build(const std::vector <int>& arr, int index, int left, int right);
    void update(int index, int l, int r, int change_index, int value);
    int sum(int index, int l, int r, int left, int right);
 public:
    explicit SegmentTree(int size = 5);
    explicit SegmentTree(const std::vector <int>& input);
    int sum(int left, int right);
    void update(int change_index, int value);
    std::vector <int> Get();
};

#endif  // MODULES_SEGMENT_TREE_INCLUDE_SEGMENT_TREE_H_
