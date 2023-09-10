// detect cycle using dfs 
// Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 
//Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.


//little complicated
//leetcode: 207 link: https://leetcode.com/problems/course-schedule/description/

//Same question
//GFG: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab


#include<iostream>
using namespace std;
class Solution{

public:
    bool dfs(int src,int par,vector<int>pre[],vector<int>&vis){
        vis[src]=1;
        for(auto a:pre[src]){
            if(!vis[a]){
               if(dfs(a,src,pre,vis)==true){
                   return true;
               }
            }
            else if(a!=par){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int num, vector<int> adj[]) {
        vector<int>vis={num,0};
        for(int i=0;i<num;i++){
            if(!vis[i]){
                if(dfs(i,-1,adj,vis)==true){
                    return true;
                }
            }
        }
        return false;
    }
};


//Leetcode:
// class Solution {
// public:
//     bool iscycle(vector<int> adj[],vector<int> &vis,int id){
//         if(vis[id]==1)
//             return true;
//         if(vis[id]==0){
//             vis[id]=1;
//             for(auto edge : adj[id]){
//                 if(iscycle(adj,vis,edge))
//                     return true;
//             }
//         }
//         vis[id] = 2;
//         return false;
//     }
//     bool canFinish(int n, vector<vector<int>>& pre) {
//         vector<int> adj[n];
//         for(auto edge : pre)
//             adj[edge[1]].push_back(edge[0]);
//         vector<int> vis(n,0);
        
//         for(int i=0;i<n;i++){
//             if(iscycle(adj,vis,i))
//                 return false;
//         }
//         return true;
//     }
// };

