// 3 Sum : Find triplets that add up to a zero
// Problem Statement: Given an array of N integers, your task is to find unique triplets 
// that add up to give a sum of zero. In short, you need to return an array of all the unique 
// triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

//Leetcode:15 link: https://leetcode.com/problems/3sum/description/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Brute force approach
        //It will lead to time limit exception
        // set<vector<int>>ss;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         for(int k=j+1;k<nums.size();k++){
        //             if(nums[i]+nums[j]+nums[k]==0){
        //                 vector<int>temp={nums[i],nums[j],nums[k]};
        //                 sort(temp.begin(),temp.end());
        //                 ss.insert(temp);
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>>ans(ss.begin(),ss.end());
        // return ans;


        //using O(n^2)
        //it can also leed to time complexity
        // set<vector<int>>ss;
        // for(int i=0;i<nums.size();i++){
        //     set<int>v;
        //     for(int j=i+1;j<nums.size();j++){
        //         int num=-(nums[i]+nums[j]);
        //         if(v.find(num)!=v.end()){
        //             vector<int>te={nums[i],nums[j],num};
        //             sort(te.begin(),te.end());
        //             ss.insert(te);
        //         }
        //         else{
        //             v.insert(nums[j]);
        //         }
        //     }
        // }
        // vector<vector<int>>ans(ss.begin(),ss.end());
        // return ans;


        //using two pointer
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){continue;}
            int low=i+1;
            int high=nums.size()-1;
            while(low<high){
                int sum=nums[i]+nums[low]+nums[high];
                if(sum<0){
                    low++;
                }
                else if(sum>0){
                    high--;
                }
                else{
                    vector<int>v={nums[i],nums[low],nums[high]};
                    ans.push_back(v);
                    low++;
                    high--;
                    while(low<nums.size() && nums[low]==nums[low-1]){low++;}
                    while(high>0 && nums[high]==nums[high+1]){high--;}
                }
            }
        }
        return ans;
    }
};