
// Search Single Element in a sorted array
// Problem Statement: Given an array of N integers. Every number in the array except one appears twice. 
//Find the single number in the array.

//leetcode:540   link: https://leetcode.com/problems/single-element-in-a-sorted-array/

#include<iostream>
using namespace std;

class Solution {
public:


    //Brute force approach//
    // int singleNonDuplicate(vector<int>& nums) {
    //     for(int i=0;i<nums.size()-1;i=i+2){
    //         if(nums[i]!=nums[i+1]){
    //             return nums[i];
    //         }
    //     }
    //     int j=nums.size()-1;
    //     return nums[j];
    // }

    //Using XOR''
    // int singleNonDuplicate(vector<int>& arr) {
    // int n = arr.size();
    // int ans = 0;
    // for (int i = 0; i < n; i++) {
    //     ans = ans ^ arr[i];
    // }
    // return ans;
    // }


    //USing Binary Search
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];
        if (arr[0] != arr[1]) return arr[0];
        if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
                return arr[mid];
            }

            if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
};