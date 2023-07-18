
// Length of Longest Substring without any Repeating Character
// Problem Statement: Given a String, find the length of longest substring without any repeating character.

//Leetcode:3  link:https://leetcode.com/problems/longest-substring-without-repeating-characters/description/


#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

class Solution {
public:
    //optimal solution O(2n)
    int lengthOfLongestSubstring(string str) {
        if(str.size()==0)return 0;
        int maxans = INT_MIN;
        unordered_set < int > set;
        int l = 0;
        for (int r = 0; r < str.length(); r++){
            if (set.find(str[r]) != set.end()){
                while (l < r && set.find(str[r]) != set.end()) {
                    set.erase(str[l]);
                    l++;
                }
            }
            set.insert(str[r]);
        maxans = max(maxans, r - l + 1);
    }
    return maxans;
    }
};


//Brute force O(n^2)
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int count=0;
//         int n=s.length();
//         for(int i=0;i<n;i++){
//             set<char>ss;
//             int county=0;
//             for(int j=i;j<n;j++){
//                 if(ss.find(s[j])!=ss.end()){
//                     break;
//                 }
//                 ss.insert(s[j]);
//                 county++;
//             }
//             count=max(count,county);
//         }
//         return count;
//     }
// };

