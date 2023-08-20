// Problem Statement: Check whether the given Binary Tree is a Balanced Binary Tree or not.
// A binary tree is balanced if, for all nodes in the tree, 
//the difference between left and right subtree height is not more than 1.

//leetcode:110  link: https://leetcode.com/problems/balanced-binary-tree/description/

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
    int dep(TreeNode* root, bool &is){
        if(root==NULL)return 0;
        int l=dep(root->left,is);
        int r=dep(root->right,is);
        if(abs(l-r)>1)is=false;
        return 1+ max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        bool is=true;
        dep(root,is);
        return is;
    }
};

//optimised
// class Solution {
// public:
//     bool isBalanced(TreeNode* root) 
//     {
//         return dfsheight(root)!=-1;
//     }
//     int dfsheight(TreeNode *root)
//     {
//         if(!root) return 0;
//         int lh=dfsheight(root->left);
//         int rh=dfsheight(root->right);
//         if(lh==-1) return -1;
//         if(rh==-1) return -1;
//         if(abs(lh-rh)>1) return -1;
//         return 1+max(lh,rh);
//     }
// };