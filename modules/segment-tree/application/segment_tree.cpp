// Copyright 2020 Boganov Sergei

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/segment_tree_app.h"

int main(int argc, const char** argv) {
    SegmentTreeApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;