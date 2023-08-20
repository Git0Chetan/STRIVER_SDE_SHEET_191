// Given the root of a binary tree, return the level order traversal of its nodes' values.
// (i.e., from left to right, level by level).


//Leetcode:102 link:https://leetcode.com/problems/binary-tree-level-order-traversal/


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


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>v;
            int n=q.size();
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};



//Another Approach
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>>v;
//         if(root==NULL){return v;}
//         vector<int>temp;
//         queue<TreeNode*>q;
//         q.push(root);
//         q.push(NULL);
//         while(!q.empty()){
//             TreeNode* f=q.front();
//             q.pop();
//             if(f==NULL){
//                 v.push_back(temp);
//                 temp.clear();
//                 if(q.size()>0){
//                     q.push(NULL);
//                 }
//                 continue;
//             }

//             temp.push_back(f->val);
//             if(f->left!=NULL){
//                 q.push(f->left);
//             }
//             if(f->right!=NULL){
//                 q.push(f->right);
//             }
//         }
//         return v;
//     }
// };


