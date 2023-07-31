// //K most frequent elements

// Given an integer array nums and an integer k, return the k most frequent elements. 
//You may return the answer in any order.


//leetcode:347  https://leetcode.com/problems/top-k-frequent-elements/description/


#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        if(k==nums.size()){return nums;}
        map<int,int> mp;
        for(auto i:nums)mp[i]++;

        priority_queue<pair<int,int>> vp;
        for(auto i:mp)
        {
            vp.push(make_pair(i.second,i.first));
        }

        vector<int> out;
        for(int i=0;i<k;i++){
        out.push_back(vp.top().second);
        vp.pop();
        }
        return out;
    }







//using map and vector
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     map<int,int> mp;
    //     for(auto i:nums)mp[i]++;

    //     vector<pair<int,int>> vp;
    //     for(auto i:mp)
    //     {
    //         vp.push_back({i.second,i.first});
    //     }

    //     sort(vp.begin(),vp.end(),greater<pair<int,int>>());
    //     vector<int> out;
    //     for(int i=0;i<k;i++)
    //     out.push_back(vp[i].second);

    //     return out;
    // }
};