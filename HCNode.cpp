#include "HCNode.h"

bool HCNode::operator<(const HCNode& other){
    if (count  != other.count){
        return count > other.count;
    }
    return symbol < other.symbol;

}

