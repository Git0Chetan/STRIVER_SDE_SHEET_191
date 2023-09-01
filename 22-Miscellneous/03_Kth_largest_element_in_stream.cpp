// Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Implement KthLargest class:

// KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
// int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.


//Leetcode:703 link:https://leetcode.com/problems/kth-largest-element-in-a-stream/description/


#include<iostream>
#include<queue>
using namespace std;

class KthLargest {
public:
    
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int x : nums) {
            pq.push(x);
            if(pq.size() > k) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > K) {
            pq.pop();
        }
        return pq.top();
    }
};

// class KthLargest {
// public:
//     int kk;
//     vector<int>numbers;
//     KthLargest(int k, vector<int>& nums) {
//         kk=k;
//         numbers=nums;
//     }
    
//     int add(int val) {
//         numbers.push_back(val);
//         sort(numbers.begin(),numbers.end());
//         int n=numbers.size();
//         return numbers[n-kk];
//     }
// };

// /**
//  * Your KthLargest object will be instantiated and called as such:
//  * KthLargest* obj = new KthLargest(k, nums);
//  * int param_1 = obj->add(val);
//  */
