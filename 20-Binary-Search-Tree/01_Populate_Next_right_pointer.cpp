//Populate next right pointer

// You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.


//Leetcode:116 link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/ 


#include<iostream>
using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    // recursive approach
    Node* connect(Node* root) {
        if(root==NULL || root->left==NULL)return root;

        root->left->next=root->right;
        root->right->next=(root->next==NULL)?NULL:root->next->left;
        connect(root->left);
        connect(root->right);
        return root;
    }
};


//iterative solution
// class Solution {
// public:
// Node* connect(Node *root) {
//     if (root == NULL) return;
//     TreeLinkNode *pre = root;
//     TreeLinkNode *cur = NULL;
//     while(pre->left) {
//         cur = pre;
//         while(cur) {
//             cur->left->next = cur->right;
//             if(cur->next) cur->right->next = cur->next->left;
//             cur = cur->next;
//         }
//         pre = pre->left;
//     }
//     return root;
// }
// };