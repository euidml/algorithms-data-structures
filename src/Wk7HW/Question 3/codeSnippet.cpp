#include<iostream>
#include<vector>

using namespace std;

/**
 * Analyze the space complexity of the following problems.
 * For each problem write the space complexity as a function of input. 
 * Then write the big-Oh of the function.
 */

// a) The following function has a foreach loop
int ArraySum(const vector<int>& arr) { // O(1) - pass by reference
    int sum = 0; // O(1)
    for (int num : arr) { // int num - O(1); arr - passed from augument by its refenence.
        sum += num;
    }
    return sum;
}
// O(1) + O(a) + O(1) = O(1)

// b) Assume str1 has m characters and str2 has n characters
string StringConcatenation(const string& str1, const string& str2) {// O(1) + O(1) - both params are passed by reference
    return str1 + str2; // O(m + n) creating new string with length m + n
}
// O(1) + O(1) + O(m + n) = O(m + n); where m+n is the length of concatenated string.

// commented out because c) generates an error.
// // c) Assume matrix is a 2D matrix with dimensions m x n
// vector<vector<int>> TransposeMatrix(const vector<vector<int>>& matrix) { // O(1) - passed by reference
//     int m = matrix.size(); // O(1)
//     int n = matrix[0].size(); // O(1)
//     vector<vector<int>> transpose(n, vector<int>(m)); // O(m x n) - creating a new 2D matrix

//     for (int i = 0; i < m; i++) { // O(1) - creating integer i; and assigning each numbers in same space
//         for (int j = 0; j < n; j++) { // O(1) - creating integer j; and assigning each numbers in same space
//             transpose[j][i] = matrix[i][j]; // O(1) - assigning numbers into the space which is already allocated
//         }
//     }
//     return transpose; // O(1) - returning 2D matrix that is already created.
// }
// // O(1) + O(1) + O(1) + O(m x n) + O(1) + O(1) + O(1) + O(1) = O(m x n)

//d) d.	Write a function vector<int> Primes(int n) that returns the first n prime numbers in a vector.
//You MUST use the Sieve of Eratosthenes algorithm for generating prime numbers
vector<int> Primes(int n) { // O(1)
    if (n <= 1) 
        return vector<int>(); // O(1) - returns an empty vector
    if(n == 2)
        return vector<int>(1,2); // O(1)- allocates only one value - 2
    vector<int> primes(1, 2); // O(1)- allocated only one value - 2
    int num = 3; // O(1)
    // Overall, it keeps inserting prime numbers into primes vector until the primes vector has length of n
    // Therefore the space complexity would be O(n - 1) where n is the paramter 'n'; 2 is already allocated.
    while (primes.size() < n) { 
        bool isPrimeNum = true; //O(1)
        for (int prime : primes) { // O(1)
            if (prime * prime > num) 
                break;
            if (num % prime == 0) {
                isPrimeNum = false;
                break;
            }
        }
        if (isPrimeNum) 
            primes.push_back(num); //O(1)
        num += 2; // O(1) assuming num wouldn't overflow
    }
    return primes; // O(1) - returns vector that is already created with length O(n);
}
// O(1) if n <= 2
// otherwise, O(1) + O(1) + O(1) + O(n - 1) + O(1) + O(1) + O(1) + O(1) 
//            = O(n)
// where n is relying on the parameter 'n'

// testing for d)
int main() {
    int n = 100;
    vector<int> result = Primes(n);
    for (int prime : result) {
        cout << prime << " ";
    }
    return 0;
}



