// Question 4:
// find next lexicographically greater permutation
// Leetcode:31;
//link: https://leetcode.com/problems/next-permutation/


//using Inbuilt Stl
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         next_permutation(nums.begin(),nums.end());
//     }
// };

//using best approach O(n)
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int n=nums.size();
//         int b=-1;
//         for(int i=n-2;i>=0;i--){
//             if(nums[i]<nums[i+1]){
//                 b=i;
//                 break;
//             }
//         }
//         if(b==-1){
//             reverse(nums.begin(),nums.end());
//             return;
//         }
      

//         for(int j=n-1;j>b;j--){
//             if(nums[j]>nums[b]){
//                 int temp=nums[j];
//                 nums[j]=nums[b];
//                 nums[b]=temp;
//                 break;
//             }
//         }

//         reverse(nums.begin()+b+1,nums.end());
//     }
// };

