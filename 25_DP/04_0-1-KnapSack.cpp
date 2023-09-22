
// A thief wants to rob a store. 
//He is carrying a bag of capacity W. 
//The store has ‘n’ items. 
//Its weight is given by the ‘wt’ array and its value by the ‘val’ array. 
//He can either include an item in its knapsack or exclude it but can’t partially have it as a fraction. 
//We need to find the maximum value of items that the thief can steal.

//leetcode: no
//gfg: https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab


#include<iostream>
using namespace std;

class solution{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
     
     
    // DP memoization
    
    int knap(int wt[],int val[],int n,int w,vector<vector<int>>&dp){
        if(n==0){
            if(wt[0]<=w){
                return val[0];
            }
             return 0;
        }
        
        if(dp[n][w]!=-1)return dp[n][w];
        
        int no = 0 + knap(wt,val,n-1,w,dp);
        int yes = INT_MIN;
        if(wt[n] <= w)yes= val[n] + knap(wt,val,n-1,w-wt[n],dp);
        
        return dp[n][w] = max(no,yes);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return knap(wt, val, n-1, W, dp);
    }
    
    
    
//Tabulation (space optimised)
//  int knapsack(vector<int>& wt, vector<int>& val, int n, int W){
//       vector<vector<int>> dp(n,vector<int>(W+1,0));
//       for(int i=wt[0]; i<=W; i++){
//           dp[0][i] = val[0];
//       }
         
//       for(int ind =1; ind<n; ind++){
//           for(int cap=0; cap<=W; cap++){
//               int notTaken = 0 + dp[ind-1][cap];
//               int taken = INT_MIN;
//               if(wt[ind] <= cap)
//                   taken = val[ind] + dp[ind-1][cap - wt[ind]];
//               dp[ind][cap] = max(notTaken, taken);
//           }
//       }
//       return dp[n-1][W];
     // }

    
    // using Recursion TLE   
    // void knap(int s,int tv,int tw,int w,int wt[],int val[],int n,int &maxi){
    //     if(s==n || tw>w){
    //         if(tw<=w){
    //             maxi=max(maxi,tv);
    //         }
    //         return;
    //     }
        
    //     maxi=max(tv,maxi);
        
    //     tv+=val[s];
    //     tw+=wt[s];
    //     knap(s+1,tv,tw,w,wt,val,n,maxi);
    //     tv-=val[s];
    //     tw-=wt[s];
    //     knap(s+1,tv,tw,w,wt,val,n,maxi);
    // }
    
    // int knapSack(int W, int wt[], int val[], int n) 
    // { 
    //     int maxi=0;
    //     knap(0,0,0,W,wt,val,n,maxi);
    //     return maxi;
    // }
};