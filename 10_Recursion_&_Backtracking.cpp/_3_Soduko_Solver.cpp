// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.


//leetcode: 37  link: https://leetcode.com/problems/sudoku-solver/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;
    }

    bool check(int row,int col,vector<vector<char>>board,char c){
        for(int i=0;i<9;i++){
            if(board[row][i]==c){
                return false;
            }
        }

        for(int i=0;i<9;i++){
            if(board[i][col]==c){
                return false;
            }
        }

        for(int i=0;i<9;i++){
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==c){
                return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>&board){
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]=='.'){
                    for(char i='1';i<='9';i++){
                        if(check(row,col,board,i)){
                            board[row][col]=i;
                            if(solve(board)){
                                return true;
                            }
                            else{
                                board[row][col]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }


    
};