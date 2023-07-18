// Count Maximum Consecutive One’s in the array
// Problem Statement: Given an array that contains only 1 and 0 return the count of 
// maximum consecutive ones in the array.


//Leetcode:485  link:https://leetcode.com/problems/max-consecutive-ones/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
     int count=0;
        int temp=0;
        for(auto n1:nums){
            if(n1==1){
                temp++;
            }
            if(count<temp){
                count=temp;
            }
            if(n1==0){
                temp=0;
            }
        }
        return count;
    }
};