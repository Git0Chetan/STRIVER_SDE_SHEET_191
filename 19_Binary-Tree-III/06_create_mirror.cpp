// Given a Binary Tree, convert it into its mirror.
//gfg:https://practice.geeksforgeeks.org/problems/mirror-tree/1



#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    void mirror(Node* node) {
        if(node==NULL)return;
        
        Node* temp=node->left;
        node->left=node->right;
        node->right=temp;
        mirror(node->left);
        mirror(node->right);
    }
};