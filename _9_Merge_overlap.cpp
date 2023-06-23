//Question: Merge Overlapping Sub-intervals
//Problem Statement: Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.
//leetcode:59   link: https://leetcode.com/problems/merge-intervals/description/

#include<iostream>
#include<vector>
using namespace std;

//optimised solution
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            if(ans.empty() || ans.back()[1]<intervals[i][0]){
                ans.push_back(intervals[i]);
            }

            else{
                ans.back()[1]=max(intervals[i][1],ans.back()[1]);
            }
        }
        return ans;
    }
};



//brute force approach
// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         int n=intervals.size();
//         sort(intervals.begin(),intervals.end());
//         vector<vector<int> >ans;

//         for(int i=0;i<n;i++){
//             int left=intervals[i][0];
//             int right=intervals[i][1];

//             if(!ans.empty() && right<ans.back()[1]){
//                 continue;
//             }

//             for(int j=i+1;j<n;j++){
//                 if(intervals[j][0] > right){
//                     break;
//                 }
//                 right=max(right,intervals[j][1]);
//                 i++;
//             }
//             ans.push_back({left,right});
//         }
//         return ans;
//     }
// };


int main()
{
    vector<vector<int>> v1= {{1, 2}, {4, 8}, {5, 7}, {12, 18},{3, 6}};
    cout<<"Given sub intervals are: "<<endl;
    for (auto it : v1) {
        cout << "[" << it[0] << ", " << it[1] << "]"<<"   ";
    }

    Solution* ans=new Solution();
    v1 = ans->merge(v1);

    cout << "\n \nAfter merging intervals : " << "\n";
    for (auto it : v1) {
        cout << "[" << it[0] << ", " << it[1] << "] "<<"   ";
    }
    cout << endl;
    return 0;
}
