// Given a weighted, undirected and connected graph of V vertices and an adjacency list adj
//where adj[i] is a list of lists containing two integers where the first integer of each list j denotes 
//there is edge between i and j , second integers corresponds to the weight of that  edge . 
//You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. 
//You have to return a list of integers denoting shortest distance between each node and Source vertex S.
// Note: The Graph doesn't contain any negative weight cycle.

#include<iostream>
#include<set>
using namespace std;

class Solution{
    public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    //We Can Also use Priority_Queue instead of set
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        set<pair<int,int>>ss;
        vector<int>dis(V,1e9);
        
        dis[s]=0;
        ss.insert({0,s});
        
        while(!ss.empty()){
            
            auto it=*(ss.begin());
            int node=it.second;
            int diss=it.first;
            ss.erase(it);
            
            for(auto a:adj[node]){
                int aNode=a[0];
                int adis=a[1];
                
                if(diss+adis < dis[aNode]){
                    if(dis[aNode]!=1e9){
                        ss.erase({dis[aNode],aNode});
                    }
                    
                    ss.insert({diss+adis,aNode});
                    dis[aNode]=diss+adis;
                }
            }
        }
        return dis;
    }
};