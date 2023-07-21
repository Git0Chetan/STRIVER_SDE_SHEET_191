// Subset Sum : Sum of all Subsets
// Problem Statement: Given an array print all the sum of the subset generated from it, in the increasing order.


//gfg:  https://practice.geeksforgeeks.org/problems/subset-sums2234/1
//similar problem.
//Leetcode:78  link:https://leetcode.com/problems/subsets/description/ 

//approach is just try to solve the problem in sub-parts i.e. divide and conquere

#include<iostream>
using namespace std;
#include<vector>

class Solution
{
public:
static void summy(vector<int>a,int index,long long v,vector<int>&ans){
        if(index>=a.size()){
            ans.push_back(v);
            return;
        }
        summy(a,index+1,v,ans);
        v+=a[index];
        summy(a,index+1,v,ans);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        long long v=0;
        summy(arr,0,v,ans);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};