// Copyright 2020 Devlikamov Vladislav

#include <include/segment-tree.h>
#include <vector>

SegmentTree::SegmentTree(int size) {
    tree.resize(4*size);
}

SegmentTree::SegmentTree(const std::vector <int>& input) {
    int size = static_cast<int>(input.size());
    tree.resize(4*size);
    build(input, 1, 0, size - 1);
}

void SegmentTree::build(const std::vector <int>& arr, int index,
                        int left, int right) {
    if (left == right) {
        tree[index] = arr[left];
    } else {
        int mid = (left + right)/2;
        build(arr, 2*index, left, mid);
        build(arr, 2*index + 1, mid + 1, right);
        tree[index] = tree[2*index] + tree[2*index + 1];
    }
}

std::vector <int> SegmentTree::Get() {
    return tree;
}
