// Topological Sort (BFS)
// Problem statement: Given a graph, find the topological order for the given graph.
// Topological sort: The linear ordering of nodes/vertices such that if there exists an edge between 2 nodes u,v then ‘u’ appears before ‘v’.


//GFG: https://practice.geeksforgeeks.org/problems/topological-sort/1

#include<iostream>
#include<queue>
using namespace std;

class Solution{
    public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>topo;
        vector<int>inorder(V,0);
        for(int i=0;i<V;i++){
            for(auto a:adj[i]){
                inorder[a]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            topo.push_back(temp);
            
            for(auto a:adj[temp]){
                inorder[a]--;
                if(inorder[a]==0){
                    q.push(a);
                }
            }
        }
        
        return topo;
	}
};