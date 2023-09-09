// Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
// Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.


//Leetcode: not available
//gfg:  https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1


#include<iostream>
#include<queue>
using namespace std;
class Solution{
    public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int>res;
        queue<int>q;
        int vis[V]={0};
        q.push(0);
        vis[0]=1;
        
        while(!q.empty()){
            int f=q.front();
            q.pop();
            res.push_back(f);
            
            for(auto a:adj[f]){
                if(!vis[a]){
                    q.push(a);
                    vis[a]=1;
                }
            }
        }
        return res;
        
    }
};