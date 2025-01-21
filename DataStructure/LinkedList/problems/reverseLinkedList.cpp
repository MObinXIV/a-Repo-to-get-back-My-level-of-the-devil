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

