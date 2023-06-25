// Question:Find the duplicate in an array of N+1 integers
// Problem Statement: Given an array of N + 1 size, where each element is between 1 and N. 
// Assuming there is only one duplicate number, your task is to find the duplicate number.
//leetcode:287  link: https://leetcode.com/problems/find-the-duplicate-number/description/



#include<iostream>
using namespace std;
#include<vector>



//using frequency vector
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>freq(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            if(freq[nums[i]]==0){
                freq[nums[i]]+=1;
            }
            else{
                return nums[i];
            }
        }
        return 0;
    }
};



//using stl map
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         map<int,int>m;
//         for(auto nu:nums){
//             m[nu]++;
//         }

//         for(auto a:m){
//             if(a.second>1){
//                 return a.first;
//             }
//         }

//         return nums[0];
//     }
// };




//using sorting
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < n - 1; i++) {
//             if (nums[i] == nums[i + 1]) {
//             return nums[i];
//             }
//         }
//         return 0;
//     }
// };


int main() {
  vector < int > array{2,5,8,3,5,88,34,55,12};
  Solution* ans=new Solution();
  cout << "The duplicate element is " << ans->findDuplicate(array) << endl;
}
