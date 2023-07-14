// Reverse Linked List in groups of Size K
// Problem Statement: Given the head of a linked list, reverse the nodes of the list k at a time, 
// and return the modified list. k is a positive integer and is less than or equal to the length of the 
// linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

//Leetcode:25  link: https://leetcode.com/problems/reverse-nodes-in-k-group/description/



#include<iostream>
#include<stack>
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
    //Using stack and using O(n)extra space
    //ListNode* reverseKGroup(ListNode* head, int k) {
    //     if(k==1 || head==NULL){return head;}
    //     ListNode* l1=head;
    //     while(l1){
    //         stack<int>v;
    //         int kk=k;
    //         ListNode* temp=l1;
    //         while(kk-- && temp){
    //             v.push(temp->val);
    //             temp=temp->next;
    //         }
    //         if(kk>=0){
    //             break;
    //         }
    //         while(!v.empty()){
    //             l1->val=v.top();
    //             l1=l1->next;
    //             v.pop();
    //         }
    //     }
    //     return head;
    // }

    //Using no extra space
    ListNode* reverseKGroup(ListNode* head,int k) {
    if(head == NULL||head->next == NULL) return head;
    int length=0;
    ListNode* temp=head;
    while(temp){
        length++;
        temp=temp->next;
    }
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    
    ListNode* pre = dummyHead;
    ListNode* cur;
    ListNode* nex;
    
    while(length >= k) {
        cur = pre->next;
        nex = cur->next;
        for(int i=1;i<k;i++) {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        length -= k;
    }
    return dummyHead->next;
    }
};