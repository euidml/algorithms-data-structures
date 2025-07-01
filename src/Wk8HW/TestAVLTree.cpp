#include <iostream>
#include "liangAVLTree.h"
using namespace std;

int main()
{
  int numbers[] = {25 , 20, 5, 1};
  AVLTree tree(numbers, 3);

  cout << "After inserting 25, 20, 5:" << endl;
  tree.LevelOrderDisplay();
  tree.DisplayTreeHorizontally();
  cout << "Maximum diameter: " << tree.Diameter() << endl;

  tree.insert(34);
  tree.insert(50);
  cout << "\nAfter inserting 34, 50:" << endl;
  tree.DisplayTreeHorizontally();
  tree.LevelOrderDisplay();
  cout << "Maximum diameter: " << tree.Diameter() << endl;


  tree.insert(30);
  cout << "\nAfter inserting 30" << endl;
  tree.DisplayTreeHorizontally();
  tree.LevelOrderDisplay();
  cout << "Maximum diameter: " << tree.Diameter() << endl;


  tree.insert(10);
  cout << "\nAfter inserting 10" << endl;
  tree.LevelOrderDisplay();
  tree.DisplayTreeHorizontally();
  cout << "Maximum diameter: " << tree.Diameter() << endl;
  cout << "Number of values ≤ 34, ≥ 20: " << tree.Count(20, 34) << endl;

  // it wouldn't be a valid AVL tree when it rotates;
  // set it not to be an VAL tree.
  tree.setToggleAVLtree(false);
  cout << "Rotation to left at root" << endl;
  tree.RotateLeft(tree.search(25));
  // doesn't work because this is not a valid AVL tree.
  // tree.LevelOrderDisplay();
  tree.DisplayTreeHorizontally();
  cout << "Maximum diameter: " << tree.Diameter() << endl;
  cout << "\nRotation to Right at root" << endl;
  tree.RotateRight(tree.search(34));
  tree.LevelOrderDisplay();
  tree.DisplayTreeHorizontally();
  cout << "Maximum diameter: " << tree.Diameter() << endl;
  tree.setToggleAVLtree(true);


  tree.remove(34);
  tree.remove(30);
  tree.remove(50);
  cout << "\nAfter removing 34, 30, 50:" << endl;
  tree.DisplayTreeHorizontally();
  tree.LevelOrderDisplay();
  cout << "Maximum diameter: " << tree.Diameter() << endl;

  tree.remove(5);
  cout << "\nAfter removing 5:" << endl;
  tree.DisplayTreeHorizontally();
  tree.LevelOrderDisplay();
  cout << "Maximum diameter: " << tree.Diameter() << endl;

  return 0;
}
