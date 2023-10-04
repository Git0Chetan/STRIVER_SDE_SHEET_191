// Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

//Leetcode: 421  link:https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/


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
    int findMaximumXOR(vector<int>& nums) {
        trie* t=new trie();

        for(auto n:nums){
            t->insert(n);
        }

        int maximum=0;
        for(auto n:nums){
            maximum=max(maximum,t->maxi(n));
        }

        return maximum;
    }
};



//TLE
// class Solution {
// public:
//     int findMaximumXOR(vector<int>& nums) {
//         int n=nums.size();
//         int maxi=0;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 int res= nums[i]^nums[j];
//                 maxi=max(maxi,res);
//             }
//         }
//         return maxi;
//     }
// };