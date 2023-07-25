// Rat in a Maze
// Consider a rat placed at (0, 0) in a square matrix of order N * N. 
//It has to reach the destination at (N – 1, N – 1). 
//Find all possible paths that the rat can take to reach from source to destination. 
//The directions in which the rat can move are ‘U'(up), ‘D'(down), ‘L’ (left), ‘R’ (right). 
//Value 0 at a cell in the matrix represents that it is blocked and the rat cannot move to it while value 1 at a cell in the matrix represents that rat can travel through it.
// Note: In a path, no cell can be visited more than one time.
// Print the answer in lexicographical(sorted) order

//gfg  link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    
    void path(int r,int c,string output,vector<string>&answer,vector<vector<int>>visited,int dr[],int dc[],int n,vector<vector<int>>m){
        if(r==n-1 && c==n-1){
            answer.push_back(output);
            return;
        }
        
        string temp="DLRU";
        for(int i=0;i<4;i++){
            int tr=r+dr[i];
            int tc=c+dc[i];
            if(tc>=0 && tr>=0 && tc<n && tr<n && !visited[tr][tc] && m[tr][tc]==1){
                visited[r][c]=1;
                path(tr,tc,output+temp[i],answer,visited,dr,dc,n,m);
                visited[r][c]=0;   
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>answer;
        string output="";
        vector<vector<int>>visited(n,vector<int>(n,0));
        int dr[]={1,0,0,-1};
        int dc[]={0,-1,1,0};
        
        if(m[0][0]==1){path(0,0,output,answer,visited,dr,dc,n,m);}
        return answer;
    }
};