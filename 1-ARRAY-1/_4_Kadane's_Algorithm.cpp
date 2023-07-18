// Question: Given an integer array arr, find the contiguous subarray (containing at least one number) which
// has the largest sum and returns its sum and prints the subarray.
// Kadane’s Algorithm : Maximum Subarray Sum in an Array
// Leetcode:53

#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;


        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            maxi=max(sum,maxi);
            if(sum<0){
                sum=0;
            }
        }
         return maxi;
    }
};

int main()
{
    vector<int>v{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution* a=new Solution();
    int maxSum = a->maxSubArray(v);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}