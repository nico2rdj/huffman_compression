/*
 * Name: Matthew Sparrow and Nicolas Martin
 * Date: 11/02/16
 * Description: Defines the BitOutputStream object and its behavior, for our 
 * 	bitwise I/O manipulation
 *
 */

#include "BitOutputStream.h"
#include <math>

#define BYTE 8

/*BitOutputStream constructor*/
BitOutputStream::BitOutputStream(std::ostream & stream): outStream(stream),
	buffer(0), numBits(0){}

/*
 * Name: addBit
 * Description: Adds a bit at index to the buffer.
 * Parameters: int index; Add bit at that index.
 * Return: void
 */

void BitOutputStream::addBit(int index){

	/*If numBits is a full byte, flush the buffer*/ 
	if(numBits == BYTE)
		flush(); 

	/*Clear buffer at index, then write new bit at index*/
	buffer = buffer|(index << ((BYTE-1)-numBits));
	
	/*Increment number of bits in buffer*/
	numBits++;
}

/*
 * Name: addHeader
 * Description: Writes a header to the output stream
 * Parameter: int index; the index to put it at
 */
void BitOutputStream::addHeader(int index){
	
	/*For our looping index*/
	int powerTwo;
	/*For tracking number of bits and bytes*/
	int nBits = 0;	
	int nBytes = 0;

	/*To see how many bits will be needed*/
	for(powerTwo = 2; powerTwo < index; powerTwo *= 2)
		nBits++;
	
	/*Convert bit count to byte count*/	
	nBytes = (nBits/BYTE) + 1;

	/*Write frequencies to outStream*/
	outStream.write((char*) & nBytes, 1);
	outStream.write((char*) & i, nBytes);
}

/*
 * Name: addNL
 * Description: Writes a newline character to the output stream
 * Parameter: char nl; the character we are writing
 */
void BitOutputStream::addNL(char nl){

	outStream.write((char*) & nl, sizeof(nl));

}

/*
 * Name: flush
 * Description: Flushes the output stream buffer
 */

void BitOutputStream::flush(){
		
	/*Set up the buffer*/
	outStream.put(buffer);

	/*Now flush it!*/
	outStream.flush();

	/*Set buffer and numBits to null value*/
	buffer = 0;
	numBits = 0;

}
