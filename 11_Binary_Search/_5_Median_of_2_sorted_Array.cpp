// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

//leetcode: 4 link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/


#include<iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        //Brute force USing extra space and O(n+m) tc
        // vector<int>ans;
        // int i=0,j=0,m=nums1.size(),n=nums2.size();
        // while(i<m && j<n){
        //     if(nums1[i]<=nums2[j]){
        //         ans.push_back(nums1[i]);
        //         i++;
        //     }
        //     else{
        //         ans.push_back(nums2[j]);
        //         j++;
        //     }
        // }

        // while(i<m){
        //     ans.push_back(nums1[i]);
        //     i++;
        // }
        // while(j<n){
        //     ans.push_back(nums2[j]);
        //     j++;
        // }

        // double answer;
        // int mn=ans.size();
        // if(mn%2==0){
        //     answer=((float)ans[mn/2]+(float)ans[(mn/2)-1])/2;
        // }
        // else{
        //     answer=ans[mn/2];
        // }
        // return answer;


        //Brute force USing NO extra space and O(m+n) tc. 
        //using counter instead of a ds


        //OPtimised
        int m=nums1.size();
        int n=nums2.size();

        if(m>n)
        return findMedianSortedArrays(nums2,nums1);
        
        int low=0,high=m,medianPos=((m+n)+1)/2;
        while(low<=high) {
            int cut1 = (low+high)>>1;
            int cut2 = medianPos - cut1;
        
            int l1 = (cut1 == 0)? INT_MIN:nums1[cut1-1];
            int l2 = (cut2 == 0)? INT_MIN:nums2[cut2-1];
            int r1 = (cut1 == m)? INT_MAX:nums1[cut1];
            int r2 = (cut2 == n)? INT_MAX:nums2[cut2];
        
            if(l1<=r2 && l2<=r1) {
                if((m+n)%2 != 0)
                    return max(l1,l2);
                else 
                    return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) high = cut1-1;
            else low = cut1+1;
        }
        return 0.0;
    }
};