// Grid Unique Paths | Count paths from left-top to the right bottom of a matrix
// Problem Statement: Given a matrix m X n, count paths from left-top to the right bottom of a matrix with the constraints that from each cell you can either only move to the rightward direction or the downward direction.

//leetcode:62   link: https://leetcode.com/problems/unique-paths/description/





class Solution {
public:
    //Brute force solution using recursion which take excess amount of time
    // int county(int m,int n,int rm,int rn){
    //     if(m>rm || n>rn){
    //         return 0;
    //     }

    //     if(m==rm && n==rn){
    //         return 1;
    //     }

    //     return (county(m+1,n,rm,rn) + county(m,n+1,rm,rn) );
    // }

    // int uniquePaths(int m, int n) {
    //     return county(0,0,m-1,n-1);
    // }


    //better approach using dynamic programming
    // int county(int m,int n,int rm,int rn,vector<vector<int>>&dp){
    //     if(m>rm || n>rn){
    //         return 0;
    //     }

    //     if(m==rm && n==rn){
    //         return 1;
    //     }
    //     if(dp[m][n]!=-1){return dp[m][n];}
    //     dp[m][n]=(county(m+1,n,rm,rn,dp) + county(m,n+1,rm,rn,dp) );
    //     return dp[m][n];
    // }

    // int uniquePaths(int m, int n) {
    //     vector<vector<int>>dp(m,vector<int>(n,-1));
    //     return county(0,0,m-1,n-1,dp);
    // }


    //using Combination formula
    int uniquePaths(int m, int n) {
            int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    }
};