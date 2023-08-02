// Given an array, print the Next Smaller Element (NSE) for every element. 
//The NSE for an element x is the first smaller element on the right side of x in the array. 
//Elements for which no smaller element exist (on the right side), consider NSE as -1. 

//leetcode:1475    link:https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/
//codeStudio   https://www.codingninjas.com/studio/problems/next-smaller-element_1112581?leftPanelTab=0
//gfg  https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab


#include<iostream>
using namespace std;
#include<stack>

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int>s;
    vector<int>v(n,-1);
    s.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        while(!s.empty() && s.top()>=arr[i]){
            s.pop();
        }
        if(!s.empty()){
            v[i]=s.top();
            s.push(arr[i]);
        }
        else{
            s.push(arr[i]);
        }
    }
    return v;
}
