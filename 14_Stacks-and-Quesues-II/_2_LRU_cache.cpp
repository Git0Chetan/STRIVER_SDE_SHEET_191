// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.



//leetcode:146   https://leetcode.com/problems/lru-cache/description/


#include<iostream>
#include<unordered_map>
using namespace std;

class LRUCache {
  public:
    class node {
      public:
        int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };

  node * head = new node(-1, -1);
  node * tail = new node(-1, -1);

  int cap;
  unordered_map < int, node * > m;

  LRUCache(int capacity) {
    cap = capacity;
    head -> next = tail;
    tail -> prev = head;
  }

  void addnode(node * newnode) {
    node * temp = head -> next;
    newnode -> next = temp;
    newnode -> prev = head;
    head -> next = newnode;
    temp -> prev = newnode;
  }

  void deletenode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }

  int get(int key_) {
    if (m.find(key_) != m.end()) {
      node * resnode = m[key_];
      int res = resnode -> val;
      m.erase(key_);
      deletenode(resnode);
      addnode(resnode);
      m[key_] = head -> next;
      return res;
    }

    return -1;
  }

  void put(int key_, int value) {
    if (m.find(key_) != m.end()) {
      node * existingnode = m[key_];
      m.erase(key_);
      deletenode(existingnode);
    }
    if (m.size() == cap) {
      m.erase(tail -> prev -> key);
      deletenode(tail -> prev);
    }

    addnode(new node(key_, value));
    m[key_] = head -> next;
  }
};




// using stl
// class LRUCache
// {
//     public:
//         list<pair<int,int>> l;
//         unordered_map<int,list<pair<int, int>>::iterator> m;
//         int size;
//         LRUCache(int capacity)
//         {
//             size=capacity;
//         }
//         int get(int key)
//         {
//             if(m.find(key)==m.end())
//                 return -1;
//             l.splice(l.begin(),l,m[key]);
//             return m[key]->second;
//         }
//         void put(int key, int value)
//         {
//             if(m.find(key)!=m.end())
//             {
//                 l.splice(l.begin(),l,m[key]);
//                 m[key]->second=value;
//                 return;
//             }
//             if(l.size()==size)
//             {
//                 auto d_key=l.back().first;
//                 l.pop_back();
//                 m.erase(d_key);
//             }
//             l.push_front({key,value});
//             m[key]=l.begin();
//         }
// };