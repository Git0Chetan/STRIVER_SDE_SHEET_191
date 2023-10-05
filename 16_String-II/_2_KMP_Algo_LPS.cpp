// Given two strings, one is a text string, txt and other is a pattern string, pat. 
//The task is to print the indexes of all the occurences of pattern string in the text string.
// For printing, Starting Index of a string should be taken as 1.


//GFG: https://practice.geeksforgeeks.org/problems/search-pattern0205/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

#include<iostream>
using namespace std;

class solution{
    public:
        void computeLPS(string pat, vector<int> &lps){
        int m = pat.size();
        if(m == 1) return ;
        int len = 0 , i = 1;
        
        while(i < m){
            if(pat[i] == pat[len]){
                lps[i] = len + 1;
                len++; i++;
            }
            else{
                if(len != 0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        }
        
        vector <int> search(string pat, string txt)
        {
            //code hee.
            int m = pat.size() , n = txt.size();
            vector<int> lps(m,0);
            vector<int> ans;
            computeLPS(pat, lps);
            int i = 0 , j = 0;
            while(i < n){
                if(pat[j] == txt[i]){
                    i++;
                    j++;
                }
                else{
                    if(j != 0){
                        j = lps[j-1];
                    }
                    else{
                        i++;
                    }
                }
                if(j == m){
                    ans.push_back(i-j+1);
                    j = lps[j-1];
                }
            }
            if(ans.size() == 0) return {-1};
            return ans;
        }
        
        
        
        // vector <int> search(string pat, string txt)
        // {
        //     vector<int>res;
        //     for(int i=0;i<txt.length();i++){
        //         if(txt.substr(i,pat.length()) == pat){
        //             res.push_back(i+1);
        //         }
        //     }
        //     return res;
        // }
};