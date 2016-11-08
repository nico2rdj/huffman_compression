#include <iostream>
#include <fstream>
#include "HCNode.h"
#include "HCTree.h"
#include "BitOutputStream.h"

using namespace std;

int main( int argc, char** argv){
    
    if( argc != 3){
        cout << " error number of arguments " << endl;
        return -1;
    }

    ifstream File1;
    File1.open(argv[1], ios::binary);

    std::vector<int> freq(256,0);
    int symbol;
    
    // compute frequencies 
	while(!File1.eof()){
         
        symbol = File1.get();
        //cout << symbol << endl;

        if(File1.eof())
			break;
      
		freq[symbol] += 1;
	}

    HCTree* tree = new HCTree();
    tree->build(freq);

    ifstream file1;
    file1.open(argv[1], ios::binary);

    ofstream file2;
    file2.open(argv[2]);

    BitOutputStream bos(file2);
    
    for(int i = 0; i < 256; i++){
        bos.writeInt(freq[i]);
    }
    char symb;
    while(file1.get(symb)){
        if(file1.eof())
            return 0;

        tree->encode(symb, bos);
    }
    
    bos.flush_last();
    
    
}
