// Two Sum : Check if a pair with given sum exists in Array
// Problem Statement: Given an array of integers arr[] and an integer target.
// 1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.
// 2nd variant: Return indices of the two numbers such that their sum is equal to the target. Otherwise, we will return {-1, -1}.
// Note: You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

// Leetcode:1  link:https://leetcode.com/problems/two-sum/description/

#include<iostream>
#include<vector>
using namespace std;
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //////////////////////////////
        //Using Brute_force Approach TC:O(n^2)
        // vector<int>v1;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         int sum=nums[i]+nums[j];
        //         if(sum==target){
        //             v1.push_back(i);
        //             v1.push_back(j);
        //             break;
        //         }
        //     }
        // }
        // return v1;



        //////////////////////////////
        //using hashmap
        // unordered_map<int, int> map;
        // for (int i = 0; i < nums.size(); i++) {
        //     int num = nums[i];
        //     int require = target - num;
        //     if (map.find(require) != map.end()) {
        //         return {map[require], i};
        //     }
        //     map[num] = i;
        // }
        // return {-1,-1};




        //////////////////////////////
        //using Two Pointer approach
        // vector<int>answer;
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int l=0;
        int r=v.size()-1;
        while(l<r){
            if((v[l].first+v[r].first) ==target){
                // answer.push_back(v[l].second);
                // answer.push_back(v[r].second);
                return {v[l].second ,v[r].second};
            }
            else if((v[l].first+v[r].first) < target){
                l++;
            }
            else{
                r--;
            }
        }
        return {-1,-1};
    }
};
