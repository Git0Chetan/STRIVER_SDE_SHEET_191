// Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

//        1
//     /     \
//    2       3
//   /  \    /   \
// 4    5  6   7

// Top view will be: 4 2 1 3 7

// gfg link:https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

#include<iostream>
#include<map>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

vector<int> topView(Node *root)
    {   
        vector<int>ans;
        map<int,int>mp;
        queue<pair<Node*,int>>q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            Node* temp=q.front().first;
            int k=q.front().second;
            q.pop();
            
            if(mp.find(k)==mp.end()){
                mp[k]=temp->data;
            }
            if(temp->left){
                q.push(make_pair(temp->left,k-1));
            }
            if(temp->right){
                q.push(make_pair(temp->right,k+1));
            }
        }
        
        for(auto a:mp){
            ans.push_back(a.second);
        }
        
        return ans;
    }
