
// Find middle element in a Linked List
// Problem Statement: Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.
//Leetcode:31   link:https://leetcode.com/problems/middle-of-the-linked-list/submissions/980923716/



//efficient way
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* slow=head;
//         ListNode* fast=head;

//         while(fast!=NULL && fast->next!=NULL){
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         return slow;
//     }
// };



//Brute force approach
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         if(head==NULL){
//             return head;
//         }
        
//         int si=1;
//         ListNode* temp=head;
//         while(temp->next!=NULL){
//             si++;
//             temp=temp->next;
//         }
//         int s1=si/2;
//         ListNode* temp1=head;
//         while(s1 > 0){
//             temp1=temp1->next;
//             s1--;
//         }
//         return temp1;
//     }
// };