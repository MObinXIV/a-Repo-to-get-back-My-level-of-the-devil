//https://leetcode.com/problems/reverse-linked-list/description/
#include<bits/stdc++.h>
using namespace std;
//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  ListNode* reverseList(ListNode* head) {
        ListNode*cur=head;
        ListNode*prev=NULL;
        ListNode*nex;
        while(cur!=NULL){
           nex=cur->next;
           cur->next=prev;
           prev=cur;
           cur=nex;
        }
        return prev;

    }

    // Calling the recursion function till I reach one node or Null 
// storing it's value to return it 
// keep reversing the the links by making the front guy (the node of the previous call ) points to the currnet guy
// & making current guy points to null
ListNode* reverseList(ListNode* head) {
    // get my last node as the new Head
       if(head==NULL||head->next==NULL) return head;

        ListNode*newHead=reverseList(head->next);
        ListNode*front=head->next; // get the previous guy node 
        // linking it reverserly to the current node 
        front->next=head;
        // making the currnet guy points to null as we go to end will points to null by default 
        head->next=NULL;

        // return the newHead node 
        return newHead;
    }

