// Merge two sorted Linked Lists
// Problem Statement: Given two singly linked lists that are sorted in increasing 
// order of node values, merge two sorted linked lists and return them as a sorted list. 
// The list should be made by splicing together the nodes of the first two lists.

//Leetcode:21   link: https://leetcode.com/problems/merge-two-sorted-lists/solutions/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {


        if(list1 == NULL) return list2; 

        if(list2 == NULL) return list1;

        if(list1->val > list2->val) std::swap(list1,list2);

        ListNode* res = list1;

        while(list1 != NULL && list2 != NULL) {
 
            ListNode* temp = NULL;

            while(list1 != NULL && list1->val <= list2->val) {

                temp = list1;  
                list1 = list1->next;
            }

            temp->next = list2;
            swap(list1,list2);
        }

        return res;


        //using stl and vector
        // vector<int> vec;
        // while(list1) {
        //     vec.push_back(list1->val);
        //     list1=list1->next;
        // }
        // while(list2) {
        //     vec.push_back(list2->val);
        //     list2=list2->next;
        // }
        // sort(vec.begin(),vec.end());
        // ListNode* result=new ListNode(-1);
        // ListNode* temp=result;

        // for(int i=0; i<vec.size(); i++) {
            //result->next=new ListNode(vec[i]);
            //result=result->next;
        // }
        // return temp->next;
    }
};