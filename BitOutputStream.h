/*
 * Name: Matthew Sparrow and Nicolas Martin 
 * Date: 11/2/16
 */

#ifndef BITOUTPUTSTREAM_H
#define BITOUTPUTSTREAM_H

#include <fstream>
#include <iostream>

class BitOutputStream{

public:
	/*Resets buffer and the bit count*/
	BitOutputStream(std::ostream & stream): outStream(stream),
		buffer(0), numBits(0){}
	
	/*Used to write a bit to the stream*/
	void addBit(int bit);
	
	/*Writes header to stream*/
	void addHeader(int bit);
	
	/*Writes a newline to the stream*/
	void addNL(char nl);
	
	/*Flushes output stream*/
	void clear();

/*Private member variables*/
private:
	
	/*Our outstream object*/
	std::ostream & outStream;
	
	/*Our buffer for I/O*/
	char buffer;
	
	/*For tracking number of bits in stream*/
	int numBits;

	



};
#endif
