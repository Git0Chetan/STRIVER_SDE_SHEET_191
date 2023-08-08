// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".


//Leetcode: 14  link: https://leetcode.com/problems/longest-common-prefix/description/



#include<iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int a=strs.size();
        string n=strs[0],m=strs[a-1],ans="";
        for(int i=0;i<n.size();i++){
            if(n[i]==m[i]){ans+=n[i];}
            else break;
        }
        return ans;
        
    }
};


//other appproach

// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs)
//     {
//         string ans;
//         for(int i=0;i<strs[0].size();i++)
//         {
//             for(int j=1;j<strs.size();j++)
//             {
//                 if(strs[0][i] != strs[j][i])
//                 {
//                     return ans;
//                 }
//             }
//             ans += strs[0][i];
//         }
//         return ans;
//     }
// };