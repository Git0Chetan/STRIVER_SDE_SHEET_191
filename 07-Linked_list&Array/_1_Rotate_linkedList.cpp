//Rotate Linked List
// Given the head of a linked list, rotate the list to the right by k places.

//Leetcode:61  link: https://leetcode.com/problems/rotate-list/description/


#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    //Optimist solution
    ListNode* rotateRight(ListNode* head,int k) {
    if(head == NULL||head->next == NULL||k == 0) return head;
    ListNode* temp = head;
    int length = 1;
    while(temp->next != NULL) {
        ++length;
        temp = temp->next;
    }
    temp->next = head;
    k = k%length;
    int end = length-k;
    while(end--) temp = temp->next;
    head = temp->next;
    temp->next = NULL;
    return head;
}




    //MY first approach:
    //it went right but something complex 😂
    // ListNode* rotateRight(ListNode* head, int k) {
    //     if(head==NULL || k==0){return head;}
    //     ListNode* temp=head;
    //     int size=0;
    //     while(temp){temp=temp->next; size++;}
    //     k=k%size;
    //     if(k==0){return head;}
    //     int t=size-k;
    //     temp=head;
    //     while(--t){
    //         temp=temp->next;
    //     }
    //     ListNode* pre=temp->next;
    //     temp->next=NULL;
    //     ListNode* curr=pre;
    //     while(curr->next!=NULL){
    //         curr=curr->next;
    //     }
    //     curr->next=head;
    //     head=pre;
    //     return head;
    // }
};