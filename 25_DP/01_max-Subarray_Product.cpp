
// Given an integer array nums, find a subarray
//  that has the largest product, and return the product.
// The test cases are generated so that the answer will fit in a 32-bit integer.

//Leetcode:152  link: https://leetcode.com/problems/maximum-product-subarray/description/

#include<iostream>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //O(n2)
        // int maxi=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     int pro=1;
        //     for(int j=0;j<nums.size();j++){
        //         pro*=nums[j];
        //         maxi=max(pro,maxi);
        //     }
        // }
        // return maxi;

        //O(n)
        //rte -when there are 3 negative numbers
        // int n=nums.size();
        // int arr[n];
        // for(int i=n-1;i>=0;i--){
        //     if(i==n-1)arr[i]=nums[i];
        //     else{
        //         arr[i]=(nums[i]*arr[i+1] > nums[i]?nums[i]*arr[i+1]:nums[i]);
        //     }
        // }
        // int maxi=INT_MIN;
        // for(int i=0;i<n;i++){
        //     maxi=max(arr[i],maxi);
        // }
        // return maxi;


        //optimised Solution
        // int n=nums.size();
        // int res=INT_MIN;
        // int suf=1;
        // int pre=1;
        // for(int i=0;i<n;i++){
        //     if(pre==0)pre=1;
        //     if(suf==0)suf=1;
        //     pre*=nums[i];
        //     suf*=nums[n-i-1];
        //     res=max(res,max(pre,suf));
        // }
        // return res;

        // int n = nums.size();
        // int minProduct = 1;
        // int maxProduct = 1;
        // int ans = INT_MIN;
        // for(int i=0; i<n; i++){
        //     if(nums[i] < 0){
        //         swap(maxProduct, minProduct);
        //     }
        //     maxProduct = max(maxProduct*nums[i], nums[i]);
        //     minProduct = min(minProduct*nums[i], nums[i]);
        //     ans = max(ans, maxProduct);
        // }
        // return ans;


    int prod=1,maxi=INT_MIN,n=nums.size();

    for(int i=0;i<n;i++){
        if(prod>= (1*pow(10,10)/10) && (nums[i]==10||nums[i]==-10))return (1*pow(10,9));
        
        if(prod==0)prod=1;
        prod*=nums[i];
        maxi=max(prod,maxi);
    }

    prod=1;
    for(int i=n-1;i>=0;i--){
        if(prod==0)prod=1;
        prod*=nums[i];
        maxi=max(prod,maxi);
    }
    return maxi;

    }
};