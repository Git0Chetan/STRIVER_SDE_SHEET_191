
// Question1 :Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// leetcode:73

#include<iostream>
using namespace std;
#include<vector>

vector<vector<int> >setZeroes(vector<vector<int> >& matrix) {

        int n=matrix.size();
        int m=matrix[0].size();
        int col0 = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {

                    matrix[i][0] = 0;

                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }


        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] != 0) {
                    if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    
    return matrix;
}

int main()
{
    vector<vector<int> > matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();

    cout<<"Given matrix is: "<<endl;
    for(auto it : matrix) {
        for (auto elec : it) {
            cout << elec << " ";
        }
        cout <<endl;
    }

    vector<vector<int> > ans = setZeroes(matrix);

    cout << "The Final matrix is: "<<endl;
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout <<endl;
    }
    return 0;
}


// O(n*m) Approach......................

//vector<vector<int>>setZeroes(vector<vector<int>>& matrix) {
//         set<int>c;
//         set<int>r;
//         for(int i=0;i<matrix.size();i++){
//             for(int j=0;j<matrix[0].size();j++){
//                 if(matrix[i][j]==0){
//                     c.insert(j);
//                     r.insert(i);
//                 }
//             }
//         }

//         for(int i=0;i<matrix.size();i++){
//             for(int j=0;j<matrix[0].size();j++){
//                 if(c.find(j)!=c.end() || r.find(i)!=r.end()){
//                     matrix[i][j]=0;
//                 }
//             }
//         }
//    return matrix;
//  }