// You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].
// The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. 
//In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.
// Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.


//Leetcode:1707  link:https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

#include<iostream>
using namespace std;

class node{
    public:
    node* arr[2];


    bool contains(int a){
        return arr[a]!=NULL;
    }

    node* get(int a){
        return arr[a];
    }

    void put(int a, node* n){
        arr[a]=n;
    }
};


class trie{
    private:
    node* root;
    public:
    trie(){
        root=new node();
    }

    void insert(int num){
        node* temp=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!temp->contains(bit)){
                node* nn=new node();
                temp->put(bit,nn);
            }
            temp=temp->get(bit);
        }
    }


    int maxi(int num){
        node* temp=root;
        int maximum=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(temp->contains(1-bit)){
                maximum=maximum | (1<<i);
                temp=temp->get(1-bit);
            }
            else{
                temp=temp->get(bit);
            }
        }
        return maximum;
    }

};


class Solution {
public:
    vector < int > maximizeXor(vector < int > & nums, vector < vector < int >> & queries) {
        vector < int > ans(queries.size(), 0);
        vector < pair < int, pair < int, int >>> oq;
        sort(nums.begin(), nums.end());
        int index = 0;
        for (auto & it: queries) {
            oq.push_back({it[1],{it[0],index++}});
        }


        sort(oq.begin(), oq.end());
        int i = 0;
        int n = nums.size();
        trie t;

        for (auto & it: oq) {
            while (i < n && nums[i] <= it.first) {
                t.insert(nums[i]);
                i++;
            }
            if (i != 0) ans[it.second.second] = t.maxi(it.second.first);
            else ans[it.second.second] = -1;
        }
        return ans;
    }
};



//TLE
// class Solution {
// public:
//     vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
//         sort(nums.begin(),nums.end());
//         int n=nums.size();

//         vector<int>res;
//         for(auto v:queries){
//             int maxi=-1;
//             int num=v[0];
//             int limit=v[1];

//             for(int i=0;i<n;i++){
//                 if(nums[i]>limit)break;
//                 int m=num^nums[i];
//                 maxi=max(maxi,m);
//             }
//             res.push_back(maxi);
//         }
//         return res;
//     }
// };
