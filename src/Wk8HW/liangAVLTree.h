#ifndef AVLTREE_H
#define AVLTREE_H

#include <vector>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

class AVLTreeNode
{
public:
  int element;        // Element contained in the node
  int height;         // height of the node
  AVLTreeNode *left;  // Pointer to the left child
  AVLTreeNode *right; // Pointer to the right child

  AVLTreeNode(int element)
  {
    this->element = element;
    height = 0;
    left = nullptr;
    right = nullptr;
  }
};

class AVLTree
{
public:
  AVLTree()
  {
    root = nullptr;
    size = 0;
    height = 0;
    toggleAVLtree = true;
  }

  AVLTree(int elements[], int arraySize)
  {
    root = nullptr;
    size = 0;
    toggleAVLtree = true;

    for (int i = 0; i < arraySize; i++)
    {
      insert(elements[i]);
    }
  }

  void setToggleAVLtree(bool temp){
    toggleAVLtree = temp;
  }

  /* Inorder traversal */
  void inorder() const
  {
    inorder(root);
  }

  /* Inorder traversal from a subtree */
  void inorder(const AVLTreeNode *root) const
  {
    if (root == nullptr)
      return;
    inorder(root->left);
    cout << root->element << " ";
    inorder(root->right);
  }

///////EXERCISE////////
  // return a queue of nodes in level order
  queue<AVLTreeNode *> LevelOrderNodes(AVLTreeNode *someNode)
  {
      queue<AVLTreeNode *> q, temp;
      if(someNode){
        temp.push(someNode);
        while(!temp.empty()){
          AVLTreeNode * tempNode = temp.front();
          temp.pop();
          q.push(tempNode);
          if(tempNode -> left)
            temp.push(tempNode -> left);
          if(tempNode -> right)
            temp.push(tempNode -> right);
        }
      }
      
    return q;
  }

///////EXERCISE////////
  // display tree with level indices
  void DisplayTreeWithLevelIndices(queue<AVLTreeNode *> q)
  {
    int i = 0, power = 0;
    while(!q.empty()){
      if(i + 1 == ((int)pow(2, power))){
        cout << "\nlevel " << power << ":";
        power++;
      }
      cout << q.front() -> element << " ";
      q.pop();
      i++;
    }
    cout << endl;
  }

  // level order display
  void LevelOrderDisplay()
  {
    if (root == nullptr)
    {
      cout << "Tree is empty." << endl;
    }
    else
    {
      queue<AVLTreeNode *> q = LevelOrderNodes(root);
      DisplayTreeWithLevelIndices(q);
    }

    /** SAMPLE OUTPUT
After inserting 25, 20, 5:
level 0: 20
level 1: 5 25

After inserting 34, 50:
level 0: 20
level 1: 5 34
level 2: 25 50

After inserting 30
level 0: 25
level 1: 20 34
level 2: 5 30 50

After inserting 10
level 0: 25
level 1: 10 34
level 2: 5 20 30 50

After removing 34, 30, 50:
level 0: 10
level 1: 5 25
level 2: 20

After removing 5:
level 0: 20
level 1: 10 25
     */
  }

  // display tree like a tree, horizontally
  void DisplayTreeHorizontally()
  {
    cout << "==========tree/horizontal view==========\n";
    DisplayTreeHorizontally(root, 0);
  }

  // display the tree rooted at someNode like a tree, horizontally
  void DisplayTreeHorizontally(AVLTreeNode *someNode, int space)
  {
    if (someNode == nullptr)
    {
      return;
    }
    else
    {
      space += 10;

      DisplayTreeHorizontally(someNode->right, space);

      cout << endl;
      for (int i = 10; i < space; i++)
      {
        cout << " ";
      }
      cout << someNode->element << endl;

      DisplayTreeHorizontally(someNode->left, space);
    }
  }

  /* Get the number of nodes in the tree */
  int getSize() const
  {
    return size;
  }

