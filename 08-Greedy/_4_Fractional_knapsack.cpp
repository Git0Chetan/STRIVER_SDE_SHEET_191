//Fractional Knapsack Problem : Greedy Approach

// Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
// Note: Unlike 0/1 knapsack, you are allowed to break the item. 

//Leetcode:no
//GFG: https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1


#include<iostream>
using namespace std;
struct Item{
    int value;
    int weight;
};


class Solution
{
    public:
    bool static shuff(Item a,Item b){
        double a1=(double)a.value/(double)a.weight;
        double b1=(double)b.value/(double)b.weight;
        return a1>b1;
        
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,shuff);
        double maxi=0;
        int i=0;
        while(i<n && W>0){
            if(W>=arr[i].weight){
                maxi+=arr[i].value;
                W-=arr[i].weight;
            }
            else{
                double a=(double)arr[i].weight/(double)W;
                maxi+= arr[i].value/a;
                W=0;
            }
            i++;
        }
        return maxi;
    }
        
};