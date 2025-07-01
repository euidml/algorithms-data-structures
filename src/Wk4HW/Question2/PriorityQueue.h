#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include "Node.h"

using namespace std;

class PriorityQueue {
public:
	int MAXIMUM_ALLOWED_PRIORITY;
	int currentHighestPriority;
	Node* head;
	Node* tail;
	PriorityQueue(int maxPriority) {
		MAXIMUM_ALLOWED_PRIORITY = maxPriority;


		currentHighestPriority = 0;

		head = new Node(INT_MIN, MAXIMUM_ALLOWED_PRIORITY);
		tail = new Node(INT_MAX, MAXIMUM_ALLOWED_PRIORITY); 


		for (int i = 0; i <= MAXIMUM_ALLOWED_PRIORITY; i++) {
			head->next[i] = tail;
			tail->prev[i] = head;
		}
	}

	int RandomPriority() {

		int pr = (int)(rand() % (MAXIMUM_ALLOWED_PRIORITY + 1));

		return pr;
	}

	Node* CreateNode(int value, int priority) {

		return new Node(value, priority);
	}

	void Enqueue(int value) {
		
		int priority = RandomPriority();
		
		Node* n = new Node(value, priority);
		
		for (int i = 0; i <= priority; i++) {
			
			cout << n->value << endl;
			if (head->next[i] == tail) {
				n->next[i] = tail;
				n->prev[i] = head;
				head->next[i] = n;
				tail->prev[i] = n;
				cout << "if statement " << endl;
				
			} else {

				Node* temp = head->next[i];
				n->next[i] = temp;
				n->prev[i] = head;
				head->next[i] = n;
				
			}
		}	
       
		if (currentHighestPriority < priority) {
			currentHighestPriority = priority;
		}
	}

	int Dequeue() {
		
		int value = -1;
		if (head->next[0] != tail && currentHighestPriority >=0) {
			cout << "current highest priority : " << currentHighestPriority << endl;
			Node* temp = tail->prev[currentHighestPriority];
			value = temp->value;
			for (int i = currentHighestPriority; i >= 0; i--) {
				temp->prev[i]->next[i] = temp->next[i];
				temp->next[i]->prev[i] = temp->prev[i];
			}

			delete temp;

			while (head->next[currentHighestPriority] == tail) {
				currentHighestPriority--;
			}

		}
		
		return value;
	}

	int Process() {
		vector<int> processingOrder;

		while (Dequeue() != -1) {
			processingOrder.push_back(Dequeue());
		}

		int size = processingOrder.size();

		cout << "Processing Order : ";
		for (int i = 0; i < size; i++) {
			cout << processingOrder[i] << " , ";
		}

		
		return 0;
	}

	void Display() {
		
		cout << currentHighestPriority << "<< current highest" << endl;
		
		for (int i = 0; currentHighestPriority >= i; i++) {
			Node* node = head->next[i];
			cout << "Priority " << i << endl;
			while (node->next[i] != tail) {
				cout << node->value << " -> ";
				node = node->next[i];
			}
			if (node) {
				cout << node->value << " .\n";
			}
			else {
				cout << " .\n";
			}
			
		}
	}
};

#endif
