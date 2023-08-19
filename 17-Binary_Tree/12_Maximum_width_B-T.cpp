// Given the root of a binary tree, return the maximum width of the given tree.

// The maximum width of a tree is the maximum width among all levels.

// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

// It is guaranteed that the answer will in the range of a 32-bit signed integer.

//Leetcode:662  link: https://leetcode.com/problems/maximum-width-of-binary-tree/



#include<iostream>
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



class Solution {
public:
    int widthOfBinaryTree(TreeNode* a) {
    
        if(!a)
        return 0;
        
        int ans = 1;
        queue<pair<TreeNode*,long long int>>q;
        q.push({a,0});

        while(!q.empty())
        {
            int sz = q.size();
            int a1 = 0, b1 = 0;
            int l = 0;
            int mn = q.front().second;
            for(int i = 0; i < sz; i++)
            {
                auto p = q.front();
                TreeNode* b = p.first;
                long long int k = p.second-mn;
                q.pop();

                if(i == 0)
                a1 = k;

                if(i == sz-1)
                b1 = k;

                if(b->left)
                q.push({b->left,2*k+1});
                
                if(b->right)
                q.push({b->right,2*k+2});
            }

            ans = max(ans,b1-a1+1);
        }

        return ans;
        
    }
};