// Find K-th Permutation Sequence
// Problem Statement: Given N and K, where N is the sequence of numbers from 1 to N([1,2,3….. N]) 
//find the Kth permutation sequence.

//Leetcode:60   link: https://leetcode.com/problems/permutation-sequence/description/



#include<iostream>
#include<vector>
using namespace std; 

class Solution {
public:


    //using STL
    // string getPermutation(int n, int k) {
    //     string s="";
    //     for(int i=1;i<=n;i++){
    //         s+=i+48;
    //     }
    //     while(--k){
    //         next_permutation(s.begin(),s.end());
    //     }
    //     return s;
    // }

    
    //using mathematical approach
    string getPermutation(int n, int k) {
      int fact = 1;
      vector < int > numbers;
      for (int i = 1; i < n; i++) {
        fact = fact * i;
        numbers.push_back(i);
      }
      numbers.push_back(n);
      string ans = "";
      k = k - 1;
      while (true) {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0) {
          break;
        }

        k = k % fact;
        fact = fact / numbers.size();
      }
      return ans;
    }
};