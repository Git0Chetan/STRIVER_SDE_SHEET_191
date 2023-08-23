//Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree 
//and inorder is the inorder traversal of the same tree, construct and return the binary tree.

//Leetcode:105  link:https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

#include<iostream>
#include<vector>
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

    TreeNode* build(vector<int>& pre , vector<int>& in,int s,int e, int &index){
        if(s>e){
            return NULL;
        }

        TreeNode* root=new TreeNode(pre[index++]);

        int ind;
        for(int i=s;i<=e;i++){
            if(in[i]==root->val){
                ind=i;
                break;
            }
        }

        root->left=build(pre,in,s,ind-1,index);
        root->right=build(pre,in,ind+1,e,index);

        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int index=0;
        return build(pre,in,0,pre.size()-1,index);
    }
};