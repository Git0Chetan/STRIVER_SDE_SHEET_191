// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

//Leetcode:12  link: https://leetcode.com/problems/integer-to-roman/description/



#include<iostream>
using namespace std;

// class Solution {
// public:
//     string intToRoman(int num) {
//         int value[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
//         int n=sizeof(value)/sizeof(value[0]);
//         string symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
//         string sb = "";
//         while(num>0){
//             for(int i=0;i<n;i++){
//                 if(num>=value[i]){
//                     sb+=symbol[i];
//                     num -= value[i];
//                     break;
//                 }
//             }
//         }
//         return sb;
//     }
// };


class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hrns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string ths[]={"","M","MM","MMM"};
        
        return ths[num/1000] + hrns[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};


