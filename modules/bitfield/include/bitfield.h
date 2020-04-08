// Copyright 2020 Kudryashov Nikita

// TODO: overload operator[]

#include <vector>

class Bitfield
{
    private:
        std::vector<unsigned char> bitfield; // Holds the set of bits counted from 0 to (size - 1) from left to right.
        unsigned int bitfield_size;
    public:
        Bitfield(unsigned int size = 0); 
        void set(unsigned int position); // Set specified position in Bitfield object to 1.
        void unset(unsigned int position); // Set specified position in Bitfield object to 0.
        int get(unsigned int position); // Return the value of specified position in Bitfield object.
        unsigned int get_size(); // Return the size of Bitfield object.
        void fill(); // Set value to 1 in all positions of Bitfield object.
};