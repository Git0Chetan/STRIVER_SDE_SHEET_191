// Palindrome Partitioning
// Problem Statement: You are given a string s, partition it in such a way that every substring is a palindrome. 
//Return all such palindromic partitions of s.
// Note: A palindrome string is a string that reads the same backward as forward.

//leetcode: 131   link:https://leetcode.com/problems/palindrome-partitioning/description/



#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:

    //sp=start point ep=end point
    bool palindrome(string s,int sp,int ep){
        while (sp <= ep) {
            if (s[sp++] != s[ep--])
            return false;
        }
        return true;
    }

    void part(int index,string s,vector<string>output,vector<vector<string>>&answer){
        if(index==s.size()){
            answer.push_back(output);
            return;
        }

        for(int i=index;i<s.size();++i){
            if(palindrome(s,index,i)){
                output.push_back(s.substr(index,i-index+1));
                part(i+1,s,output,answer);
                output.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>>answer;
        vector<string>output;
        int index=0;
        part(index,s,output,answer);
        return answer;
    }
};