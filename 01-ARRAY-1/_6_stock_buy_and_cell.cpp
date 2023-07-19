// Question: Stock Buy And Sell
// Problem Statement: You are given an array of prices where prices[i] is the price of a given stock on an ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

//leetcode:121 link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low=0;
        int maxi=0;


        for(int i=1;i<prices.size();i++){
            int diff=prices[i]-prices[low];
            maxi=max(diff,maxi);

            if(prices[i]<prices[low]){
                low=i;
            }
        }
        return maxi;
    }
};


int main() {
    vector<int> arr = {7,1,5,3,6,4};
    Solution* a=new Solution();
    int maxPro = a->maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}