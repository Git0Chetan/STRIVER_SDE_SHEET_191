// Serialize And Deserialize a Binary Tree
// Problem Statement: Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
// Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

//leetcode: 297  link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

#include<iostream>
#include<queue>
#include<sstream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)return "";
        
        queue<TreeNode* >q;
        string s="";
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();

            if(temp==NULL){
                s+="#,";
            }
            else{
                s+=to_string(temp->val)+",";
            }

            if(temp!=NULL){
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        stringstream s(data);
        string str="";
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();

            getline(s,str,',');
            if(str=="#"){
                temp->left=NULL;
            }
            else{
                TreeNode* t=new TreeNode(stoi(str));
                q.push(t);
                temp->left=t;
            }

            getline(s,str,',');
            if(str=="#"){
                temp->right=NULL;
            }
            else{
                TreeNode* t=new TreeNode(stoi(str));
                q.push(t);
                temp->right=t;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));