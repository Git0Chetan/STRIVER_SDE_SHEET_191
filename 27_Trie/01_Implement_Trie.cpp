// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.
// Implement the Trie class:
// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

//Leetcode:208  link : https://leetcode.com/problems/implement-trie-prefix-tree/description/


#include<iostream>
using namespace std;

class node{
    public:
    char data;
    unordered_map<char,node*>mp;
    bool isterminal;

    node(char d){
        data=d;
        isterminal=false;
    }
};


class Trie {
public:

    node* root;
    Trie() {
        root=new node('\0');
    }
    
    void insert(string word) {
        node* temp=root;
        for(auto s:word){
            if(temp->mp.count(s)==0){
                node* newnode=new node(s);
                temp->mp[s]=newnode;
            }
            temp=temp->mp[s];
        }
        temp->isterminal=true;
    }
    
    bool search(string word) {
        node* temp=root;
        for(auto s:word){
            if(temp->mp.count(s)==0){
                return false;
            }
            temp=temp->mp[s];
        }
        return temp->isterminal;
    }
    
    bool startsWith(string prefix) {
        node* temp=root;
        for(auto s:prefix){
            if(temp->mp.count(s)==0){
                return false;
            }
            temp=temp->mp[s];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */