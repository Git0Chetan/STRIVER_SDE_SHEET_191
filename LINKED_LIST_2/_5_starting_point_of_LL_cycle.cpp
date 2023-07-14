// Starting point of loop in a Linked List
// Problem Statement: Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
//Internally, pos is used to denote the index of the node that the tail’s next pointer is connected to (0-indexed). It is -1 if there is no cycle.
// Note that pos is not passed as a parameter.
// Do not modify the linked list.


//Leetcode :142   link: https://leetcode.com/problems/linked-list-cycle-ii/


#include<iostream>
#include<set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                break;
            }
        }
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }
        ListNode *ptr1 = head;
        ListNode *ptr2 = slow;
        while (ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr1;
    }


    //using extra memory i.e.hashmap
    // ListNode* detectCycle(ListNode* head) {
    //     unordered_set<LisNode*> st;
    //     while(head != NULL) {
    //         if(st.find(head) != st.end()) return head;
    //         st.insert(head);
    //         head = head->next;
    //     }
    //     return NULL;
    // }

};