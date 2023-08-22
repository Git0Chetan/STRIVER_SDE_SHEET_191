// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

// The path sum of a path is the sum of the node's values in the path.

// Given the root of a binary tree, return the maximum path sum of any non-empty path.

//Leetcode:124  link:https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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

    int path(TreeNode* root, int &maxi){
        if(root==NULL){
            return 0;
        }

        int left=max(0,path(root->left,maxi));
        int right=max(0,path(root->right,maxi));

        maxi=max(maxi, left + right + root->val);
        return max(left+root->val ,right+root->val);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        if(root==NULL){
            return maxi;
        }
        path(root,maxi);
        return maxi;
    }
};