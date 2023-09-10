// Detect A cycle in a Directed Graph using BFS- kahns algorithm
// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

//GFG:  https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

#include<iostream>
#include<queue>
using namespace std;

class Solution{
    public:
    //Using BFS and topp..sort
    bool isCyclic(int V, vector<int> adj[]) {
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
        
        int cnt=0;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            cnt++;
            
            for(auto a:adj[temp]){
                inorder[a]--;
                if(inorder[a]==0){
                    q.push(a);
                }
            }
        }
        
        if(cnt!=V){
            return true;
        }
        return false;
    }

};
