// Flattening a Linked List
// Problem Statement: Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Each of the sub-linked-list is in sorted order.
// Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
// Note: The flattened list will be printed using the bottom pointer instead of the next pointer.

//Leetcode : no
//gfg: https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include<iostream>
using namespace std;
#include<vector>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};


//Using vector and sort stl algorithm
// Node *flatten(Node *root)
// {
//   vector<int>v;
//   Node* temp1=root;
//   while(temp1){
//         v.push_back(temp1->data);
//         Node* temp=temp1->bottom;
//         while(temp){
//           v.push_back(temp->data);
//           temp=temp->bottom;
//       }
//       temp1=temp1->next;
//   }
   
//       sort(v.begin(),v.end());
//       Node* ans=new Node(-1);
//       Node* res=ans;
//       for(auto n:v){
//           Node* temp=new Node(n);
//           ans->bottom=temp;
//           ans=ans->bottom;
//       }
//   return res->bottom;
// }



//Using merge
Node* mergeTwoLists(Node* a, Node* b) {
    Node *temp = new Node(0);
    Node *res = temp; 
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a; 
            temp = temp->bottom; 
            a = a->bottom; 
        }
        else {
            temp->bottom = b;
            temp = temp->bottom; 
            b = b->bottom; 
        }
    }
    if(a) temp->bottom = a; 
    else temp->bottom = b; 
    return res -> bottom; 
}
Node *flatten(Node *root){
        if (root == NULL || root->next == NULL) 
            return root; 
        root->next = flatten(root->next); 
        root = mergeTwoLists(root, root->next); 
        return root; 
}