// Delete given node in a Linked List : O(1) approach
// Problem Statement: Write a function to delete a node in a singly-linked list.
// You will not be given access to the head of the list instead, you will be given access to the node to be deleted directly.
// It is guaranteed that the node to be deleted is not a tail node in the list.

//leetcode: 237   link:https://leetcode.com/problems/delete-node-in-a-linked-list/description/

#include<iostream>
using namespace std;
#include<vector>


//Time complexity O(1):
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};

