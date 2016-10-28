include "HCTree.h"



void HCTree::build(const vector<int>& freqs){
   
   //in the top of the queue always the smallest node
    std::priority_queue<HCNode*, std::vector<HCNode*>, HCNodePtrComp> pq;
	
	for(int i = 0; i < 256; i++){
		if(freqs[i] != 0 ){
			HCNode* newNode = new HCNode(freqs[i], (byte)i);
			pq.push(newNode);
			leaves[i] = newNode;
		}
	}
    
    while( pq.size() != 1){

        HCNode* n1 = pq.top();
        pq.pop();
        HCNode* n2 = pq.top();
        pq.pop();

        HCNode* newNode = HCNode(n1->count + n2->count, n1->symbol); //we do not care about the symbol value in this newNode
        newNode->c0 = n1;
        newNode->c1 = n2;

        n1->p = newNode;
        n2->p = newNode;

        pq.push(newNode);
    }

    root = pq.top();
    pq.pop();	
    
}

/*void HCTree::encode(byte symbol, BitOutputStream& out) const{

   // HCNode* leaf = leaves[(int)symbol];
}*/


void HCTree::encode(byte symbol, ofstream& out) const{

       HCNode* node = leaves[(int)symbol];
       while( node->p != NULL){
           if( node->p->c0 == node)
               out.write(0);
           else
               out.write(1);
        node = node->p;
    }
}

/*
int HCTree::decode(BitInputStream& in) const{

}*/


int HCTree::decode(ifstream& in) const{

    HCNode *p = root;
    char c;
    while( in.get(c)){
        int path = stoi(c);
        if( c == 0)
            p = root->c0;
        else
            p = root->c1;
    }

    // check if the file has been entirely read
    if (in.eof())                      
      std::cout << "[EoF reached]\n";
    else
        std::cout << "[error reading]\n";

    in.close();                        
    

    return (int)p->symbol;

}




