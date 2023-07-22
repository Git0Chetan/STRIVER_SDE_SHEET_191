// Combination Sum – 1
// Problem Statement: 
// Given an array of distinct integers and a target, you have to return the list of all unique combinations where the chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from the given array an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
// It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

//leetcode:39  link: https://leetcode.com/problems/combination-sum/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //optimal solution
    void combination(vector<int>nums,int index,vector<int>output,int target,vector<vector<int>>&answer){
        if(index==nums.size()){
            if(target==0){
                answer.push_back(output);
            }
            return;
        }
            
        if(nums[index]<=target){
            output.push_back(nums[index]);
            combination(nums,index,output,target-nums[index],answer);
            output.pop_back();
        }

        combination(nums,index+1,output,target,answer);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>answer;
        vector<int>output;
        combination(candidates,0,output,target,answer);
        return answer;
    }
};





// class Solution {
// public:
//     void combination(vector<int>nums,int index,vector<int>output,int sum,int target,vector<vector<int>>&answer){
//         if(sum>=target){
//             if(sum==target){
//                 answer.push_back(output);
//             }
//             return;
//         }

//         for(int i=index;i<nums.size();i++){
//             sum+=nums[i];
//             output.push_back(nums[i]);
//             combination(nums,i,output,sum,target,answer);
//             sum-=nums[i];
//             output.pop_back();
//         }
        
//     }


//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>>answer;
//         vector<int>output;
//         combination(candidates,0,output,0,target,answer);
//         return answer;
//     }
// };