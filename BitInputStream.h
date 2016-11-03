#ifndef BITINPUTSTREAM_H
#define BITINPUTSTREAM_H

#include <iostream>

class BitInputStream{
    private:
        char buf;
        int nbits;
        std::istream & in;

    public:
        BitInputStream(std::istream & is) : in(is);
        void fill();
        int readBit();

};

#endif
