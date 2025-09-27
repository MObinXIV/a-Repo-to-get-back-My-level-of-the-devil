//https://leetcode.com/problems/reverse-linked-list-ii/description/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(!head || left==right) return head;
        ListNode*dummyNode = new ListNode(0);
        dummyNode->next=head;
        int pos=1;
        // Step.1: move to beforeLeft
        ListNode*beforeLeft=dummyNode;
        while(pos<left){
            beforeLeft=beforeLeft->next;
            pos++;
        }

        // step.2: cut the sublist
        ListNode*leftNode= beforeLeft->next;
        ListNode*rightNode=leftNode;
        while(pos<right){
            rightNode=rightNode->next;
            pos++;
        }
        ListNode*afterRight=rightNode->next;

        //step.3: disconnect & reverse
        // separate the sublist
        rightNode->next=NULL;
        ListNode*prev=NULL;
        ListNode*cur=leftNode;
        // normal reversal as we separated the list 
        while(cur!=NULL){
            ListNode*next= cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
    beforeLeft->next=prev;
    leftNode->next=afterRight;

    return dummyNode->next;
    }