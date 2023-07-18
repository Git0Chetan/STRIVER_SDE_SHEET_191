// Remove Duplicates in-place from Sorted Array
// Problem Statement: Given an integer array sorted in non-decreasing order, 
//remove the duplicates in place such that each unique element appears only once. 
//The relative order of the elements should be kept the same.
// If there are k elements after removing the duplicates, 
//then the first k elements of the array should hold the final result. 
//It does not matter what you leave beyond the first k elements.
// Note: Return k after placing the final result in the first k slots of the array.


//Leetcode:26  link:https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        //Brute force approach
        // int count=0;
        // vector<int>v;
        // for(int i=0;i<nums.size();i++){
        //     bool flag=true;
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]==nums[j]){
        //             flag=false;
        //         }
        //     }
        //     if(flag==true){
        //         v.push_back(nums[i]);
        //         count++;
        //     }
        // }
        // nums=v;
        // return count;



        //Using stl
        // for(int i=0;i<nums.size()-1;)
        // {
        //     if(nums[i]==nums[i+1])
        //      nums.erase(nums.begin()+i+1);
        //      else
        //      i++;
        // }
        // return nums.size();


        //Using Hashmap
        // set<int>s;
        // for(int i=0;i<nums.size();i++){
        //     s.insert(nums[i]);
        // }
        // int j=0;
        // for(auto x:s){
        //     nums[j]=x;
        //     j++;
        // }
        // return j;


        //Using Two Pointer Approach
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};