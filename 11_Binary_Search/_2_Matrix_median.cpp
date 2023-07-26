
// Median of Row Wise Sorted Matrix
// In this article we will solve the most asked coding interview problem: Median of Row Wise Sorted Matrix
// Problem Statement: Given a row-wise sorted matrix of size r*c, where r is no. of rows and c is no. of columns, find the median in the given matrix.
// Assume – r*c is odd

//leetcode: not available
//gfg: https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

#include<iostream>
using namespace std;
#include<vector>

class solution{
public:
int find_min(vector<int>row,int val){
        int low=0;
        int high=row.size()-1;
        
        while(low<=high){
            int mid=low+ (high-low)/2;
            if(row[mid]<=val){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        int l=0;
        int h=1e9;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            int count=0;
            for(int i=0;i<R;i++){
                count+=find_min(matrix[i],mid);
            }
            if(count > (R*C)/2){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};