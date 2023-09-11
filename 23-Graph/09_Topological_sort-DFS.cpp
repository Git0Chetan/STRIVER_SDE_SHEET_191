// Topological Sort Using DFS
// Problem Statement: Given a DAG( Directed Acyclic Graph ), print all the vertex of the graph in a topologically sorted order. If there are multiple solutions, print any.
// Pre-req: DFS traversal, Graphs, Stack data structure.


//GFG: https://practice.geeksforgeeks.org/problems/topological-sort/1


#include<iostream>
using namespace std;

class Solution{
    public:
	//using dfs 
	
	void dfs(int src,vector<int>&vis,vector<int>&topo,vector<int> adj[]){
	    vis[src]=1;
	    for(auto a:adj[src]){
	        if(!vis[a]){
	            dfs(a,vis,topo,adj);
	        }
	    }
	    topo.push_back(src);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>vis(V,0);
	    vector<int>topo;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,vis,topo,adj);
	        }
	    }
	    int l=0,h=V-1;
	    while(l<h){
	        swap(topo[l],topo[h]);
	        l++;
	        h--;
	    }
	    return topo;
	}
};