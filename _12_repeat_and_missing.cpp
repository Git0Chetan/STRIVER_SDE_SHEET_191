//Question:Find the repeating and missing numbers
//Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] 
//both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. 
//The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

//GFG: link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
//Alternative 0n leetcode:
//Leetcode:268   link:https://leetcode.com/problems/missing-number/description/


#include<iostream>
using namespace std;
#include<vector>


class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int>ans;
        vector<int>aa(n+1,-1);
        
        for(auto num:arr){
            aa[num]++;
        }
        
        int A;
        int B;
        for(int i=0;i<n+1;i++){
            if(aa[i]==-1){
                B=i;
            }
            if(aa[i]==1){
                A=i;
            }
        }
        ans.push_back(A);
        ans.push_back(B);
        return ans;
    }
};



int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    Solution* answer=new Solution();
    vector<int> ans = answer->findTwoElement(a,a.size());
    cout << "The repeating and missing numbers are: {"<< ans[0] << ", " << ans[1] << "}\n";
    return 0;
}

