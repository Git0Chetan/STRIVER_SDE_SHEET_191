// Floor IN BST
// You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
// Note: when x is smaller than the smallest node of BST then returns -1.

//Leetcode: no
//GFG :https://practice.geeksforgeeks.org/problems/floor-in-bst/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab


#include<iostream>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
};

int floor(Node* root, int x) {
    int a=-1;
    while(root){
        if(root->data <= x){
            if(root->data > a){
                a=root->data;
            }
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return a;
}