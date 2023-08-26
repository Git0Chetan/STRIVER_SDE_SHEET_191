//LOWEST COMMON ANSCESTOR OF BST
// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

//Leetcode:235  link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



// optimised solution --recursion
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root==NULL || root==p || root==q){
//             return root;
//         }

//         int r=root->val;
//         int pp=p->val;
//         int qq=q->val;

//         if(r<pp && r<qq){
//             return lowestCommonAncestor(root->right,p,q);
//         }
//         else if(r>pp && r>qq){
//             return lowestCommonAncestor(root->left,p,q);
//         }

//         return root;
//     }
// };

// optimised solution --using while loop

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
        while (true) {
            if (p->val < node->val && q->val < node->val)
                node = node->left;
            else if (p->val > node->val && q->val > node->val)
                node = node->right;
            else
                break;    
        }
        return node;
    }
};





//Brute force approach
// class Solution {
// public:

//     void find(TreeNode* root, TreeNode* p, queue<TreeNode*>&pp){
//         if(root==p){
//             pp.push(root);
//             return;
//         }

//         if(root->val > p->val){
//             pp.push(root);
//             find(root->left,p,pp);
//         }
//         else{
//             pp.push(root);
//             find(root->right,p,pp);
//         }
//     }

//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         queue<TreeNode*>pp;
//         find(root,p,pp);
//         queue<TreeNode*>qq;
//         find(root,q,qq);

//         TreeNode* temp;
//         while(pp.front()==qq.front()){
//             temp=pp.front();
//             pp.pop();
//             qq.pop();
//         }
//         return temp;
//     }
// };