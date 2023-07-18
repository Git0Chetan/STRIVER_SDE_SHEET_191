// Implement a last-in-first-out (LIFO) stack using only two queues. 
// The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

// Implement the MyStack class:

// void push(int x) Pushes element x to the top of the stack.
// int pop() Removes the element on the top of the stack and returns it.
// int top() Returns the element on the top of the stack.
// boolean empty() Returns true if the stack is empty, false otherwise.


//Leetcode: 225  link: https://leetcode.com/problems/implement-stack-using-queues/description/

#include<iostream>
#include<queue>
using namespace std;

//Using Single Queue
class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int siz=q.size();
        while(siz>1){
            siz--;
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int num=q.front();
        q.pop();
        return num;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};




// //Using two Queues
// class MyStack {
// public:
//     queue<int>q;
//     int top1=0;

//     MyStack() { 
//     }

//     void push(int x) {
//         q.push(x);
//         top1=x;
//     }
    
//     int pop() {
//         queue<int>q1;
//         while(q.size()!=1){
//             top1=q.front();
//             q1.push(q.front());
//             q.pop();
//         }
//         int num=q.front();
//         q=q1;
//         return num;
//     }
    
//     int top() {
//         return top1;
//     }
    
//     bool empty() {
//         return q.empty();
//     }
// };
