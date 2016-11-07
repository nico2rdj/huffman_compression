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
    
        
    BitInputStream bis(file1);
    int max_size = 0;
    for( int i = 0; i < freq.size(); i++){
        freq[i] = bis.readInt();
        max_size += freq[i];
    }



	
    HCTree* tree = new HCTree();
    tree->build(freq);

    
    ofstream file;
    file.open(argv[2]);

    for( int i = 0; i < max_size; i++){
        int charac = tree->decode(bis);
       // cout << "charc = " << charac << endl; 
        file <<	(char)charac;
    }
    

}
