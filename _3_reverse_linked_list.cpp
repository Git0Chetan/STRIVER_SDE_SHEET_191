// Question:
// Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.
// Leetcode:206

#include<iostream>
using namespace std;
#include<vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x){
        val=x;
        next=NULL;
    }
};

//Approach 1
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;
        while (head != NULL) {
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }
};

//Approach 2
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* temp=head;
        vector<int>v;

        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            temp->val=v.back();
            v.pop_back();
            temp=temp->next;
        }
        return head;
    }
};

void display(ListNode* head){
    ListNode* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" -> ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    ListNode* head=new ListNode(5);
    head->next=new ListNode(6);
    head->next->next=new ListNode(7);
    head->next->next->next=new ListNode(8);
    head->next->next->next->next=new ListNode(9);
    head->next->next->next->next->next=new ListNode(10);
    cout<<"Initial Linked list"<<endl;
    display(head);

    cout<<"Reverse Linked list approach 1"<<endl;
    Solution1* ans=new Solution1();
    head=ans->reverseList(head);
    display(head);

    cout<<"Reverse Linked list approach 2"<<endl;
    Solution2* ans1=new Solution2();
    head=ans1->reverseList(head);
    display(head);

}