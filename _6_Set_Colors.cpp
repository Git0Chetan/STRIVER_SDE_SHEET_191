// Sort an array of 0s, 1s and 2s
// Question: Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)
//Leetcode:75

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

//short and easy method 
void sortColors(vector<int> &A) {
    int num0 = 0, num1 = 0, num2 = 0;
    int n=A.size();
    
    for(int i = 0; i < n; i++) {
        if (A[i] == 0) ++num0;
        else if (A[i] == 1) ++num1;
        else if (A[i] == 2) ++num2;
    }
    
    for(int i = 0; i < num0; ++i) A[i] = 0;
    for(int i = 0; i < num1; ++i) A[num0+i] = 1;
    for(int i = 0; i < num2; ++i) A[num0+num1+i] = 2;
}
};

//using concept of Dutch National flag algorithm
// void sortColors(vector<int>& arr) {
//     int n=arr.size();
//     int low = 0, mid = 0, high = n - 1;

//     while (mid <= high) {
//         if (arr[mid] == 0) {
//             swap(arr[low], arr[mid]);
//             low++;
//             mid++;
//         }
//         else if (arr[mid] == 1) {
//             mid++;
//         }
//         else {
//             swap(arr[mid], arr[high]);
//             high--;
//         }
//     }
// }
// };



// //using quick sort
// int partition(vector<int>& v,int low,int high){
//     int index=low-1;
//     int pivot=high;
//     while(low<=high){
//         if(v[low]<v[pivot]){
//             index++;
//             int temp=v[low];
//             v[low]=v[index];
//             v[index]=temp;
//         }
//         low++;
//     }
//     index++;
//     int temp=v[index];
//     v[index]=v[high];
//     v[high]=temp;
//     return index;
// }

// void mergee(vector<int>& nums,int low ,int high){
//     if(low<high){
//         int pi=partition(nums,low,high);
//         mergee(nums,low,pi-1);
//         mergee(nums,pi+1,high);
//     }
// }

// void sortColors(vector<int>& nums) {
//         mergee(nums,0,nums.size()-1);
//     }

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    Solution* ans=new Solution();
    ans->sortColors(arr);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}