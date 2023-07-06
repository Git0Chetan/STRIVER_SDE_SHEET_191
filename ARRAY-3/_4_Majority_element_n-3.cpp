// Majority Elements(>N/3 times) | Find the elements that appears more than N/3 times in the array
// Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

//leetcode:229  link:https://leetcode.com/problems/majority-element-ii/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        //brute force approach
        //time limit exceed
        // set<int>v;
        // for(int i=0;i<nums.size();i++){
        //     int count=0;
        //     for(int j=0;j<nums.size();j++){
        //         if(nums[i]==nums[j]){
        //             count++;
        //         }
        //     }

        //     if(count>(nums.size()/3)){
        //         v.insert(nums[i]);
        //     }
        // }
        // vector<int>v1;
        // for(auto a:v){
        //     v1.push_back(a);
        // }

        // return v1;



        //Better Approach
        //using map and vector
        // vector<int>v;
        // map<int,int>m;
        // int n=nums.size();
        // int r=int(n/3)+1;
        // for(int i=0;i<n;i++){
        //     m[nums[i]]++;
        //     if(m[nums[i]]==r){
        //         v.push_back(nums[i]);
        //     }
        // }
        // return v;



        //optimised solution:
        vector<int>v;
        int ele1=INT_MIN;
        int ele2=INT_MIN;
        int c1=0;
        int c2=0;
        for(int i=0;i<nums.size();i++){
            if(c1==0 && ele2!=nums[i]){
                c1=1;
                ele1=nums[i];
            }
            else if(c2==0 && ele1!=nums[i]){
                c2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1){
                c1++;
            }
            else if(nums[i]==ele2){
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        int col1=0;
        int col2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1){col1++;}
            else if(nums[i]==ele2){col2++;}
        }

        if(col1>=(nums.size()/3)+1){v.push_back(ele1);}
        if(col2>=(nums.size()/3)+1){v.push_back(ele2);}
        sort(v.begin(),v.end());
        return v;
    }
};