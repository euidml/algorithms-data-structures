#ifndef NODE_H
#define NODE_H

#include <vector>

using namespace std;

// the node
class Node{
public:
    int value; // holds data – DO NOT ALTER
    vector<Node*> next; // next nodes at various levels – DO NOT ALTER
    vector<Node*> prev; // previous nodes at various levels – DO NOT ALTER
    // Node *down;  // node at the level below – MAY ALTER/REMOVE/ADD MORE LINKS
    Node(int val, int level){
        value = val;
        next = vector<Node*>(level+1, nullptr);
        prev = vector<Node*>(level+1, nullptr);
        // down = nullptr;
    };
};


#endif