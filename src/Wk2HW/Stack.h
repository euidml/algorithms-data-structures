#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief a class representing stack ADT.
 * 
 */
class Stack{
private:
    vector<int> data;
    int size;
public:
    Stack(){
        // data = vector<int>(); // not needed
        size = 0;
    };
    
    /**
     * @brief this method adds a new integer to the end of the data vector
     * 
     * @example
     * 
     * Stack s;
     * s.push(1);
     * s.push(2);
     * s.push(3);
     * 
     * @result
     * s = [1, 2, 3]
     * 
     * @timecomplexity:  O(n) when resezing as there's no enough capacity, otherwise O(1)
     * approaching O(1) (if it has enough capacity left; the capacity increases itself by 2 whenever it increase its size.)
     * 
     * @param x , int 
     * @return none
     */
    void Push(int x){
        data.push_back(x);
        size++;
    }

    /**
     * @brief this method retreives the last element of the data vector, delete it from the vector, and delete it. 
     * 
     * @example
     * Stack s;
     * s.push(1);
     * s.push(2);
     * int a = s.pop();
     * 
     * @result
     * s = [1]
     * a = 2
     * 
     * @timecomplexity: O(1) because we know the exact reference of the target(last element) with counting its size.
     * 
     * @param none
     * @return int 
     */
    int pop(){
        int temp = 0;
        if(peek() != 0){
            temp = data.back();
            data.pop_back();
            size--;
        }
        return temp;
    }

    /**
     * @brief this method retreives the last element of the data vector, and return it.
     * 
     * @example
     * Stack s;
     * s.push(1);
     * int a = s.peek();
     * 
     * @result
     * s = [1]
     * a = 1
     * 
     * @timecomplexity: O(1), same as pop(), we know the exact reference.
     * 
     * @param none
     * @return int 
     */
    int peek(){
        if(size == 0){
            cout << "Stack is empty! returning 0" << endl;
            return 0;
        }
        return data.back();
    }
};

#endif