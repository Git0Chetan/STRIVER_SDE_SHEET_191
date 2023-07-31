// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.


//leetcode: 23 link: https://leetcode.com/problems/merge-k-sorted-lists/description/
//gfg : similar-array link:https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

#include<iostream>
#include<queue>
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
    struct compare
    {
        bool operator()(ListNode* &a,ListNode* &b)
        {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare>minh;
        for(int i=0;i<lists.size();i++)
        {
           if(lists[i]!=NULL) minh.push(lists[i]);
        }
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        while(minh.size()>0)
        {
            ListNode* p=minh.top();
            minh.pop();
            temp->next=new ListNode(p->val);
            temp=temp->next;
            if(p->next!=NULL) minh.push(p->next);
        }
        return head->next;
    }
};






//love babbar trick

// class Compare {
// public:
//     bool operator()(ListNode* a, ListNode* b)
//     {
//         return a->val < b->val;
//     }
// };

// class Solution {
// public:

//     // static bool compare(const ListNode* a, const ListNode* b){
//     //     return a->val > b->val;
//     // }

//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         priority_queue<ListNode*,vector<ListNode*>,Compare>min_heap;
//         int k=lists.size();
//         if(k==0){
//             return NULL;
//         }

//         for(int i=0;i<k;i++){
//             if(lists[i]!=NULL){
//                 min_heap.push(lists[i]);
//             }
//         }


//         ListNode* head=NULL;
//         ListNode* tail=NULL;

//         while(min_heap.size()>0){
//             ListNode* top=min_heap.top();
//             min_heap.pop();

//             if(top->next!=NULL){
//                 min_heap.push(top->next);
//             }

//             if(head==NULL){
//                 head=top;
//                 tail=top;
//             }
//             else{
//                 tail->next=top;
//                 tail=top;
//             }
//         }
    
//         tail->next=NULL;
//         return head;
//     }
// };




// -------- gfg array
// class Solution
// {
//     public:
    //using priority queue;
    // vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    // {
    //     priority_queue<int,vector<int>,greater<int>>q;
    //     for(int i=0;i<k;i++){
    //         for(int j=0;j<arr[i].size();j++){
    //             q.push(arr[i][j]);
    //         }
    //     }
    //     vector<int>qv;
    //     for(int m=0;m<q.size();m++){
    //         qv.push_back(q.top());
    //         q.pop();
    //     }
    //     return qv;
    // }
// };



//using merge sort concept---------

// void merge(vector<int>&ans,vector<int>temp){
//     vector<int>res;
//     int m=ans.size();
//     int n=temp.size();
//     int i=0;
//     int j=0;
//     while(i<m && j<n){
//         if(ans[i]<=temp[j]){
//             res.push_back(ans[i]);
//             i++;
//         }
//         else{
//             res.push_back(temp[j]);
//             j++;
//         }
//     }

//     while(i<m){
//         res.push_back(ans[i]);
//         i++;
//     }
//     while(j<n){
//         res.push_back(temp[j]);
//         j++;
//     }
//     ans=res;
// }

// vector<int> mergeKArrays(vector<vector<int>>&arr, int k)
// {
//     vector<int>a=arr[0];
//     for(int i=1;i<k;i++){
//         merge(a,arr[i]);
//     }

//     return a;
// }
