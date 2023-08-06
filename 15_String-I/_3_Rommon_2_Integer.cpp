// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.


//Leetcode: 13  link: https://leetcode.com/problems/roman-to-integer/description/




#include<iostream>
#include<unordered_map>
using namespace std;


//Optimised using map
class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        unordered_map <char,int> mp{
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

    for(int i=0;i<s.size();i++){
        if(mp[s[i]]<mp[s[i+1]]){
            //for cases such as IV,CM, XL, etc...
            ans=ans-mp[s[i]];
        }
        else{
            ans=ans+mp[s[i]];
        }
    }
        return ans;
    }
};


//using switch statement
// class Solution {
// public:
//     int romanToInt(string s) {
//         int n=s.length();
//         int i=0;
//         long sum=0;
//         while(i<n){
//             switch(s[i]){
//                 case 'I':
//                 if(s[i+1]=='V'){
//                     sum+=4;
//                     i++;
//                 }
//                 else if(s[i+1]=='X'){
//                     sum+=9;
//                     i++;
//                 }
//                 else{
//                     sum+=1;
//                     i++;
//                 }
//                 break;

//                 case 'V':
//                 sum+=5;
//                 break;

//                 case 'X':
//                 if(s[i+1]=='L'){
//                     sum+=40;
//                     i++;
//                 }
//                 else if(s[i+1]=='C'){
//                     sum+=90;
//                     i++;
//                 }
//                 else{
//                     sum+=10;
//                     i++;
//                 }
//                 break;

//                 case 'L':
//                 sum+=50;
//                 break;

//                 case 'C':
//                 if(s[i+1]=='D'){
//                     sum+=400;
//                     i++;
//                 }
//                 else if(s[i+1]=='M'){
//                     sum+=900;
//                     i++;
//                 }
//                 else{
//                     sum+=10;
//                     i++;
//                 }
//                 break;

//                 case 'D':
//                 sum+=500;
//                 break;

//                 case 'M':
//                 sum+=1000;
//                 break;
//             }
//         }
//         return sum;
//     }
// };
