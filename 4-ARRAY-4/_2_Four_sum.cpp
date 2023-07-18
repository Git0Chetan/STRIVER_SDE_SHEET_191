// 4 Sum | Find Quads that add up to a target value
// Problem Statement: Given an array of N integers, your task is to find unique quads that add up 
// to give a target value. In short, you need to return an array of all the unique quadruplets 
// [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.

//Leetcode:18   link:https://leetcode.com/problems/4sum/description/


#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        //Brute force O(n^4)
        // set<vector<int>>answer;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             for(int l=k+1;l<n;l++){
        //                 long long sum=nums[i]+nums[j];
        //                 sum+=nums[k];
        //                 sum+=nums[l];
        //                 if(sum==target){
        //                     vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
        //                     sort(temp.begin(),temp.end());
        //                     answer.insert(temp);
        //                 }
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>>ans={answer.begin(),answer.end()};
        // return ans;


        //Optimised Solution using two pointers
        set<vector<int>>answer;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>1 && nums[i]==nums[i-1]){continue;}
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]){continue;}
                
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                        answer.insert(temp);
                        k++;
                        l--;

                        while(k<l && nums[k]==nums[k-1]){k++;}
                        while(k<l && nums[l]==nums[l+1]){l--;}
                    }
                    else if(sum<target){k++;}
                    else{l--;}
                }
            }
        }
        vector<vector<int>>ans={answer.begin(),answer.end()};
        return ans;

    }
};