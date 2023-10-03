// Given a string of length N of lowercase alphabet characters. 
//The task is to complete the function countDistinctSubstring(), 
//which returns the count of total number of distinct substrings of this string.

//Leetcode:premium
//GFG: https://practice.geeksforgeeks.org/problems/count-of-distinct-substrings/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

#include<iostream>
using namespace std;

class node{
    public:
    node* arr[26];
};
int countDistinctSubstring(string s)
{
    node* root=new node();
    int n=s.length();
    
    int res=0;
    for(int i=0;i<n;i++){
        node* temp=root;
        for(int j=i;j<n;j++){
            if(temp->arr[s[j]-'a']==NULL){
                node* nn=new node();
                temp->arr[s[j]-'a']=nn;
                res++;
            }
            temp=temp->arr[s[j]-'a'];
        }
    }
    return res+1;
}


//TLE
// int countDistinctSubstring(string s)
// {
//     set<string>ss;
//     int n=s.length();
//     for(int i=0;i<n;i++){
//         string str="";
//         for(int j=i;j<n;j++){
//             str+=s[j];
//             ss.insert(str);
//         }
//     }
//     return ss.size()+1;
// }

