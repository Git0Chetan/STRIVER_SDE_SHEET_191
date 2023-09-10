// Detection of cycle using dfs in Directed graph 
// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges,
// check whether it contains any cycle or not.

//GFG: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

#include<iostream>
using namespace std;

class Solution{
    public:
  
    bool dfs(int src,int vis[],int dfsvis[], vector<int>adj[]){
        vis[src]=1;
        dfsvis[src]=1;
        for(auto a:adj[src]){
            if(!vis[a]){
                if(dfs(a,vis,dfsvis,adj))return true;
            }
            else if(dfsvis[a]){
                return true;
            }
        }
        dfsvis[src]=0;
        return false;
    }
    
    bool isCyclic(int N, vector < int > adj[]) {
      int vis[N], dfsVis[N];
     
      for(int i = 0; i < N; i++){
        vis[i] = 0;
        dfsVis[i] = 0;
      }

      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          if (dfs(i, vis, dfsVis,adj)) {
            return true;
          }
        }
      }
      return false;
    }
};