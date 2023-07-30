// Maximum Sum Combination
// Given two integer array A and B of size N each.
// A sum combination is made by adding one element from array A and another element of array B.
// Return the maximum K valid distinct sum combinations from all the possible sum combinations.
// Note : Output array must be sorted in non-increasing order.

//leetcode : no
//gfg : https://practice.geeksforgeeks.org/problems/maximum-sum-combination/1


#include<iostream>
#include<queue>
#include<set>
using namespace std;

vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int,int>>s;
        vector<int>answer;
        
        pq.push(make_pair(a[n-1]+b[n-1],make_pair(n-1,n-1)));
        s.insert(make_pair(n-1,n-1));
        
        while(k--){
            pair<int,pair<int,int>> temp=pq.top();
            pq.pop();
            answer.push_back(temp.first);
            int i=temp.second.first;
            int j=temp.second.second;
            
            pair<int,int>temp1=make_pair(i-1,j);
            if(i>=0 && s.find(temp1)==s.end()){
                pq.push(make_pair(a[i-1]+b[j],temp1));
                s.insert(temp1);
            }
            
            
            pair<int,int>temp2=make_pair(i,j-1);
            if(j>=0 && s.find(temp2)==s.end()){
                pq.push(make_pair(a[i]+b[j-1],temp2));
                s.insert(temp2);
            }
        }
        return answer;
    }