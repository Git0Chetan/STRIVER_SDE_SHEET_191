// Given the roots of two binary trees p and q, write a function to check if they are the same or not.

// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

//Leetcode:100  link : https://leetcode.com/problems/same-tree/description/



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


//Optimised
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(p==NULL || q==NULL){
//             return p==q;
//         }

//         if(p->val != q->val)return false;

//         return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        
//     }
// };



//best
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL){
            return p==q;
        }

        return p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        
    }
};



// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) {
//         if(q==NULL && p==NULL)return true;
//         if(q==NULL || p==NULL)return false;
//         queue<TreeNode*>q1;
//         queue<TreeNode*>q2;
//         q1.push(p);
//         q2.push(q);

//         while(!q1.empty() || !q2.empty()){
//             TreeNode* a=q1.front();
//             TreeNode* b=q2.front();
//             q1.pop();
//             q2.pop();
//             if(a==NULL && b==NULL){continue;}
//             if(a==NULL || b==NULL){return false;}
            
//             if(a->val!=b->val){return false;}

//             if(a->left!=NULL){q1.push(a->left);}
//             else{q1.push(NULL);}
//             if(a->right!=NULL){q1.push(a->right);}
//             else{q1.push(NULL);}
//             if(b->left!=NULL){q2.push(b->left);}
//             else{q2.push(NULL);}
//             if(b->right!=NULL){q2.push(b->right);}
//             else{q2.push(NULL);}
//         }
//         if(q1.size()!=q2.size()){return false;}
//         return true;
        
//     }
// };

