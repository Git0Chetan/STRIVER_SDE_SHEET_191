// Strongly Connected Components – Kosaraju’s Algorithm: G-54
// Problem Statement: Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, 
//Find the number of strongly connected components in the graph.


//GFG: https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

#include<iostream>
#include<stack>
using namespace std;

class Solution{
    public:
	
	void topoo(int src, vector<int>&vis,stack<int>&topo,vector<vector<int>>& adj){
	    vis[src]=1;
	    for(auto a:adj[src]){
	        if(!vis[a]){
	            topoo(a,vis,topo,adj);
	        }
	    }
	    topo.push(src);
	}
	
	void dfs(int src,vector<int>&vis,vector<int>trans[]){
	    vis[src]=1;
	    for(auto a:trans[src]){
	        if(!vis[a]){
	            dfs(a,vis,trans);
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //Finishing time sorting array
        stack<int>topo;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topoo(i,vis,topo,adj);
            }
        }
        
        //Reverse the graph
        vector<int>transpose[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto a:adj[i]){
                transpose[a].push_back(i);
            }
        }
        
        //find the count of scc
        int count=0;
        while(!topo.empty()){
            int i=topo.top();
            topo.pop();
            if(!vis[i]){
                count++;
                dfs(i,vis,transpose);
            }
        }
        
        return count;
    }
};