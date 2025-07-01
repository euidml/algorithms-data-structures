#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "LinkedListFull.h"
using namespace std;
/**
 * @brief a class represents int type Queue ADT using linked list from "LinkedListFull.h"
 * 
 */
template <typename T>
class Queue
{
  private:
    LinkedList<int> data;
    int size;

  public:
    /**
     * @brief Construct a new Queue object
     * 
     */
    Queue(){
      size = 0;
    }
    /**
   * @brief this method is to add a node in the rear of the queue (first in)
   * 
   * @example
   * Queue q;
   * q.enqueue(1);
   * q.enqueue(2);
   * q.enqueue(3);
   * 
   * @result
   * q = 1 -> 2 -> 3
   * 
   * @timecomplexity: O(1) because we know the exact reference of the rear.
   * 
   * @param value - int
   * 
   * @return none
   */
    void enequeue(int value){
      data.addLast(value);
    }
    /**
     * @brief this method is to delete the first node in head from of the queue and return the value of it(first out)
     * 
     * @example
     * Queue q;
     * q.enqueue(1);
     * q.enqueue(2);
     * q.enqueue(3);
     * int a = q.pop();
     * 
     * @result
     * q = 2 -> 3
     * a = 1
     * 
     * @timecomplexity: O(1) because we know the exact reference of the head.
     * 
     * @param value - int
     * 
     * @return none
     */
    int pop(){
      return data.removeFirst();
    }
    /**
     * @brief this method is to return the value of a node in the head of the queue (first in)
     * 
     * @example
     * Queue q;
     * q.enqueue(1);
     * q.enqueue(2);
     * q.enqueue(3);
     * int a = q.peekFront()
     * 
     * @result
     * q = 1 -> 2 -> 3
     * a = 1
     * 
     * @timecomplexity: O(1) because we know the exact reference of the head.
     * 
     * @param value - int
     * 
     * @return none
     */
    int peekFront(){
      return data.getFirst();
    }
    /**
     * @brief this method is to return the value of a node in the rear of the queue (first out)
     * 
     * @example
     * Queue q;
     * q.enqueue(1);
     * q.enqueue(2);
     * q.enqueue(3);
     * int a = q.peekRear()
     * 
     * @result
     * q = 1 -> 2 -> 3
     * a = 3
     * 
     * @timecomplexity: O(1) because we know the exact reference of the rear.
     * 
     * @param value - int
     * 
     * @return none
     */
    int peekRear(){
      return data.getLast();
    }
};

#endif