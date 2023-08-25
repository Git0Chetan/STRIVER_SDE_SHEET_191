// 04_construct_BST_from_Preorder

// Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

// It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

// A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

// A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

//Leetcode: 1008  link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/


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


//  class Solution {
// public:
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         return helper(preorder.begin(), preorder.end());
//     }
    
//     TreeNode * helper(vector<int>::iterator begin, vector<int>::iterator end) {
//         if (begin == end) {
//             return nullptr;
//         }
        
//         auto node = new TreeNode(*begin);
//         auto right = upper_bound(begin + 1, end, *begin);
        
//         node->left = helper(begin + 1, right);
//         node->right = helper(right, end);
//         return node;
//     }
// };

//Recursive
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder, int max_val = INT_MAX) {
        if (i == preorder.size() || preorder[i] > max_val) return NULL;
        
        TreeNode* root = new TreeNode(preorder[i++]);
        
        root->left = bstFromPreorder(preorder, root->val);
        root->right = bstFromPreorder(preorder, max_val);
        
        return root;
    }
    
private:
    int i = 0;
};




//did not work
// class Solution {
// public:
//     TreeNode* bstFromPreorder(vector<int>& pre) {
//         stack<TreeNode*>s;
//         int n=pre.size();
//         TreeNode* temp=new TreeNode();
//         temp->left=new TreeNode(pre[0]);
//         s.push(temp->left);
//         int i=1;
//         while(i<n){
//             TreeNode* root=s.top();
//             if(pre[i] < root->val){
//                 root->left= new TreeNode(pre[i++]);
//                 if(pre[i]<pre[i-1]){
//                     s.push(root->left);
//                 }
//             }
//             else{
//                 root->right = new TreeNode(pre[i++]);
//                 s.pop();
//             }
//         }
//         return temp->left;
//     }
// };