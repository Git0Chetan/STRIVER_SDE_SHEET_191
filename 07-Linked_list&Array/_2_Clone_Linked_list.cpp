// Clone Linked List with Random and Next Pointer
// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
// Construct a deep copy of the list.

//Leetcode:138  link: https://leetcode.com/problems/copy-list-with-random-pointer/description/


#include<iostream>
#include<map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    // USing no extra space
//     Node* copyRandomList(Node* head) {
//      Node* temp = head;
//     while(temp != NULL) {
//         Node* newNode = new Node(temp->val);
//         newNode->next = temp->next;
//         temp->next = newNode;
//         temp = temp->next->next;
//     }

//     Node* itr = head;
//     while(itr != NULL) {
//         if(itr->random != NULL)
//             itr->next->random = itr->random->next;
//         itr = itr->next->next;
//     }

//     Node* dummy = new Node(0);
//     itr = head;
//     temp = dummy;
//     Node* fast;
//     while(itr != NULL) {
//         fast = itr->next->next;
//         temp->next = itr->next;
//         itr->next = fast;
//         temp = temp->next;
//         itr = fast;
//     }
//     return dummy->next;
// }

//using hashmap
Node* copyRandomList(Node* head) {
      map<Node*, Node*> m;
        int i=0;
        Node* ptr = head;
        while (ptr) {
            m[ptr] =new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            m[ptr]->next = m[ptr->next];
            m[ptr]->random = m[ptr->random];
            ptr = ptr->next;
        }
        return m[head];
    }
};