// Implement Trie – II
// Problem Statement:  Implement a data structure ”TRIE” from scratch. Complete some functions.
// 1) Trie(): Initialize the object of this “TRIE” data structure.
// 2) insert(“WORD”): Insert the string “WORD”  into this “TRIE” data structure.
// 3) countWordsEqualTo(“WORD”): Return how many times this “WORD” is present in this “TRIE”.
// 4) countWordsStartingWith(“PREFIX”): Return how many words are there in this “TRIE” that have the string “PREFIX” as a prefix.
// 5) erase(“WORD”): Delete this string “WORD” from the “TRIE”.


//Coding ninja:  https://www.codingninjas.com/studio/problems/implement-trie_1387095?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=1
// leetcode,gfg  -- not present



#include <iostream>
using namespace std;

struct node{
    node* arr[26];
    int isend=0;
    int ispref=0;

    bool ispresent(char c){
        return arr[c-'a']!=NULL;
    }
    
    node* get(char c){
        return arr[c-'a'];
    }

    void put(char c,node* n){
       arr[c-'a']=n; 
    }

    void increaseEnd() {
        isend++;
    }
    void increasePrefix() {
        ispref++;
    }
    void deleteEnd() {
        isend--;
    }
    void reducePrefix() {
        ispref--;
    }
    int getEnd() {
        return isend;
    } 
    int getPrefix() {
        return ispref;
    }
    
};
class Trie{

    public:
    node* root;

    Trie(){
        root=new node();
    }

    void insert(string &word){
        node* temp=root;
        
        for(auto a:word){
            if(!temp->ispresent(a)){
                node* nn=new node;
                temp->put(a,nn);
            }
            temp=temp->get(a);
            temp->increasePrefix();
        }
        temp->increaseEnd();
    }

    int countWordsEqualTo(string &word)
    {
        node *n = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (n->ispresent(word[i]))
            {
                n = n->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return n->getEnd();
    }


  int countWordsStartingWith(string & word) {
    node * n = root;
    for (int i = 0; i < word.length(); i++) {
      if (n -> ispresent(word[i])) {
        n = n -> get(word[i]);
      } else {
        return 0;
      }
    }
    return n -> getPrefix();
  }

  void erase(string & word) {
    node * n = root;
    for (int i = 0; i < word.length(); i++) {
      if (n -> ispresent(word[i])) {
        n = n -> get(word[i]);
        n -> reducePrefix();
      } else {
        return;
      }
    }
    n -> deleteEnd();
  }

};
