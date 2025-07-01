#include "LinkedListFull.h"
#include <iostream>
using namespace std;

/**
 * @brief this is a main method to test linked list in LinkedListFull.h.
 * 
 * @param none
 * @return int 
 */
int main(){
LinkedList<int> list;
// Display a empty list
cout << "Showing the list is currently empty: ";
list.Show();
// Add elements to the list
list.add(10);
list.add(20);
list.add(30);

// Display the list using the recursive Show method
cout << "List contents after adding 10, 20, 30 in order: ";
list.Show();

// Remove the last element
int removedValue = list.removeLast();
cout << "Removed last element: " << removedValue << endl;

// Display the modified list
cout << "List contents after removing the last element: ";
list.Show();

// Display if the linked list contains target element
cout << "List contains 20?: " << boolalpha << list.contains(20) << endl;
cout << "List contains 30?: " << boolalpha << list.contains(30) << endl;


// Test add(int index, T element)
list.add(2, 40);
list.add(2, 30);
cout << "List after adding (2, 40) and (2, 30) in order: ";
list.Show();

// Test if the index in add(int index, T element) greater than the list's size
list.add(10, 50); // size : 4 
cout << "List after adding (10, 50) when the size is 4: ";
list.Show();

//Tests clear()
list.clear();
cout << "Display after clear() invoked: ";
list.Show();
}