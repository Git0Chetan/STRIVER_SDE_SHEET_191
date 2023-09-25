// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.

// The answer is guaranteed to fit into a signed 32-bit integer.


//leetcode: 518  link:https://leetcode.com/problems/coin-change-ii/

#include<iostream>
using namespace std;

class Solution {
public:
    int change(int T, vector<int>& coins) {
        vector<long> prev(T+1,0);
        for(int i=0;i<=T;i++){
           prev[i]=(i%coins[0]==0);
        }
    
    for(int ind=1; ind<coins.size();ind++){
        vector<long> cur(T+1,0);
        for(int target=0;target<=T;target++){
            long notTaken = prev[target];
            
            long taken = 0;
            if(coins[ind]<=target)
                taken = cur[target-coins[ind]];
                
            cur[target] = notTaken + taken;
        }
        prev = cur;
    }
    
    return prev[T];
    }
};

 

    
//Memoization
// class Solution {
// public:


//     int coin(int ind,int amount,vector<int>coins,vector<vector<int>>&dp){
//         if(ind==0){
//             return (amount%coins[0]==0);
//         }
//         if(dp[ind][amount]!=-1)return dp[ind][amount];

//         int notake=coin(ind-1,amount,coins,dp);
//         int take=0;
//         if(amount>=coins[ind]){
//             take=coin(ind,amount-coins[ind],coins,dp);
//         }

//         return dp[ind][amount]=take+notake ;
//     }

//     int change(int amount, vector<int>& coins) {
//         vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
//         return coin(coins.size()-1,amount,coins,dp);
//     }
// };