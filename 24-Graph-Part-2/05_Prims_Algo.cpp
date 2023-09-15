// Given a weighted, undirected and connected graph of V vertices and E edges. 
//The task is to find the sum of weights of the edges of the Minimum Spanning Tree. 
//Given  adjacency list adj as input parameters . Here adj[i] contains vectors of size 2, 
//where the first integer in that vector denotes the end of the edge and the second integer denotes the edge weight.

//GFG :  https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1


#include<iostream>
#include<queue>
using namespace std;

class Solution{
    public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(V,0);
        
        int sum=0;
        pq.push({0,0});
        
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int wt=it.first;
            pq.pop();
            
            if(vis[node]==1)continue;
            vis[node]=1;
            sum+=wt;
            
            for(auto a:adj[node]){
                int ad=a[0];
                int awt=a[1];
                
                if(!vis[ad]){
                    pq.push({awt,ad});
                }
            }
        }
        return sum;
    }
};