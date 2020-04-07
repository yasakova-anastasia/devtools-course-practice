// Copyright 2020 Kudryashov Nikita

#include "include/bitfield.h"

Bitfield::Bitfield(unsigned int size) {
    bitfield_size = size;
    
    unsigned int quotient = size / 8;
    unsigned int remainder = size % 8;
    
    if (remainder == 0) {
        bitfield.resize(quotient);
    } else {
        bitfield.resize(quotient + 1);
    }
}

void Bitfield::set(unsigned int position) {
    if (position > bitfield_size - 1) {
        throw "Out of bounds setting"; 
    } else {
        bitfield[position / 8] &= (1 << (8 - position % 8));
    }
}
 


