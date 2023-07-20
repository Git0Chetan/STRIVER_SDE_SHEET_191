// N meetings in one room
// Problem Statement: There is one meeting room in a firm. 
// You are given two arrays, start and end each of size N.For an index ‘i’, 
// start[i] denotes the starting time of the ith meeting while end[i]  will 
// denote the ending time of the ith meeting. Find the maximum number of meetings that can be accommodated 
// if only one meeting can happen in the room at a  particular time. 
// Print the order in which these meetings will be performed.

//leetcode: no;
//gfg: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1


#include<iostream>
#include<vector>
using namespace std;
int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>mp;
        for(int i=0;i<n;i++){
            mp.push_back(make_pair(end[i],start[i]));
        }
        sort(mp.begin(),mp.end());
        
        int count=1;
        int st=mp[0].first;
        for(int i=1;i<n;i++){
            
                if(mp[i].second>st){
                    count++;
                    st=mp[i].first;
                }
        }
        
        return count;
    }