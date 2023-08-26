// Predecessor and Successor
// There is BST given with the root node with the key part as an integer only. You need to find the in-order successor and predecessor of a given key. If either predecessor or successor is not found, then set it to NULL.
// Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 

//leetcode:no
//gfg: https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1


#include<iostream>
using namespace std;

struct Node{
  int key;
  Node* left;
  Node* right;  
};

class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        if(root==NULL){
            return;
        }
        findPreSuc(root->left,pre,suc,key);
        if(root->key < key){
            if(pre){
                if(pre->key < root->key){
                    pre=root;
                }
            }
            else{
                pre=root;
            }
        }
        if(root->key > key){
            if(suc){
                if(suc->key > root->key){
                    suc=root;
                }
            }
            else{
                suc=root;
            }
        }
        findPreSuc(root->right,pre,suc,key);
    }
};