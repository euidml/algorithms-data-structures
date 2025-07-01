#include <iostream>
#include <cstdlib>
#include <random>
#include <ctime>
#include <chrono>
#include <cmath> 
#include "HashingLinearProbingDemo.h"
#include "MergeSort.h"
#include "GenerateRandomString.h"

using namespace std;
using namespace std::chrono;

bool OofNSqurare(string str){
    for (int i = 0; i < str.length(); i++){
        for (int j = 0; j < str.length(); j++){
            if(i != j && str[i] == str[j])
                return true;
        }
    }
    return false;
}

bool OofNlogN(string str) {
    string sortedStr = str;
    int length = sortedStr.length();
    // Sort the characters using Merge Sort
    mergeSort(sortedStr, 0, length - 1);
    // Check for adjacent duplicate characters in the sorted string
    for (int i = 1; i < length; i++) {
        if (sortedStr[i] == sortedStr[i - 1]) {
            return true;
        }
    }
    return false;
}

bool OofN(string str){
    HashingLinearProbingDemo a(str.length(), 1.0);
    int prev;
    for(int i = 0; i < str.length(); i++){
        prev = a.numofKeys();
        a.insert(str[i]);
        if(prev == a.numofKeys())
            return true;
    }
    return false;
}

int main(){
    
        // generating several random string with length of 40;
        cout << "\nGenerating random strings & non-duplicated string\n" << endl;
        int NUMBER_OF_STRINGS = 10;
        GenerateRandomString strs[NUMBER_OF_STRINGS];
        double OofNSquareAverageTime = 0;
        double OofNLogNAverageTime = 0;
        double OofNAverageTime = 0;
        for(int i = 0; i < NUMBER_OF_STRINGS; i++)
            cout << strs[i].getString() << endl;
        // GenerateRandomString a(40); 
        // GenerateRandomString b(40); 
        // GenerateRandomString c(40); 
        string non_duplcate = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        cout << "Printing generated strings" << endl;
        for(int i = 0; i < NUMBER_OF_STRINGS; i++)
            cout << strs[i].getString() << endl;
        // cout << a.getString() << endl;
        // cout << b.getString() << endl;
        // cout << c.getString() << endl;
        cout << non_duplcate << endl;
        bool isRepeated=false;
        string str;
        // O(n^2) solution
        cout << "\nChecking if repeated characters in O(n^2) solution" << endl;
        for(int i = 0; i < NUMBER_OF_STRINGS; i++){
            str = strs[i].getString();
            // checking period
            auto start = high_resolution_clock::now();
            isRepeated = OofNSqurare(str);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << strs[i].getString() <<  ": " << boolalpha<< isRepeated << ", time taken (in nanoseconds): "<< duration.count()<< endl;
            OofNSquareAverageTime += duration.count();
        }
        // mostly O(n^s) is faster than O(nlogn) since O(nlogn) sort the string first where the most of strings contain duplicated string.
        cout << "Average time taken by O(n^2): " << OofNSquareAverageTime / NUMBER_OF_STRINGS << " nanoseconds." <<  endl; 
        // check if codes works properly
        cout << "Validating Algorithm with non-duplicated string" << endl;
        auto start = high_resolution_clock::now();
        isRepeated = OofNSqurare(non_duplcate);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << non_duplcate <<  ": " << boolalpha<< isRepeated << ", time taken (in nanoseconds): "<< duration.count()<< endl;
        OofNSquareAverageTime = duration.count();
        
        // O(nlog(n)) solution
        cout << "\nChecking if repeated characters in O(nlog(n)) solution using merge sort" << endl;
        for(int i = 0; i < NUMBER_OF_STRINGS; i++){
            str = strs[i].getString();
            // checking period
            auto start = high_resolution_clock::now();
            isRepeated = OofNlogN(str);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << str <<  ": " << boolalpha<< isRepeated << ", time taken (in nanoseconds): "<< duration.count()<< endl;
            OofNLogNAverageTime += duration.count();
        }
        cout << "Average time taken by O(nlogn): " << OofNLogNAverageTime / NUMBER_OF_STRINGS << " nanoseconds." <<  endl; 
        // check if codes works properly
        cout << "Validating Algorithm with non-duplicated string" << endl;
        start = high_resolution_clock::now();
        isRepeated = OofNlogN(non_duplcate);
        stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        cout << non_duplcate <<  ": " << boolalpha<< isRepeated << ", time taken (in nanoseconds): "<< duration.count()<< endl;
        OofNLogNAverageTime = duration.count();

        // O(n) solution
        cout << "\nChecking if repeated characters in O(n) solution using hashtable(set)" << endl;
        for(int i = 0; i < NUMBER_OF_STRINGS; i++){
            str = strs[i].getString();
            // checking period
            auto start = high_resolution_clock::now();
            isRepeated = OofN(str);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop - start);
            cout << str <<  ": " << boolalpha<< isRepeated << ", time taken (in nanoseconds): "<< duration.count()<< endl;
            OofNAverageTime += duration.count();
        }
        cout << "Average time taken by O(n): " << OofNAverageTime / NUMBER_OF_STRINGS << " nanoseconds." <<  endl; 
        // check if codes works properly
        cout << "Validating Algorithm with non-duplicated string" << endl;
        start = high_resolution_clock::now();
        isRepeated = OofN(non_duplcate);
        stop = high_resolution_clock::now();
        duration = duration_cast<nanoseconds>(stop - start);
        cout << non_duplcate <<  ": " << boolalpha<< isRepeated << ", time taken (in nanoseconds): "<< duration.count()<< endl;
        OofNAverageTime = duration.count();

        cout << "\nValidating time complexities of operation on non-duplicated string aussming O(n) with non-duplicated string is corrected for expected O(n)" << endl;
        cout << "O(n) in nanoseconds - Expected : " << OofNAverageTime << ", Actual: " << OofNAverageTime << endl;
        cout << "O(n*log(n)) in nanoseconds - Expected: " << OofNAverageTime*log2(OofNAverageTime)  << ", Actual: " << OofNLogNAverageTime << endl;
        cout << "O(n) in nanoseconds - Expected: " << pow(OofNAverageTime, 2) << ", Actual: " << OofNSquareAverageTime << endl;


    return 0;

}
