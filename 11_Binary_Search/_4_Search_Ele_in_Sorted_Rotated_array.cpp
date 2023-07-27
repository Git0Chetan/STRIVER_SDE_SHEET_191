// Search Element in a Rotated Sorted Array
// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. 
// Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.

//Leetcode:33  link:https://leetcode.com/problems/search-in-rotated-sorted-array/description/



#include<iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]<=nums[high]){
                if(nums[mid]<=target && nums[high]>=target){
                    low=mid+1;}
                else{
                    high=mid-1;
                }
            }
            else{
                if(nums[mid]>=target && nums[low]<=target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }   
        }
        return -1;
    }
};
