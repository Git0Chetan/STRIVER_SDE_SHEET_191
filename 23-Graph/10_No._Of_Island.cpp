// Number of Distinct Islands
// Problem Statement: Given a boolean 2D matrix grid of size N x M. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is equal to another (not rotated or reflected).

//Leeetcode:200 link: https://leetcode.com/problems/number-of-islands/description/

//gfg: https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1


#include<iostream>
#include<set>
using namespace std;
//Leetcode:
class Solution {
public:

    void dfs(int i,int j,int m,int n,vector<vector<int>>&vis,vector<vector<char>>&grid){
        vis[i][j]=1;
        int dir[]={0,-1,0,1,0};
        for(int k=0;k<4;k++){
            int dr=i+dir[k];
            int dc=j+dir[k+1];
            if(dr<m && dr>=0 && dc<n && dc>=0 && !vis[dr][dc] && grid[dr][dc]=='1'){
                dfs(dr,dc,m,n,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(i,j,m,n,vis,grid);
                }
            }
        }
        return count;
    }
};



//optimised (BFS)
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == '1') {
//                     islands++;
//                     grid[i][j] = '0';
//                     queue<pair<int, int>> todo;
//                     todo.push({i, j});
//                     while (!todo.empty()) {
//                         pair<int, int> p = todo.front();
//                         todo.pop();
//                         for (int k = 0; k < 4; k++) {
//                             int r = p.first + offsets[k], c = p.second + offsets[k + 1];
//                             if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
//                                 grid[r][c] = '0';
//                                 todo.push({r, c});
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return islands;
//     }
// };

//optimised (DFS)
// class Solution {
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == '1') {
//                     islands++;
//                     eraseIslands(grid, i, j);
//                 }
//             }
//         }
//         return islands;
//     }
// private:
//     void eraseIslands(vector<vector<char>>& grid, int i, int j) {
//         int m = grid.size(), n = grid[0].size();
//         if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') {
//             return;
//         }
//         grid[i][j] = '0';
//         eraseIslands(grid, i - 1, j);
//         eraseIslands(grid, i + 1, j);
//         eraseIslands(grid, i, j - 1);
//         eraseIslands(grid, i, j + 1);
//     }
// };



//GFG-----------
class Solution {
  private:
    void dfs(int row, int col, vector < vector < int >> & vis,
      vector < vector < int >> & grid, vector < pair < int, int >> & vec, int row0, 
      int col0) {
          
      vis[row][col] = 1;

      vec.push_back({
        row - row0,
        col - col0
      });
      int n = grid.size();
      int m = grid[0].size();

      int dir[]={0,-1,0,1,0}; 
      for (int i = 0; i < 4; i++) {
        int nrow = row + dir[i];
        int ncol = col + dir[i+1];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
          !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
          dfs(nrow, ncol, vis, grid, vec, row0, col0);
        }
      }
    }
  public:
    int countDistinctIslands(vector < vector < int >> & grid) {
      int n = grid.size();
      int m = grid[0].size();
      vector < vector < int >> vis(n, vector < int > (m, 0));
      set < vector < pair < int, int >>> st;

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (!vis[i][j] && grid[i][j] == 1) {
            vector < pair < int, int >> vec;
            dfs(i, j, vis, grid, vec, i, j);
            st.insert(vec);
          }
        }
      }
      return st.size();
    }
};