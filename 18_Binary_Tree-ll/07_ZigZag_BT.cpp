// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
//(i.e., from left to right, then right to left for the next level and alternate between)

//Leetcode:103  link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

#include<iostream>
#include<queue>
#include<stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


//best solution
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         queue<TreeNode* >q;
  vector<vector<int>>ans;
  bool flag=true;
        q.push(root);
        if(!root)
        return ans;

        while(!q.empty())
        {
            int n=q.size();
            vector<int>v;
            
            while(n--)
            {
                TreeNode* p=q.front();
                v.push_back(p->val);
                q.pop();

                if(p->left)
                {
                    q.push(p->left);
                }
                 if(p->right)
                {
                    q.push(p->right);
                }

            }
           if(!flag)
           {
               reverse(v.begin(),v.end());
           }
            ans.push_back(v);
             flag=!flag;
        }
        return ans;
    }
};


// using single queue
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector < vector < int >> result;
//         if (root == NULL) {
//             return result;
//         }

//         queue < TreeNode * > nod;
//         nod.push(root);
//         bool lTR = true;

//         while (!nod.empty()) {
//             int size = nod.size();
//             vector < int > row(size);
//             for (int i = 0; i < size; i++) {
//                 TreeNode * node = nod.front();
//                 nod.pop();

//                 int index = (lTR) ? i : (size - 1 - i);

//                 row[index] = node -> val;
//                 if (node -> left) {
//                 nod.push(node -> left);
//                 }
//                 if (node -> right) {
//                 nod.push(node -> right);
//                 }
//             }

//             lTR = !lTR;
//             result.push_back(row);
//         }
//         return result;
//     }
// };

//Using two stack
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         stack< TreeNode* >s1;
//         stack< TreeNode* >s2;

//         vector<vector<int> >v;
//         vector<int>temp;

//         if(root==NULL){
//             return v;
//         }
//         s1.push(root);

//     while(!s1.empty() || !s2.empty()){
    
//         while(!s1.empty()){
//             TreeNode* t=s1.top();
//             s1.pop(); 
//             temp.push_back(t->val);
//             if(t->left!=NULL){
//                 s2.push(t->left);
//             }
//             if(t->right!=NULL){
//                 s2.push(t->right);
//             }
//         }
//         v.push_back(temp);
//         temp.clear();
//         while(!s2.empty()){
//             TreeNode* t=s2.top();
//             s2.pop(); 
//             temp.push_back(t->val);
//             if(t->right!=NULL){
//                 s1.push(t->right);
//             }
//             if(t->left!=NULL){
//                 s1.push(t->left);
//             } 
//         }
//         if(!temp.empty()){
//             v.push_back(temp);
//             temp.clear();
//         }
        
//     }
//     return v;
//     }
// };




//using 1 stack and 1 queue
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>>ans;

//         if(root==NULL)return ans;

//         queue<TreeNode*>q;
//         stack<int>s;
        
//         q.push(root);
//         bool is=true;

//         while(!q.empty()){
//             vector<int>v;
//             int n=q.size();

//             while(n--){
//                 TreeNode* temp=q.front();
//                 q.pop();
//                 if(is){
//                     v.push_back(temp->val);
//                 }
//                 else{
//                     s.push(temp->val);
//                 }

//                 if(temp->left){
//                     q.push(temp->left);
//                 }
//                 if(temp->right){
//                     q.push(temp->right);
//                 }
//             }
//             while(!s.empty()){
//                 v.push_back(s.top());
//                 s.pop();
//             }
//             ans.push_back(v);
//             is= !is;
//         }
//         return ans;
//     }
// };