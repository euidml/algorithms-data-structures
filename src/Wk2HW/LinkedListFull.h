#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
  T element;     // Element contained in the node
  Node<T> *next; // Pointer to the next node

  Node() // No-arg constructor
  {
    next = NULL;
  }

  Node(T element) // Constructor
  {
    this->element = element;
    next = NULL;
  }
};

template <typename T>
class LinkedList
{
public:
  LinkedList()
  {
    head = tail = NULL;
    size = 0;
  }
  void addFirst(T element)
  {
    Node<T> *newNode = new Node<T>(element);
    newNode->next = head;
    head = newNode;
    size++;

    if (tail == NULL)
      tail = head;
  }
  void addLast(T element)
  {
    if (tail == NULL)
    {
      head = tail = new Node<T>(element);
    }
    else
    {
      tail->next = new Node<T>(element);
      tail = tail->next;
    }

    size++;
  }
  T getFirst() const
  {
    if (size == 0)
      cout << ("Index out of range");
    else
      return head->element;
  }
  T getLast() const
  {
    if (size == 0)
      cout << ("Index out of range");
    else
      return tail->element;
  }
  T removeFirst() 
  {
    if (size == 0)
      cout << ("No elements in the list");
    else
    {
      Node<T> *temp = head;
      head = head->next;
      size--;
      T element = temp->element;
      delete temp;
      return element;
    }
  }
/**
 * @brief this method is to remove the last node (tail) in the Linked List and return the element of the node
 * 
 * @example
 * LinkedList<int> list;
 * list.add(10);
 * list.add(20);
 * list.add(30);
 * list.show();
 * int a = list.removeLast();
 * list.show();
 * cout << "a: " << a << endl;
 * 
 * @result
 * 10 -> 20 -> 30
 * 10 -> 20
 * a: 30
 * 
 * @timecomplexity: O(1) if the size is either 0  or 1, otherwise O(n) recursively
 * 
 * @param none
 * @return T
 */
T removeLast()
{
  if (size == 0)
    throw runtime_error("No elements in the list");
  else if (size == 1)
  {
    Node<T> *temp = head;
    head = tail = NULL;
    size = 0;
    T element = temp->element;
    delete temp;
    return element;
  }
  else
  {
   return removeLast(head);
  }
}


  void add(T element)
  {
    addLast(element);
  }

  
  /**
   * @brief this method is to add a node in the specified target index.
   * 
   * @example 
   * LinkedList<int> list;
   * list.add(10);
   * list.add(20);
   * list.show();
   * list.add(1, 30);
   * list.show();
   * list.add(6, 40);
   * list.show();
   * 
   * @result
   * 10 -> 20
   * 10 -> 30 -> 20
   * 10 -> 30 -> 20 -> 40
   * 
   * @timecomplexity: O(1) if the target index is at head, tail or greater number than the size , otherwise O(n)
   * 
   * @param index-int, element-T
   * @return none
   */
  void add(int index, T element)
  {
    if (index == 0)
      addFirst(element);
    else if (index >= size)
      addLast(element);
    else
    {
      size++;
      return add(index, 0, element, head);
    }
  }
  /**
   * @brief this method is to clear all nodes in the Linked List 
   * 
   * @example 
   * LinkedList<int> list;
   * list.add(10);
   * list.add(20);
   * list.add(30);
   * list.show();
   * list.clear();
   * list.show();
   * 
   * @result
   * 10 -> 20 -> 30
   * It is empty
   * 
   * @timecomplexity: always O(n) since it is using clear(Node<T> *current),
   * a recursive helper method with time complexity O(n)
   * 
   * @param none
   * @return none
   */
  void clear()
  {
    clear(head);
    delete tail;
    size = 0;
  }
  /**
   * @brief this method is to check if any nodes have a target value at least once.
   * 
   * @example
   * LinkedList<int> list;
   * list.add(10);
   * list.add(20);
   * list.add(30);
   * cout << boolalpha << list.contains(20) << endl;
   * cout << boolalpha << list.contains(40) << endl;
   * list.show();
   * @result
   * true
   * false
   * 
   * @timecomplexity: O(n) since it always invokes contains(T element, Node<T> *current) which is O(n)
   * 
   * @param element, T
   * @return boolean
   */
  bool contains(T element)
  {
    return contains(element, head);
  }
 
  T get(int index) const
  {
    if (index < 0 || index > size - 1)
      cout << ("Index out of range");

    Node<T> *current = head;
    for (int i = 0; i < index; i++)
      current = current->next;

    return current->element;
  }
  int indexOf(T element) const
  {
    // Implement it in this exercise - DONE; already implemented
    Node<T> *current = head;
    for (int i = 0; i < size; i++)
    {
      if (current->element == element)
        return i;
      current = current->next;
    }

    return -1;
  }
  bool isEmpty() const
  {
    return head == NULL;
  }
  int lastIndexOf(T element) const
  {
    int lastIndex = -1;
    Node<T> *current = head;
    for (int i = 0; i < size; i++)
    {
      if (current->element == element)
        lastIndex = i;
      current = current->next;
    }

    return lastIndex;
  }

