// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.

//Leetcode:543  link: https://leetcode.com/problems/diameter-of-binary-tree/description/

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



//optimised solution
class Solution {
public:
    int dep(TreeNode* root,int &dia){
        if(root==NULL)return 0;
        int l=dep(root->left,dia);
        int r=dep(root->right,dia);

        dia=max(dia,l+r);
        return 1+max(l,r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int dia=0;
        dep(root,dia);
        return dia;
    }
};


//time complexity is more
// class Solution {
// public:
//     int dep(TreeNode* root){
//         if(root==NULL)return 0;
//         return 1+max(dep(root->left),dep(root->right));
//     }

//     int diameterOfBinaryTree(TreeNode* root) {
//         if(root==NULL)return 0;
//         int l= dep(root->left)+dep(root->right);
//         return max(l,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
//     }
// };

