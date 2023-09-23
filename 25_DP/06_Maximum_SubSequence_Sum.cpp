// Given an array of n positive integers. 
//Find the sum of the maximum sum subsequence of the given array such that the integers in the 
//subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence.

// GFG: https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

#include<iostream>
using namespace std;

class Solution{

        //Tabulation DP
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int dp[n];
	    
	    for(int i=0;i<n;i++){
	        dp[i]=arr[i];
	    }
	    
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i]){
	                if(dp[i]< arr[i]+dp[j]){
	                    dp[i]=arr[i]+dp[j];
	                }
	            }
	        }
	    }
	    
	    int maxi=INT_MIN;
	    for(int i=0;i<n;i++){
	        maxi=max(maxi,dp[i]);
	    }
	    
	    return maxi;
	}  
	
	
	
//TLE
// 	int maximum(int ind,int arr[],int maxi,int sum){
// 	    if(ind<0){
// 	        return sum;
// 	    }
	    
// 	    int take=0;
// 	    int no_take=0;
// 	    if(arr[ind]<maxi){
// 	        take=maximum(ind-1,arr,arr[ind],sum+arr[ind]);
// 	    }
// 	    no_take=maximum(ind-1,arr,maxi,sum);
	    
// 	    return max(take,no_take);
// 	}
// 	int maxSumIS(int arr[], int n)  
// 	{  
// 	    return maximum(n-1,arr,INT_MAX,0);
// 	}  

};