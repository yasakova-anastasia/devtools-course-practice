// Copyright 2020 Kudryashov Nikita

#include <string>
#include <vector>
#include <utility>
#include "../include/triangle_param.h"
#include "../include/triangle_param_calculator.h"

std::string TriangleParamCalculator::help() {
    std::string syntax = "Follow syntax rules:\n1. First, one must write 3 points for triangle A, B, C in this way: \
A < x value of A > < y value of A > B < x value of B > < y value of B > \
C < x value of C > < y value of C >\n2.Second, one must write his requests to calculate \
in any order, each followed by space.\n  2.1 List of all possible requests:\n\
    < LengthAB > for AB length's side\n\
    < LengthBC > for BC length's side\n\
    < LengthAC > for AC length's side\n\
    < CornerA > for A corner value\n\
    < CornerB > for B corner value\n\
    < CornerC > for C corner value\n\
    < Perimeter> for triangle perimiter value\n\
    < Square > for triangle square value\n\
    < All > for all available parameters\n\
Example: A 0.1 2.2 B 4.3 3.2 C 3.3 10.1 Square \
LengthAB CornerA";
    return syntax;
}
std::vector<std::string> TriangleParamCalculator::parseRequests(int argc, const char** argv){
    unsigned int size = argc - 10;
    std::vector<std::string> res(size);
    for(unsigned int i = 0; i < res.size(); ++i) {
        if(strcmp(argv[10 + i], "LengthAB") != 0 && strcmp(argv[10 + i], "LengthBC") != 0 && 
            strcmp(argv[10 + i], "LengthAC") != 0 && strcmp(argv[10 + i], "CornerA") != 0 &&
            strcmp(argv[10 + i], "CornerB") != 0 && strcmp(argv[10 + i], "CornerC") != 0 &&
            strcmp(argv[10 + i], "Perimeter") != 0 && strcmp(argv[10 + i], "Square") != 0 &&
            strcmp(argv[10 + i], "All") != 0) {
                throw(std::string)"Wrong requests arguments. Please, follow the syntax.\n";
            } else {
                res[i] = argv[10 + i];
            }
    }
    
    return res;
}

Triangle TriangleParamCalculator::parseTriangleData(int argc, const char** argv) {
    std::string temp;
    std::pair<double, double> a, b, c;
    if (strcmp(argv[1], "A") != 0 && strcmp(argv[4], "B") != 0 && strcmp(argv[7], "C") != 0) {
        throw (std::string)"Wrong top names arguments. Please, follow the syntax.\n";
    }
    try {
        // A set
        temp = argv[2];
        a.first = stod(temp);
        
        temp = argv[3];
        a.second = stod(temp);
        
        // B set
        temp = argv[5];
        b.first = stod(temp);
        
        temp = argv[6];
        b.second = stod(temp);
        
        // C set
        temp = argv[8];
        c.first = stod(temp);
        
        temp = argv[9];
        c.second = stod(temp);
        
        return Triangle(a, b, c);
    } catch(const int e) {
        throw (std::string)"Three of your points are in the same line\n.";
    } catch (...) {
        throw (std::string)"Wrong number type arguments. Please, follow the syntax.\n";
    } 
    
}

std::string TriangleParamCalculator::calculate(int argc, const char** argv) {
    Triangle t;
    std::vector<std::string> requests;
    std::string answer;
    
    if (argc < 9) {
        return help();
    }
    
    try {
        t = parseTriangleData(argc, argv);
    } catch (std::string err) {
        return err;
    }
    
    try {
        requests = parseRequests(argc, argv);
    } catch (std::string err) {
        return err;
    }
    
    answer += "Requested calculations:\n";
    for(unsigned int i = 0; i < requests.size(); ++i) {
        if (requests[i] != (std::string)"All") {
            answer += (std::to_string(i + 1) + ". " + requests[i] + " = ");
        } else {
            answer += (std::to_string(i + 1) + ". " + requests[i] + "\n");
        }
        
        if (requests[i] == (std::string)"LengthAB") {
            answer += (std::to_string(t.side(t.getTopB(),t.getTopC())) + "\n");
        }
        
        if (requests[i] == (std::string)"LengthBC") {
            answer += (std::to_string(t.side(t.getTopB(),t.getTopC())) + "\n");
        }
        
        if (requests[i] == (std::string)"LengthAC") {
            answer += (std::to_string(t.side(t.getTopA(),t.getTopC())) + "\n");
        }
        
        if (requests[i] == (std::string)"CornerA") {
            answer += (std::to_string(t.cornA()) + "\n");
        }
        
        if (requests[i] == (std::string)"CornerB") {
            answer += (std::to_string(t.cornB()) + "\n");
        }
        
        if (requests[i] == (std::string)"CornerC") {
            answer += (std::to_string(t.cornC()) + "\n");
        }
        
        if (requests[i] == (std::string)"Perimeter") {
            answer += (std::to_string(t.perimetr()) + "\n");
        }
        
        if (requests[i] == (std::string)"Square") {
            answer += (std::to_string(t.square()) + "\n");
        }
        
        if (requests[i] == (std::string)"All") {
            answer += ("LengthAB = " + std::to_string(t.side(t.getTopA(),t.getTopB())) + "\n");
            answer += ("LengthBC = " + std::to_string(t.side(t.getTopB(),t.getTopC())) + "\n");
            answer += ("LengthAC = " + std::to_string(t.side(t.getTopA(),t.getTopC())) + "\n");
            answer += ("CornerA = " + std::to_string(t.cornA()) + "\n");
            answer += ("CornerB = " + std::to_string(t.cornB()) + "\n");
            answer += ("CornerC = " + std::to_string(t.cornC()) + "\n");
            answer += ("Perimeter = " + std::to_string(t.perimetr()) + "\n");
            answer += ("Square = " + std::to_string(t.square()) + "\n");
        }
    }
    
    return answer;
}