#ifndef NODE_H
#define NODE_H

#include <vector>

using namespace std;

// the node
class Node{
public:
    int value;
    int hashCode;
    // Array of pointers to the next nodes (which may be located at various levels)
    // next[i] is the next link for level i
    // the size of this vector determines the number of levels that the current node is part of
    vector<Node*> next; 
    Node(int val, int level, int hashCode){
        this->hashCode = hashCode;
        value = val;
        next = vector<Node*>(level+1, nullptr); // initialize array of pointers to nulls
    };
};

#endif