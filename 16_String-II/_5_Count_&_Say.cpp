// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
// To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

// For example, the saying and conversion for digit string "3322251":


/*
it has approach just like
if n=1  output "1"
if n=2  output "11"
if n=3  output "21"
if n=4  output "1211"
if n=5  output "111221"
if n=6  output "312211"
....
*/


//leetcode:38   link: https://leetcode.com/problems/count-and-say/description/


#include<iostream>
using namespace std;


class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        if(n==2){
            return "11";
        }

        string str="11";
        for(int i=3;i<=n;i++){
            str+="@";
            string temp="";
            int count=1;
            for(int j=1;j<str.length();j++){
                if(str[j]!=str[j-1]){
                    temp+=to_string(count);
                    temp+=str[j-1];
                    count=1;
                }
                else{
                    count++;
                }
            }
            str=temp;
        }
        return str;
    }
};
