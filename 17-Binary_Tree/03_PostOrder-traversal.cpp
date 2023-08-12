// Given the root of a binary tree, return the postorder traversal of its nodes' values.
//LEFT -- RIGHT -- NODE

//Leetcode:145  link: https://leetcode.com/problems/binary-tree-postorder-traversal/description/


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


//Recursive
class Solution {
public:
    vector<int>answer;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL){return answer;}
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        answer.push_back(root->val);
        return answer;
    }
};

