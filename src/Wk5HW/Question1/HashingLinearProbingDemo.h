#ifndef HASHINGLINEARPROBINGDEMO_H
#define HASHINGLINEARPROBINGDEMO_H
#include <iostream>
#include <functional>

using namespace std;

class HashingLinearProbingDemo{
    private:
        int* hashTable;
        int hashTableSize;
        int numberOfKeys;
        double loadFactorThreshold;
        bool validate(int value){
            if(hashTable == nullptr){
                cout << "Hash Table is currently NULL" << endl;
                return false;
            }
            if(value == 0){
                cout << "0 is not allowed" << endl;
                return false;
            }
            return true;
        }
        int hashing(int value){
            hash<int> builtInHashFunction;
            return builtInHashFunction(value) % hashTableSize;
        }
    
    public:
        HashingLinearProbingDemo(){
            hashTable = nullptr;
            hashTableSize = 0;
            numberOfKeys = 0;
            loadFactorThreshold = 1.0;
        }
        HashingLinearProbingDemo(int size, double lft){
            hashTableSize = size;
            hashTable = new int[hashTableSize];
            numberOfKeys = 0;
            for(int i = 0; i < hashTableSize; i++)
                hashTable[i] = 0;
            loadFactorThreshold = lft;
        }

        ~HashingLinearProbingDemo(){
            cout << "destructing Hash Table" << endl;
            delete[] hashTable;
        }

        void insert(int value){
            if(!validate(value) || search(value)) // checking if there's a duplicated value
                return;
            if(((double)numberOfKeys + 1)/hashTableSize >= loadFactorThreshold) // why numberOfKeys + 1?
                ReHash();
            int hashTableIndex = hashing(value);
            // cout <<"index: " <<  hashTableIndex << endl;
            while(hashTable[hashTableIndex] != 0) // did linear probing with while loop instead of using if-else
                hashTableIndex = (hashTableIndex + 1) % hashTableSize;
            hashTable[hashTableIndex] = value;
            numberOfKeys++;

        }

        void remove(int value){
            if(!validate(value))
                return;
            int hashTableIndex = hashing(value);
            while (hashTable[hashTableIndex] != 0) {
                if (hashTable[hashTableIndex] == value) {
                    hashTable[hashTableIndex] = 0;
                    numberOfKeys--;
                    return;
                }
                hashTableIndex = (hashTableIndex + 1) % hashTableSize;
            }
        }

        bool search(int value){
            if(!validate(value))
                return false;
            int hashTableIndex = hashing(value);
            while(hashTable[hashTableIndex] != 0){
                if (hashTable[hashTableIndex] == value) 
                    return true;
                hashTableIndex = (hashTableIndex + 1) % hashTableSize;
            }
            return false;
        }
        void ReHash(){
            int prevSize = hashTableSize;
            int* prevHashTable = hashTable;
            hashTableSize *= 2;
            hashTable = new int[hashTableSize];
            for(int i = 0; i < prevSize; i++){
                if(prevHashTable[i] != 0){
                    // prevent rehashing again
                    // decrease numberOfKeys first because it would incease again in the insert();
                    numberOfKeys--; 
                    insert(prevHashTable[i]);
                }
            }
            cout << "\nRehash () excuted; \nprev size: " << prevSize << " current size: " << hashTableSize << "\n"<< endl;
            delete[] prevHashTable;
            return;
        }

        void Display(){
            for(int i = 0; i < hashTableSize; i++){
                cout << hashTable[i] << " ";
            }
            cout << endl;
        }

};

#endif