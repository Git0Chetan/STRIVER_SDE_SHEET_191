
// Morris Preorder Traversal of a Binary Tree
// Problem Statement: Morris Preorder Traversal of a Binary tree. 
// Given a Binary Tree, find the Morris preorder traversal of Binary Tree.


//Coding ninja link : https://www.codingninjas.com/studio/problems/preorder-traversal_3838888?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1


#include<iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int>v;

    TreeNode* curr=root;

    while(curr!=NULL){
        if(curr->left==NULL){
            v.push_back(curr->data);
            curr=curr->right;
        }
        else{
            TreeNode* prev=curr->left;

            while(prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }

            if(prev->right==NULL){
                prev->right=curr;
                v.push_back(curr->data);
                curr=curr->left;
            }
            else{
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
    return v;
}