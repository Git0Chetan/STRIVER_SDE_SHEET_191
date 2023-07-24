// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

//Leetcode:51  link: https://leetcode.com/problems/n-queens/description/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //Optimised
     void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
          board[row][col] = 'Q';
          leftrow[row] = 1;
          lowerDiagonal[row + col] = 1;
          upperDiagonal[n - 1 + col - row] = 1;
          solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
          board[row][col] = '.';
          leftrow[row] = 0;
          lowerDiagonal[row + col] = 0;
          upperDiagonal[n - 1 + col - row] = 0;
        }
      }
    }

  public:
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
      solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
      return ans;
    }
};





    //Time and space complexity:more i.e(O{n!*n}) O(N^2)
//     bool isSafe(int row,int col,vector<string>output,int siz){
//         int tr=row;
//         int tc=col;
//         while(tc>=0){
//             if(output[tr][tc]=='Q'){
//                 return false;
//             }
//             tc--;
//         }

//         tc=col;
//         while(tc>=0 && tr>=0){
//             if(output[tr][tc]=='Q'){
//                 return false;
//             }
//             tc--;
//             tr--;
//         }

//         tr=row;
//         tc=col;
//         while(tc>=0 && tr<siz){
//             if(output[tr][tc]=='Q'){
//                 return false;
//             }
//             tc--;
//             tr++;
//         }

//         return true;

//     }
//     void solve(int col,int siz,vector<string>output,vector<vector<string>>&answer){
//         if(col==siz){
//             answer.push_back(output);
//             return;
//         }

//         for(int i=0;i<siz;i++){
//             if(isSafe(i,col,output,siz)){
//                 output[i][col]='Q';
//                 solve(col+1,siz,output,answer);
//                 output[i][col]='.';
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>>answer;
//         string s="";
//         for(int i=0;i<n;i++){
//             s+='.';
//         }
//         vector<string>output(n,s);
//         solve(0,n,output,answer);
//         return answer;
//     }
// };