#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SkipList.h"

using namespace std;

int main(){
    srand(time(0));
 
    cout << "\nTesting a priority queue with a doubly linked skiplist:" << endl;
    SkipList lst(5); // skiplist with maximum level index
    
    // test inserting
    cout << "\nTesting Enqueue():" << endl;
    lst.Enqueue(13);
    lst.Enqueue(7);
    lst.Enqueue(11);
    lst.Enqueue(1);
    lst.Enqueue(5);
    lst.Enqueue(19);

    lst.Enqueue(313);
    lst.Enqueue(37);
    lst.Enqueue(311);
    lst.Enqueue(31);
    lst.Enqueue(35);
    lst.Enqueue(319);
    cout << "Inserted as below:" << endl; 
    lst.Show();

    // //test Dequeue
    cout << "\n\nTesting Dequeue():" << endl;
    lst.Show();
    cout << "Executing Dequeue" << endl;
    int a = lst.Dequeue();
    cout << "\nFirst Dequeued item:  " << a << endl;
    lst.Show();
    a = lst.Dequeue();
    cout << "Second Dequeued item:  " << a << endl;
    
    // test Process
    cout << "\nDo Processing:" << endl;
    lst.Process();
    cout << "\nExcuting Processing when there's no node left" << endl;
    lst.Process();
    cout << "\nAdding nodes before excuting destructor..." << endl;
    lst.Enqueue(1);
    lst.Enqueue(2);
    lst.Show();
    cout << "\nExcuting destructor..." << endl;
    return 0;
}