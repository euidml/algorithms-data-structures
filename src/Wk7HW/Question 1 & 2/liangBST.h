#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <fstream>
using namespace std;

class TreeNode
{
public:
  int element; // Element contained in the node
  TreeNode* left; // Pointer to the left child
  TreeNode* right; // Pointer to the right child

  TreeNode() // default constructor
  {
    element = 0;
    left = nullptr;
    right = nullptr;
  }

  TreeNode(const int& e) // defined constructor
  {
    this->element = e;
    left = nullptr;
    right = nullptr;
  }
};

class BST
{
public:
  BST() // default constructor
  {
    root = nullptr;
    size = 0;
  }

  // BST(int *elements, int arraySize) // defined constructor
  // {
  //   root = nullptr;
  //   size = 0;

  //   for (int i = 0; i < arraySize; i++)
  //   {
  //     insert(elements[i]);
  //   }
  // }

  /* Copy constructor */
  BST(const BST& tree)
  {
    root = nullptr;
    size = 0;
    copy(tree.root); // Recursively copy nodes to this tree
  }

/////EXERCISE
  /* Copies the element from the specified tree to this tree */
  void copy(const TreeNode* root)
  {
    if(!root)
      return;
    int temp = root -> element;
    insert(temp);
    // insert(root -> element);
    copy(root -> left);
    copy(root -> right);
  }

  /* Destructor */
  ~BST()
  {
    clear();
  }

/////EXERCISE
  /* Return the address of the node if the element is in the tree; returns nullptr otherwise */
  TreeNode* search(const int& e) const
  {
    TreeNode* current = root;
    while(current){
      if(current -> element == e)
        return current;
      else if(current -> element < e)
        current = current -> right;
      else
        current = current -> left;
    }
    return nullptr;
  }

  TreeNode* createNewNode(const int& e)
  {
    return new TreeNode(e);
  }

  // Insert element e into the binary tree
  // Return true if the element is inserted successfully
  // Return false if the element is already in the list
  bool insert(const int& e)
  {
    if (root == nullptr)
      root = createNewNode(e); // Create a new root
    else
    {
      // Locate the parent node
      TreeNode* parent = nullptr;
      TreeNode* current = root;
      while (current != nullptr)
        if (e < current->element)
        {
          parent = current;
          current = current->left;
        }
        else if (e > current->element)
        {
          parent = current;
          current = current->right;
        }
        else
          return false; // Duplicate node not inserted

      // Create the new node and attach it to the parent node
      if (e < parent->element)
        parent->left = createNewNode(e);
      else
        parent->right = createNewNode(e);
    }

    size++;
    return true; // Element inserted
  }

  /* Inorder traversal */
  void inorder() const
  {
    inorder(root);
  }

  /* Inorder traversal from a subtree */
  void inorder(const TreeNode* someNode) const
  {
    if (someNode == nullptr) 
      return;
    inorder(someNode->left); // process all nodes in left sub-tree of someNode
    cout << someNode->element << " "; // process someNode
    inorder(someNode->right); // process all nodes in right sub-tree of someNode
  }

  /* Postorder traversal */
  void postorder() const
  {
    postorder(root);
  }

/////EXERCISE
  /** Inorder traversal from a subtree */
  void postorder(const TreeNode* someNode) const
  {
    if(someNode == nullptr) return;
    postorder(someNode -> left);
    postorder(someNode -> right);
    cout << someNode->element << " ";
  }

  /* Preorder traversal */;
  void preorder() const
  {
    preorder(root);;
  }

/////EXERCISE
  /* Preorder traversal from a subtree */;
  void preorder(const TreeNode* someNode) const
  {
    if(someNode == nullptr) return;
    cout << someNode->element << " ";
    preorder(someNode -> left);;
    preorder(someNode -> right);;
  }

  /* Get the number of nodes in the tree */
  int getSize() const
  {
    return size;
  }

/////EXERCISE
  /* Remove all nodes from the tree */
  void clear()
  {
    clear(root);
    root = nullptr;
    size = 0;
  }

  void clear(const TreeNode* someNode) const
  {
    if(!someNode)
      return;
    clear(someNode -> left);
    clear(someNode -> right);
    cout << someNode->element << " deleted!" << endl;
    delete someNode;
    
  }
/////EXERCISE
  /* Return a path from the root leading to the specified element.
  If specified element does not exist in the tree then add a nullptr 
  to the end.*/
  vector<TreeNode*>* path(const int& e) const
  {
    vector<TreeNode*>* nodes = new vector<TreeNode*>();
    TreeNode* current = root; 
    while(current){
      nodes -> push_back(current);
      if(current -> element < e)
        current = current -> right;
      else if(current -> element > e)
        current = current -> left;
      else
        break;
    }
    if(!current)
      nodes -> push_back(current);
    return nodes;
  }