  int getSize() const
  {
    return size;
  }
  T remove(int index)
  {
    if (index < 0 || index >= size)
      cout << ("Index out of range");
    else if (index == 0)
      return removeFirst();
    else if (index == size - 1)
      return removeLast();
    else
    {
      Node<T> *previous = head;

      for (int i = 1; i < index; i++)
      {
        previous = previous->next;
      }

      Node<T> *current = previous->next;
      previous->next = current->next;
      size--;
      T element = current->element;
      delete current;
      return element;
    }
  }
  T set(int index, T element)
  {
    if (index < 0 || index >= size)
      cout << ("Index out of range");

    Node<T> *current = head;
    for (int i = 0; i < index; i++)
    {
      current = current->next;
    }

    T oldElement = current->element;
    current->element = element;
    return oldElement;
  }
  /**
   * @brief this method is to display elements nodes graphically
   * 
   * @example
   * LinkedList<int> list;
   * list.add(10);
   * list.add(20);
   * list.add(30);
   * list.show();
   * list.clear()
   * list.show();
   * 
   * @result
   * 10 -> 20 -> 30
   * It is empty
   * 
   * @timecomplexity: O(1) if size == 0, otherwise O(n)
   * 
   * @param none
   * @return none
   */
  void Show()
  {
    if(size != 0)
      return Show(head);
    else
      cout << "It is empty" << endl;
  }
  

private:
  Node<T> *head, *tail;
  int size;
  /**
   * @brief a private helper method of add(int index, T element) finds a targer recursively.
   * 
   * @example
   * LinkedList<int> list;
   * list.add(10);
   * list.add(20);
   * list.show();
   * list.add(1, 0, 30, list.head); // assuming head is a public member of list.
   * list.show();
   * 
   * @result
   * 10 -> 20
   * 10 -> 30 -> 20
   * 
   * @timecomplexity: O(n) since it is a recursive method.
   * 
   * @param index-int, count-int, element-T, current-pointer of Node<T>
   * @return none
   */
  void add(int index, int count, T element, Node<T> *current){
    if(index - 1 == count){
      Node<T> *temp = current->next;
      current->next = new Node<T>(element);
      (current->next)->next = temp;
    }else{
      return add(index, ++count, element, current->next);
    }
  }
  /**
 * @brief a private helper method of removeLast() to find a target node(tail) recursively
 * 
 * @example
 * * LinkedList<int> list;
 * list.add(10);
 * list.add(20);
 * list.add(30);
 * list.show();
 * int a = list.removeLast(list.head); // assuming head is a public member of list.
 * list.show();
 * cout << "a: " << a << endl;
 * 
 * @result
 * 10 -> 20 -> 30
 * 10 -> 20
 * a: 30
 * 
 * @timecomplexity: O(n) since it is a recursive method.
 * 
 * @param current, pointer of Node<T>
 * @return T, element of the last node
 */
T removeLast(Node<T> *current)
{
  if (current->next == tail)
  {
    Node<T> *temp = tail;
    tail = current;
    tail->next = NULL;
    T element = temp->element;
    size--;
    delete temp;
    return element;
  }
  else
  {
    return removeLast(current->next);
  }
}
  
   /**
   * @brief a private helper method of clear() deletes all nodes in the list recursively.
   * 
   * @example
   * LinkedList<int> list;
   * list.add(10);
   * list.add(20);
   * list.add(30);
   * list.show();
   * list.clear(list.head); //assuming head is a public member of list.
   * list.show();
   * 
   * 
   * @result
   * 10 -> 20 -> 30
   * It is empty
   * 
   * @timecomplexity: O(n) because it iterates the whole list from the head to the tail recursvely.
   * 
   * @param current - pointer of Node<T>
   * @return none
   */
  void clear(Node<T> *current){
    if(current != tail){
      clear(current->next);
      delete current;
    }
  }

   /**
   * @brief this method is a private helper method of contains(T element)
   * 
   * @example
   * LinkedList<int> list;
   * list.add(10);
   * list.add(20);
   * list.add(30);
   * cout << boolalpha << list.contains(20, list.head) << endl; //assuming head is a public member of list.
   * cout << boolalpha << list.contains(40, list.head) << endl; //assuming head is a public member of list.
   * @result
   * true
   * false
   * 
   * @timecomplexity: O(n) because it iterates the whole list 
   * from head until it finds target value or reaching the tail recursively.
   * 
   * @param  element-T, current-pointer of Node<T>
   * @return T 
   */
  bool contains(T element, Node<T> *current){
    if (current->element == element)
      return true;
    else if(current -> next == NULL)
      return false;
    return contains(element, current -> next); 
  }
  /**
   * @brief this is a private helper method of Show() to display elements recursively
   * 
   * @example
   * LinkedList<int> list;
   * list.add(10);
   * list.add(20);
   * list.add(30);
   * list.show(head); //assuming head is a public member of list 
   * // not need to test when size == 0 because it is only invoked when size != 0
   * 
   * @result
   * 10 -> 20 -> 30
   * It is empty
   * 
   * @timecomplexity: always O(n) because it iterates the whole list until it reaches the tail.
   * 
   * @param current-pointer of Node<T>
   * @return none
   */
  void Show(Node<T> *current){
    if(current -> next != NULL){
      cout << current->element << " -> ";
      return Show(current->next);
    }
    cout << current -> element << endl;
  }

};

#endif
