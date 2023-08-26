// Problem statement: Given a binary search tree find the kth largest and smallest element in Binary Search Tree.
// Given a Binary Search Tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

//Leetcode: no
//gfg: https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class Solution
{
    public:
    
    void in(Node* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        in(root->left,v);
        v.push_back(root->data);
        in(root->right,v);
    }

    int kthLargest(Node *root, int K)
    {
        vector<int>v;
        in(root,v);
        return v[v.size()-K];
    }
};