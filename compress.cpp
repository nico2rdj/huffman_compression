#include <iostream>
#include <fstream>
#include "HCNode.h"
#include "HCTree.h"

using namespace std;

int main( int argc, char** argv){
    
    if( argc != 3){
        cout << " error number of arguments " << endl;
        return -1;
    }

    ifstream theFile;
    theFile.open(argv[1], ios::binary);

    std::vector<int> freq(256,0);
    int symbol;
    
    // compute frequencies 
	while(!theFile.eof()){
         
        symbol = theFile.get();
        cout << symbol << endl;

        if(theFile.eof())
			break;
      
		freq[symbol] += 1;
	}

    HCTree* tree = new HCTree();
    tree->build(freq);

    ifstream the_file;
    the_file.open(argv[1], ios::binary);

    ofstream file;
    file.open(argv[2]);

   /* //fout<<"Encode for each character:\n";
    for(int i=0; i < freq.size(); i++){ 
         if(freq[i] !=0 && i != 10 ){
            file << (char)i << " : ";

            tree->encode((char)i,file);
            
      
    }
  }/*/
    string fre;
    for(int i = 0; i < 256; i++){
        string new_one = to_string(freq[i]);
        fre = new_one + "\n";
        file << fre;
    }
    char symb;
    while(the_file.get(symb)){

	//	symb = the_file.get();
      //  cout << symb << endl;
	//	if(the_file.eof())
	//		break;
        if((int)symb != 10)
	    	tree->encode(symb, file);
	}



}
