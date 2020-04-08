// Copyright 2020 Kudryashov Nikita

// TODO: potentially remove 7,8 const and replace them with (char_size - 1), char_size to make
//          code more readable and easier to understand. THROUGH DEFINE

#include "include/bitfield.h"

Bitfield::Bitfield(unsigned int size) {
    bitfield_size = size;
    
    unsigned int quotient = size / 8;
    unsigned int remainder = size % 8;
    
    // Bitfield object creates empty (having 0 at all positions).
    if (remainder == 0) {
        bitfield.resize(quotient, 0);
    } else {
        bitfield.resize(quotient + 1, 0);
    }
}

void Bitfield::set(unsigned int position) {
    if (position > bitfield_size - 1) {
        throw "Out of bounds setting"; 
    } else {
        bitfield[position / 8] |= (1 << (7 - position % 8));
    }
}

unsigned int Bitfield::get_size() {
    return bitfield_size;
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
    unsigned char temp = (bitfield[position / 8] << (position % 8));
    return temp >> 7;
    
    // return ((bitfield[position / 8] << (position % 8)) >> 7); 
    // This doesn't work for some reason. Mb priorioty problems? Ask later.
}

void Bitfield::fill() {
    for(int i = 0; i < bitfield.capacity(); i++) {
        bitfield[i] = 255;
    }
}
 


