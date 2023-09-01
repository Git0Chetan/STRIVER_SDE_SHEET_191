// //Find Median in an Running Stream of nums
// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:

// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.


//Leetcode:295  link: https://leetcode.com/problems/find-median-from-data-stream/description/


#include<iostream>
#include<queue>
using namespace std;


class MedianFinder {
public:
    priority_queue<int>maxi;
    priority_queue<int,vector<int>,greater<int> >mini;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxi.push(num);
        mini.push(maxi.top());
        maxi.pop();
        if(mini.size()>maxi.size()){
            maxi.push(mini.top());
            mini.pop();
        }
    }
    
    double findMedian() {
        if(maxi.size()==mini.size()){
            float ans= (maxi.top()+mini.top())/2.0;
            return ans;
        }
        return maxi.top();
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
