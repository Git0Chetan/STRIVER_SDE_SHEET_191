// Morris Inorder Traversal of a Binary tree
// Problem Statement: Write a program for Morris Inorder Traversal of a Binary Tree.
//This is exactly our threaded binary tree, which we use in the algorithm.

//Leetcode: 


#include<iostream>
using namespace std;

struct node {
  int data;
  struct node * left, * right;
};


vector < int > inorderTraversal(node * root) {
  vector < int > inorder;

  node * cur = root;
  while (cur != NULL) {
    if (cur -> left == NULL) {
      inorder.push_back(cur -> data);
      cur = cur -> right;
    } else {
      node * prev = cur -> left;
      while (prev -> right != NULL && prev -> right != cur) {
        prev = prev -> right;
      }

      if (prev -> right == NULL) {
        prev -> right = cur;
        cur = cur -> left;
      } else {
        prev -> right = NULL;
        inorder.push_back(cur -> data);
        cur = cur -> right;
      }
    }
  }
  return inorder;
}
