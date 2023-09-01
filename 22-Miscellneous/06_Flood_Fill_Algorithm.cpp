// Flood Fill Algortihm
// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
// You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
// Return the modified image after performing the flood fill.

//Leetcode: 733 link: https://leetcode.com/problems/flood-fill/description/

#include<iostream>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>&image,int sr,int sc,int col,int color){
        if(image[sr][sc]==col){
            image[sr][sc]=color;

            int r=image.size();
            int c=image[0].size();

            int d[]={0,1,0,-1,0};
            for(int i=0;i<4;i++){
                int dr=sr+d[i];
                int dc=sc+d[i+1];

                if(dr<r && dr>=0 && dc<c && dc>=0){
                    dfs(image,dr,dc,col,color);
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]!=color){
            dfs(image,sr,sc,image[sr][sc],color);
        }
        return image;
    }


};



//Easy to understand
// class Solution {
// public:
    
//     void dfs(vector<vector<int>>& image, int i, int j,int val, int newColor)
//     {
//         if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] == newColor || image[i][j] != val)
//         {
//             return;
//         }
//         image[i][j] = newColor;
//         dfs(image,i-1,j,val,newColor);
//         dfs(image,i+1,j,val,newColor);
//         dfs(image,i,j-1,val,newColor);
//         dfs(image,i,j+1,val,newColor);
//     }
    
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
//     {
//         int val = image[sr][sc];
//         dfs(image,sr,sc,val,newColor);
//         return image;
//     }
// };
