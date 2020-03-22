// Copyright 2020 Devlikamov Vladislav

#ifndef MODULES_SEGMENT_TREE_INCLUDE_SEGMENT_TREE_H_
#define MODULES_SEGMENT_TREE_INCLUDE_SEGMENT_TREE_H_

#include <vector>

class SegmentTree {
 private:
    std::vector <int> tree;
 public:
    explicit SegmentTree(int size = 5);
};

#endif  // MODULES_SEGMENT_TREE_INCLUDE_SEGMENT_TREE_H_
