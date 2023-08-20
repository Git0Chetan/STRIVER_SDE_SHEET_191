// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

//leetcode:104   link: https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;

        int l=1+maxDepth(root->left);
        int r=1+maxDepth(root->right);

        return max(l,r);
    }
};

 
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {

//         if(root==NULL){
//             return 0;
//         }
//         return(1+max(maxDepth(root->left),maxDepth(root->right)));

//     }
// };


//We can use Level order traversal also but the length of code increases and also there will be need of another data structure that is a queue.

