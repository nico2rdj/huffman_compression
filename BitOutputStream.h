/*
 * Name: Matthew Sparrow and Nicolas Martin 
 * Date: 11/2/16
 */

#ifndef BITOUTPUTSTREAM_H
#define BITOUTPUTSTREAM_H

#include <iostream>


class BitOutputStream{

/*Private member variables*/
private:
	
	/*Our outstream object*/
	std::ostream & out;
	
	/*Our buffer for I/O*/
	char buf;
	
	/*For tracking number of bits in stream*/
	int nbits;


public:
	/*Resets buffer and the bit count*/
	BitOutputStream(std::ostream & os):out(os),
	buf(0), nbits(0){}
;
	
	/*Used to write a bit to the stream*/
	void writeBit(int i);
	
    /*Used to write the int value to the stream*/	
    void writeInt(int i);
	
	/*Used to write the last value to the buffer*/
    void flush_last();
	
	/*Flushes output stream*/
	void flush();


};
#endif
