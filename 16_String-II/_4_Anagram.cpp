// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
//typically using all the original letters exactly once.

//Leetcode:242  link: https://leetcode.com/problems/valid-anagram/description/

#include<iostream>
using namespace std;


//using sort O(logn)
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         return s == t;
//     }
// };


//using hashmap O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;
        
        for (auto x : s) {
            count[x]++;
        }
        
        for (auto x : t) {
            count[x]--;
        }
        
        for (auto x : count) {
            if (x.second != 0) {
                return false;
            }
        }
        
        return true;
    }
};


// Using Array O(n)
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         int count[26] = {0};
        
//         for (char x : s) {
//             count[x - 'a']++;
//         }
        
//         for (char x : t) {
//             count[x - 'a']--;
//         }
        
//         for (int val : count) {
//             if (val != 0) {
//                 return false;
//             }
//         }
        
//         return true;
//     }
// };