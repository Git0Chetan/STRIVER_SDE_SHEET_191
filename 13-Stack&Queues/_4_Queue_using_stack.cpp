// Implement Queue using Stack
// Problem Statement: Given a Stack having some elements stored in it. Can you implement a
// Queue using the given Stack?
// Queue: A Queue is a linear data structure that works on the basis of FIFO(First in First out). This means the element added at first will be removed first from the Queue.


//Leetcode:232   link: https://leetcode.com/problems/implement-queue-using-stacks/description/

#include<iostream>
#include<stack>
using namespace std;

//Optimised T.C. O(1) || O(n)
class MyQueue {
public:
    stack<int>input;
    stack<int>output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty()){
            while(input.size()){
                output.push(input.top());
                input.pop();
            }
        }
        int num=output.top();
        output.pop();
        return num;
    }
    
    int peek() {
        if (output.empty())
            while (input.size())
            output.push(input.top()), input.pop();
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};







//Using two stack approach
//Push operation can be O(N) as well O(1);
// class MyQueue {
// public:
//     stack<int>s1;
//     stack<int>s2;
//     MyQueue() {
        
//     }
//     void push(int x) {
//         while(!s1.empty()){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s1.push(x);
//         while(!s2.empty()){
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }
    
//     int pop() {
//         int v=s1.top();
//         s1.pop();
//         return v;
//     }
    
//     int peek() {
//         return s1.top();
//     }
    
//     bool empty() {
//         return s1.empty();
//     }
// };
