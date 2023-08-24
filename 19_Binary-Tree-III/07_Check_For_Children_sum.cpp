// Problem Statement: Children Sum Property in a Binary Tree. Write a program that converts any binary tree to one that follows the children sum property.
// The children sum property is defined as, For every node of the tree, the value of a node is equal to the sum of values of its children(left child and right child).
// Note: 
// The node values can be increased by 1 any number of times but decrement of any node value is not allowed.
// A value for a NULL node can be assumed as 0.
// You are not allowed to change the structure of the given binary tree.

//leetcode: not available
//coding ninja

#include<iostream>
using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

void reorder(node * root) {
  if (root == NULL) return;
  int child = 0;
  if (root -> left) {
    child += root -> left -> data;
  }
  if (root -> right) {
    child += root -> right -> data;
  }

  if (child < root -> data) {
    if (root -> left) root -> left -> data = root -> data;
    else if (root -> right) root -> right -> data = root -> data;
  }

  reorder(root -> left);
  reorder(root -> right);

  int tot = 0;
  if (root -> left) tot += root -> left -> data;
  if (root -> right) tot += root -> right -> data;
  if (root -> left || root -> right) root -> data = tot;
}
void changeTree(node * root) {
  reorder(root);
}