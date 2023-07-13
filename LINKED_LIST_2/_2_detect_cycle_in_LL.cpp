// Detect a Cycle in a Linked List
// Problem Statement: Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
// Return true if there is a cycle in the linked list. Otherwise, return false.


//Leetcode:141  link: https://leetcode.com/problems/linked-list-cycle/description/


#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    //Using hashtable(set)
    // bool hasCycle(ListNode *head) {
    //     if(head==NULL){return 0;}
    //     unordered_set<ListNode*>ss;
    //     ListNode* l1=head;
    //     while(l1){
    //         if(ss.find(l1)!=ss.end()){
    //             return 1;
    //         }
    //         ss.insert(l1);
    //         l1=l1->next;
    //     }
    //     return 0;
    // }


    //using two Pointers (slow & fast)
    bool hasCycle(ListNode *head){
        if(head==NULL){
            return false;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
    
};