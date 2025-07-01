#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include "Node.h"


#ifndef SKIPLIST_H
#define SKIPLIST_H

using namespace std;

class SkipList{
public:
    // Maximum allowed level index
    int MAXIMUM_ALLOWED_LEVEL_INDEX;
 
    // current maximum level amongst the inserted nodes
    int currentHighestPriority;
    
    // the head node's next links are connected to the first node at every level
    Node *head;
    Node *tail;

    SkipList(int maxLevels){
        MAXIMUM_ALLOWED_LEVEL_INDEX = maxLevels;

        // initially we have the bottom-most level only
        currentHighestPriority = 0;
    
        // create the header node, value is irrelevant (as long as it doesn't match an inserted value - NO REPEATS), number of next links is important (initially this node is the first node at every level)
        head = new Node(INT_MIN, MAXIMUM_ALLOWED_LEVEL_INDEX);
        tail = new Node(INT_MIN, MAXIMUM_ALLOWED_LEVEL_INDEX);
        for(int i = 0; i <= MAXIMUM_ALLOWED_LEVEL_INDEX; i++){
            head -> next[i] = tail;
            tail -> prev[i] = head;
        }
    }

    ~SkipList(){
        Node* current = head -> next[0];
        Node* temp;
        while(current != tail){
            temp = current;
            current = current -> next[0];
            cout << "node " << temp << " with value " << temp -> value << " has deleted!" << endl;
            delete temp;
        }
        cout << "head " << head << " has deleted!" << endl; 
        delete head;
        cout << "tail " << tail << " has deleted!" << endl; 
        delete tail;

    }

    int RandomLevel(){
        return (int) (MAXIMUM_ALLOWED_LEVEL_INDEX * ((float)rand()/RAND_MAX));
    }

    Node* CreateNode(int value, int level){
        // create a new node with next links for every level that this node will be part of
        // it will use these links to connect to the next node at each level  
        return new Node(value, level);
    }

    void Enqueue(int value){
        int priority = RandomLevel();
        if(priority > currentHighestPriority)
            currentHighestPriority = priority;
        Node* temp = CreateNode(value, priority);
        for(int i = 0; i <= priority; i++){
            head -> next[i] -> prev[i] = temp;
            temp -> next[i] = head -> next[i];
            head -> next[i] = temp;
            temp -> prev[i] = head;
        }
    }

    int Dequeue(){
        if(tail -> prev[0] == head){
            return tail -> value; // INT_MAX
        }
        Node *current = tail -> prev[currentHighestPriority];
        for(int i = 0; i <= current -> priority; i++){
            current -> prev[i] -> next[i] = current -> next[i];
            current -> next[i] -> prev[i] = current -> prev[i];
        }
        while(head -> next[currentHighestPriority] == tail)
            currentHighestPriority--;
        int value = current -> value;
        delete current;
        return value;
    }

    void Process(){
        cout << "\n*** Showing Structure ***\n" << endl;
        Show();
        cout << "\nProcessing... (Dequeuing all nodes)" << endl;
        vector<int> queue;
        int temp = Dequeue();
        while(temp != INT_MIN){
            queue.push_back(temp);
            temp = Dequeue();
        }
        cout << "\nPrinting nodes in priority" << endl;
        if(queue.size() > 0){
            for(int i = 0; i < queue.size() - 1; i++){
                cout << queue[i] << ", ";
            }
            cout << queue.back() << "\n" << endl;
        }
    }

    void Show(){
        cout << "showing nodes in ascending order with: " << endl;
        for (int i=0;i<=currentHighestPriority;i++){
            Node *node = head->next[i];
            cout << "Level " << i << ": ";
            while (node -> next[i] != tail){
                cout << node->value << " <-> ";
                node = node->next[i];
            }
            cout << node->value << " .\n";
        }
    }
};
#endif