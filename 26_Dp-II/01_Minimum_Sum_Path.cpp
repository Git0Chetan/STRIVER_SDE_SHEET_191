// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.


//Leetcode:64  link: https://leetcode.com/problems/minimum-path-sum/description/

#include<iostream>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)dp[i][j]= grid[0][0];
                else{
                    int up=grid[i][j];
                    if(i>0)up+=dp[i-1][j];
                    else up+=1e9;

                    int left=grid[i][j];
                    if(j>0)left+=dp[i][j-1];
                    else left+=1e9;


                    dp[i][j]=min(left,up);
                }
            }
        }
        return dp[n-1][m-1];
    }
};






//Memoization approach DP
// class Solution {
// public:

//     int path(int i,int j ,vector<vector<int>>& grid,vector<vector<int>>&dp){
//         if(i==0 && j==0){
//             return grid[0][0];
//         }
//         if(i<0 || j<0 ){
//             return INT_MAX;
//         }
//         if(dp[i][j]!=-1)return dp[i][j];

//         return dp[i][j]=grid[i][j]+ min(path(i-1,j,grid,dp),path(i,j-1,grid,dp));
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return path(n-1,m-1,grid,dp);
//     }
// };



//Recursive Approach
// class Solution {
// public:
//     int path(int i,int j ,vector<vector<int>>& grid,int n,int m){
//         if(i==n-1 && j==m-1){
//             return grid[i][j];
//         }
//         if(i>=n || j>=m ){
//             return INT_MAX;
//         }
//         return grid[i][j]+ min(path(i+1,j,grid,n,m),path(i,j+1,grid,n,m));
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         return path(0,0,grid,n,m);
//     }
// };