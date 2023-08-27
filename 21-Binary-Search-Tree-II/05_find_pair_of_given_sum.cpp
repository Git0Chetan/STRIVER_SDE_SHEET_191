//Pair in BST havin SUM k
// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

// leetcode: 653   link:https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

#include<iostream>
#include<stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};


// space_O(n) & time O(n)
class Solution {
public:
    void find(TreeNode* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        find(root->left,v);
        v.push_back(root->val);
        find(root->right,v);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        find(root,v);
        int l=0;
        int r=v.size()-1;
        while(l<r){
            if(v[l]+v[r]==k){
                return true;
            }
            if(v[l]+v[r]<k){
                l++;
            }
            else{
                r--;
            }
        }
        return false;
    }
};

//time-O(n). space-O(logn);
// class Solution {
// public:
//     bool findTarget(TreeNode* root, int target) {
    
//    if(!root) return false;

//     stack<TreeNode*> s1, s2;
//     TreeNode* temp1 = root;
//     TreeNode* temp2 = root;


//     while(1)
//     {
//         while(temp1)
//         {
//             s1.push(temp1);
//             temp1 = temp1->left;
//         }

//         while(temp2)
//         {
//             s2.push(temp2);
//             temp2 = temp2->right;
//         }

//         if(s1.empty() || s2.empty()) break;

//         temp1 = s1.top();
//         temp2 = s2.top();

//         if((temp1->val + temp2->val) == target)
//         {
//             if(temp1 == temp2) return false;

//             return true;
//         }

//         else if((temp1->val + temp2->val) < target)
//         {
//             s1.pop();
//             temp1 = temp1->right;
//             temp2 = NULL;
//         }
//         else
//         {
//             s2.pop();
//             temp2 = temp2->left;
//             temp1 = NULL;
//         }
//     }

//     return false;
// }
// };



