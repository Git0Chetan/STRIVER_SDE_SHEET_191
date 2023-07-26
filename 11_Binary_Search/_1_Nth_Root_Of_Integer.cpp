// Nth Root of a Number using Binary Search
// Problem Statement: Given two numbers N and M, find the Nth root of M. 
// The nth root of a number M is defined as a number X when raised to the power N equals M. If the ‘nth root is not an integer, return -1.


//leetcode: no
//CodingStudio : https://www.codingninjas.com/studio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

#include<iostream>
using namespace std;
//creates time limit excided
// int NthRoot(int n, int m) {

//   for(int i=1;i<m;i++){
//     if(pow(i,n)==m){
//       return i;
//     }
//   }
//   return -1;
// }


// Using binary search
int NthRoot(int n, int m) {

  int low=1;
  int high=m;
  while(low<high){
    int mid=low+ (high-low)/2;
    if(pow(mid,n)<m){
      low=mid+1;
    }
    else if(pow(mid,n)>m){
      high=mid;
    }
    else{
      return mid;
    }
  }
  return -1;
}