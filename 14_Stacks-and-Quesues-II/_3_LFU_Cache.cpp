// Design and implement a data structure for a Least Frequently Used (LFU) cache.

// Implement the LFUCache class:

// LFUCache(int capacity) Initializes the object with the capacity of the data structure.
// int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
// void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
// To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

// When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

// The functions get and put must each run in O(1) average time complexity.

//Leetcode: 460  link: https://leetcode.com/problems/lfu-cache/description/


#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class LFUCache {
    
    int capacity;
    int minFreq = -1;
    unordered_map<int, pair<int, int>> keyValFreq;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> keyIterator;
    
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        
        if(keyValFreq.find(key) != keyValFreq.end()){
            
            int freq = keyValFreq[key].second;
            list<int>::iterator it = keyIterator[key]; 
            freqList[freq].erase(it); 
            keyValFreq[key].second++;
            freq++;
            freqList[freq].push_front(key); 
            keyIterator[key] = freqList[freq].begin();
            
            if(freqList[minFreq].size() == 0) minFreq++;
            
            return keyValFreq[key].first; 
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        
        if(capacity == 0 && minFreq == -1) return;
        
        if(keyValFreq.find(key) != keyValFreq.end()){
            keyValFreq[key].first = value;
            int freq = keyValFreq[key].second; 
            list<int>::iterator it = keyIterator[key];
            freqList[freq].erase(it);
            keyValFreq[key].second++;
            freq++;
            freqList[freq].push_front(key);
            keyIterator[key] = freqList[freq].begin();
            if(freqList[minFreq].size() == 0) minFreq++;
            return;
        }
        
        if(capacity == 0){
            int temp = freqList[minFreq].back();
            freqList[minFreq].pop_back();
            keyValFreq.erase(temp);
            keyIterator.erase(temp);
            capacity++;
        }
        
        minFreq = 1;
        keyValFreq[key] = {value, 1};
        freqList[1].push_front(key);
        keyIterator[key] = freqList[1].begin();
        capacity--;
        return;
    }
};
