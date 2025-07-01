#include <iostream>
#include <cstdlib>
#include <ctime>
#include "HashingLinearProbingDemo.h"

using namespace std;

int main(){
    srand(time(0));
 
    cout << "\nTesting a hash table:" << endl;
    HashingLinearProbingDemo hashTable(10, 0.75); // skiplist with maximum level index
    // Testing Insert()
    cout << "\nTesting Insert():\n" << endl;
    cout << "Displaying values" << endl;
    cout << "Inserting 0 to see if error would raised up" << endl;
    hashTable.insert(0);
    hashTable.insert(1);
    hashTable.insert(-1);
    // inserting duplicated values to see if it works correctly.
    hashTable.insert(6);
    hashTable.insert(6);
    hashTable.Display();
    cout << "Displaying values after rehashing" << endl;
    hashTable.insert(2);
    hashTable.insert(4);
    hashTable.insert(25);
    hashTable.insert(42);
    hashTable.insert(-23);
    hashTable.Display();

    // Testing Search()
    cout << "\nTesting Search():\n" << endl;
    cout << "Displaying values" << endl;
    hashTable.Display();
    cout << "Searching 0 to see if error would raised up" << endl;
    hashTable.search(0);
    cout << "Searching 1; 1 exist? : " << boolalpha << hashTable.search(1) << endl;
    cout << "Searching -1; -1 exist? : " << boolalpha << hashTable.search(-1) << endl;
    cout << "Searching 5; 5 exist? : " << boolalpha << hashTable.search(5) << endl;

    cout << "\nTesting remove():\n" << endl;
    cout << "Displaying values" << endl;
    hashTable.Display();
    cout << "\nAttempting to remove 0 to see if error would raised up" << endl;
    hashTable.remove(0);
    cout << "\nSearching 1; 1 exist? : " << boolalpha << hashTable.search(1) << endl;
    cout << "Removing 1" << endl;
    hashTable.remove(1);
    cout << "Searching 1; 1 exist? : " << boolalpha << hashTable.search(1) << endl;
    cout << "\nSearching 5; 5 exist? : " << boolalpha << hashTable.search(5) << endl;
    cout << "Removing 5" << endl;
    hashTable.remove(5);
    cout << "Searching 5; 5 exist? : " << boolalpha << hashTable.search(5) << endl;

    // Testing rehashing manually
    cout << "\nTesting Rehash() Manually:\n" << endl;
    cout << "Previous hashTable: " << endl;
    hashTable.Display();
    hashTable.ReHash();
    cout << "New hashTable after rehashing: " << endl;
    hashTable.Display();
    
    



    
    return 0;
}