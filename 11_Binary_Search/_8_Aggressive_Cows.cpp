// Aggressive Cows : Detailed Solution
// Problem Statement: You are given an array ‘arr’ of size ‘n’ which denotes the position of stalls.
// You are also given an integer ‘k’ which denotes the number of aggressive cows.
// You are given the task of assigning stalls to ‘k’ cows such that the minimum distance between any two of them is the maximum possible.
// Find the maximum possible minimum distance.

//similar magnetic force
//Leetcode:1552  link : https://leetcode.com/problems/magnetic-force-between-two-balls/description/



#include<iostream>
using namespace std;

class Solution {
public:

    bool possible(vector<int>position,int m,int mid){
        int count=1;
        int pos=position[0];

        for(int i=0;i<position.size();i++){
            if(position[i]-pos >=mid){
                count++;
                if(count==m){
                    return true;
                }
                pos=position[i];
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int s=0;
        int e=position[position.size()-1];
        int mid=s+ (e-s)/2;
        int ans=-1;

        while(s<=e){
            if(possible(position,m,mid)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+ (e-s)/2;
        }

        return ans;
    }
};
