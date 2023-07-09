// //Longest Consecutive Sequence in an Array
// Problem Statement: You are given an array of ‘N’ integers. 
// You need to find the length of the longest sequence which contains the consecutive elements.

//Leetcode:128  link:https://leetcode.com/problems/longest-consecutive-sequence/description/


#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        //we can use brute force approach using two for loops it will create TLE by O(n^2)complexity


        //Using Sort and single loop
        // O(N * log(N))
        // if(nums.size()==0){return 0;}
        // sort(nums.begin(),nums.end());
        
        // int count=1;
        // int maxi=1;
        // for(int i=1;i<nums.size();i++){
        //     if(nums[i-1]==nums[i]-1){
        //         count++;
        //     }
        //     else if(nums[i-1]!=nums[i]){
        //         count=1;
        //     }
        //     maxi=max(maxi,count);
        // }
        // return maxi;


        //using 
        //O(n)
        set<int>n;
        for(auto num:nums){
            n.insert(num);
        }

        int longest=0;
        for(int i=0;i<nums.size();i++){
            if(n.find(nums[i]-1)==n.end()){
                int current=nums[i];
                int count=1;

                while(n.find(current+1)!=n.end()){
                    current+=1;
                    count++;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};