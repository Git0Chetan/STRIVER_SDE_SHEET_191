// Given string str of length N. The task is to find the minimum characters to be added at the front to make string palindrome.
// Note: A palindrome is a word which reads the same backward as forward. Example: "madam".

//GFG: https://practice.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

#include<iostream>
using namespace std;


class solution{
public:
    //TLE-BRUTE_FORCE
    // bool check(string str){
    //     int l=0;
    //     int r=str.length()-1;
        
    //     while(l<r){
    //         if(str[l]!=str[r]){
    //             return false;
    //         }
            
    //         l++;
    //         r--;
    //     }
    //     return true;
    // }
    
    // int minChar(string str){
    //     int count=0;
        
    //     for(int i=str.length();i>0;i--){
    //         if(check(str.substr(0,i))){
    //             return count;
    //         }
    //         count++;
    //     }
        
    //     return count;
    // }
    
    
    //USing Z_index
vector<int> ComputeZArray(string str){

    vector<int> Z(str.size(), 0);
     
    int l = 0, r = 0;
     
    for(int i = 1; i < str.size(); i++){
         
        if(i <= r){
            Z[i] = min(Z[i - l], r - i + 1);
        }
         
        while(str[0 + Z[i]] == str[i + Z[i]]){
            Z[i]++;
        }
         
        if(i + Z[i] - 1 > r){
            l = i;
            r = i + Z[i] - 1;
        }
         
    }
     
    return Z;
}
 
int minChar(string str) {
    int n= str.size();
    string rev = str;
    reverse(rev.begin(),rev.end());
     
    string ns = str + "$" + rev;
     
    int charactersToRemove = INT_MIN;
     
    vector<int> Z = ComputeZArray(ns);
     
    for(int i = 0; i < Z.size(); i++){
        if(Z[i] == ns.size() - i) charactersToRemove = max(charactersToRemove, Z[i]);
    }
 
    return n - charactersToRemove;
}
};