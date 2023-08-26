// Ceil in BST
// Given a BST and a number X, find Ceil of X.
// Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.
// If Ceil could not be found, return -1.

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

int findCeil(Node* root, int x) {
    int a=-1;
    while(root){
        if(root->data==x){
            return root->data;
        }
        if(root->data>x){
            a=root->data;
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return a;
}
