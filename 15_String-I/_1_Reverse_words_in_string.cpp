// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters.
// The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. 
//The returned string should only have a single space separating the words. Do not include any extra spaces.

//Leetcode: 151   link: https://leetcode.com/problems/reverse-words-in-a-string/description/


#include<iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
   int left = 0;
    int right = s.length()-1;
    
    string temp="";
    string ans="";
    
    while (left <= right) {
        char ch= s[left];
        if (ch != ' ') {
            temp += ch;
        } else if (ch == ' ' && left+1<=right && s[left+1]!=' ') {
            if (ans!="") ans = temp + " " + ans;
            else ans = temp;
            temp = "";
        }
        left++;
    }
    
    if (temp!="") {
        if (ans!="") ans = temp + " " + ans;
        else ans = temp;
    }
    
    return ans;
    }
};



//using stringstream function
// class Solution {
// public:
//     string reverseWords(string s) {
//         stringstream ss(s);
//         string ans="";
//         vector<string>a;
//         string word;
//         while(ss>>word){
//             a.push_back(word);
//         }
//         int n=a.size();
//         for(int i=n-1;i>0;i--){
//             ans+=a[i];
//             ans+=" ";
//         }
//         ans+=a[0];
//         return ans;
//     }
// };