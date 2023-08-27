//BST iterator
//right-node-left

// Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):
// BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
// boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
// int next() Moves the pointer to the right, then returns the number at the pointer.
// Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.
// You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

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


//OPtimised
class BSTIterator {
public:
    stack<TreeNode*>s;

    void pushh(TreeNode* root){
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushh(root);
    }
    
    int next() {
        auto topi =s.top();
        s.pop();
        pushh(topi->right);
        return topi->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

 //SC=O(n)
// class BSTIterator {
// public:
//     stack<TreeNode*>s;
//     void BST(TreeNode* root){
//         if(!root)return;
//         BST(root->right);
//         s.push(root);
//         BST(root->left);
//     }

//     BSTIterator(TreeNode* root) {
//         BST(root);
//     }
    
//     int next() {
//         int nex=s.top()->val;
//         s.pop();
//         return nex;
//     }
    
//     bool hasNext() {
//         return !s.empty();
//     }
// };

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */