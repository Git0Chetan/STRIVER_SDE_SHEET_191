// Question.2:
// Given an integer numRows, return the first numRows of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Leetcode:118:

#include<iostream>
using namespace std;
#include<vector>

vector<vector<int>> generate(int r) {
    vector<vector<int>>v;
        for(int i=0;i<r;i++){
            vector<int>v1;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    v1.push_back(1);
                    continue;
                }
                if(i>1){
                    int sum=(v[i-1][j])+(v[i-1][j-1]);
                    v1.push_back(sum);
                }
            }
            v.push_back(v1);
        }
    return v;
}


int main()
{
    int n = 5;
    vector<vector<int>> ans = generate(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout<<endl;
    }
    return 0;
}