  /* Delete an element e from the binary tree.
   * Return true if the element is deleted successfully
   * Return false if the element is not in the tree */
  bool remove(const int& e)
  {
    // Locate the node to be deleted and also locate its parent node
    TreeNode* parent = nullptr;
    TreeNode* current = root;
    while (current != nullptr)
    {
      if (e < current->element)
      {
        parent = current;
        current = current->left;
      }
      else if (e > current->element)
      {
        parent = current;
        current = current->right;
      }
      else
        break; // Element e is in the tree pointed by current
    }

    if (current == nullptr)
      return false; // Element e is not in the tree

    // Case 1: current has no left children
    if (current->left == nullptr)
    {
      // Connect the parent with the right child of the current node
      if (parent == nullptr)
      {
        root = current->right;
      }
      else
      {
        if (e < parent->element)
          parent->left = current->right;
        else
          parent->right = current->right;
      }

      delete current; // Delete current
    }
    else
    {
      // Case 2: The current node has a left child
      // Locate the rightmost node in the left subtree of
      // the current node and also its parent
      TreeNode* parentOfRightMost = current;
      TreeNode* rightMost = current->left;

      while (rightMost->right != nullptr)
      {
        parentOfRightMost = rightMost;
        rightMost = rightMost->right; // Keep going to the right
      }

      // Replace the element in current by the element in rightMost
      current->element = rightMost->element;

      // Eliminate rightmost node
      if (parentOfRightMost->right == rightMost)
        parentOfRightMost->right = rightMost->left;
      else
        // Special case: parentOfRightMost->right == current
        parentOfRightMost->left = rightMost->left;

      delete rightMost; // Delete rightMost
    }

    size--;
    return true; // Element inserted
  }

/////ADDITIONAL EXERCISES/////

    // returns the height of the tree
    int GetHeight(){
        if(root == nullptr){
            return 0;
        }
        else{
            return GetHeight(root);
        }
    }

/////EXERCISE
    // returns the height of someNode
    int GetHeight(TreeNode* someNode){
      if(someNode){
        int leftMostHeight = GetHeight(someNode -> left);
        int rightMostHeight = GetHeight(someNode -> right);
        return (leftMostHeight > rightMostHeight ? leftMostHeight : rightMostHeight) + 1;
      }
      return 0;
    }

    

    // Increment each node's value by 1
    void IncrementByOne(){
        InorderIncrementByOne(root);
    }

/////EXERCISE
    // Increment each node (that is part of the tree rooted at someNode) by 1
    void InorderIncrementByOne(TreeNode* someTreeNode){
        if(!someTreeNode)
          return;
        InorderIncrementByOne(someTreeNode -> left);
        someTreeNode -> element++;
        InorderIncrementByOne(someTreeNode -> right);
    }

    // returns the number of nodes in the tree
    int NodeCount(){
        return InOrderNodeCount(root);
    }

/////EXERCISE
    // returns the number of nodes in the tree rooted at someNode
    int InOrderNodeCount(TreeNode* someNode){
        if(someNode)
          return InOrderNodeCount(someNode -> left) + InOrderNodeCount(someNode -> right) + 1;
        return 0;
    }

    // returns the number of nodes in the tree with odd values
    int NodesWithOddValues(){
      return InOrderNodesWithOddValues(root);
    }

/////EXERCISE
    // returns the number of nodes in the tree rooted at someNode with odd values
    int InOrderNodesWithOddValues(TreeNode* someNode){
        if(someNode)
          return InOrderNodesWithOddValues(someNode -> left) + InOrderNodesWithOddValues(someNode -> right) + (someNode -> element % 2 != 0 ? 1 : 0);
        return 0;
    }

  // level order display
    void LevelOrderDisplay(){
        LevelOrderDisplay(root);
    }

/////EXERCISE
    // level order display of the tree rooted at someNode
    void LevelOrderDisplay(TreeNode* someNode){
        // use a queue, STL queue is fine
        if(!someNode)
          return;
        queue<TreeNode*> orderByLevel;
        orderByLevel.push(someNode);
        while(!orderByLevel.empty()){
          // getting the number of all nodes at previous level to clear them.;
          int a = orderByLevel.size();
          while(a > 0){
            TreeNode* temp = orderByLevel.front();
            orderByLevel.pop();
            cout << temp -> element <<  " ";
            if(temp -> left)
              orderByLevel.push(temp -> left);
            if(temp -> right)
              orderByLevel.push(temp -> right);
            a--;
          }
          cout << endl;
        }
    }
    
