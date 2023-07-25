// M – Coloring Problem
// Problem Statement: Given an undirected graph and a number m, determine if the graph can be colored with at most m colors such that no two adjacent vertices of the graph are colored with the same color.

//gfg  link: https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#


#include<iostream>
#include<vector>
using namespace std;

bool check(int node,bool graph[101][101],int n,vector<int>color,int col){
    for(int k=0;k<n;k++){
        if(graph[k][node]==1 && color[k]==col){
            return false;
        }
    }
    return true;
}
    
bool coloring(int node,bool graph[101][101],vector<int>color,int m,int n){
    if(node==n){
        return true;
    }
    
    for(int i=1;i<=m;i++){
        if(check(node,graph,n,color,i)){
            color[node]=i;
            if(coloring(node+1,graph,color,m,n))return true;
            color[node]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    vector<int>color(n,0);
    if(coloring(0,graph,color,m,n)){
        return true;
    }
    
    return false;
}