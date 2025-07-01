#include "Queue.h"
#include <iostream>
using namespace std;

/**
 * @brief this is a main method to test queue in Queue.h.
 * 
 * @param none
 * @return int 
 */
int main() {
    Queue<int> queue;

    // Enqueue some values into the queue
    queue.enequeue(10);
    queue.enequeue(20);
    queue.enequeue(30);

    // Peek at the front and rear items
    cout << "Front of the queue: " << queue.peekFront() << endl;
    cout << "Rear of the queue: " << queue.peekFront() << endl;

    // Dequeue and print the dequeued item
    cout << "Dequeued item: " << queue.pop() << endl;

    // Peek at the front and rear items again
    cout << "Front of the queue after dequeue: " << queue.peekFront() << endl;
    cout << "Rear of the queue after dequeue: " << queue.peekRear() << endl;
    
    return 0;
}