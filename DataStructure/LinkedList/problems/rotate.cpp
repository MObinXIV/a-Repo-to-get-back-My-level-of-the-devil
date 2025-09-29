//https://leetcode.com/problems/rotate-list/description/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        int sizeOfList=0;
        ListNode*cur=head;
        while(cur!=NULL){
            cur=cur->next;
            sizeOfList++;
        }
        // here we need no change
        if(k%sizeOfList==0) return head;
        int numOfLoops=sizeOfList- k%sizeOfList;
        cur=head;
        while(--numOfLoops){
            cur=cur->next;
        }
        ListNode*newHead = cur->next;
        cur->next=NULL;
        ListNode*tail=newHead;
        while(tail->next!=NULL) tail=tail->next;
        tail->next=head;
        head=newHead;
        return head;
    }