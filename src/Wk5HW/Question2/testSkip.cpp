#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SkipList.h"

using namespace std;

int main(){
    srand(time(0));
 
    cout << "\nTesting a singly linked skiplist:" << endl;
    SkipList hashTable(10, 0.75, 3); // skiplist with maximum level index
    
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

    //Testing remove
    cout << "\nTesting remove():\n" << endl;
    cout << "Displaying values" << endl;
    hashTable.Display();
    cout << "\nAttempting to remove 0 to see if error would raised up" << endl;
    hashTable.remove(0);
    cout << "\nSearching 1; 1 exist? : " << boolalpha << hashTable.search(1) << endl;
    cout << "Removing 1" << endl;
    hashTable.remove(1);
    cout << "Searching 1; 1 exist? : " << boolalpha << hashTable.search(1) << endl;
    cout << "\nSearching -1; -1 exist? : " << boolalpha << hashTable.search(-1) << endl;
    cout << "Removing -1" << endl;
    hashTable.remove(-1);
    cout << "Searching -1; -1 exist? : " << boolalpha << hashTable.search(-1) << endl;
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
    

    // // test inserting
    // cout << "\nTesting insert():" << endl;
    // lst.insert(13);
    // lst.insert(7);
    // lst.insert(11);
    // lst.insert(11);
    // lst.insert(1);
    // lst.Display();


    // cout << "\n Calling Rehash() internally" << endl;
    // lst.insert(2);
    // lst.insert(4);
    // lst.insert(3);
    // lst.insert(-1);
    // lst.insert(23);
    // lst.Display();

    // cout << "\nTesting delete():" << endl;
    // lst.Delete(3);
    // // lst.Delete(23);
    // lst.Display();


    // lst.insert(19);

    // lst.insert(313);
    // lst.insert(37);
    // lst.insert(311);
    // lst.insert(31);
    // lst.insert(35);
    // lst.insert(319);
    // cout << "Inserted as below:" << endl;
    // lst.Show();

    // //test searching
    // cout << "\n\nTesting search():" << endl;
    // lst.Show();
    // cout << "\n-1 Exist?: "; 
    // cout << boolalpha <<  lst.Search(-1) << endl;
    // cout << "1 Exist?: "; 
    // cout << boolalpha <<  lst.Search(1) << endl;
    // cout << "31 Exist?: "; 
    // cout << boolalpha <<  lst.Search(31) << endl;
    // cout << "319 Exist?: "; 
    // cout << boolalpha <<  lst.Search(319) << endl;
    // cout << "500 Exist?: "; 
    // cout << boolalpha <<  lst.Search(500) << endl;

    // //test delete
    // cout << "\n\nTesting Delete():" << endl;
    // lst.Show();
    // cout << "\n1 Exist?: "; 
    // cout << boolalpha <<  lst.Search(1) << endl;
    // cout << "Attempting to delete 1" <<endl;
    // lst.Delete(1);
    // cout << "1 Exist?: "; 
    // cout << boolalpha <<  lst.Search(1) << endl;
    // cout << "\n319 Exist?: "; 
    // cout << boolalpha <<  lst.Search(319) << endl;
    // cout << "Attempting to delete 319" <<endl;
    // lst.Delete(319);
    // cout << "319 Exist?: "; 
    // cout << boolalpha <<  lst.Search(319) << endl;
    // cout << "\n500 Exist?: "; 
    // cout << boolalpha <<  lst.Search(1) << endl;
    // cout << "Attempting to delete 500" <<endl;
    // lst.Delete(500);
    // cout << "500 Exist?: "; 
    // cout << boolalpha <<  lst.Search(1) << "\n" << endl;

    // //Show the noes left
    // cout << "\nShowing nodes left:" << endl;
    // lst.Show();
    return 0;
}