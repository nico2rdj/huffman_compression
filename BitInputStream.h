#ifndef BITINPUTSTREAM_H
#define BITINPUTSTREAM_H

#include <iostream>

class BitInputStream{
    private:
        char buf;
        int nbits;
        std::istream & in;

    public:
        BitInputStream(std::istream & is);
        void fill();
        int readBit();
        char readByte();
        int readInt();

};

#endif
