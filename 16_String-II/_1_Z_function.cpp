// Given two strings needle and haystack, 
//return the index of the first occurrence of needle in haystack, or -1 
//if needle is not part of haystack.


//Leetcode:28   link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/


#include<iostream>
using namespace std;

//Brute force
// class Solution {
// public:
//     int strStr(string hay, string need) {
//         int pos=-1;
//         for(int i=0;i<hay.length();i++){
//             pos=i;
//             int j=0;
//             int k=i;
//             while(hay[k]==need[j]){
//                 k++;
//                 j++;
//                 if(j==need.length()){
//                     return pos;
//                 }
//             }

//             pos=-1;
//         }
//         return pos;
//     }
// };


//Optimised
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int start_idx = -1;
//         int str_len = haystack.length();
        
//         for(int i = 0; i < haystack.length(); i++){
//             if((haystack[i] == needle[0]) && (str_len - i + 1 >= needle.length())){
//                 if(haystack.substr(i, needle.length()) == needle){
//                     start_idx = i;
//                     break;
//                 }
//             }
//         }
        
//         return start_idx;
//     }
// };


//Using Z_function:
class solution{
    public:
    vector <int> search(string pat, string txt)
        {
            
            int m=txt.length();
            int n=pat.length();
            
            string ns=pat+"#"+txt;
            vector<int>z;
            for(int i=0;i<ns.length();i++){
                if(i<=n){
                    z.push_back(0);
                }
                else{
                    int left=0;
                    int right=i;
                    while(right<ns.length() && ns[left]==ns[right]){
                        left++;
                        right++;
                    }
                    z.push_back(left);
                }
            }
            
            vector<int>result;
            for(int i=0;i<ns.length();i++){
                if(z[i]==n){
                    result.push_back(i-n);
                }
            }
            
            return result;
        }
};