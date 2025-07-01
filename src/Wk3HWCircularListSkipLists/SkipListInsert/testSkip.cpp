#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SkipList.h"

using namespace std;

int main(){
    srand(time(0));
 
    cout << "\nTesting a singly linked skiplist:" << endl;
    SkipList lst(3); // skiplist with maximum level index
    
    // test inserting
    cout << "\nTesting insert():" << endl;
    lst.InsertElement(13);
    lst.InsertElement(7);
    lst.InsertElement(11);
    lst.InsertElement(1);
    lst.InsertElement(5);
    lst.InsertElement(19);

    lst.InsertElement(313);
    lst.InsertElement(37);
    lst.InsertElement(311);
    lst.InsertElement(31);
    lst.InsertElement(35);
    lst.InsertElement(319);
    cout << "Inserted as below:" << endl;
    lst.Show();

    //test searching
    cout << "\n\nTesting search():" << endl;
    lst.Show();
    cout << "\n-1 Exist?: "; 
    cout << boolalpha <<  lst.Search(-1) << endl;
    cout << "1 Exist?: "; 
    cout << boolalpha <<  lst.Search(1) << endl;
    cout << "31 Exist?: "; 
    cout << boolalpha <<  lst.Search(31) << endl;
    cout << "319 Exist?: "; 
    cout << boolalpha <<  lst.Search(319) << endl;
    cout << "500 Exist?: "; 
    cout << boolalpha <<  lst.Search(500) << endl;

    //test delete
    cout << "\n\nTesting Delete():" << endl;
    lst.Show();
    cout << "\n1 Exist?: "; 
    cout << boolalpha <<  lst.Search(1) << endl;
    cout << "Attempting to delete 1" <<endl;
    lst.Delete(1);
    cout << "1 Exist?: "; 
    cout << boolalpha <<  lst.Search(1) << endl;
    cout << "\n319 Exist?: "; 
    cout << boolalpha <<  lst.Search(319) << endl;
    cout << "Attempting to delete 319" <<endl;
    lst.Delete(319);
    cout << "319 Exist?: "; 
    cout << boolalpha <<  lst.Search(319) << endl;
    cout << "\n500 Exist?: "; 
    cout << boolalpha <<  lst.Search(1) << endl;
    cout << "Attempting to delete 500" <<endl;
    lst.Delete(500);
    cout << "500 Exist?: "; 
    cout << boolalpha <<  lst.Search(1) << "\n" << endl;

    //Show the noes left
    cout << "\nShowing nodes left:" << endl;
    lst.Show();
    return 0;
}