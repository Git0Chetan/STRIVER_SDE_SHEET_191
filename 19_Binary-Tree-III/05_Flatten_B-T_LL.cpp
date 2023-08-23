// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.


//Leetcode: 114 link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

#include<iostream>
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


//recursive solution
class Solution {
public:
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        if(root==NULL){
            return;
        }

        flatten(root->right);
        flatten(root->left);

        root->left=NULL;
        root->right=prev;
        prev=root;
    }
};


//First Approach
// class Solution {
// public:
//     void pre(TreeNode* root, vector<int>&v){
//         if(root==NULL)return;
//         v.push_back(root->val);
//         pre(root->left,v);
//         pre(root->right,v);
//     }

//     void flatten(TreeNode* root) {
//         if(root==NULL){return;}
//         vector<int>v;
//         pre(root,v);

//         root->val=v[0];
//         root->left=NULL;
//         root->right=NULL;
//         int n=v.size();
//         for(int i=1;i<n;i++){
//             root->right=new TreeNode(v[i]);
//             root->left=NULL;
//             root=root->right;
//         }
//     }
// };



//Using Stack 
// class Solution {
//   TreeNode * prev = NULL;
//   public:
//    void flatten(TreeNode * root) {
//   if (root == NULL) return;
//   stack < TreeNode * > st;
//   st.push(root);
//   while (!st.empty()) {
//     node * cur = st.top();
//     st.pop();

//     if (cur -> right != NULL) {
//       st.push(cur -> right);
//     }
//     if (cur -> left != NULL) {
//       st.push(cur -> left);
//     }
//     if (!st.empty()) {
//       cur -> right = st.top();
//     }
//     cur -> left = NULL;
//   }
// }



//Morris traversal best approach
// class Solution {
//   TreeNode * prev = NULL;
//   public:
//    void flatten(TreeNode* root) {
//         TreeNode* cur = root;
// 		while (cur)
// 		{
// 			if(cur->left)
// 			{
// 				TreeNode* pre = cur->left;
// 				while(pre->right)
// 				{
// 					pre = pre->right;
// 				}
// 				pre->right = cur->right;
// 				cur->right = cur->left;
// 				cur->left = NULL;
// 			}
// 			cur = cur->right;
// 		}
//     }
// };


