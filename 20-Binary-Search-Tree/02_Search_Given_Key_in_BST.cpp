//02_Search_Given_Key_in_BST.cpp

// You are given the root of a binary search tree (BST) and an integer val.
// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

//Leetcode:700 link: https://leetcode.com/problems/search-in-a-binary-search-tree/description/


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
    //recursive
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)return NULL;

        int temp=root->val;

        if(temp==val){
            return root;
        }
        else if(temp > val){
            return searchBST(root->left,val);
        }
        return searchBST(root->right,val);
    }


    //iterative
    // TreeNode* searchBST(TreeNode* root, int val) {
    // while (root != nullptr && root->val != val) {
    //   root = (root->val > val) ? root->left : root->right;
    // }
    // return root;
// }
};