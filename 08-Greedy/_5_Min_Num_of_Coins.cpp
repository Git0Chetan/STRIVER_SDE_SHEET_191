
// Find minimum number of coins
// Problem Statement: Given a value V, if we want to make a change for V Rs, and
// we have an infinite supply of each of the denominations in Indian currency, 
// i.e., we have an infinite supply of { 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes,
// what is the minimum number of coins and/or notes needed to make the change.

//leetcode:no
//codeStudio :   https://www.codingninjas.com/studio/problems/find-minimum-number-of-coins_975277?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
//gfg : https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1


#include<iostream>
#include<vector>
using namespace std;

vector<int> MinimumCoins(int n)
{
    vector<int>v;
    int coin[9]={1000,500,100,50,20,10,5,2,1};
    int i=0;
    while(i<9 && n>0){
        if(coin[i]<=n){
            n-=coin[i];
            v.push_back(coin[i]);
            continue;
        }
        i++;
    }
    return v;
}