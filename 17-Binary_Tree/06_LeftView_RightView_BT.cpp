// Right/Left view of binary tree
// Problem Statement: Given a Binary Tree, find the Right/Left view of it. 
//The right view of a Binary Tree is a set of nodes visible when the tree is viewed from the right side. 
//The left view of a Binary Tree is a set of nodes visible when the tree is viewed from the left side.

//Leetcode: 199  link:https://leetcode.com/problems/binary-tree-right-side-view/description/

#include<iostream>
#include<queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// Using Queue
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        if(root==NULL)return v;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* f=q.front();
                q.pop();
                if(f->left)q.push(f->left);
                if(f->right)q.push(f->right);
                if(i==n-1)v.push_back(f->val);
            }
        }
        return v;
    }
};


//RECURSIVE APPROACH
// class Solution {
// public:
//     void recursion(TreeNode *root, int level, vector<int> &res)
//     {
//         if(root==NULL) return ;
//         if(res.size()==level) res.push_back(root->val);
//         recursion(root->right, level+1, res);
//         recursion(root->left, level+1, res);
//     }
    
//     vector<int> rightSideView(TreeNode *root) {
//         vector<int> res;
//         recursion(root, 0, res);
//         return res;
//     }
// };

