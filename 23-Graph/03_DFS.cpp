// DFS 
// You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
// Note: Use the recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.

//Leetcode:Not available
//GFG :https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1


#include<iostream>
using namespace std;
class Solution{
    public:
  
    void dfs(vector<int>&res,int vis[],vector<int> adj[],int s){
        res.push_back(s);
        vis[s]=1;
        for(auto a:adj[s]){
            if(!vis[a]){
                dfs(res,vis,adj,a);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V+1]={0};
        vector<int>res;
        dfs(res,vis,adj,0);
        return res;
    }
};