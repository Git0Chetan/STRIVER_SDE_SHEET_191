// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

//leetcode:994 link: https://leetcode.com/problems/rotting-oranges/description/



#include<iostream>
#include<queue>
using namespace std;


//USING BFS


class Solution {
  public:
    int orangesRotting(vector < vector < int >> & grid) {
      int n = grid.size();
      int m = grid[0].size();

      queue < pair < pair < int, int > , int >> q;
      int vis[n][m];
      int cntFresh = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (grid[i][j] == 2) {
            q.push({{i, j}, 0}); 
            vis[i][j] = 2;
          }
          else {
            vis[i][j] = 0;
          }

          if (grid[i][j] == 1) cntFresh++;
        }
      }
      int tm = 0;
      int drow[] = {-1, 0, +1, 0};
      int dcol[] = {0, 1, 0, -1}; 
      int cnt = 0;

      while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();

        for (int i = 0; i < 4; i++) {
          int nrow = r + drow[i];
          int ncol = c + dcol[i];
          if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
             q.push({{nrow, ncol}, t + 1}); 
            vis[nrow][ncol] = 2;
            cnt++;

          }
        }
      }
      if (cnt != cntFresh) return -1;

      return tm;
    }
};
