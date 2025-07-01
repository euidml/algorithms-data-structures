#include "Hotel.h"

using namespace std;

void Menu(int option, Hotel h){
    if(option == 0){
        cout << "\nTest has ended...\n" << endl;
        return;
    }else if(option == 1){
        cout << "\nTesting ShowRooms()\n" << endl;
        cout << "Booking extra rooms first... \n" << endl;
        h.BookRoom(5);
        h.BookRoom(41);
        h.BookRoom(32);
        h.BookRoom(59);
        h.BookRoom(12);
        h.BookRoom(18);
        h.BookRoom(14);
        h.BookRoom(9);
        h.BookRoom(39);
        h.BookRoom(37);
        cout << "\n*** Result ***\n" << endl;
        h.ShowRooms();
    }else if(option == 2){
        cout << "\nTesting BookRoom()\n" << endl;
        cout << "Testing invalid room number (1 > number || number > 60)" << endl;
        cout << "Trying to book 0" << endl;
        h.BookRoom(0);
        cout << "Trying to book 61" << endl;
        h.BookRoom(61);
        cout << "\nTesting valid room number (1 < number <= 60)" << endl;
        cout << "Trying to book 1" << endl;
        h.BookRoom(1);
        cout << "Trying to book  30" << endl;
        h.BookRoom(30);
        cout << "Trying to book 60" << endl;
        h.BookRoom(60);
        cout << "Trying to book  30 again to see if the appropriate messege pops up" << endl;
        h.BookRoom(30);
    }else if(option == 3){
        cout << "\nTesting CheckOut()\n" << endl;
        cout << "Testing invalid room number (1 > number || number > 60)" << endl;
        cout << "Trying to checkout 0" << endl;
        h.CheckOut(0);
        cout << "Trying to checkout 61" << endl;
        h.CheckOut(61);
        cout << "\nTesting valid room number (1 < number <= 60)" << endl;
        cout << "Trying to checkout 1 which is not booked yet to see if the appropriate messege pops up" << endl;
        h.CheckOut(1);
        cout << "Trying to checkout  30 which is already booked before Menu() excuted" << endl;
        h.CheckOut(30);
        cout << "Trying to checkout 60" << endl;
        h.CheckOut(60);
        cout << "Trying to checkout 30 again to see if the appropriate messege pops up" << endl;
        h.CheckOut(30);
    }
    Menu(option - 1, h);
}

int main(){
    Hotel h;
    int option = 3;
    // booking a room for testing Checkout()
    h.BookRoom(30);
    cout << "\nTest for Hotel class\n" << endl;
    Menu(option, h);
}
