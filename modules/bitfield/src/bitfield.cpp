// Copyright 2020 Kudryashov Nikita

#include "include/bitfield.h"

Bitfield::Bitfield(unsigned int size) {
    bitfield_size = size;
    
    unsigned int quotient = size / 8;
    unsigned int remainder = size % 8;
    
    if (remainder == 0) {
        bitfield.reserve(quotient);
    } else {
        bitfield.reserve(quotient + 1);
    }
    
    // Bitfield object creates empty (having 0 at all positions).
    for (int i = 0; i < bitfield.capacity(); i++) {
        bitfield[i] = 0;
    }
}

void Bitfield::set(unsigned int position) {
    if (position > bitfield_size - 1) {
        throw "Out of bounds setting"; 
    } else {
        bitfield[position / 8] &= (1 << (7 - position % 8));
    }
}

void Bitfield::unset(unsigned int position)
{
    if (position > bitfield_size - 1) {
        throw "Out of bounds unsetting"; 
    } else {
        bitfield[position / 8] &= (~(1 << (7 - position % 8)));
    }
}

int Bitfield::get(unsigned int position) {
    return bitfield[position / 8] << (7 - position % 8);
}
 


