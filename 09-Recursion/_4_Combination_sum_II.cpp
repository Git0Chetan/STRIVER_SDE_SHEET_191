// Combination Sum II – Find all unique combinations
// In this article we will solve the most asked interview question “Combination Sum II – Find all unique combinations”.
// Problem Statement: Given a collection of candidate numbers (candidates) and a target number (target), 
//find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination.

//leetcode:40  link: https://leetcode.com/problems/combination-sum-ii/description/



#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void combination(vector<int>nums,int index,vector<int>output,int target,vector<vector<int>>&answer){
        if(target==0){
            answer.push_back(output);
            return ;
        }

        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){continue;}
            if (nums[i] > target) break;
            output.push_back(nums[i]);
            combination(nums,i+1,output,target-nums[i],answer);
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>answer;
        vector<int>output;
        int index=0;
        sort(candidates.begin(),candidates.end());
        combination(candidates,index,output,target,answer);
        return answer;
    }
};