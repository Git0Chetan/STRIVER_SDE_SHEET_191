// Kth largest/smallest element in an array
// Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.
// Can you solve it without sorting?


//leetcode:215  link: https://leetcode.com/problems/kth-largest-element-in-an-array/description/


#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        //with the help of sorting
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // if(k>n)return 0;
        // return nums[n-k];


        //using stl(HEAP)
        priority_queue<int>q;
        for(auto n:nums){
            q.push(n);
        }
        int ans;
        while(k--){
            ans=q.top();
            q.pop();
        }
        return ans;
    }
};



//using partition (quick sort)
// int findKthLargest(vector<int>& nums, int k) {
    // int left = 0, right = nums.size() - 1, kth;
    // while (1) {
    //     int idx = partition(nums, left, right);
    //     if (idx == k - 1) {
    //         kth = nums[idx];
    //         break;
    //     }
    //     if (idx < k - 1) {
    //         left = idx + 1;
    //     } else {
    //         right = idx - 1;
    //     }
    // }
    // return kth;
// }

//partition(vector<int>& arr, int left, int right) {
//         int pivot = arr[left] ;
//         int l = left + 1 ;
//         int r = right;
//         while (l <= r) {
//             if (arr[l] < pivot && arr[r] > pivot) {
//                 swap(arr[l], arr[r]);
//                 l++ ;
//                 r-- ;
//             }
//             if (arr[l] >= pivot) {
//                 l++;
//             }
//             if (arr[r] <= pivot) {
//                 r--;
//             }
//         }
//         swap(arr[left], arr[r]);
//         return r;
//     }



