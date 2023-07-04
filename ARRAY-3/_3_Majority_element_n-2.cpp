// // Find the Majority Element that occurs more than N/2 times
// // Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

// // Leetcode:169  link: https://leetcode.com/problems/majority-element/description/


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         // //Brute force
//         // for(int i=0;i<nums.size();i++){
//         //     int c=1;
//         //     for(int j=i+1;j<nums.size();j++){
//         //         if(nums[j]==nums[i]){c++;}
//         //     }
//         //     if(c>nums.size()/2){
//         //         return nums[i];
//         //     }
//         // }
//         // return 0;



//         //using map
//         map<int,int>m;
//         for(int i=0;i<nums.size();i++){
//             m[nums[i]]++;
//         }
//         for(auto a:m){
//             if(a.second>nums.size()/2){
//                 return a.first;
//             }
//         }
//         return 0;
//     }
// };