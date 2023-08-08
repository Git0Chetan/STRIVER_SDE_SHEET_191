// Given two strings, one is a text string and other is a pattern string. 
//The task is to print the indexes of all the occurences of pattern string in the text string. 
//For printing, Starting Index of a string should be taken as 1.

// Leetcode:no
//GFG:      https://practice.geeksforgeeks.org/problems/31272eef104840f7430ad9fd1d43b434a4b9596b/1



#include<iostream>
using namespace std;

vector <int> search(string pat, string txt)
        {
            vector<int>a;
            for(int i=0;i<txt.length();i++){
                int count=0;
                int k=i;
                for(int j=0;j<pat.length();j++){
                    if(txt[k]!=pat[j]){
                        count=-1;
                        break;
                    }
                    k++;
                }
                if(count==0){
                    a.push_back(i+1);
                }
            }
            if(a.size()==0){
                return {-1};
            }
            return a;
        }

