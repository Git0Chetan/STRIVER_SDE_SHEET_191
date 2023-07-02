// Check if given Linked List is Plaindrome
// Check if the given Linked List is Palindrome
// Problem Statement: Given the head of a singly linked list, return true if it is a palindrome.

//Leetcode:234   link: https://leetcode.com/problems/palindrome-linked-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//using stl
// class Solution {
// public:
//     bool isPalindrome(ListNode* head){
//         vector<int>a;
//         while(head!=NULL){
//             a.push_back(head->val);
//             head=head->next;
//         }

//         vector<int>b=a;

//         reverse(a.begin(),a.end());
//         return a==b;
//     }
// };


// //using bruteforce
// class Solution {
// public:
//     bool isPalindrome(ListNode* head){
//         vector<int>a;
//         while(head!=NULL){
//             a.push_back(head->val);
//             head=head->next;
//         }
//         for(int i=0;i<a.size()/2;i++){
//             if(a[i] != a[a.size()-i-1]) return false;
//         }
//         return true;   
//     }
// };


//optimised solution
// class Solution {
// public:
//     ListNode* reverse(ListNode* ptr) {
//         ListNode* pre=NULL;
//         ListNode* nex=NULL;
//         while(ptr!=NULL) {
//             nex = ptr->next;
//             ptr->next = pre;
//             pre=ptr;
//             ptr=nex;
//         }
//         return pre;
//     }

//     bool isPalindrome(ListNode* head) {
//         if(head==NULL||head->next==NULL) return true;
            
//         ListNode* slow = head;
//         ListNode* fast = head;
            
//         while(fast->next!=NULL&&fast->next->next!=NULL) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
            
//         slow->next = reverse(slow->next);
//         slow = slow->next;
//         ListNode* dummy = head;
            
//         while(slow!=NULL) {
//             if(dummy->val != slow->val) return false;
//             dummy = dummy->next;
//             slow = slow->next;
//         }
//         return true;
//     }
// };