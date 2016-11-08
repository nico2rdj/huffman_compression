
#include "BitOutputStream.h"


#define BYTE 8


/* write bit into the buffer*/
void BitOutputStream::writeBit(int i){

	/*If numBits is a full byte, flush the buffer*/ 
	if(nbits == BYTE)
		flush(); 

	/*Clear buffer at index, then write new bit at index*/
	buf = buf|(i << ((BYTE-1)-nbits));
   
	
	/*Increment number of bits*/
	++nbits;
}

/*For the last flush if the buffer is not filled we still have to write what is inside*/
void BitOutputStream::flush_last(){
    if( nbits != 0)
        flush();
}

/*Write the numbers in the buffer  */
void BitOutputStream::writeInt(int i){
  
    out.write((char*)&i, 3);
}

/*
 * Name: flush
 * Description: Flushes the output stream buffer
 */

void BitOutputStream::flush(){
		
	/*Set up the buffer*/
	out.put(buf);

	/*Now flush it!*/
	out.flush();

	/*Set buffer and numBits to null value*/
	buf = nbits = 0;

}
