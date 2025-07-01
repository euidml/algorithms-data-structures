#include <iostream>
#include <cmath>

using namespace std;

#ifndef HOTEL_H
#define HOTEL_H

class Hotel{
    private:
        long rooms;
    
    public:
        Hotel(){
            rooms = 0;
        }

        bool CheckAvailability(int roomNumber){
            if(1 > roomNumber || roomNumber > 60){
                cout << "Room number "<< roomNumber << " doesn't exist." << endl;
                return false;
            }
            return (rooms >> (roomNumber - 1) & 1) == 0;
        }

        void BookRoom(int roomNumber){
            if(CheckAvailability(roomNumber)){
                rooms |= (1L << (roomNumber - 1));
                cout << "Room number " << roomNumber << " booked." << endl;
            }else{
                cout << "Room number " << roomNumber << " didn't booked. It is not available." << endl;
            }

        }

        void CheckOut(int roomNumber) {
            if(!CheckAvailability(roomNumber) && (0 < roomNumber && roomNumber <= 60)){
                rooms &= ~(1L << (roomNumber - 1));
                cout << "Room number " << roomNumber << " has checked out." << endl;
            }else{
                cout << "Room number " << roomNumber << " has not checked out. It is not booked yet." << endl;
            }
        }
        
        void ShowRooms(){
            int reserved = 0, available = 0; 
            bool ifReserved;
            unsigned long long lastRoom = 1ULL << 60;
            for(unsigned long long current = 1; current < lastRoom; current <<= 1){
                int i = log2(current);
                ifReserved = ((rooms >> i) & 1) == 1;
                cout << "Room number " << i + 1 << " is " << (ifReserved ? "reserved." : "available.") << endl;
                if(ifReserved){
                    reserved++;
                }else{
                    available++;
                }
            }
            cout <<"\nSummary:\nTotal reserved: " << reserved << " rooms\n" << "Total available: " << available << " rooms\n" << endl;
        }
};

#endif
