// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree 
//and postorder is the postorder traversal of the same tree, construct and return the binary tree.

//Leetcode: 106  link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/


#include<iostream>
#include<vector>
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

    TreeNode* build(vector<int>in,vector<int>post,int s,int e,int &index){
        if(s>e){
            return NULL;
        }

        TreeNode* root=new TreeNode(post[index--]);
        int ind;
        for(int i=s;i<=e;i++){
            if(in[i]==root->val){
                ind=i;
                break;
            }
        }

        root->right=build(in,post,ind+1,e,index);
        root->left=build(in,post,s,ind-1,index);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int index=in.size()-1;
        return build(in,post,0,in.size()-1,index);
    }
};


//class Solution {
// public:

// TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
//     return create(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
// }

// TreeNode* create(vector<int> &inorder, vector<int> &postorder, int is, int ie, int ps, int pe){
//     if(ps > pe){
//         return nullptr;
//     }
//     TreeNode* node = new TreeNode(postorder[pe]);
//     int pos;
//     for(int i = is; i <= ie; i++){
//         if(inorder[i] == node->val){
//             pos = i;
//             break;
//         }
//     }
//     node->left = create(inorder, postorder, is, pos - 1, ps, ps + pos - is - 1);
//     node->right = create(inorder, postorder, pos + 1, ie, pe - ie + pos, pe - 1);
//     return node;
// }
// };