    // display tree like a tree horizontally
    void DisplayTreeHorizontally(){
        DisplayTreeHorizontally(root, 0);
    }

    // display the tree rooted at someNode like a tree, horizontally
    void DisplayTreeHorizontally(TreeNode* someNode, int space){
        if(someNode == nullptr){
            return;
        }
        else{
            space += 10;

            DisplayTreeHorizontally(someNode->right, space);

            cout << endl;
            for(int i = 10; i < space; i++){
                cout << " ";
            }
            cout << someNode->element << endl;

            DisplayTreeHorizontally(someNode->left, space);
        }
    }

    ///// This below is written from Question2
    // read file by constructor
    BST(string fileName){
      root = nullptr;
      size = 0;
      string myText;
      ifstream MyReadFile(fileName);
      // file is supposed to be saved as preorder;
      while(getline (MyReadFile, myText)){
        stringstream ss(myText);
        string token;
        while(getline(ss, token, ' ')){
          int number;
          stringstream(token) >> number;
          this -> insert(number);
        }
      }
      MyReadFile.close();
    }

    void saveTree(){
      ofstream MyFile("tree.txt");
      string temp = "";
      manipulateTreeInPreOrderIntoString(root, temp);
      MyFile << temp;
      MyFile.close();
    }

    void manipulateTreeInPreOrderIntoString(TreeNode* someNode, string& temp){
      if(!someNode)
        return;
      temp += to_string(someNode -> element) + " ";
      manipulateTreeInPreOrderIntoString(someNode -> left, temp);
      manipulateTreeInPreOrderIntoString(someNode -> right, temp);
    }
    

    TreeNode* kthSmallest(int k){
      if(k < 1 || k > size)
        return nullptr;
      TreeNode* current = root;
      if(k == 1){
        while(current -> left)
          current = current -> left;
      }
      else if(k == size){
        while(current -> right)
          current = current -> right;
      }
      else{
        int i = 0;
        findKthSmallest(root, k, i, current);
      }
      return current;
    }
    // finding kth smallest using inorder traverse recursively
    void findKthSmallest(TreeNode* someNode,int k, int& i, TreeNode*& kthElement){
      if(!someNode)
        return;
      findKthSmallest(someNode -> left, k, i, kthElement);
      i++;
      if(i == k){
        kthElement = someNode;
        return;
      }
      findKthSmallest(someNode -> right, k, i, kthElement);
    }

    TreeNode* ClosestCommonAncestor(TreeNode* node1, TreeNode* node2){
      if(!node1 || !node2)
        return nullptr;
      vector<TreeNode*>* path1 = path(node1 -> element);
      vector<TreeNode*>* path2 = path(node2 -> element);
      int currentClosestLvl = 0;
      while(currentClosestLvl < path1 -> size() && currentClosestLvl < path2 -> size() &&path1->at(currentClosestLvl) -> element == path2->at(currentClosestLvl) -> element)
         currentClosestLvl++;
      return path1->at(currentClosestLvl - 1);
    }
    
    
    bool operator == (BST* const& other){
        if(!other || this -> size != other -> size)
          return false;
        return checkBothElementsSame(this -> root, other -> root);
    }
    bool checkBothElementsSame(TreeNode* node1, TreeNode* node2){
      // XOR - if only one of the node is null, then the trees are not equal
      if(((!node1 && node2) || (node1 && !node2)))
        return false;
      // at this point it's true if both elements are equal, but we need to check for other leaves as well.
      return (!node1 && !node2) ? true : (node1 -> element == node2 -> element) && checkBothElementsSame(node1 -> left, node2 -> left) && checkBothElementsSame(node1 -> right, node2 -> right);
    }

    void operator = (BST* const& other){
      if(!other)
        return;
      this -> clear(this -> root);
      this -> copy(other -> root);
    }

    BST(int *elements, int arraySize, bool balanced = false) // defined constructor
  {
    root = nullptr;
    size = 0;
    if(balanced){
      sort(elements, elements + arraySize);
      int mid = arraySize / 2;
      for(int i = 0; i <= mid; i++){
        insert(elements[mid - i]);
        insert(elements[mid + i]);
      }
    }else{
      for (int i = 0; i < arraySize; i++)
      {
        insert(elements[i]);
      }
    }
  }

private:
  TreeNode* root;
  int size;
};

#endif
