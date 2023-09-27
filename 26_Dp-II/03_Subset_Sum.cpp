// Given an integer array nums, return true if you can partition the array into two subsets such that 
//the sum of the elements in both subsets is equal or false otherwise.


//Leetcode: 416  link:https://leetcode.com/problems/partition-equal-subset-sum/


#include<iostream>
using namespace std;


//Memoization
class Solution {
public:

    bool can(int ind,vector<int>&nums,int tar,vector<vector<int>>&dp){
        if(ind<0){
            return false;
        }
        if(tar==0){
            return true;
        }

        if(dp[ind][tar]!= -1)return dp[ind][tar];

        bool notake=can(ind-1,nums,tar,dp);
        bool take=false;

        if((tar-nums[ind])>=0){
            take=can(ind-1,nums,tar-nums[ind],dp);
        }

        return dp[ind][tar]=(notake || take);
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int tar=0;

        for(int i=0;i<n;i++){
            tar+=nums[i];
        }

        if(tar%2 != 0)return false;

        tar/=2;
        vector<vector<int>>dp(n,vector<int>(tar+1,-1));

        return can(n-1,nums,tar,dp);
    }
};




//Recursion
// class Solution {
// public:

//     bool can(int ind,vector<int>&nums,int tar,int sum){
//         if(ind<0){
//             return false;
//         }
//         if(tar==sum){
//             return true;
//         }

//         bool notake=can(ind-1,nums,tar,sum);
//         bool take=can(ind-1,nums,tar-nums[ind],sum+nums[ind]);
//         return (notake || take);
//     }
//     bool canPartition(vector<int>& nums) {
//         int sum=0;
//         for(int i=0;i<nums.size();i++){
//             sum+=nums[i];
//         }

//         return can(nums.size()-1,nums,sum,0);
//     }
// };
