#include "BitInputStream.h"

#define BYTE 8

BitInputStream::BitInputStream(std::istream & is) : in(is){
            buf = 0;
            nbits = BYTE;
        }

void BitInputStream::fill(){
        buf = in.get();
        nbits = 0;
}
/*read the bit value*/
int BitInputStream::readBit(){
       

    if(nbits == BYTE)
        fill();

       
    ++nbits;
    
    return (buf >> (BYTE - nbits)) & 1;

    

}
/*return the char value of the Byte*/
char BitInputStream::readByte(){
    return in.get();
}


int BitInputStream::readInt(){
    int i = 0;
    in.read((char*)&i, sizeof(int));
    return i;
}


