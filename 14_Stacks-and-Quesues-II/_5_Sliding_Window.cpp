// You are given an array of integers nums, 
//there is a sliding window of size k which is moving from the very left of the array to the very right. 
//You can only see the k numbers in the window. 
//Each time the sliding window moves right by one position.
// Return the max sliding window.

//leetcode:239 link:https://leetcode.com/problems/sliding-window-maximum/description/

#include<iostream>
#include<queue>
using namespace std;

//Optimised solution using deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>v;
        deque<int>d;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(!d.empty() && d.front()==i-k)d.pop_front();

            while(!d.empty() && nums[d.back()]<=nums[i]){
                d.pop_back();
            }
            d.push_back(i);
            if(i>=k-1){
                v.push_back(nums[d.front()]);
            }
        }
        return v;
    }
};





// brute force using sliding window
// class Solution {
// public:
//     int maxi(vector<int>nums,int l,int h){
//         int maxi=INT_MIN;
//         for(int i=l;i<=h;i++){
//             maxi=max(maxi,nums[i]);
//         }
//         return maxi;
//     }

//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int>v;
//         int n=nums.size();
//         int low=0;
//         int high=k-1;

//         while(high<n){
//             v.push_back(maxi(nums,low,high));
//             low++;
//             high++;
//         }
//         return v;
//     }
// };