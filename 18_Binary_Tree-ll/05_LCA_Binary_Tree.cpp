// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between
// two nodes p and q as the lowest node in T that has both p and q as descendants 
//(where we allow a node to be a descendant of itself).”

//Leetcode:236  link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode *right;

};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q){
            return root;
        }

        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(!left){
            return right;
        }
        else if(!right){
            return left;
        }
        return root;
    }
};