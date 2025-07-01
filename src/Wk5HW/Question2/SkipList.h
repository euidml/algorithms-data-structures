#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <random>
#include <climits>
#include <functional>
#include "Node.h"


#ifndef SKIPLIST_H
#define SKIPLIST_H

using namespace std;
/** class represents a skiplist
 * 
 */
class SkipList{
private:
    int hashTableSize;
    int numberOfKeys;
    double loadFactorThreshold;
    bool validate(int value){
        if(value == 0){
            cout << "0 is not allowed" << endl;
            return false;
        }
        return true;
    }
    int hashing(int value){
        hash<int> builtInHashFunction;
        return builtInHashFunction(value) % hashTableSize;
    }
public:
    // Maximum allowed level index
    int MAXIMUM_ALLOWED_LEVEL_INDEX;
 
    // current maximum level amongst the inserted nodes
    int currentHighestLevelIndex;
    
    // the head node's next links are connected to the first node at every level
    Node *head;

    SkipList(int size, double lft, int maxLevels){
        loadFactorThreshold = lft;
        hashTableSize = size;
        numberOfKeys = 0;
        MAXIMUM_ALLOWED_LEVEL_INDEX = maxLevels;
        
        // initially we have the bottom-most level only
        currentHighestLevelIndex = 0;
    
        // create the header node, value is irrelevant (as long as it doesn't match an inserted value - NO REPEATS), number of next links is important (initially this node is the first node at every level)
        head = new Node(INT_MIN, MAXIMUM_ALLOWED_LEVEL_INDEX, INT_MIN);
    }
    ~SkipList(){
        Node* current = head -> next[0];
        Node* temp;
        while(current){
            temp = current;
            current = current -> next[0];
            cout << "Node " << temp << " with value " << temp -> value << " has deleted!" << endl;
            delete temp;
        }
        cout << "head " << head << " has deleted!" << endl;
        delete head;
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

    Node* CreateNode(int value, int level, int hashCode){
        // create a new node with next links for every level that this node will be part of
        // it will use these links to connect to the next node at each level  
        return new Node(value, level, hashCode);
    }
    
    void insert(int value){
        if(!validate(value))
            return;
        if(((double)numberOfKeys + 1)/hashTableSize >= loadFactorThreshold)
            ReHash();
        Node *current = head; // start at head node
        vector<Node*> update(MAXIMUM_ALLOWED_LEVEL_INDEX+1, nullptr);
        int hashCode = hashing(value);
        for (int i = currentHighestLevelIndex; i >= 0; i--){ // start at the highest level and move down so that more nodes may be skipped
            // for level i, if value is to be inserted here then find out where (i.e. after which node)
            while (current->next[i] != nullptr && current->next[i]->hashCode < hashCode){
                current = current->next[i];
            }
            update[i] = current;
        }
        current = current -> next[0];
        // if there's no any nodes with same hashcode(current is the first node to be added with its hashcode )
        if(!current || current -> hashCode != hashCode){
            int ranLevel = RandomLevel();
            if (ranLevel > currentHighestLevelIndex){
                for (int i = currentHighestLevelIndex+1; i <= ranLevel; i++) // int i = currentHighestLevelIndex+1 here cause Error.
                    update[i] = head;
                currentHighestLevelIndex = ranLevel;
            }
            Node* temp = CreateNode(value, ranLevel, hashCode);
            for (int i = 0; i<=ranLevel; i++){
                temp->next[i] = update[i]->next[i];
                update[i]->next[i] = temp;
            }
            numberOfKeys++;
        // if a node with same hashCode already exist, add the node to the rear of the sequence of the nodes with same hash code
        // the reason why adding it to the rear is to avoid adding duplicated value.
        }else{
            while(current -> next[0] && current -> next[0] -> hashCode == current -> hashCode && current -> value != value)
                current = current -> next[0];
            if(current -> value != value){
                Node* temp = CreateNode(value, 0, hashCode);
                temp -> next[0] = current -> next[0];
                current -> next[0] = temp;
                numberOfKeys++;
            }
        }
    }
    void ReHash(){
        int prevSize = hashTableSize;
        Node* prevHead = head;
        hashTableSize *= 2;
        // also increasing MAXIMUM_ALLOWED_LEVEL_INDEX for varience of levels
        MAXIMUM_ALLOWED_LEVEL_INDEX *= (1 + loadFactorThreshold);
        head = new Node(INT_MIN, MAXIMUM_ALLOWED_LEVEL_INDEX, INT_MIN);
        currentHighestLevelIndex = 0;
        Node* current = prevHead -> next[0];
        Node* temp;
        while(current){
            temp = current;
            numberOfKeys--; 
            insert(current -> value);
            current = current -> next[0];
            delete temp;
        }
        cout << "\nRehash () excuted;\n" << "MAXIMUM_ALLOWED_LEVEL_INDEX: " << MAXIMUM_ALLOWED_LEVEL_INDEX << " \nprev size: " << prevSize << " current size: " << hashTableSize << "\n"<< endl;
        delete prevHead;
    }
    void remove(int value){
        if(!validate(value))
            return;
        if(((double)numberOfKeys + 1)/hashTableSize >= loadFactorThreshold) // why numberOfKeys + 1?
            ReHash();
        Node *current = head; // start at head node
        vector<Node*> update(MAXIMUM_ALLOWED_LEVEL_INDEX+1, nullptr);
        int hashCode = hashing(value); 
        for (int i = currentHighestLevelIndex; i >= 0; i--){ // start at the highest level and move down so that more nodes may be skipped
            // for level i, if value is to be inserted here then find out where (i.e. after which node)
            while (current->next[i] != nullptr && current->next[i]->hashCode <= hashCode && current -> next[i] -> value != value){
                current = current->next[i];
            }
            update[i] = current;
        }
        current = current -> next[0];
        if (current && current->value == value){
            // checking if targeted node has next vector for pathing (size > 1)and any next[0] node has same hashcode with current exists;
            // the reason why doing this is to shifting "next" vector to the next[0] with same hashcode
            // if it doesn't have next vector for pathing (size == 0) or the next node with same hashcode doesn't exist
            bool ifNextHashExist = current -> next[0] && current -> next[0] -> hashCode == hashCode;
            if(ifNextHashExist)
                for(int i = 1; i < current->next.size(); i++)
                    current -> next[0] -> next.push_back(current -> next[i]);
            for(int i = 0; i < current->next.size(); i++){
                if(ifNextHashExist){
                    update[i] -> next[i] = current -> next[0];
                }else{
                    update[i] -> next[i] = current -> next[i];
                }                
            }
            // checks if current was the last node on the highest level index.
            // If so, then decrease the currentHighestLevelIndex since there's no node on currentHighestLevelIndex level
            while(!(head -> next[currentHighestLevelIndex]))
                currentHighestLevelIndex--;
            numberOfKeys--;
            delete current;
        }
    }
    
    bool search(int value){
        if(!validate(value))
            return false;
        int hashCode = hashing(value);
        Node *current = head;
        for (int i = currentHighestLevelIndex; i >= 0; i--){ 
            while (current->next[i] != nullptr && current->next[i]->hashCode <= hashCode && current -> next[i] -> value != value){
                current = current->next[i];
            }
        }
        current = (current -> next[0] != nullptr) ? current->next[0] : current;
        return current->value == value;
    }
    

    void Display(){
        for (int i=0;i<=currentHighestLevelIndex;i++){
            Node *node = head->next[i];
            cout << "Level " << i << ": ";
            while (node != nullptr && node->next[i] != nullptr){
                cout << node->value << " -> ";
                node = node->next[i];
            }
            cout << node->value << " .\n";
        }
    }
};

#endif