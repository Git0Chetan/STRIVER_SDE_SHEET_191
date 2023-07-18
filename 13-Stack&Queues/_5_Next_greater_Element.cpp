// Next Greater Element Using Stack
// Problem Statement: Given a circular integer array A, return the next greater element for every element in A.
// The next greater element for an element x is the first element greater than x that we come across while traversing 
//the array in a clockwise manner. If it doesn’t exist, return -1 for this element.

//Leetcode:503   link:https://leetcode.com/problems/next-greater-element-ii/submissions/


#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
//using stack
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector < int > nge(n, -1);
        stack < int > st;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            if (i < n) {
                if (!st.empty()) nge[i] = st.top();
            }
            st.push(nums[i % n]);
        }
        return nge;
    }
};




//Brute force approach
// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>ans(n,INT_MIN);
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[j]>nums[i]){
//                     ans[i]=nums[j];
//                     break;
//                 }
//             }
//             if(ans[i]==INT_MIN){
//                 for(int k=0;k<i;k++){
//                     if(nums[k]>nums[i]){
//                     ans[i]=nums[k];
//                     break;
//                 }
//                 }
//             }
//             if(ans[i]==INT_MIN){
//                 ans[i]=-1;
//             }
            
//         }
//         return ans;
//     }
// };


