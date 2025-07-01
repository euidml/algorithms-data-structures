#include <iostream>
#include <random>
#include "liangBST.h"

using namespace std;

int main() {
    BST bst; // Create an empty BST

    // Insert some elements
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    
    //testing save tree and creating tree using saved file.
    bst.saveTree();
    BST reloadedTree("tree.txt");
    cout << "Inorder traversal of 'bst': ";
    bst.inorder();
    cout << endl;
    cout << "Inorder traversal of 'reloadedTree': ";
    reloadedTree.inorder();
    cout << endl;
    

    // Inorder traversal
    cout << "Inorder traversal: ";
    bst.inorder();
    cout << endl;

    // Preorder traversal
    cout << "Preorder traversal: ";
    bst.preorder();
    cout << endl;

    // Postorder traversal
    cout << "Postorder traversal: ";
    bst.postorder();
    cout << endl;

    cout << "Showing nodes in level order" << endl;
    bst.LevelOrderDisplay();

    // Get the size of the tree and height
    cout << "Size of the tree: " << bst.getSize() << endl;
    cout << "Height of the tree: " << bst.GetHeight() << endl;

    // Search for an element & path
    TreeNode* foundNode = bst.search(30);
    if (foundNode) {
        cout << "Found element 30: " << foundNode->element << endl;
    } else {
        cout << "Element 30 not found." << endl;
    }
    vector<TreeNode*>* pathOf20 = bst.path(20);
    vector<TreeNode*>* pathOf35 = bst.path(35);
    cout << "Showing path of searching 20: ";
    for(int i = 0; i < pathOf20 -> size(); i++){
        if(pathOf20 -> at(i))
            cout << pathOf20 -> at(i) -> element << " ";
        else
            cout << "nullptr"; 
    }
    cout << endl;
    cout << "Showing path of searching 35: ";
    for(int i = 0; i < pathOf35 -> size(); i++){
        if(pathOf35 -> at(i))
            cout << pathOf35 -> at(i) -> element << " ";
        else
            cout << "nullptr"; 
    }
    cout << endl;


    // Copy constructor
    BST copiedBST(bst);
    cout << "\nCopied BST (Inorder traversal): ";
    copiedBST.inorder();
    cout << endl;

    // Remove an element
    bst.remove(30);
    cout << "Inorder traversal after removing 30: ";
    bst.inorder();
    cout << endl;

    // Clear the tree
    bst.clear();
    cout << "Inorder traversal after clearing the tree: ";
    bst.inorder();
    cout << endl;

    // Create a balanced BST from an array
    int elements[] = {50, 30, 70, 20, 40, 60, 80};
    BST balancedBST(elements, 7, true);
    cout << "\nBalanced BST (Inorder traversal): ";
    balancedBST.inorder();
    cout << endl;
    

    // testing = operator and == operator
    bst.clear();
    cout << "Inorder traversal after cleaning 'bst' to show whether it is empty: ";
    bst.inorder();
    cout << endl;
    bst = &copiedBST;
    cout << "Inorder traversal of 'bst' after assignment from 'copiedBST': ";
    bst.inorder();
    cout << endl;
    cout << "Inorder traversal of 'copiedBST': ";
    copiedBST.inorder();
    cout << endl;
    // testing LevelOrderDisplay();
    cout << "\nShowing each nodes in level order" << endl;
    cout << "bst" << endl;
    bst.LevelOrderDisplay();
    cout << "copiedBST" << endl;
    copiedBST.LevelOrderDisplay();
    cout << "Are 'bst' and 'copiedBST' same?(using == operator): " << boolalpha << (bst == &copiedBST)<< endl;

    // testing InorderIncrementByOne() by IncrementByOne()
    cout << "Inorder traversal before IncrementByOne(): ";
    bst.inorder();
    cout << endl;
    bst.IncrementByOne();
    cout << "Inorder traversal after IncrementByOne(): ";
    bst.inorder();
    cout << endl;

    // testing NodeCount and NodesWithOddValues
    cout << "Inorder traveral of 'bst' which consists of odd values only: ";
    bst.inorder();
    cout << endl;
    cout << "Inorder traveral of 'copiedBST' which consists of even values only: ";
    copiedBST.inorder();
    cout << endl;
    cout << "# of nodes in 'bst': " << bst.NodeCount() << endl;
    cout << "# of nodes with odd number in 'bst': " << bst.NodesWithOddValues() << endl;
    cout << "# of nodes in 'copiedBST': " << copiedBST.NodeCount() << endl;
    cout << "# of nodes with odd number in 'copiedBST': " << copiedBST.NodesWithOddValues() << endl;

    // testing kthSmallest 
    cout << "\nTesting finding kth smallest element" << endl;
    cout << "inserting some values more before testing" << endl;
    bst.insert(15);
    bst.insert(25);
    bst.insert(35);
    bst.insert(45);
    bst.insert(55);
    bst.insert(57);
    bst.insert(90);
    cout << "Inorder traveral of 'bst' which consists of odd values only: ";
    bst.inorder();
    cout << endl;
    bst.DisplayTreeHorizontally();
    cout << "The most smallest value: " << bst.kthSmallest(1) -> element << endl;
    cout << "The largest value: " << bst.kthSmallest(bst.getSize()) -> element << endl;
    cout << "The 3rd smallest value: " << bst.kthSmallest(3) -> element << endl;
    cout << "The 10th smallest value: " << bst.kthSmallest(10) -> element << endl;
    
    //testing ClosestCommonAncestor
    cout << "\nShowing nodes in horizontally" << endl;
    bst.DisplayTreeHorizontally();
    cout << "ClosestCommonAncestor of 15 and 35: ";
    TreeNode* a = bst.ClosestCommonAncestor(bst.search(15), bst.search(35));
    cout << (a ? to_string(a -> element) : "doesn't exist") << endl;
    cout << "ClosestCommonAncestor of 31 and 45: ";
    a = bst.ClosestCommonAncestor(bst.search(31), bst.search(45));
    cout << (a ? to_string(a -> element) : "doesn't exist") << endl;
    cout << "ClosestCommonAncestor of 21 and 57: ";
    a = bst.ClosestCommonAncestor(bst.search(21), bst.search(57));
    cout << (a ? to_string(a -> element) : "doesn't exist") << endl;
    cout << "ClosestCommonAncestor of 21 and 85(which doesn't exist): ";
    a = bst.ClosestCommonAncestor(bst.search(21), bst.search(85));
    cout << (a ? to_string(a -> element) : "doesn't exist") << endl;

    return 0;
}
