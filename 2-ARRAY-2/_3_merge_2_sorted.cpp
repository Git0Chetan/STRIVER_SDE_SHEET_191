//question: Merge two Sorted Arrays Without Extra Space
// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
//and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.
// The final sorted array should not be returned by the function, but instead be stored inside 
//the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements 
//denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. 
//nums2 has a length of n.

//leetcode:88  link:https://leetcode.com/problems/merge-sorted-array/description/
//gfg:Merge Without Extra Space


#include<iostream>
#include<vector>
using namespace std;

//using Brute force and extra space
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>v;
        int i=0;
        int j=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                v.push_back(nums1[i]);
                i++;
            }
            else{
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            v.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            v.push_back(nums2[j]);
            j++;
        }
        nums1=v;
    }
};


// //using no extra space
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//             int i=m-1;
//             int j=0;
//             vector
//             while(i>=0 && j<n){
//                 if(nums1[i]<nums2[j]){
//                     break;
//                 }
//                 else{
//                     swap(nums1[i],nums2[j]);
//                     i--;
//                     j++;
//                 }
//             }
//             sort(nums1.begin(),nums1.end());
//             sort(nums2.begin(),nums2.end());
//             nums.
//     }
// };



//using stl function:
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//      vector<int>v;
//      //v=nums2;

//      for(int i=0;i<m;i++){
//             v.push_back(nums1[i]);
//      } 
//      for(int j=0;j<n;j++){
//             v.push_back(nums2[j]);
//      } 
//      sort(v.begin(),v.end());
//      nums1=v;  

//     }
// };