// Add two numbers represented as Linked Lists
// Problem Statement: Given the heads of two non-empty linked lists representing two non-negative integers.
// The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers 
// and return the sum as a linked list.


//Leetcode:2  link: https://leetcode.com/problems/add-two-numbers/description/


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry=0;
        ListNode* ans=new ListNode(-1);
        ListNode* res=ans;

        while(l1 && l2){
            int sum=l1->val + l2->val + carry;
            ListNode* temp= new ListNode(sum%10);
            ans->next=temp;
            ans=ans->next;
            carry=sum/10;
            l1=l1->next;
            l2=l2->next;
        }

        while(l1){
            int sum=l1->val + carry;
            ListNode* temp= new ListNode(sum%10);
            ans->next=temp;
            ans=ans->next;
            carry=sum/10;
            l1=l1->next;
        }

        while(l2){
            int sum=l2->val + carry;
            ListNode* temp= new ListNode(sum%10);
            ans->next=temp;
            ans=ans->next;
            carry=sum/10;
            l2=l2->next;
        }

        if(carry>0){
            ListNode* temp= new ListNode(carry);
            ans->next=temp;
            ans=ans->next;
        }

        return res->next;



        //Reducing the above while loops 
        // ListNode *dummy = new ListNode(); 
        // ListNode *temp = dummy; 
        // int carry = 0;
        // while( (l1 != NULL || l2 != NULL) || carry) {
        //     int sum = 0; 
        //     if(l1 != NULL) {
        //         sum += l1->val; 
        //         l1 = l1 -> next; 
        //     }
            
        //     if(l2 != NULL) {
        //         sum += l2 -> val; 
        //         l2 = l2 -> next; 
        //     }
            
        //     sum += carry; 
        //     carry = sum / 10; 
        //     ListNode *node = new ListNode(sum % 10); 
        //     temp -> next = node; 
        //     temp = temp -> next; 
        // }
        // return dummy -> next; 

    }
};