// Remove N-th node from the end of a Linked List
// Problem Statement: Given a linked list, and a number N. 
// Find the Nth node from the end of this linked list and delete it. 
// Return the head of the new modified linked list.


//Leetcode:19   link:https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/


#include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//brute force : calculate the length and then delete the nth node:



//OPtimised approach using two pointers 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* slow=head;
        ListNode* fast=head;

        while(n--){
            fast=fast->next;
        }

        if(fast==NULL){
            head=slow->next;
            return head;
        }

        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};

