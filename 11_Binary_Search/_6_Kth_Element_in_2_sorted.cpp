
// K-th Element of two sorted arrays
// Problem Statement: Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the kth position of the final sorted array.


//Gfg  link: https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1

#include<iostream>
using namespace std;

//Brute force approach
// int kthElement(int arr1[], int arr2[], int n, int m, int k)
// {
//         int i=0;
//         int j=0;
//         while(i<n && j<m && k>1){
//             k--;
//             if(arr1[i]<=arr2[j]){
//                 i++;
//             }
//             else{
//                 j++;
//             }
//         }
        
//         if(i<n && k>1){
//             k--;
//             i++;
//         }
//         if(j<m && k>1){
//             k--;
//             j++;
//         }
        
//         if(k==1){
//             if(i<n && j<m){
//                 if(arr1[i]<=arr2[j]){return arr1[i];}
//                 else{
//                     return arr2[j];
//                 }
//             }
//             if(i<n)return arr1[i];
//             else return arr2[j];
//         }
        
//         return 0;
//     }


//Optimised

int kthElement(int arr1[], int arr2[], int m, int n, int k)
    {
        if(m > n) {
            return kthElement(arr2, arr1, n, m, k); 
        }
        
        int low = max(0,k-n), high = min(k,m);
        
        while(low <= high) {
            int cut1 = (low + high) >> 1; 
            int cut2 = k - cut1; 
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            int r1 = cut1 == m ? INT_MAX : arr1[cut1]; 
            int r2 = cut2 == n ? INT_MAX : arr2[cut2]; 
            
            if(l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }
            else if (l1 > r2) {
                high = cut1 - 1;
            }
            else {
                low= cut1 + 1; 
            }
        }
        return 1; 
    }