// We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].
// You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.
// If you choose a job that ends at time X you will be able to start another job that starts at time X.

// leetcode:1235  link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/

#include<iostream>
using namespace std;

class Solution{
    public:
    vector<int>dp;
int find(vector<vector<int>>& events,int idx,int end){
    if(idx==events.size())
        return 0;
    if( events[idx][0] < end )
        return find( events, idx + 1 , end );
    if( dp[idx] != -1)
        return dp[idx];
    int res= max ( events[idx][2] + find(events, idx + 1 , events[idx][1] ),  find(events , idx + 1 , end ) );
    return dp[idx] = res;
}
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
{
    vector<vector<int>>events(startTime.size(),vector<int>(3,0));
    for(int i=0;i<startTime.size();i++)
    {
        events[i][0]=startTime[i];
        events[i][1]=endTime[i];
        events[i][2]=profit[i];
    }
    sort(events.begin() , events.end());
    int n = events.size();
    dp.resize( n,-1);
    return find(events , 0 , 0);
}
};



//MLE
// class Solution {
// public:

//     int job(int ind,vector<vector<int>>&v,int end,int n,vector<vector<int>>&dp){
//         if(ind==n)return 0;
//         if(dp[ind][end]!=-1)return dp[ind][end];

//         int no=job(ind+1,v,end,n,dp);
//         int take=0;
//         if(v[ind][0]>=end){
//             take=v[ind][2]+job(ind+1,v,v[ind][1],n,dp);
//         }
//         return dp[ind][end]=max(no,take);
//     }

//     static bool comp(vector<int>a,vector<int>b){
//         return a[1]<b[1];
//     }

//     int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
//         int n=profit.size();
//         vector<vector<int>>v(n);
        
//         int maxi=0;
//         for(int i=0;i<n;i++){
//             int x=start[i];
//             int y=end[i];
//             int z=profit[i];
//             maxi=max(maxi,y);
//             v[i]={x,y,z};
//         }

//         sort(v.begin(),v.end(),comp);

//         vector<vector<int>>dp(n,vector<int>(maxi+1,-1));
//         return job(0,v,0,n,dp);

//     }
// };


//TLE
// class Solution {
// public:

//     int job(int ind,vector<vector<int>>&v,int end,int n,vector<int>&dp){
//         if(ind==n)return 0;
//         if(dp[end]!=-1)return dp[end];

//         int no=job(ind+1,v,end,n,dp);
//         int take=0;
//         if(v[ind][0]>=end){
//             take=v[ind][2]+job(ind+1,v,v[ind][1],n,dp);
//         }
//         return dp[end]=max(no,take);
//     }

//     static bool comp(vector<int>a,vector<int>b){
//         return a[1]<b[1];
//     }

//     int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
//         int n=profit.size();
//         vector<vector<int>>v(n);
        
//         int maxi=0;
//         for(int i=0;i<n;i++){
//             int x=start[i];
//             int y=end[i];
//             int z=profit[i];
//             maxi=max(maxi,y);
//             v[i]={x,y,z};
//         }

//         sort(v.begin(),v.end(),comp);
//         vector<int>dp(1000001,-1);
//         return job(0,v,0,n,dp);

//     }
// };