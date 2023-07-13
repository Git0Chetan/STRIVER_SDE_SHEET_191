// Find intersection of Two Linked Lists
// Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. 
// If the two linked lists have no intersection at all, return null.

//Leetcode:160  link:https://leetcode.com/problems/intersection-of-two-linked-lists/


#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    //Using Brute force Approach
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode* l1=headA;
    //     ListNode* l2=headB;
    //     while(l1){
    //         while(l2){
    //             if(l1==l2){
    //                 return l1;
    //             }
    //             l2=l2->next;
    //         }
    //         l2=headB;
    //         l1=l1->next;
    //     }
    //     return NULL;
    // }


    //Using hashMap
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    //     unordered_set<ListNode*>s;
    //     ListNode* l1=headA;
    //     ListNode* l2=headB;
    //     while(l1){
    //         s.insert(l1);
    //         l1=l1->next;
    //     }
    //     while(l2){
    //         if(s.find(l2)!=s.end()){
    //             return l2;
    //         }
    //         l2=l2->next;
    //     }
    //     return NULL;
    // }


    //using calculating the difference
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    //     ListNode* l1=headA;
    //     ListNode* l2=headB;
    //     int d1=0,d2=0;
    //     while(l1 || l2){
    //         if(l1){
    //             d1++;
    //             l1=l1->next;
    //         }
    //         if(l2){
    //             d2++;
    //             l2=l2->next;
    //         }
    //     }
    //     l1=headA;
    //     l2=headB;
    //     int diff=d1-d2;
    //     if(diff < 0) 
    //         while(diff++ != 0) l2 = l2->next; 
    //     else while(diff-- != 0) l1 = l1->next;

    //     while(l1 != NULL) {
    //         if(l1 == l2) return l1;
    //         l2 = l2->next;
    //         l1 = l1->next;
    //     }
    //     return l1;
    // }


    //optimised solution
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        ListNode* l1=headA;
        ListNode* l2=headB;

        while(l1!=l2){
            l1=l1==NULL?headB:l1->next;
            l2=l2==NULL?headA:l2->next;
        }
        return l1;
    }
};