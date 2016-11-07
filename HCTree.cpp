#include "HCTree.h"
#include <stack>
#include <string>

void HCTree::build(const vector<int>& freqs){
   
   //in the top of the queue always the smallest node
    std::priority_queue<HCNode*,std::vector<HCNode*>, HCNodePtrComp> pq;
    
	for(int i = 0; i < 256; i++){
		if(freqs[i] != 0  ){ 
			HCNode* newNode = new HCNode(freqs[i], (byte)i);
			pq.push(newNode);
			leaves[i] = newNode;
            //cout << "freq " << i << " " << freqs[i] << endl;

		}
     }
    
    while( pq.size() > 1){

        HCNode* n1 = pq.top();
        //cout<<n1->symbol<<" "<<n1->count<<endl;  

        pq.pop();
        HCNode* n2 = pq.top();
        //cout<<n2->symbol<<" "<<n2->count<<endl;  

        pq.pop();

        HCNode* newNode = new HCNode(n1->count + n2->count, n1->symbol); //we do not care about the symbol value in this newNode
        newNode->c0 = n2;
        newNode->c1 = n1;

        n1->p = newNode;
        n2->p = newNode;

        pq.push(newNode);
    }
    
    if(pq.size() != 0){ //case of empty file
        root = pq.top();
        //cout<<root->symbol<<" "<<root->count<<endl;  
        pq.pop();	
    }
    
}

void encode_rec_optimized(HCNode* node, stack<int> &node_p){
    if(node->p == NULL )
        return;

        if( node->p->c0 == node)
               node_p.push(0);
           else
               node_p.push(1);
        encode_rec_optimized(node->p, node_p);

}

void HCTree::encode(byte symbol, BitOutputStream& out) const{
       stack<int> node_p;
       HCNode* node = leaves[symbol];
       encode_rec_optimized(node, node_p);
       

       while(!node_p.empty()){
         out.writeBit(node_p.top());       
         node_p.pop();
       }



}



void encode_rec(HCNode* node, ofstream& out){
    if(node->p == NULL )
        return;
    encode_rec(node->p, out);
    if( node->p->c0 == node)
               out.put('0');
           else
               out.put('1');

}

void HCTree::encode(byte symbol, ofstream& out) const{

       HCNode* node = leaves[symbol];
       if( node == root){
            out << root->symbol;
       }else
        encode_rec(node, out);
}

int HCTree::decode(BitInputStream& in) const{
    HCNode *p = root;
    int c;
    while(p->c0 != NULL && p->c1 != NULL){
        c = in.readBit();
        if( c == 0)
            p = p->c0;
        else if( c == 1)
            p = p->c1;
        else
            return -1;

    }
    return p->symbol;

}

int HCTree::decode(ifstream& in) const{

    char c;
    if(root == NULL){ //empty file
        in.get(c);
        return -1;
    }
    HCNode *p = root;
    
           
   if( p->c0 != NULL && p->c1 != NULL)
        while( p->c0 != NULL && p->c1 != NULL){
            in.get(c);
            cout << " value c : " << c ;
            if( c != '0' && c!= '1')
                return -1;

            if( c == '0')
                p = p->c0;
            else if(c == '1')
                p = p->c1;
    }
    else
        in.get(c); 
    if( c == 0) // for the eof
        return -1;
    return (int)p->symbol;

}




