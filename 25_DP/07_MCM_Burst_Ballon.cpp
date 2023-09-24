// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

// Return the maximum coins you can collect by bursting the balloons wisely.


// Leetcode:312  link :: https://leetcode.com/problems/burst-balloons/description/


#include<iostream>
using namespace std;


// Using Memoization
class Solution {
public:

    int coins(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j)return 0;

        if(dp[i][j]!=-1){return dp[i][j];}

        int coin=INT_MIN;
        for(int k=i;k<=j;k++){
            int cost= nums[i-1]*nums[k]*nums[j+1] + coins(i,k-1,nums,dp) +coins(k+1,j,nums,dp);
            coin=max(coin,cost);
        }

        return dp[i][j]=coin;
    }


    int maxCoins(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return coins(1,n,nums,dp);
    }
};




//Recursion
// class Solution {
// public:

//     int coins(int i,int j,vector<int>&nums){
//         if(i>j)return 0;

//         int coin=INT_MIN;
//         for(int k=i;k<=j;k++){
//             int cost= nums[i-1]*nums[k]*nums[j+1] + coins(i,k-1,nums) +coins(k+1,j,nums);
//             coin=max(coin,cost);
//         }

//         return coin;
//     }


//     int maxCoins(vector<int>& nums) {
//         int n=nums.size();
//         nums.push_back(1);
//         nums.insert(nums.begin(),1);
//         return coins(1,n,nums);
//     }
// };

