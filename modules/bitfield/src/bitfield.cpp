// Copyright 2020 Kudryashov Nikita

// TODO: potentially remove 7,8 const and replace them with (char_size - 1), char_size to make
//          code more readable and easier to understand. THROUGH DEFINE

#include "include/bitfield.h"
#include <string>

Bitfield::Bitfield(unsigned int size) {
    bitfield_size = size;
    
    unsigned int quotient = size / 8;
    unsigned int remainder = size % 8;
    
    // Bitfield object creates empty (having 0 at all positions).
    if (remainder == 0) {
        bitfield.resize(quotient, 0); // Resize vector to specified size and fill with elements.
    } else {
        bitfield.resize(quotient + 1, 0); // Resize vector to specified size and fill with elements.
    }
}

void Bitfield::set(unsigned int position) {
    if (position > bitfield_size - 1) {
        throw (std::string)"Out of bounds setting"; 
    } else {
        bitfield[position / 8] |= (1 << (7 - position % 8));
    }
}

unsigned int Bitfield::get_size() const{
    return bitfield_size;
}

void Bitfield::unset(unsigned int position)
{
    if (position > bitfield_size - 1) {
        throw (std::string)"Out of bounds unsetting"; 
    } else {
        bitfield[position / 8] &= (~(1 << (7 - position % 8)));
    }
}

int Bitfield::get(unsigned int position) const{
    if (position > bitfield_size - 1) {
        throw (std::string)"Out of bounds unsetting"; 
    } else {
        unsigned char temp = (bitfield[position / 8] << (position % 8));
        return temp >> 7;
    }
    
    // return ((bitfield[position / 8] << (position % 8)) >> 7); 
    // This doesn't work for some reason. Mb priorioty problems? Ask later.
}

void Bitfield::fill() {
    for(int i = 0; i < bitfield.size(); i++) {
        bitfield[i] = 255;
    }
}

void Bitfield::clear() {
    for(int i = 0; i < bitfield.size(); i++) {
        bitfield[i] = 0;
    }
}

void Bitfield::set(std::vector<unsigned int> arr_of_positions) {
    for (int i = 0; i < arr_of_positions.size(); i++) {
        if(arr_of_positions[i] > bitfield_size - 1) {
            throw (std::string)"Out of bounds setting";
        } else {
            this->set(arr_of_positions[i]);
        }
    }
}

void Bitfield::unset(std::vector<unsigned int> arr_of_positions) {
    for (int i = 0; i < arr_of_positions.size(); i++) {
        if(arr_of_positions[i] > bitfield_size - 1) {
            throw (std::string)"Out of bounds unsetting";
        } else {
            this->unset(arr_of_positions[i]);
        }
    }
}

Bitfield& Bitfield::operator =(const Bitfield& arg) {
    if(this != &arg) {
        if(bitfield_size != arg.bitfield_size) {
            bitfield.resize(arg.bitfield_size);
        }
        for (int i = 0; i < arg.bitfield_size; i++) {
            bitfield[i] = arg.bitfield[i];
        }
    } 

    return *this;
}

bool Bitfield::operator ==(const Bitfield& rhs) const {
    if (bitfield_size != rhs.bitfield_size) {
        return false;
    } else {
        for(int i = 0; i < rhs.get_size(); i++) {
            if(this->get(i) != rhs.get(i)) {
                return false;
            }
        }
        return true;
    }
}

bool Bitfield::operator !=(const Bitfield& rhs) const{
    return  !(*this == rhs);
}

int Bitfield::operator [](unsigned int position) const {
    if(position > bitfield_size - 1) {
        throw (std::string)"Out of bounds getting.";
    } else {
        return get(position);
    }
}
 
 


