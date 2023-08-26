// Problem statement: Given a binary search tree find the kth largest and smallest element in Binary Search Tree.

// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

//Leetcode:203 link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/


#include<iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 
class Solution {
public:
    void in(TreeNode* root,vector<int>&v,int k){
        if(root==NULL || v.size()>k){
            return;
        }
        in(root->left,v,k);
        v.push_back(root->val);
        in(root->right,v,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
        in(root,v,k);
        return v[k-1];
    }
};