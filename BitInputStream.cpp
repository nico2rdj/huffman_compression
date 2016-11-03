include "BitInputStream.h"


BitInputStream::BitInputStream(std::istream & is) : in(is){
            buf = 0;
            nbits = 8;
        }

void BitInputStream::fill(){
        buf = in.get();
        nbits = 0;
}

int BitInputSTream::readBit(){
    
    if(nbits == 8)
        fill();

    int bit = buf & 1;
    buf = buf >> 1;
    ++nbits;
    
    return bit;
}



