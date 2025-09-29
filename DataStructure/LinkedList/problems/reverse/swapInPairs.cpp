//https://leetcode.com/problems/swap-nodes-in-pairs/description/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  ListNode* reverseKGroup(ListNode* head, int k){
    if(!head || k==1) return head;

    ListNode*tmp=head;
    for(int i =0;i<k;i++){
        if(!tmp) return head;
        tmp=tmp->next;
    }

    // reverse 
    ListNode*cur=head;
    ListNode*prev=NULL;
    ListNode*next=NULL;
    int cnt=0;
    while(cur!=NULL && cnt<k){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        cnt++; 
    }

    // after reversing head is the tail in this group
    head->next=reverseKGroup(next,k);

    return prev;
} 

//we can also reverse k groups with value 2 & it works
ListNode* swapPairs(ListNode* head) {
        if(!head || head->next==NULL) return head;

        ListNode*first=head;
        ListNode*second=head->next;
        first->next = swapPairs(second->next);
        second->next=first;
        return second;
    }