// Given a rod of length N inches and an array of prices, price[]. 
//price[i] denotes the value of a piece of length i. 
//Determine the maximum value obtainable by cutting up the rod and selling the pieces.
// Note: Consider 1-based indexing.

//GFG: https://practice.geeksforgeeks.org/problems/rod-cutting0840/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

#include<iostream>
using namespace std;

class Solution{
    public:
  
    int cut(int ind,int n,int price[],vector<vector<int>>&dp){
        if(ind == 0){
            return n*price[0];
        }
        
        if(dp[ind][n]!=-1)return dp[ind][n];
        
        int no = 0 + cut(ind-1,n,price,dp);
    
        int take = INT_MIN;
        int rodL = ind+1;
        if(rodL <= n){
            take = price[ind] + cut(ind,n-rodL,price,dp);
        }
        
        return dp[ind][n]=max(no,take);
    }
    
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return cut(n-1,n,price,dp);
    }
};