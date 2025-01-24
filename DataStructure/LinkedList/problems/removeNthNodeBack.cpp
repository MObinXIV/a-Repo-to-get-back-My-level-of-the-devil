//https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

// Our goal is to reach the prev node before the node we wanna deleting
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(NULL) {}
  };

//O(n) solution
ListNode* removeNthFromEnd(ListNode* head, int n) {
        // getting the list size;
        int s = 0 ; 
        ListNode*tmp=head;
        while(tmp!=NULL) {
          s++;
          tmp=tmp->next;
        }

        int realSize= s-n;
        // if I wanna delete the head node 
       if(realSize==0) return head->next;
       tmp=head;
       ListNode*prev=NULL;
       while(realSize>0){
        prev=tmp;
        tmp=tmp->next;
        realSize--;
       }
       prev->next=tmp->next;
       tmp->next-NULL;
       delete tmp;
       return head;
        
    }
ListNode* removeNthFromEnd(ListNode* head, int n){
  // let's use dummy to move 
  ListNode*dummy=new ListNode();
  dummy->next=head;// linking it with head 
   ListNode*fast=dummy;
   ListNode*slow=dummy;
   int i =0; 
   // position fast in the n postion from front
   // I do move nth steps as I wann get s-n using the next loop
   while(i<n){
    fast=fast->next;
    i++;
   }

    // move s-n steps using fast pointer 
    // this will position slow in the position of prev value 
   // let's postion it from back using fast
   while(fast->next!=NULL){
    fast=fast->next;
    slow=slow->next;
   }

   // now we position slow in the position before our deletion node;
   ListNode* delNode=slow->next;
   slow->next=slow->next->next;
   delete delNode;
   return dummy->next;

   
}
