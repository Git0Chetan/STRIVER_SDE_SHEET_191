// // Detect a cycle using bfs approach
// Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

//Leetcode: not present
//gfg: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab


#include<iostream>
#include<queue>
using namespace std;

class Solution{
     private:
    bool BFS(int src,vector<int> adj[],bool vis[])
    {
        queue<pair<int,int>>q;
        q.push({src,-1});
        vis[src]=true;
        
        while(!q.empty()){
            int f=q.front().first;
            int p=q.front().second;
            q.pop();
            
            for(auto a:adj[f]){
                if(!vis[a]){
                    q.push({a,f});
                    vis[a]=true;
                }
                else if(p!=a){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    bool isCycle(int V, vector<int> adj[]) {
        bool vis[V] = {false};
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
             if(BFS(i,adj,vis))
                return true;
        }
        return false;
    }

};