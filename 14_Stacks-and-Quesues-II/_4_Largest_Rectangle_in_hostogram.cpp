// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
// return the area of the largest rectangle in the histogram.


// leetcode: 84  link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/

#include<iostream>
#include<stack>
using namespace std;

//optimised
class Solution {
public:
int largestRectangleArea(vector < int > & histo) {
      stack < int > st;
      int maxA = 0;
      int n = histo.size();
      for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
          int height = histo[st.top()];
          st.pop();
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
            
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
    }

};



//Using Two vectors (left and right)
// class Solution {
//   public:
//     int largestRectangleArea(vector < int > & heights) {
//       int n = heights.size();
//       stack < int > st;
//       int leftsmall[n], rightsmall[n];
//       for (int i = 0; i < n; i++) {
//         while (!st.empty() && heights[st.top()] >= heights[i]) {
//           st.pop();
//         }
//         if (st.empty())
//           leftsmall[i] = 0;
//         else
//           leftsmall[i] = st.top() + 1;
//         st.push(i);
//       }

//       while (!st.empty())
//         st.pop();

//       for (int i = n - 1; i >= 0; i--) {
//         while (!st.empty() && heights[st.top()] >= heights[i])
//           st.pop();

//         if (st.empty())
//           rightsmall[i] = n - 1;
//         else
//           rightsmall[i] = st.top() - 1;

//         st.push(i);
//       }
//       int maxA = 0;
//       for (int i = 0; i < n; i++) {
//         maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
//       }
//       return maxA;
//     }
// };




//Brute force approach
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int maxi=0;
//         for(int i=0;i<heights.size();i++){
//             int mini=INT_MAX;
//             for(int j=i;j<heights.size();j++){
//                 if(heights[j]>maxi){
//                     maxi=heights[j];
//                 }
//                 if(mini>heights[j]){
//                     mini=heights[j];
//                 }
//                 int t=(j-i)+1;
//                 if(maxi<(t*mini)){
//                     maxi=t*mini;
//                 }
//             }
//         }
//         return maxi;
//     }
// };