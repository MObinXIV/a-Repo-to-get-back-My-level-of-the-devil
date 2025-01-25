//https://leetcode.com/problems/merge-two-sorted-lists/description/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2!=NULL) return list2;
        if(list2==NULL && list1!=NULL) return list1;
        if(list1==NULL && list2==NULL) return NULL;
        ListNode*p1=list1;
       ListNode*p2=list2;
       ListNode* dummy= new ListNode();
       ListNode*ret= dummy;
       while(p1!=NULL && p2!=NULL){
          if(   p1->val < p2->val)
          {
            dummy->next=new ListNode(p1->val);
            dummy=dummy->next;
            p1=p1->next;
          }
          else {
             dummy->next=new ListNode(p2->val);
            dummy=dummy->next;
            p2=p2->next;
          }
       }

       while(p1!=NULL){
        dummy->next= new ListNode(p1->val);
        p1=p1->next;
        dummy=dummy->next;
       }
       while(p2!=NULL){
        dummy->next= new ListNode(p2->val);
        p2=p2->next;
        dummy=dummy->next;
        
       }
       return ret->next;
    }