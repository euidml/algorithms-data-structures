#include <iostream>

using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node {
public:
    // added id in order to track each task after they are done.
    int id;
    int data;
    Node* next;
    Node(int id, int value) : data(value), next(nullptr), id(id){}
};

class CircularLinkedList {
private:
    Node* last;

public:
    CircularLinkedList() : last(nullptr) {}
    /**
     * @brief Destroy the Circular Linked List object
     * 
     */
    ~CircularLinkedList() {
        Node* current;
        while(last){
            current = last -> next;
            cout << "deleting " << current -> data << " of " << this <<  endl;
            // using current so that deleteNode can be O(1)
            deleteNode(current -> data);
        }
        cout << "i'm out!" << endl;
    }


    // Insert a new node with data at the end of the circular linked list
    void insert(int id, int data) {
        Node* new_node = new Node(id, data);
        if (!last) {
            last = new_node;
            last->next = last;
        } else {
            new_node->next = last->next;
            last->next = new_node;
            last = new_node;
        }
    }

    // Delete a node with the given data
    void deleteNode(int data) {
        if (!last)
            return;
        Node* current = last->next;
        Node* previous = nullptr;

        while (current->next != last->next) {
            if (current->data == data) {
                if (current == last->next)
                    last->next = last->next->next;
                if (current == last)
                    last = previous;
                if (previous)
                    previous->next = current->next;
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }

        if (current->data == data) {
            if (current == last->next)
                last->next = last->next->next;
            if (current == last)
                last = previous;
            if (previous)
                previous->next = current->next;
            delete current;
        }
    }

    // Search for a node with the given data
    bool search(int data) {
        if (!last)
            return false;

        Node* current = last->next;

        do {
            if (current->data == data)
                return true;
            current = current->next;
        } while (current != last->next);

        return false;
    }
    
    /**
     * @brief this method is to move the last trakced node to its next node
     * 
     * @example
     * CircularLinkedList c;
     * c.insert(0)
     * c.insert(1)
     * c.insert(2) // last is 2
     * int a = getLastNode() -> data
     * c.goToNext(); // not the last is 0
     * int b = getLastNode() -> data
     * 
     * @result
     * a = 2
     * b = 0
     * @timecomplexity:  O(1); it has the direct reference of next.
     * 
     * @param none
     * @return none
     */
    void goToNext(){
        if(last)
            last = last -> next;
    }

    /**
     * @brief this method is to return the reference of the last node.
     * 
     * @example
     * CircularLinkedList c;
     * c.insert(0)
     * c.insert(1)
     * int a = getLastNode() -> data
     * 
     * @result
     * a = 1
     * 
     * @timecomplexity:  O(1); returns the exact refenence of last.
     * 
     * @param 
     * @return 
     */
    Node* getLastNode(){
        return last;
    }

    
    // display all elements in the circular linked list
    void display() {
        if (!last)
            return;
        Node* current = last->next;

        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != last->next);

        cout << endl;
    }
};

#endif