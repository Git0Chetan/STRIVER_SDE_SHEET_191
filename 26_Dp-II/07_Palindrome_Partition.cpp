
// Given a string s, partition s such that every substring of the partition is a palindrome
// Return the minimum cuts needed for a palindrome partitioning of s.

// Leetcode:132 link: https://leetcode.com/problems/palindrome-partitioning-ii/description/

#include<iostream>
using namespace std;

class Solution {
public:
    bool ispalindrome(string &s,int i, int j){  
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    int minCut(string s) {
        int n=s.length();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>-1;i--){
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                if(ispalindrome(s,i,j)){
                    int part=1+dp[j+1];
                    mini=min(mini,part);
                }}
            dp[i]=mini;
        }

        return dp[0]-1;
    }
};

// //best approach for recursion --MLE
// class Solution {
// public:

//     bool check(string s,int st,int en){
//         while(st<en){
//             if(s[st]!=s[en])return false;
//             st++;
//             en--;
//         }
//         return true;
//     }
//     int cut(int i,int n,string s,vector<int>&dp){
//         if(i==n)return 0;

//         if(dp[i]!=-1)return dp[i];
//         int mincost=INT_MAX;

//         for(int j=i;j<n;j++){
//             if(check(s,i,j)){
//                 int cost=1+cut(j+1,n,s,dp);
//                 mincost=min(mincost,cost);
//             }
//         }
//         return dp[i]=mincost;
//     }

//     int minCut(string s) {
//         int n=s.size();
//         vector<int>dp(n,-1);
//         return cut(0,n,s,dp)-1;
//     }
// };



//Memoization - MLE
// class Solution {
// public:

//     bool check(string s,int st,int en){
//         while(st<=en){
//             if(s[st]!=s[en])return false;
//             st++;
//             en--;
//         }
//         return true;
//     }


//     int cut(string s, int ind,int st,int en,vector<vector<int>>&dp){
//         if(ind==st && st!=en)return INT_MAX;
//         if(st==en)return 0;
//         if(dp[st][en]!=-1)return dp[st][en];
//         if(check(s,st,en)){
//             return 0;
//         }
//         int no=cut(s,ind-1,st,en,dp);
//         int take=1+cut(s,ind-1,st,ind-1,dp)+cut(s,en,ind,en,dp);
//         return dp[st][en]=min(no,take);    
//     }

//     int minCut(string s) {
//         int n=s.length();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         return cut(s,n-1,0,n-1,dp);
//     }
// };


// TLE - Recursion
// class Solution {
// public:

//     bool check(string s,int st,int en){
//         while(st<=en){
//             if(s[st]!=s[en])return false;
//             st++;
//             en--;
//         }
//         return true;
//     }


//     int cut(string s, int ind,int st,int en){
//         if(ind==st && st!=en)return INT_MAX;
//         if(st==en)return 0;
//         if(check(s,st,en)){
//             return 0;
//         }
//         int no=cut(s,ind-1,st,en);
//         int take=1+cut(s,ind-1,st,ind-1)+cut(s,en,ind,en);
//         return min(no,take);    
//     }

//     int minCut(string s) {
//         return cut(s,s.length()-1,0,s.length()-1);
//     }
// };

