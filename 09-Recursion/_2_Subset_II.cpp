// Subset – II | Print all the Unique Subsets
// Problem Statement: Given an array of integers that may contain duplicates the task is to return all possible subsets.
// Return only unique subsets and they can be in any order.

//leetcode:90  link:https://leetcode.com/problems/subsets-ii/description/


#include<iostream>
#include<vector>
#include<set>
using namespace std;


class Solution {
public:
    //Subsets without using set
    void subset(vector<int>nums,int index,vector<int>output,vector<vector<int>>&answer){
        answer.push_back(output);
        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1]){continue;}
            output.push_back(nums[i]);
            subset(nums,i+1,output,answer);
            output.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>answer;
        vector<int>output;
        int index=0;
        sort(nums.begin(),nums.end());
        subset(nums,index,output,answer);
        return answer;
    }






//Using Set for no duplicates
    // void subset(vector<int>nums,int index,vector<int>output,set<vector<int>>&answer){
    //     if(index>=nums.size()){
    //         sort(output.begin(),output.end());
    //         answer.insert(output);
    //         return;
    //     }

    //     subset(nums,index+1,output,answer);
    //     output.push_back(nums[index]);
    //     subset(nums,index+1,output,answer);
    // }



    // vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    //     set<vector<int>>answer;
    //     vector<int>output;
    //     int index=0;
    //     subset(nums,index,output,answer);
    //     vector<vector<int>>ans(answer.begin(),answer.end());
    //     return ans;
    // }
};