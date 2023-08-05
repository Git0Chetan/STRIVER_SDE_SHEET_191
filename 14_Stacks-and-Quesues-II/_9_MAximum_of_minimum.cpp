// Given an integer array. The task is to find the maximum of the minimum of every window size in the array.
// Note: Window size varies from 1 to the size of the Array.


//gfg: https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

//cant solved it in optimised way
//only brute force approach



#include<iostream>
using namespace std;

vector <int> maxOfMin(int arr[], int n)
    {
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            vector<int>temp(n,0);
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                if(arr[j]<mini){
                    mini=arr[j];
                }
                temp[j-i]=mini;
            }
            for(int k=0;k<n;k++){
                if(ans[k]<temp[k]){
                    ans[k]=temp[k];
                }
            }
        }
        return ans;
    }
