



#include<iostream>
#include<stack>
using namespace std;



class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};


//Optimised using number of iteration.
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>>ans;
    vector<int>pre,ini,post;

    stack < pair < TreeNode * , int >> st;
    st.push({root,1});

    if (root == NULL) return ans;

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        if (it.second == 1) {
            pre.push_back(it.first -> data);
            it.second++;
            st.push(it);

            if (it.first -> left != NULL) {
                st.push({it.first -> left,1});
            }
        }
        else if (it.second == 2) {
            ini.push_back(it.first -> data);
            it.second++;
            st.push(it);

            if (it.first -> right != NULL) {
                st.push({it.first -> right,1});
            }
        }
        else {
            post.push_back(it.first->data);
        }
    }
    ans.push_back(ini);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}

// ********

// Using separate function for all traversal
// vector<int>v;
// void inorder(TreeNode* root){
//     if(root==NULL){
//         return ;
//     }
//     if(root->left)inorder(root->left);
//     v.push_back(root->data);
//     if(root->right)inorder(root->right);

// }

// void preorder(TreeNode* root){
//     if(root==NULL){
//         return ;
//     }
//     v.push_back(root->data);
//     if(root->left)preorder(root->left);
//     if(root->right)preorder(root->right);

// }

// void postorder(TreeNode* root){
//     if(root==NULL){
//         return;
//     }
//     if(root->left)postorder(root->left);
//     if(root->right)postorder(root->right);
//     v.push_back(root->data);
    
// }

// vector<vector<int>> getTreeTraversal(TreeNode *root){
//     vector<vector<int>>ans;
//     inorder(root);
//     ans.push_back(v);
//     v.clear();
//     preorder(root);
//     ans.push_back(v);
//     v.clear();
//     postorder(root);
//     ans.push_back(v);
//     return ans;
// }




// ********
// Using a single function for all traversal
// vector<int>io;
// vector<int>po;
// vector<int>op;

// void inorder(TreeNode* root){
//     if(root==NULL){
//         return ;
//     }
//     po.push_back(root->data);
//     if(root->left)inorder(root->left);
//     io.push_back(root->data);
//     if(root->right)inorder(root->right);
//     op.push_back(root->data);
// }

// vector<vector<int>> getTreeTraversal(TreeNode *root){
//     vector<vector<int>>ans;
//     inorder(root);
//     ans.push_back(io);
//     ans.push_back(po);
//     ans.push_back(op);
//     return ans;
// }


