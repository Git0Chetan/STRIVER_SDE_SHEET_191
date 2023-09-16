// Given a weighted, undirected and connected graph of V vertices and E edges. 
// The task is to find the sum of weights of the edges of the Minimum Spanning Tree. 
// Given  adjacency list adj as input parameters . Here adj[i] contains vectors of size 2, 
// where the first integer in that vector denotes the end of the edge and the second integer denotes the edge weight.

//GFG: https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include<iostream>
using namespace std;

class Solution{
    public:
    class disjoint{
	    public:
	    vector<int>size,par;
	    
	    disjoint(int n){
	        size.resize(n+1);
	        par.resize(n+1);
	        for(int i=0;i<n;i++){
	        par[i]=i;
	        size[i]=1;
	        }
	    }
	    
	    
	    int findPar(int u){
	        if(par[u]==u){
	            return u;
	        }
	        return par[u]=findPar(par[u]);
	    }
	    
	    void unionbysize(int u,int v){
	        int uu=findPar(u);
	        int vv=findPar(v);
	        
	        if(uu==vv)return;
	        
	        if(size[uu]>size[vv]){
	            par[vv]=uu;
	            size[uu]+=size[vv];
	        }
	        else{
	            par[uu]=vv;
	            size[vv]+=size[uu];
	        }
	    }
	};
	
    
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edge;
        
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                edge.push_back({it[1],{i,it[0]}});
            }
        }
        
        sort(edge.begin(),edge.end());
        disjoint ds(V);
        
        int weight=0;
        for(auto ad:edge){
            int u=ad.second.first;
            int v=ad.second.second;
            int w=ad.first;
            if(ds.findPar(u)!=ds.findPar(v)){
            weight+=w;
            ds.unionbysize(u,v);
            }
        }
        
        return weight;
        
    }

};