// Length of the longest subarray with zero Sum
// Problem Statement: Given an array containing both positive and negative integers, 
//we have to find the length of the longest subarray with the sum of all elements equal to zero.

// Leetcode:Not available
// GFG:Largest subarray with 0 sum    
//LINK: https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1



#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        //brute force approach
        // int maxi=0;
        // if(n==1 && A[0]==0){return 1;}
        // for(int i=0;i<n;i++){
        //     int sum=A[i];
        //     for(int j=i+1;j<n;j++){
        //         sum+=A[j];
        //         if(sum==0){maxi=max(maxi,j-i+1);}
        //     }
        // }
        // return maxi;
        
        int sum=0;
        int maxi=0;
        unordered_map<int,int>mpp;
        
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0){
                maxi=i+1;
            }
            else{
                if(mpp.find(sum)!=mpp.end()){
                    maxi=max(maxi,i-mpp[sum]);
                }
                else{
                    mpp[sum]=i;
                }
            }
        }
        return maxi;
    }
};