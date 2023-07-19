// Trapping Rainwater
// Problem Statement: Given an array of non-negative integers representation elevation of ground. 
// Your task is to find the water that can be trapped after rain.

//leetcode:42   link:https://leetcode.com/problems/trapping-rain-water/description/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        //Brute force approach
        //Time limit exception
        // int i=0;
        // int n=height.size();
        // int volume=0;

        // while(i<n){
        //     int mini=height[i];
        //     int maxi=height[i];
        //     int l=i,h=i;
        //     while(l>=0){
        //         if(mini<height[l]){
        //             mini=height[l];
        //         }
        //         l--;
        //     }
        //     while(h<=n-1){
        //         if(maxi<height[h]){
        //             maxi=height[h];
        //         }
        //         h++;
        //     }
        //     if(mini==height[i] || maxi==height[i]){
        //         i++;
        //     }
        //     else{
        //         int minn=min(mini,maxi);
        //         volume+=(minn-height[i]);
        //         i++;
        //     }
            
        // }
        // return volume;


        //better approach
        //more space complexity 
        // int n = height.size();
        // int pre[n];
        // int suf[n];

        // pre[0] = height[0];
        // for (int i = 1; i < n; i++) {
        //   pre[i] = max(pre[i - 1], height[i]);
        // }

        // suf[n - 1] = height[n - 1];
        // for (int i = n - 2; i >= 0; i--) {
        //   suf[i] = max(suf[i + 1], height[i]);
        // }
        // int water= 0;
        // for (int i = 0; i < n; i++) {
        //   water += min(pre[i], suf[i]) - height[i];
        // }
        // return water;


        //optimised solution
        //two pointer approach

        int n=height.size();
        int l=0;
        int maxl=0;
        int maxh=0;
        int h=n-1;
        int water=0;
        while(l<=h){
            if(height[l]<=height[h]){
                if(maxl<=height[l]){
                    maxl=height[l];
                    l++;
                }
                else{
                    water+= maxl-height[l];
                    l++;
                }
            }
            else{
                if(maxh<=height[h]){
                    maxh=height[h];
                    h--;
                }
                else{
                    water+= maxh-height[h];
                    h--;
                }
            }
        }
        return water;
    }
};