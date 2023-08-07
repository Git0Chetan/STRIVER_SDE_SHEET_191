//     //STRING TO INTEGER
//     Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function)
// The algorithm for myAtoi(string s) is as follows:
// Read in and ignore any leading whitespace.
// Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
// Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
// Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
// If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
// Return the integer as the final result.
// Note:

// Only the space character ' ' is considered a whitespace character.
// Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.

//LEETCODE: 8  link: https://leetcode.com/problems/string-to-integer-atoi/description/


#include<iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int num=0;
        bool sign=true;
        int i=0;

        while(i<n && s[i]==' '){
            i++;
        }
        if(i==n){return 0;}
        if(s[i]=='-'){
            sign=false;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }


        while(i<n && s[i]=='0'){
            i++;
        }

        if(i==n){return 0;}

        while(i<n && s[i]>='0' && s[i]<='9'){
            int digit=s[i]-'0';
            if((num>(INT_MAX/10)) || (num==(INT_MAX/10)&& digit>7)){
                return sign?INT_MAX:INT_MIN;
            }
            num=num*10;
            num+=digit;
            i++;
        }
        
        if(sign==false){
            return num*-1;
        }
          
        return num;
    }
};