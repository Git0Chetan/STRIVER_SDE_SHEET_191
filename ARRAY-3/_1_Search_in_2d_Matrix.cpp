// Search in a sorted 2D matrix
// Problem Statement: Given an m*n 2D matrix and an integer, write a program to find if the given integer exists in the matrix.
// Given matrix has the following properties:
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row

//Leetcode:74 link:https://leetcode.com/problems/search-a-2d-matrix/description/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int r=matrix.size();
        int c=matrix[0].size();

        if(r==0 || c==0){
            return false;
        }

        int low = 0;
        int high= (r*c) - 1;
        
        while(low <= high) {
            int mid = (low + (high - low) / 2);
            if(matrix[mid/c][mid % c] == target) {
                return true;
            }
            if(matrix[mid/c][mid % c] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
};