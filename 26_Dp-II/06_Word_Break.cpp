// Given a string s and a dictionary of strings wordDict, 
//return true if s can be segmented into a space-separated sequence of one or more dictionary words.
// Note that the same word in the dictionary may be reused multiple times in the segmentation.

//Leetcode:139   link:https://leetcode.com/problems/word-break/

#include<iostream>
#include<set>
using namespace std;


class Solution {
public:

    bool wb(string s,set<string>ss,int st,int en,vector<int>&dp){
        if(st>=en)return true;
        if(dp[st]!=-1)return dp[st];

        bool res=false;
        for(int i=1;st+i<=en;i++){
            if(ss.find(s.substr(st,i))!=ss.end() && wb(s,ss,i+st,en,dp)){
                res=true;
                break;
            }
        }
        return dp[st]=res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>ss;
        for(auto a:wordDict){
            ss.insert(a);
        }
        int n=s.length();
        vector<int>dp(n,-1);

        return wb(s,ss,0,n,dp);
    }
};



//Time Limit Exceed
// class Solution {
// public:
//     bool word(string s,vector<string>& D,string c){
//         if(c.size()>s.size())return false;

//         for(int i=0;i<c.size();i++){
//             if(c[i]!=s[i])return false;
//         }

//         s.erase(s.begin(),s.begin()+c.size());

//         if(s=="")return true;

//         for(int i=0;i<D.size();i++){
//             if(word(s,D,D[i]))return true;
//         }
//         return false;

//     }
//     bool wordBreak(string s, vector<string>& Dict) {
//         for(int i=0;i<Dict.size();i++){
//             if(word(s,Dict,Dict[i]))return true;
//         }
//         return false;
//     }
// };


//Memory Exceed
// class Solution {
// public:

//     bool word(int ind,int n,string c,string s,vector<string>& Dict){
//         if(ind==n)return false;
//         if(c==s)return true;

//         return word(ind+1,n,c+Dict[ind],s,Dict) || word(ind-1,n,c,s,Dict);
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         return word(0,wordDict.size()," ",s,wordDict);
//     }
// };