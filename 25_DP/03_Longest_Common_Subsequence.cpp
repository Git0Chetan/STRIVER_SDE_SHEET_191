// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.

//Leetcode:1143  link: https://leetcode.com/problems/longest-common-subsequence/description/


#include<iostream>
using namespace std;

class Solution {
public:

    //Memoization
    int longi(int t1,int t2,string &s1,string &s2 ,vector<vector<int>>&dp){
        if(t1<0 || t2<0){
            return 0;
        }
        if(dp[t1][t2]!=-1){
            return dp[t1][t2];
        }

        if(s1[t1]==s2[t2]){
            return dp[t1][t2]=1+longi(t1-1,t2-1,s1,s2,dp);
        }
        return dp[t1][t2]=max(longi(t1,t2-1,s1,s2,dp),longi(t1-1,t2,s1,s2,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int t1=text1.size();
        int t2=text2.size();
        vector<vector<int>>dp(t1,vector<int>(t2,-1));
        return longi(t1-1,t2-1,text1,text2,dp);

    }
};

//Tabulation
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int m=text1.size(),n=text2.size();
//         int a[m+1][n+1];
//         for(int i=0;i<=m;i++){
//             for(int j=0;j<=n;j++){
//                 if(i==0||j==0){
//                     a[i][j]=0;
//                 }
//             }
//         }
//         for(int i=1;i<=m;i++){
//             for(int j=1;j<=n;j++){
//                 if(text1[i-1]==text2[j-1]){
//                     a[i][j]=1+a[i-1][j-1];
//                 }
//                 else{
//                     a[i][j]=max(a[i][j-1],a[i-1][j]);
//                 }
//             }
//         }
//         return a[m][n];
//     }
// };


//Error
// class Solution {
// public:

//     void sub(int st,int n,string text,string s,unordered_map<string,int>&mp1){
//         if(st==n){
//             if(s.length()==0)return;
//             mp1[s]=s.length();
//         }

//         sub(st+1,n,text,s,mp1);
//         s+=text[st];
//         sub(st+1,n,text,s,mp1);
//         // s.erase(s.begin()+s.length()-1);
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         string s;
//         unordered_map<string,int>mp1;
//         unordered_map<string,int>mp2;
//         sub(0,text1.length(),text1,s,mp1);
//         sub(0,text1.length(),text2,s,mp2);

//         // sort(mp1.begin(),mp1.end());
//         int res=-1;
//         for(auto a:mp2){
//             if(mp1.find(a.first)!=mp1.end()){
//                 res=a.second;
//             }
//         }

//         return res;

//     }
// };