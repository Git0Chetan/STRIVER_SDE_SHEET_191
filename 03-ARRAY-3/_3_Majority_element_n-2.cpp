// // Find the Majority Element that occurs more than N/2 times
// // Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

// // Leetcode:169  link: https://leetcode.com/problems/majority-element/description/


#include<iostream>
#include<vector>
using namespace std;

class Solution{
    int majorityElement(vector<int>& nums) {
        // //Brute force
        // for(int i=0;i<nums.size();i++){
        //     int c=1;
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[j]==nums[i]){c++;}
        //     }
        //     if(c>nums.size()/2){
        //         return nums[i];
        //     }
        // }
        // return 0;



        //using map
        // map<int,int>m;
        // for(int i=0;i<nums.size();i++){
        //     m[nums[i]]++;
        // }
        // for(auto a:m){
        //     if(a.second>nums.size()/2){
        //         return a.first;
        //     }
        // }
        // return 0;


        //Optimised Solution
        int n = nums.size();
        int cnt = 0;
        int el;

        for (int i = 0; i < n; i++) {
            if (cnt == 0) {
                cnt = 1;
                el = nums[i];
            }
            else if (el == nums[i]) cnt++;
            else cnt--;
        }

        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == el) cnt1++;
        }

        if (cnt1 > (n / 2)) return el;
        return -1;

    }
};