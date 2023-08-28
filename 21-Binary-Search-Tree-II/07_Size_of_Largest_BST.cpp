// Largest BST
// Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
// Note: Here Size is equal to the number of nodes in the subtree.

//gfg:https://practice.geeksforgeeks.org/problems/largest-bst/1


#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class NodeVal{
    public:
    int maxSize;
    int maxi;
    int mini;
    
    NodeVal(int maxSize,int mini,int maxi){
        this->maxSize=maxSize;
        this->maxi=maxi;
        this->mini=mini;
    }
};

class Solution{
    public:
    
    NodeVal largest(Node* root){
        if(root==NULL){
            return NodeVal(0,INT_MAX,INT_MIN);
        }
        
        auto left = largest(root->left);
        auto right = largest(root->right);
        
        if(left.maxi < root->data && right.mini > root->data){
            return NodeVal(left.maxSize + right.maxSize +1 , min(root->data,left.mini),max(root->data,right.maxi));
        }
        
        return NodeVal(max(left.maxSize,right.maxSize),INT_MIN,INT_MAX);
    }
    
    int largestBst(Node *root)
    {
    	return largest(root).maxSize;
    }
};