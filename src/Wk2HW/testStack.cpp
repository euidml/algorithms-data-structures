#include "Stack.h"
#include <iostream>

using namespace std;

/**
 * @brief this is a main method to test stack in Stack.h.
 * 
 * @param none
 * @return int 
 */
int main(){
    Stack stack;

    // Push some values onto the stack; [1, 2, 3]
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);

    // Peek and print the top item; [1, 2, 3]
    int peek = stack.peek();
    std::cout << "Top of the stack: " << peek << std::endl;

    // Pop and print the popped item [1, 2] 
    int poped = stack.pop();
    std::cout << "Popped item: " << poped << std::endl;

    // Peek and print the new top item, [1, 2]
    peek = stack.peek();
    std::cout << "Top of the stack after pop: " << peek << std::endl;

    return 0;
}