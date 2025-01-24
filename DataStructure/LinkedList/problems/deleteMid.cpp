//https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(NULL) {}
  };
  // The idea based on that when fast reaches end slow reaches mid 

ListNode* deleteMiddle(ListNode* head) {
  if (head == nullptr || head->next == nullptr) { 
        return (head == nullptr) ? nullptr : head->next; 
    }
       // when the fast reaches end the slow is in mid 
       ListNode*prev=NULL;
       ListNode*fast=head;
       ListNode*slow=head;
       while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        fast=fast->next->next;
        slow=slow->next;
       }
       prev->next=slow->next;
       slow->next=NULL;
       delete slow;
       return head;
    }