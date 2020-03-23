// Copyright 2020 Devlikamov Vladislav

#include <include/segment-tree.h>
#include <vector>
#include <algorithm>

SegmentTree::SegmentTree(int size) {
    if (size <= 0) {
        throw "Cannot be negative or zero size";
    } else {
        _size = size;
        tree.resize(4*size);
    }
}

SegmentTree::SegmentTree(const std::vector <int>& input) {
    int size = static_cast<int>(input.size());
    if (size <= 0) {
        throw "Cannot be negative or zero size";
    } else {
        _size = size;
        tree.resize(4*size);
        build(input, 1, 0, size - 1);
    }
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

int SegmentTree::sum(int index, int l, int r, int left, int right) {
    if (left > right) {
        return 0;
    } else if (left == l && right == r) {
        return tree[index];
    } else {
        int mid = (l + r)/2;
        return sum(2*index, l, mid, left, std::min(right, mid)) +
            sum(2*index + 1, mid + 1, r, std::max(left, mid + 1), right);
    }
}

int SegmentTree::sum(int left, int right) {
    if (left < 0 || right < 0) {
        throw "left or right interval cannot be negative";
    }
    if (right < left) {
        throw "left interval cannot be > than right";
    }
    if (right >= _size) {
        throw "right interval cannot be > that size";
    }
    if (left != 0) {
        return sum(1, 0, _size - 1, 0, right) -
               sum(1, 0, _size - 1, 0, left - 1);
    } else {
        return sum(1, 0, _size - 1, 0, right);
    }
}
