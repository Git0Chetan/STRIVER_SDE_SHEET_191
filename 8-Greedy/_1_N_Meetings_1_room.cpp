//N meetings in one room

// There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
// What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?
// Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


//Leetcode: not available
//gfg:  https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
//codeStudio https://www.codingninjas.com/studio/problems/maximum-meetings_1062658?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf



#include<iostream>
using namespace std;


bool seco(const pair<int,int>a , const pair<int,int>b){
    return a.second<b.second;
}


int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n=start.size();
    
        vector<pair<int,int>>mp;
        for(int i=0;i<n;i++){
            mp.push_back(make_pair(start[i],end[i]));
        }
        sort(mp.begin(),mp.end(),seco);
        
        int count=1;
        int st=mp[0].second;
        for(int i=1;i<n;i++){
            
                if(mp[i].first>st){
                    count++;
                    st=mp[i].second;
                }
        }
        
        return count;
}