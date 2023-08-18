//Vertical order traversal
// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

// Return the vertical order traversal of the binary tree.

//leetcode:987  link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/


#include<iostream>
#include<map>
#include<set>
#include<queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//this approach doesnt work for ascending order for same vertical and horizontal level

// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         vector<vector<int>>ans;
//         map<int,vector<int>>mp;
//         queue<pair<TreeNode*,int>>q;
//         q.push(make_pair(root,0));

//         while(!q.empty()){
//             int n=q.size();
//             for(int i=0;i<n;i++){
//                 TreeNode* temp=q.front().first;
//                 int k=q.front().second;
//                 q.pop();
//                 mp[k].push_back(temp->val);
//                 if(temp->right){
//                     q.push(make_pair(temp->right,k+1));
//                 }
//                 if(temp->left){
//                     q.push(make_pair(temp->left,k-1));
//                 }
//             }        
//         }

//         for(auto a:mp){
//             sort(a.second.begin(),a.second.end());
//             ans.push_back(a.second);
//         }
//         return ans;
//     }
// };


//Optimised solution
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            auto info = q.front();
            q.pop();
            TreeNode* node = info.first;
            int x = info.second.first;
            int y = info.second.second;
            nodes[x][y].insert(node->val);
            
            if(node->left)
                q.push({node->left, {x-1, y+1}});
            if(node->right)
                q.push({node->right, {x+1, y+1}});
        }
        
        for(auto p : nodes){
            vector<int>col;
            for(auto i : p.second)
            {
                col.insert(col.end(), i.second.begin(), i.second.end());
            }
            
            ans.push_back(col);
        }
        return ans;
    }
};

