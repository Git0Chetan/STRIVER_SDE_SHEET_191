// A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
// Note: Follow 0 based indexing.
// Follow Up: Can you optimize it to O(N)

//gfg : https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab


#include<iostream>
#include<stack>
using namespace std;

int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int>st;
        for(int i=0; i<n; i++){
            st.push(i);
        }
        
        while(st.size()>1){
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            
            if(M[a][b]==1){
                st.push(b);
            }else{
                st.push(a);
            }
        }
        
        int candidate=st.top();
        st.pop();
        
        for(int j=0; j<n; j++){
            if(M[candidate][j]==1) return -1;
        }
        
        for(int i=0; i<n; i++){
            if(candidate!=i && M[i][candidate]==0) return -1;
        }
        
        return candidate;
    }