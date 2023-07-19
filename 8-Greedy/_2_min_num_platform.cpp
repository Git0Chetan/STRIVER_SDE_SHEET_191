// Minimum number of platforms required for a railway

// Problem Statement: We are given two arrays that represent the arrival and departure times of trains that stop at the platform. 
// We need to find the minimum number of platforms needed at the railway station so that no train has to wait.

//leetcode: no

//gfg:  https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

#include<iostream>
using namespace std;


int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr,arr+n);
        sort(dep,dep+n);
        
        int mini=1;
        int count=1;
        int j=0;
        int i=1;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                count++;
                i++;
            }
            else{
                j++;
                count--;
            }
            mini=max(count,mini);
        }
        return mini;
    }