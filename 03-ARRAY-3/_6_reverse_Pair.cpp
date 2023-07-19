// Count Reverse Pairs
// Problem Statement: Given an array of numbers, you need to return the count of reverse pairs.
// Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

//leetcode:493   link: https://leetcode.com/problems/reverse-pairs/description/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    //Brute force approach O(n^2) TLE and size overflow
    // int reversePairs(vector<int>& nums) {
    //     int count=0;
    //     for(int i=0;i<nums.size()-1;i++){
    //         for(int j=i+1;j<nums.size();j++){
    //             if((long long)nums[i]>2*(long long)(nums[j])){
    //                 count++;
    //             }
    //         }
    //     }
    //     return count;
    // }



    //Optimised Solution using merge sort
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2 * (long long)arr[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2 ;
        cnt += mergeSort(arr, low, mid);  
        cnt += mergeSort(arr, mid + 1, high); 
        cnt += countPairs(arr, low, mid, high); 
        merge(arr, low, mid, high); 
        return cnt;
    }
        int reversePairs(vector<int>&nums){
            return mergeSort(nums,0,nums.size()-1);
        }
};