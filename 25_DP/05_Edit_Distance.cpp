// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

//Leetcode:72  link: https://leetcode.com/problems/edit-distance/description/

#include<iostream>
using namespace std;

//Memoization
// class Solution {
// public:

//     int mini(int n,int m, string w1,string w2,vector<vector<int>>&dp){
//         if(n<0)return m+1;
//         if(m<0)return n+1;
//         if(dp[n][m]!=-1)return dp[n][m];

//         if(w1[n]==w2[m])return dp[n][m]=mini(n-1,m-1,w1,w2,dp);
//         return dp[n][m]=1+min(mini(n-1,m-1,w1,w2,dp),min(mini(n-1,m,w1,w2,dp),mini(n,m-1,w1,w2,dp)));
//     }
//     int minDistance(string word1, string word2) {
//         int m=word1.length();
//         int n=word2.length();
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         return mini(m-1,n-1,word1,word2,dp);
//     }
// };


//tabulation
class Solution{
    public:
    int minDistance(string& S1, string& S2){
    
    int n = S1.size();
    int m = S2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = j;
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(S1[i-1]==S2[j-1])
                dp[i][j] = 0+dp[i-1][j-1];
            
            else dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        }
    }
    
    return dp[n][m];
    
}
};


