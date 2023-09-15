// Bellman Ford Algorithm: G-41
// Problem Statement: Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertices from the source vertex S.
// Note: If the Graph contains a negative cycle then return an array consisting of only -1.
//it is generally used for Negative cycles

//GFG: https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU


#include<iostream>
using namespace std;

class Solution{
    public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>dist(V,1e8);
        dist[S]=0;
        
        for(int i=0;i<V-1;i++){
            for(auto a:edges){
                int u=a[0];
                int v=a[1];
                int w=a[2];
                
                if(dist[u]!=1e8 && dist[v]>dist[u]+w){
                    dist[v]=dist[u]+w;
                }
            }
        }
        
        for(auto a:edges){
            int u=a[0];
            int v=a[1];
            int w=a[2];
            
            if(dist[u]!=1e8 && dist[v]>dist[u]+w){
                return {-1};
            }
        }
        
        return dist;
    }
};