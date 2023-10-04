// Given a string S, Find all the possible subsequences of the String in lexicographically-sorted order.

//GFG: https://practice.geeksforgeeks.org/problems/power-set4302/1#

#include<iostream>
using namespace std;

class Solution{
    public:
		vector<string> AllPossibleStrings(string s){
		    vector<string>ans;
		    
		    int n=s.length();
		    for(int i=0;i<(1<<n);i++){
		        string sub="";
		        for(int j=0;j<n;j++){
		            if(i&(1<<j)){
		                sub+=s[j];
		            }
		        }
		        if(sub.length()!=0){
		            ans.push_back(sub);
		        }
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
		
		
		
			
//Using Recursion
// 	    void poss(int ind,string s,vector<string>ans,string &str){
// 	        if(ind>=s.length()){
// 	            ans.push_back(str);
// 	        }
	        
// 	        str+=s[ind];
// 	        poss(ind+1,s,ans,str);
// 	        str.pop_back();
// 	        poss(ind+1,s,ans,str);
// 	    }
// 		vector<string> AllPossibleStrings(string s){
// 		    vector<string>ans;
// 		    string str="";
// 		    poss(0,s,ans,str);
// 		    return ans;
// 		}
};