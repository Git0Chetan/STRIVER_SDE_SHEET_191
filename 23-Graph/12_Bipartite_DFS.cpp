// Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. 
//Check whether the graph is bipartite or not.

//leetcode:785 link:https://leetcode.com/problems/is-graph-bipartite/description/
//GFG: https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

#include<iostream>
using namespace std;

class Solution{
    public:
    bool dfs(int src,vector<int>&vis,vector<int>adj[],int col){
        vis[src]=col;
        for(auto a:adj[src]){
            if(vis[a]==-1){
                if(dfs(a,vis,adj,!col)==false){
                    return false;
                }
            }
            else if(vis[a]==col){
                return false;
            }
        }
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
        vector<int>vis(V,-1);

        for(int i=0;i<V;i++){
            if(vis[i]==-1){
                if(dfs(i,vis,adj,0)==false){
                    return false;
                }
            }
        }
        return true;
	}
};