// 03_Construct_BST_From_Given_Keys.cpp

// Given an integer array nums where the elements are sorted in ascending order, convert it to a 
// height-balanced binary search tree.

//Leetcode:108 link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/


#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include<iostream>
using namespace std;

class Solution {
public:
    TreeNode* create(vector<int>nums,int l,int h){
        if(l>h){
            return NULL;
        }
        int mid=(l+h)/2;
        TreeNode* temp=new TreeNode(nums[mid]);
        temp->left = create(nums,l,mid-1);
        temp->right = create(nums,mid+1,h);
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create(nums,0,nums.size()-1);
    }
};
