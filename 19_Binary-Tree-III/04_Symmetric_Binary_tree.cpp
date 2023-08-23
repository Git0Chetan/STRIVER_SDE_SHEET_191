// Problem Statement: 
// Check for Symmetrical Binary Trees
// Write a program to check whether a binary tree is symmetrical or not.
// Problem Description: 
// A symmetrical binary tree is a tree that forms a mirror of itself around the center. In other words, every node in the left subtree will have a mirror image in the right subtree.

//Leetcode:101 link: https://leetcode.com/problems/symmetric-tree/description/

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

    bool equal(TreeNode* r1,TreeNode* r2){
        if(r1==NULL || r2==NULL){
            return r1==r2;
        }

        if(r1->val==r2->val){
            return equal(r1->left,r2->right) && equal(r1->right,r2->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return equal(root->left,root->right);
    }
};
