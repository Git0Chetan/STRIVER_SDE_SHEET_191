//Binary Tree to DLL
//Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. 
//The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. 
//The order of nodes in DLL must be same as Inorder of the given Binary Tree. 
//The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.
//Note: H is the height of the tree and this space is used implicitly for the recursion stack.

//GFG: link:https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab


#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    public: 
    
    void bd(Node* root,Node* &prev){
        if(root==NULL){
            return;
        }

        bd(root->right,prev);
        root->right=prev;
        if(prev!=NULL)
        prev->left=root;
        prev=root;
        bd(root->left,prev);
    }
    
    Node * bToDLL(Node *root)
    {
        Node* prev = NULL;
        bd(root,prev);
        return prev;
    }
};

