// Job Sequencing Problem

// Problem Statement: You are given a set of N jobs where each job comes with a deadline and profit.
// The profit can only be earned upon completing the job within its deadline. Find the number of jobs done and
// the maximum profit that can be obtained. 
// Each job takes a single unit of time and only one job can be performed at a time.


//Leetcode:NO
//GFG: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

#include<iostream>
#include<vector>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution 
{
 public:
    //Function to find the maximum profit and the number of jobs done.
    
    bool static profi(Job a, Job b){
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,profi);
    
    int maxi=arr[0].dead;
    
    for(int i=1;i<n;i++){
        if(maxi<arr[i].dead){
            maxi=arr[i].dead;
        }
    }
    
    int loc[maxi+1];
    for(int i=0;i<maxi+1;i++){
        loc[i]=-1;
    }
    
    int count=0;
    int profit=0;
    
    for(int i=0;i<n;i++){
        for(int j=arr[i].dead;j>0;j--){
            if(loc[j]==-1){
                loc[j]=i;
                count++;
                profit+=arr[i].profit;
                break;
            }
        }
    }
    return {count,profit};
    }
};