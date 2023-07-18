// Count the number of subarrays with given xor K
// Problem Statement: Given an array of integers A and an integer B. 
// Find the total number of subarrays having bitwise XOR of all elements equal to k.

//leetcode: not available
//code studion link: https://www.codingninjas.com/studio/problems/subarrays-with-xor-k_6826258?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse&leftPanelTab=1


#include<unordered_map>
#include<vector>
using namespace std;

int subarraysWithSumK(vector < int > a, int b) {
    //Brute force approach
    // int count=0;
    // for(int i=0;i<a.size();i++){
    //     int sum=0;
    //     for(int j=i;j<a.size();j++){
    //         sum=sum^a[j];
    //         if(sum==b){
    //             count++;
    //         }
    //     }
    // }
    // return count;


    //optimal approach 
    //Using hashmap
    int count=0;
    int xr=0;
    unordered_map<int,int>mpp;
    mpp[xr]++;
    for(int i=0;i<a.size();i++){
        xr=xr^a[i];
        int x=xr^b;
        count+=mpp[x];
        mpp[xr]++;
    }
    return count;

}