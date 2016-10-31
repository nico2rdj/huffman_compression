#include "HCTree.h"
#include<stack>

void HCTree::build(const vector<int>& freqs){
   
   //in the top of the queue always the smallest node
    std::priority_queue<HCNode*,std::vector<HCNode*>, HCNodePtrComp> pq;
	//std::vector<HCNode*>, HCNodePtrComp>
	for(int i = 0; i < 256; i++){
		if(freqs[i] != 0 && i != 10  ){ //10 new line chacracter
			HCNode* newNode = new HCNode(freqs[i], (byte)i);
			pq.push(newNode);
			leaves[i] = newNode;
            cout << "freq " << i << " " << freqs[i] << endl;

		}
       	}
    
    while( pq.size() > 1){

        HCNode* n1 = pq.top();
        cout<<n1->symbol<<" "<<n1->count<<endl;  

        pq.pop();
        HCNode* n2 = pq.top();
        cout<<n2->symbol<<" "<<n2->count<<endl;  

        pq.pop();

        HCNode* newNode = new HCNode(n1->count + n2->count, n1->symbol); //we do not care about the symbol value in this newNode
        newNode->c0 = n2;
        newNode->c1 = n1;

        n1->p = newNode;
        n2->p = newNode;

        pq.push(newNode);
    }

    root = pq.top();
    cout<<root->symbol<<" "<<root->count<<endl;  
    pq.pop();	
    
}

/*
void HCTree::build(const vector<int>& freqs){
  std::priority_queue<HCNode*,std::vector<HCNode*>,HCNodePtrComp> pq;
  //creating each node
  for(int i=0; i<freqs.size(); i++){
    //we dont want 0 counts symbol
    if(freqs[i] != 0 && i != 10){
      leaves[i] = new HCNode(freqs[i],(byte)i,0,0,0);
      pq.push(leaves[i]);
  }
  }
 
  //check if pushed correctly
  while(pq.size()>1){
    HCNode* l0 = pq.top();//0 go left
    cout<<l0->symbol<<" "<<l0->count<<endl; 
    pq.pop();
    HCNode* r1 = pq.top();//1 go right
    cout<<r1->symbol<<" "<<r1->count<<endl;  
    pq.pop();
    int freq = l0->count + r1->count;
    HCNode* p = new HCNode(freq, r1->symbol, l0, r1, 0);
    l0->p = p;
    r1->p = p;
    pq.push(p);
  }
  root = pq.top(); 
  pq.pop();
}
/*void HCTree::encode(byte symbol, BitOutputStream& out) const{

   // HCNode* leaf = leaves[(int)symbol];
}

void HCTree::encode(byte symbol, ofstream& out) const{
  string enc = "";
  HCNode* temp = leaves[symbol];
  HCNode* deb = temp;
  while(temp != root){
    if( (temp->p)->c0 == temp)
      enc = enc+'0';
    if( (temp->p)->c1 == temp)
      enc = enc+'1';
    temp = temp->p;
  }
  string result = "";
  for(int j = enc.length()-1; j>=0; j--)
    result = result + enc[j];
  //out<<symbol<<" "<<result<<endl;
    out<<result;
}
/*/


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
      // out << symbol;

}

/*
int HCTree::decode(BitInputStream& in) const{

}*/


int HCTree::decode(ifstream& in) const{

    HCNode *p = root;
    char c;
       
        
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

  
                
    

    return (int)p->symbol;

}




