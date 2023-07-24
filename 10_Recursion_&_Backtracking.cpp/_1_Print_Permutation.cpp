//Print All Permutations of a String/Array
// Given an array nums of distinct integers, return all the possible permutations. 
//You can return the answer in any order.

//Leetcode:46   link: https://leetcode.com/problems/permutations/description/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    void permutation(int index,vector<int>nums,vector<vector<int>>&answer){
        if(index==nums.size()){
            answer.push_back(nums);
            return ;
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            permutation(index+1,nums,answer);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>answer;
        permutation(0,nums,answer);
        return answer;
    }
};

