// Given a binary tree, print the bottom view from left to right.
// A node is included in bottom view if it can be seen when we look at the tree from bottom.

//                       20
//                     /    \
//                   8       22
//                 /   \        \
//               5      3       25
//                     /   \      
//                   10    14

// For the above tree, the bottom view is 5 10 3 14 25.
// If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.


//gfg link : https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1


#include<iostream>
#include<queue>
#include<map>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root, 0});
        while(!q.empty()){
            Node* node = q.front().first;
            int x = q.front().second;
            q.pop();
            mp[x]=node->data;
            if(node->left) q.push({node->left, x-1});
            if(node->right) q.push({node->right, x+1});
        }
        vector<int> ans;
        for(auto it : mp) ans.push_back(it.second);
        return ans;
    }
};