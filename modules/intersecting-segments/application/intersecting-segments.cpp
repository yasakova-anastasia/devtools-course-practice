// Copyright 2020 Maximova Irina

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/segments_app.h"

int main(int argc, const char** argv) {
    Segment_app app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
