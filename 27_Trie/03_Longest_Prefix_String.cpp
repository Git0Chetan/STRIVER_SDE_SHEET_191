// Ninja developed a love for arrays and strings so this time his teacher gave him an array of strings, 'A' of size 'N'. 
// Each element of this array is a string. The teacher taught Ninja about prefixes in the past, so he wants to test his knowledge.
// A string is called a complete string if every prefix of this string is also present in the array 'A'.
//  Ninja is challenged to find the longest complete string in the array 'A'.
//  If there are multiple strings with the same length, return the lexicographically smallest one and if no string exists, return "None".


//Coding ninja  : https://www.codingninjas.com/studio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0

#include<iostream>
using namespace std;

class node{
    public:
    unordered_map<char,node*>mp;
    bool isterminal=false;
};
string completeString(int n, vector<string> &a){
    node* root=new node();
    for(auto word:a){
        node* temp=root;
        for(auto ch:word){
            if(temp->mp.count(ch)==0){
                node* nn=new node();
                temp->mp[ch]=nn;
            }
            temp=temp->mp[ch];
        }
        temp->isterminal=true;
    }
    string s="None";
    for(auto t:a){
        node* temp=root;
        bool res=true;
        for(auto ch:t){
            if (temp->mp.count(ch) == 0) {
                res=false;
                break;
            }
            temp=temp->mp[ch];
            if (!temp->isterminal) {
                res = false;
                break;
            }
        }
        if(res){
            if(s.length()==t.length()){
                s=(s<t)?s:t;
            }
            else{
                s=(s>t)?s:t;
            }
        }
    }

    return s;
}