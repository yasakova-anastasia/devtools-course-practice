// Copyright 2020 Yasakova Anastasia

#include <vector>
#include <string>
#include <sstream>
#include "include/queue_application.h"

std::string QueueApp::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return _sstream.str();
    }
    try {
        int i = 1;
        while (i < argc) {
            int check = 0;
            std::string op = *(argv + i);
            if (op == "getElement") {
                check = 1;
                _sstream << "GetElem = " << queue.Get() << ", ";
            }
            if (op == "topElement") {
                check = 2;
                _sstream << "TopElem = " << queue.TopElem() << ", ";
            }
            if (op == "putElement") {
                check = 3;
                queue.Put(ParseValue(*(argv + i + 1)));
            }
            if (op == "getCount") {
                check = 4;
                _sstream << "Number of Elements = " << queue.GetCount();
            }
            if (check == 0)
                throw std::string("Bad arguments!");
            ++i;
            if (check == 3)
                ++i;
        }
        return _sstream.str();
    } catch(std::string str) {
        return str;
    }
}

std::string QueueApp::help(const char* appname, const char* message) {
    std::cout << message << std::endl;
    return std::string(message) + "This is a Queue application.\n\n"+
        "Please provide arguments in the following format:\n\n"+
        "  $ " + appname + " <actions> \n\n" +
        "Where <actions> are: \n\n" +
        "getElement - get front element from queue\n" +
        "topElement - access to front element from queue\n" +
        "putElement <data> - insert element into queue\n" +
        "getCount - get number of elements in queue\n ";
}

bool QueueApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        _sstream << help(argv[0]);
        return false;
    }
    return true;
}

int QueueApp::ParseValue(std::string data) {
    int unsigned j = 0;
    int sign = 1;
    int number = 0;
    while (j != data.size()) {
        if (!std::isdigit(data[j]) && data[j] != '-')
            throw std::string("Invalid value: " + std::string(data));
        if (j == 0 && data[j] == '-')
            sign = -1;
        else
            number = number * 10 + data[j] - 48;
        ++j;
    }
    number *= sign;
    return number;
}
