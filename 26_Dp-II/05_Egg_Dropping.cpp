// You are given N identical eggs and you have access to a K-floored building from 1 to K.

// There exists a floor f where 0 <= f <= K such that any egg dropped from a floor higher than f will break, and any egg dropped from or below floor f will not break. 
// There are few rules given below. 

// An egg that survives a fall can be used again.
// A broken egg must be discarded.
// The effect of a fall is the same for all eggs.
// If the egg doesn't break at a certain floor, it will not break at any floor below.
// If the eggs breaks at a certain floor, it will break at any floor above.
// Return the minimum number of moves that you need to determine with certainty what the value of f is.


//GFG link:  https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

#include<iostream>
using namespace std;

class solution{
    public:
    
    int egg(int k,int n,vector<vector<int>>&dp){
        if(n<=1){
            return n;
        }
        if(k==1){
            return n;
        }

        if(dp[k][n]!=-1)return dp[k][n];

        int mini=INT_MAX;

        for(int i=1;i<=n;i++){
            int res=1+max(egg(k-1,i-1,dp),egg(k,n-i,dp));
            mini=min(mini,res);
        }

        return dp[k][n]=mini;
    }
    int eggDrop(int k, int n) {
        if(k==1)return n;
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return egg(k,n,dp);
    }
};