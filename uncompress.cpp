#include <iostream>
#include <fstream>
#include "HCNode.h"
#include "HCTree.h"

using namespace std;

int main( int argc, char** argv){
    
    if(argc != 3){
        cout << " error number of arguments " << endl;
        return -1;
    }

    ifstream file1;
    file1.open(argv[1]);

    std::vector<int> freq(256,0);
    
    int totalChar = 0;
    
    // compute frequencies 
    //
    string freqName;
    for( int i = 0; i < freq.size(); i++){
        getline(file1, freqName);
        freq[i] = stoi(freqName);

    }


	
    HCTree* tree = new HCTree();
    tree->build(freq);

    
    ofstream file;
    file.open(argv[2]);
    
   /* if( tree->root->c0 == NULL and tree->root->c1 == NULL){
        *for( int i= 0; i < freq[tree->root->symbol]; i++)
            file << tree->root->symbol;
        return 1;
    }*/
    while(1){
	
		//if(file1.eof())
		//	break;

    int charac = tree->decode(file1);
    if( charac != -1) 
	    file <<	(char)charac;
    else
        return 1;    
    }



}
