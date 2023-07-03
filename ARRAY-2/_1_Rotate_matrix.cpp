//Question: Rotate matrix
//You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
//You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
//Leetcode:48  link: https://leetcode.com/problems/rotate-image/description/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n=matrix.size();

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};


int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3,4}, {5, 6, 7,8}, {9, 10, 11,12},{13,14,15,16}};

    cout << "Given Image matrix" << endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout<<endl;
    }

    Solution* ans=new Solution();
    ans->rotate(arr);

    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout<<endl;
    }

}