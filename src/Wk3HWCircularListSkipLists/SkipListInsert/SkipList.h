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
/** class represents a skiplist
 * 
 */
class SkipList{
public:
    // Maximum allowed level index
    int MAXIMUM_ALLOWED_LEVEL_INDEX;
 
    // current maximum level amongst the inserted nodes
    int currentHighestLevelIndex;
    
    // the head node's next links are connected to the first node at every level
    Node *head;

    SkipList(int maxLevels){
        MAXIMUM_ALLOWED_LEVEL_INDEX = maxLevels;

        // initially we have the bottom-most level only
        currentHighestLevelIndex = 0;
    
        // create the header node, value is irrelevant (as long as it doesn't match an inserted value - NO REPEATS), number of next links is important (initially this node is the first node at every level)
        head = new Node(INT_MIN, MAXIMUM_ALLOWED_LEVEL_INDEX);
    }

    int RandomLevel(){
        float probablity = (float)rand()/RAND_MAX; // flip a coin
        int lvl = 0;
        while (probablity < 0.5 && lvl < MAXIMUM_ALLOWED_LEVEL_INDEX){
            lvl++; // landed heads so increase level by 1
            probablity = (float)rand()/RAND_MAX; // flip a coin again
        }
        return lvl;        
    }

    Node* CreateNode(int value, int level){
        // create a new node with next links for every level that this node will be part of
        // it will use these links to connect to the next node at each level  
        return new Node(value, level);
    }
    /**
     * @brief this methos is to insert a new node on the skiplist.
     * 
     * @example
     * Skiplist s(3);
     * s.insert(1);
     * s.insert(0);
     * s.insert(2);
     * s.Show();
     * 
     * @result
     * 
     * Level 0: 0 -> 1 -> 2 .
     * Level 1: 0 -> 2 .
     * Level 2: 2 .
     * 
     * @timecomplexity:  O(n); searching is O(log(n))
     * 
     * @param value - int
     * @return noe=ne
     */
    void InsertElement(int value){
        Node *current = head; // start at head node
        vector<Node*> update(MAXIMUM_ALLOWED_LEVEL_INDEX+1, nullptr); // this will hold the nodes that need updating at every level after the insert takes place
        // O(log2(n))
        for (int i = currentHighestLevelIndex; i >= 0; i--){ // start at the highest level and move down so that more nodes may be skipped
            // for level i, if value is to be inserted here then find out where (i.e. after which node)
            while (current->next[i] != nullptr && current->next[i]->value < value){
                current = current->next[i];
            }
            // found the node after which the value is to be placed at level i, move down a level, if possible 
            update[i] = current;
        }    
        
        // at level 0, where current is pointing to by the end of the preceding loop, move over one node to where the value is to be inserted to see if the value already exists there (NO REPEATS allowed)
        current = current->next[0];
    
        if (current == nullptr || current->value != value){
            // O(n)
            int ranLevel = RandomLevel(); // choose a random level upto where the new node will be placed
    
            if (ranLevel > currentHighestLevelIndex){
                // if random level for current node is higher than the current maximum level for existing nodes; 
                // then set head as the node after which the new value is to be inserted for each level over current maximum to the level chosen for new value to be inserted (update currently contains nulls for these level(s)).
                // O(n)
                for (int i = currentHighestLevelIndex+1; i <= ranLevel; i++){ // int i = currentHighestLevelIndex+1 here cause Error.
                    update[i] = head;
                }
    
                // also change the current maximum level for the existing nodes
                currentHighestLevelIndex = ranLevel;
            }
    
            // create new node with next links for every level from ranLevel to zero
            Node* n = CreateNode(value, ranLevel);
    
            // placing new node in the correct place at every level
            //O(n)
            for (int i = 0; i<=ranLevel; i++){
                n->next[i] = update[i]->next[i];
                update[i]->next[i] = n;
            }
        }
           
    }

    void InsertElement(int value){
        Node *current = head; 
        vector<Node*> update(MAXIMUM_ALLOWED_LEVEL_INDEX+1, nullptr); 
        for (int i = currentHighestLevelIndex; i >= 0; i--){
            while (current->next[i] != nullptr && current->next[i]->value < value){
                current = current->next[i];
            }
            update[i] = current;
        }    
        current = current->next[0];
    
        if (current == nullptr || current->value != value){
            int ranLevel = RandomLevel();
            if (ranLevel > currentHighestLevelIndex){
                for (int i = currentHighestLevelIndex+1; i <= ranLevel; i++){
                    update[i] = head;
                }
                currentHighestLevelIndex = ranLevel;
            }
            Node* n = CreateNode(value, ranLevel);
            for (int i = 0; i<=ranLevel; i++){
                n->next[i] = update[i]->next[i];
                update[i]->next[i] = n;
            }
        }  
    }
    
    void Delete(int value){
        Node *current = head; // start at head node
        vector<Node*> update(MAXIMUM_ALLOWED_LEVEL_INDEX+1, nullptr); // this will hold the nodes that need updating at every level after the insert takes place
        for (int i = currentHighestLevelIndex; i >= 0; i--){ // start at the highest level and move down so that more nodes may be skipped
            // for level i, if value is to be inserted here then find out where (i.e. after which node)
            while (current->next[i] != nullptr && current->next[i]->value < value){
                current = current->next[i];
            }
            // found the node after which the value is to be placed at level i, move down a level, if possible 
            update[i] = current;
        }
        current = current->next[0];
        if (current && current->value == value){
                
            for (int i = 0; i < current -> next.size(); i++){
                update[i] -> next[i] = current -> next[i];
            }
            // checks if current was the last node on the highest level index.
            // If so, then decrease the currentHighestLevelIndex since there's no node on currentHighestLevelIndex level
            while(!(head -> next[currentHighestLevelIndex])){
                currentHighestLevelIndex--;
            }
            delete current;
        }
    }
    
    bool Search(int value){
        Node *current = head;
        for (int i = currentHighestLevelIndex; i >= 0; i--){ 
            while (current->next[i] != nullptr && current->next[i]->value < value){
                current = current->next[i];
            }
        }
        current = (current -> next[0] != nullptr) ? current->next[0] : current;
        return current->value == value;
    }
    

    void Show(){
        for (int i=0;i<=currentHighestLevelIndex;i++){
            Node *node = head->next[i];
            cout << "Level " << i << ": ";
            while (node != nullptr && node->next[i] != nullptr){
                cout << node->value << " -> ";
                node = node->next[i];
                // cout << "a";
            }
            cout << node->value << " .\n";
        }
    }
};

#endif