// There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. 
//You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. 
//More formally, for each v in graph[u], there is an undirected edge between node u and node v. 
//The graph has the following properties:
// There are no self-edges (graph[u] does not contain u).
// There are no parallel edges (graph[u] does not contain duplicate values).
// If v is in graph[u], then u is in graph[v] (the graph is undirected).
// The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
// A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

// Return true if and only if it is bipartite.

//leetcode:785 link:https://leetcode.com/problems/is-graph-bipartite/description/
//GFG: https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    bool bfs(int src,int v,vector<int>&vis,vector<vector<int>>& graph) {
        queue<int>q;
        q.push(src);
        vis[src]=0;
        while(!q.empty()){
            int f=q.front();
            q.pop();

            for(auto a:graph[f]){
                if(vis[a]==-1){
                    vis[a]=!vis[f];
                    q.push(a);
                }
                else if(vis[f]==vis[a]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>vis(v,-1);

        for(int i=0;i<v;i++){
            if(vis[i]==-1){
                if(bfs(i,v,vis,graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};