//Compare version number

// Given two version numbers, version1 and version2, compare them.

// Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain leading zeros. Every revision contains at least one character. Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.

// To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. If a version number does not specify a revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.

// Return the following:

// If version1 < version2, return -1.
// If version1 > version2, return 1.
// Otherwise, return 0.


//Leetcode:165  link: https://leetcode.com/problems/compare-version-numbers/description/

#include<iostream>
using namespace std;

//Optimised

class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n=v1.length();
        int m=v2.length();

        int i=0;
        int j=0;

        int num1=0;
        int num2=0;

        while(i<n || j<m){

            while(i<n && v1[i]!='.'){
                num1 = num1*10+(v1[i]-'0');
                i++;
            }

            while(j<m && v2[j]!='.'){
                num2 = num2*10+(v2[j]-'0');
                j++;
            }

            if(num1>num2)return 1;
            if(num2>num1)return -1;
            num1=0;
            num2=0;
            i++;
            j++;
        }

        return 0;
    }
};





//brute force first approach
// class Solution {
// public:
//     int compareVersion(string v1, string v2) {
//         int n=v1.length();
//         int m=v2.length();

//         int i=0;
//         int j=0;

//         while(i<n || j<m){
//             int num1=0;
//             int num2=0;
//             bool num=false;

//             while(i<n && v1[i]!='.'){

//                 if(num1==0){
//                     num1+=v1[i]-'0';
//                 }
//                 else{
//                     num=true;
//                 }
                
//                 if(num){
//                     num1*=10;
//                     num1+=v1[i]-'0';
//                 }
//                 i++;
//             }

//             num=false;
//             while(j<m && v2[j]!='.'){

//                 if(num2==0){
//                     num2+=v2[j]-'0';
//                 }
//                 else{
//                     num=true;
//                 }
                
//                 if(num){
//                     num2*=10;
//                     num2+=v2[j]-'0';
//                 }
//                 j++;
//             }

//             if(num1>num2)return 1;
//             if(num2>num1)return -1;
//             i++;
//             j++;
//         }

//         return 0;
//     }
// };