  // Insert element e into the binary tree
  // Return true if the element is inserted successfully
  // Return false if the element is already in the list
  bool binaryTreeInsert(const int &e)
  {
    if (root == nullptr)
      root = createNewNode(e); // Create a new root
    else
    {
      // Locate the parent node
      AVLTreeNode *parent = nullptr;
      AVLTreeNode *current = root;
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

  // Return a path from the root leading to the specified element
  vector<AVLTreeNode *> *path(const int &e) const
  {
    vector<AVLTreeNode *> *v = new vector<AVLTreeNode *>();
    AVLTreeNode *current = root;
    while (current != nullptr)
    {
      v->push_back(current);
      if (e < current->element)
        current = current->left;
      else if (e > current->element)
        current = current->right;
      else
        break;
    }

    return v;
  }

  // insert element into AVLTree
  bool insert(int element)
  {
    bool successful = binaryTreeInsert(element);
    if (!successful)
      return false; // element is already in the tree
    else
      // Balance from element to the root if necessary
      balancePath(element);

    return true; // element is inserted
  }

  // remove element from AVLTree
  bool remove(int element)
  {
    if (root == nullptr)
      return false; // Element is not in the tree

    // Locate the node to be deleted and also locate its parent node
    AVLTreeNode *parent = nullptr;
    AVLTreeNode *current = root;
    while (current != nullptr)
    {
      if (element < current->element)
      {
        parent = current;
        current = current->left;
      }
      else if (element > current->element)
      {
        parent = current;
        current = current->right;
      }
      else
        break; // Element is in the tree pointed by current
    }

    if (current == nullptr)
      return false; // Element is not in the tree

    // Case 0: current is a leaf
    if(current->left == nullptr && current->right == nullptr){
      if (parent == nullptr)
      {
        root = nullptr;
      }
      else
      {
        if (element < parent->element)
          parent->left = nullptr;
        else
          parent->right = nullptr;
      }
      // added because it occurs in a bug without this.
      balancePath(parent->element);
      delete current; // Delete current
    }
    // Case 1: current has no left children
    else if (current->left == nullptr)
    {
      // Connect the parent with the right child of the current node
      if (parent == nullptr)
        root = current->right;
      else
      {
        if (element < parent->element)
          parent->left = current->right;
        else
          parent->right = current->right;

        // Balance the tree if necessary
        balancePath(parent->element);
      }

      delete current; // Delete current
    }
    else
    {
      // Case 2: The current node has a left child
      // Locate the rightmost node in the left subtree of
      // the current node and also its parent
      AVLTreeNode *parentOfRightMost = current;
      AVLTreeNode *rightMost = current->left;

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
        // Special case: parentOfRightMost is current
        parentOfRightMost->left = rightMost->left;

      // Balance the tree if necessary
      balancePath(parentOfRightMost->element);

      delete rightMost; // Delete rightMost
    }

    size--;
    return true; // Element inserted
  }

///////EXERCISE////////
  /* Return the address of the node if the element is in the tree; returns nullptr otherwise */
  AVLTreeNode *search(const int &e) const
  {
    AVLTreeNode* current = root;
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

  // create a new AVLTreeNode
  AVLTreeNode *createNewNode(int element)
  {
    return new AVLTreeNode(element);
  }

///////EXERCISE////////
  /** Balance the nodes in the path from the specified node to the root if necessary */
  void balancePath(int element)
  {
    vector<AVLTreeNode *> *p = path(element);
    for (int i = p->size() - 1; i >= 0; i--)
    {
      AVLTreeNode *A = (*p)[i];
      AVLTreeNode *parentOfA = (A == root) ? nullptr : (*p)[i - 1];

      updateHeight(A); // ensure that height is updated first

      // WRITE CODE HERE
      // hint: we need to check if the tree is balanced at A i.e. use balanceFactors of A and A's children to determine if rotations are needed (if needed then perform rotations by calling the appropriate balance methods [SEE BELOW])
      // int bfOfParentOfA = balanceFactor(parentOfA);
      int bfOfA = balanceFactor(A);
      int bfOfALeft = balanceFactor(A -> left);
      int bfOfARight = balanceFactor(A -> right);
      // cout << "A: " << A ->element << " height: "<< A->height << " bfs: " << bfOfA << ", " << bfOfALeft << ", " << bfOfARight << ", " << endl;
      // RR rotation
      if(bfOfA == 2 && (bfOfARight == 1 || bfOfARight == 0))
        balanceRR(A, parentOfA);
      // LL rotation
      if(bfOfA == -2 && (bfOfALeft == -1 || bfOfALeft == 0))
        balanceLL(A, parentOfA);
      // RL rotation
      if(bfOfA == 2 && (bfOfARight == -1))
        balanceRL(A, parentOfA);
      // LR rotation
      if(bfOfA == -2 && (bfOfALeft == 1))
        balanceLR(A, parentOfA);

    }
  }

  /** Update the height of a specified node */
  // IMPORTANT: I modifed leaf node's height to be 1, not 0.
  void updateHeight(AVLTreeNode *node)
  {
    if(!node)
      return;
    if (node->left == nullptr && node->right == nullptr) // node is a leaf
      node->height = 1;
    else if (node->left == nullptr) // node has no left subtree
      node->height = 1 + (*(node->right)).height;
    else if (node->right == nullptr) // node has no right subtree
      node->height = 1 + (*(node->left)).height;
    else
      node->height = 1 + max((*(node->right)).height, (*(node->left)).height);
  }

///////EXERCISE////////
  /** Return the balance factor of the node */
  int balanceFactor(AVLTreeNode *node)
  {
    if(!node)
      return 0;
      // return INT_MIN;
    // assuming all nodes' heights are properly updated
    // use right subtree height - left subtree height
    return  ((node -> right) ? node -> right -> height : 0) - ((node -> left) ? node -> left -> height : 0);
  }

  /** Balance LL */
  void balanceLL(AVLTreeNode *A, AVLTreeNode *parentOfA)
  {
    AVLTreeNode *B = A->left; // A is left-heavy and B is left-heavy

    if (A == root)
      root = B;
    else if (parentOfA->left == A)
      parentOfA->left = B;
    else
      parentOfA->right = B;

    A->left = B->right; // Make T2 the left subtree of A
    B->right = A;       // Make A the left child of B
    updateHeight(A);
    updateHeight(B);
  }

  /** Balance LR */
  void balanceLR(AVLTreeNode *A, AVLTreeNode *parentOfA)
  {
    AVLTreeNode *B = A->left;  // A is left-heavy
    AVLTreeNode *C = B->right; // B is right-heavy

    if (A == root)
      root = C;
    else if (parentOfA->left == A)
      parentOfA->left = C;
    else
      parentOfA->right = C;

    A->left = C->right; // Make T3 the left subtree of A
    B->right = C->left; // Make T2 the right subtree of B
    C->left = B;
    C->right = A;

    // Adjust heights
    updateHeight(A);
    updateHeight(B);
    updateHeight(C);
  }

///////EXERCISE////////
  /** Balance RR */
  void balanceRR(AVLTreeNode *A, AVLTreeNode *parentOfA)
  {
    AVLTreeNode *B = A->right; // A is left-heavy and B is left-heavy

    if (A == root)
      root = B;
    else if (parentOfA->right == A)
      parentOfA->right = B;
    else
      parentOfA->left = B;

    A->right = B->left; // Make T2 the left subtree of A
    B->left = A;       // Make A the left child of B
    updateHeight(A);
    updateHeight(B);
  }

///////EXERCISE////////
  /** Balance RL */
  void balanceRL(AVLTreeNode *A, AVLTreeNode *parentOfA)
  {

    AVLTreeNode *B = A->right;  // A is left-heavy
    AVLTreeNode *C = B->left; // B is right-heavy

    if (A == root)
      root = C;
    else if (parentOfA->right == A)
      parentOfA->right = C;
    else
      parentOfA->left = C;

    A->right = C->left; // Make T3 the left subtree of A
    B->left = C->right; // Make T2 the right subtree of B
    C->right = B;
    C->left = A;

    // Adjust heights
    updateHeight(A);
    updateHeight(B);
    updateHeight(C);
  }

  // returns the number of nodes at level level in the tree
  int CountNodesAtLevel(int level)
  {
    int count = 0;
    // assuming level of root is 1,
    CountNodesAtLevel(root, level, count);
    return count;
  }

///////EXERCISE////////
  // helper function for CountNodesAtLevel
  void CountNodesAtLevel(AVLTreeNode *someNode, int level, int &count)
  {
    int i = 1;
    queue<AVLTreeNode*> queueForEachLvl;
    queueForEachLvl.push(someNode);
    while(!queueForEachLvl.empty()){
      if(i == level){
        count = queueForEachLvl.size();
        return;
      }
      int numOfPrevLvlNodes = queueForEachLvl.size();
      for(int j = 0; j < numOfPrevLvlNodes; j++){
        AVLTreeNode* temp = queueForEachLvl.front();
        queueForEachLvl.pop();
        if(temp -> left)
          queueForEachLvl.push(temp -> left);
        if(temp -> right)
          queueForEachLvl.push(temp -> right);
      }
      i++;
    }
    cout << "nodes doesn't exist at given level." << endl;
  }

  // returns the number of nodes in the tree that are between min and max (inclusive)
  int Count(int min, int max)
  {
    int count = 0;
    Count(root, min, max, count);
    return count;
  }

///////EXERCISE////////
  // helper function for Count
  void Count(AVLTreeNode *someNode, int min, int max, int &count)
  {
    // the efficient way is to find only essential nodes in preoreer traversal
    // find subtree root node to start preorder traversal.
    // recursively counts nodes in preorder; if element is out of bound, omit the "the outer side"
    if(!someNode)
      return;
    if(someNode -> element >= min && someNode -> element <= max){
      count++;
      Count(someNode -> left, min, max, count);
      Count(someNode -> right, min, max, count);
    }else if(someNode -> element < min)
      Count(someNode -> right, min, max, count);
    else
      Count(someNode-> left, min, max, count);
  }

///////EXERCISE////////
  // right rotates the tree at node someNode if possible (if someNode is nullptr or someNode->left is nullptr, no rotation is performed)
  void RotateRight(AVLTreeNode *someNode)
  {
    if(!someNode || !someNode -> left)
      return;
    AVLTreeNode* prev = findPrev(root);
    // RR rotation
    balanceLL(someNode, prev);
  }


///////EXERCISE////////
  // left rotates the tree at node someNode if possible (if someNode is nullptr or someNode->right is nullptr, no rotation is performed)
  void RotateLeft(AVLTreeNode *someNode)
  {
    if(!someNode || !someNode -> right)
      return;
    AVLTreeNode* prev = findPrev(root);
    // LL rotation
    balanceRR(someNode, prev);
  }
   AVLTreeNode* findPrev(AVLTreeNode *someNode){
    AVLTreeNode* prev;
    if(someNode){
      int e = someNode -> element;
      AVLTreeNode* current = root;
      while(current){
        prev = current;
        if(current -> element == e)
          break;
        else if(current -> element < e)
          current = current -> right;
        else
          current = current -> left;
      }
    }
    return prev;
  }
  void updateHeightForAllNodes(AVLTreeNode *someNode){
    if(!someNode)
      return;
    updateHeightForAllNodes(someNode -> left);
    updateHeightForAllNodes(someNode -> right);
    updateHeight(someNode);
  }

  // returns the diameter of the tree
  // diameter is the number of nodes along the longest path between any two leaves in the tree
  // see https://leetcode.com/problems/diameter-of-binary-tree/
  int Diameter()
  {
    return Diameter(root);
  }

///////EXERCISE////////
  // helper function for Diameter
  int Diameter(AVLTreeNode *someNode)
  {
    if(!someNode)
     return 0;
    // update AVL tree before preceed
    if(toggleAVLtree)
      balancePath(someNode -> element);
    
    // check for bf of root?
    return 1 + (someNode -> left ? someNode -> left -> height : 0) + (someNode -> right ? someNode -> right -> height : 0);
  }
  
private:
  AVLTreeNode *root;
  int size;
  int height;
  vector<AVLTreeNode*> backups;
  // added this member for some testments which would not work with AVL tree.
  // i.e. RotateLeft or RotateRight
  bool toggleAVLtree;
};

#endif
