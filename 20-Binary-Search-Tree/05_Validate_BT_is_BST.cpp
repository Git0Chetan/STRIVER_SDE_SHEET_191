// VALIDATE BINARY TREE
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left 
// subtree
//  of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.


//Leetcode:98   link: https://leetcode.com/problems/validate-binary-search-tree/description/


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
    bool isValidBS(TreeNode* root,long mini,long maxi){
        if(root==NULL)return true;

        if(root->val>=maxi || root->val<=mini)return false;

        return isValidBS(root->left,mini,root->val) && isValidBS(root->right,root->val,maxi);
    }

    bool isValidBST(TreeNode* root) {
        return isValidBS(root, LONG_MIN, LONG_MAX);
    }

};




//Uisng inorder traversal
// class Solution {
// public:
//     void in(TreeNode* root,vector<int>&v){
//         if(root==NULL)return;
//         in(root->left,v);
//         v.push_back(root->val);
//         in(root->right,v);
//     }

//     bool isValidBST(TreeNode* root) {
//         vector<int>v;
//         in(root,v);
        
//         for(int i=1;i<v.size();i++){
//             if(v[i-1]>=v[i]){
//                 return false;
//             }
//         }
//         return true;
//     }
// };