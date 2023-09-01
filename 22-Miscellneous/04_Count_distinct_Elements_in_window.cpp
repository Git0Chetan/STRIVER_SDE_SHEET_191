// Count distinct elements in every window
// Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

//Leetcode:no
//gfg: https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab


#include<iostream>
#include<unordered_map>
using namespace std;

class Solution{
  public:
    vector <int> countDistinct (int a[], int n, int k)
    {
    unordered_map<int,int>mp;
    vector<int>ans;
    if(k>n)return ans;
    
    int i=0;
    for(i;i<k;i++){
        mp[a[i]]++;
    }
    ans.push_back(mp.size());
    
    for(i;i<n;i++){
        mp[a[i-k]]--;
        if(mp[a[i-k]]==0){
            mp.erase(a[i-k]);
        }
        
        mp[a[i]]++;
        ans.push_back(mp.size());
    }
    return ans;
    }
};
