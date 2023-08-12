// Given the root of a binary tree, return the preorder traversal of its nodes' values.
// Root - Left - Right

//leetcode:144 link:https://leetcode.com/problems/binary-tree-preorder-traversal/description/

#include<iostream>
#include<stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



// //Recursive
// class Solution {
// public:

//     vector<int> pre(vector<int>&v,TreeNode* root){
//         if(root==NULL){
//             return v;
//         }
//         v.push_back(root->val);
//         pre(v,root->left);
//         pre(v,root->right);

//         return v;
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int>v;
//         return pre(v,root);
//     }
// };


//iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>pre;
        stack<TreeNode*>s;

        while(true){
            if(root!=NULL){
                pre.push_back(root->val);
            }
            

            if(root!=NULL && root->left!=NULL){
                s.push(root->right);
                root=root->left;   
            }
            else if(root!=NULL && root->right!=NULL){
                root=root->right;
            }
            else{
                if(s.empty()){
                    break;
                }
                root=s.top();
                s.pop();
            }
        }
        return pre;
    }
};

//Another iterative
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector < int > preOrder;
//         if (root == NULL)
//             return preOrder;

//         stack < TreeNode * > s;
//         s.push(root);

//         while (!s.empty()) {
//             TreeNode * top = s.top();
//             preOrder.push_back(top -> val);
//             s.pop();
//             if (top-> right != NULL)
//                 s.push(top -> right);
//             if (top -> left != NULL)
//                 s.push(top -> left);
//         }
//         return preOrder;
//     }
// };