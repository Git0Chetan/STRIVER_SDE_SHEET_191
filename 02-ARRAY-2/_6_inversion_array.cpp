// Count inversions in an array
// Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).
// What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

//leetcode:775 link: https://leetcode.com/problems/global-and-local-inversions/description/
//gfg:count inversion  link:https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab



#include <iostream>
#include<vector>
using namespace std;

int numberOfInversions(vector<int>&a, int n) {

    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = numberOfInversions(a, n);
    cout << "The number of inversions is: "
         << cnt << endl;
    return 0;
}


//not able to get the optimised solution:
class Solution{
  public:
     long long count;
    
   
void merge(long long v[],int l,int mid,int h)
{
    
    long long i=l,j=mid+1;
    vector<long long > vec;
    
    while(i<=mid && j<=h)
    {
        if(v[i]<=v[j])
        {
            vec.push_back(v[i]);
            i++;
        }
        else{
            count+=mid+1-i;
            vec.push_back(v[j]);
            j++;
        }
    }
    
    while(i<=mid)
    {
        vec.push_back(v[i]);
        i++;
    }
    while(j<=h)
    {
        vec.push_back(v[j]);
        j++;
    }
    
    
    for(int i=l;i<=h;i++)
    {
        v[i]=vec[i-l];
    }
}
    
    void mergeSort(long long arr[],int low,int high)
    {
        if(low<high)
        {
            long long mid=low+(high-low)/2;
            mergeSort(arr,low,mid);
            mergeSort(arr,mid+1,high);
            merge(arr,low,mid,high);
        }
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
       count=0;
       
        mergeSort(arr,0,N-1);
    
        return count;
        
    }
};