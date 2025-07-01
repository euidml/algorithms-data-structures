#include <iostream>
#include <vector>
#include "CircularList.h"
#include "RoundRobinProcessScheduler.h"

using namespace std;

int main(){
    // testing CircularLinkedList here
    cout << "\nTesting a circular linked list:" << endl;
    CircularLinkedList c;
    // testing insert()
    c.insert(1, 10);
    c.insert(2, 20);
    c.insert(3, 30);
    //testing display()
    cout << "current nodes in order: ";
    c.display();
    // testing getLastNode()
    int a = c.getLastNode() -> data;
    cout << "Value of last (tracking) node: " << a << endl;
    // testing goToNext()
    c.goToNext();
    a = c.getLastNode() -> data;
    cout << "Value of last (tracking) node after go to next: " << a << endl;
    cout << "current nodes in order: ";
    c.display();
    // testing deleteNode
    c.deleteNode(20);
    cout << "current nodes in order after deleting 20: ";
    c.display();
    //testing round robin
    cout << "\nTesting a Round Robin: " << endl;
    RoundRobinProcessScheduler r;
    r.LoadFromFile("process.txt");
    r.Process();
    r.ShowResults();
    // Testing deconstructors - will be executeed after main() returned.
    cout << "\nExcuting Deconstructors" << endl;
    return 0;
}