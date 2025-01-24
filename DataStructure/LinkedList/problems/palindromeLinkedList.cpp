//https://leetcode.com/problems/palindrome-linked-list/description/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

 bool isPalindromeStack(ListNode* head){
      stack<int>st;
      ListNode*tmp=head;
      while(tmp!=NULL){
        st.push(tmp->val);
        tmp=tmp->next;
      }
      tmp=head;
      while(tmp!=NULL){
        if(st.top()!=tmp->val) return false;
        st.pop();
        tmp=tmp->next;
      }
      return true;
    }

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
  /**
   * the idea is to reach the mid 
   * reverse it 
   * combare the reversed right half with the unreversed left half  
   */
bool isPalindrome(ListNode* head) {
       ListNode*slow=head;
       ListNode*fast=head;
       // My mission here is to postion the slow guy in the middle-1 
       while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
       }
       ListNode*reveHalf=reverseList(slow);
       ListNode*leftHalf=head;
       while(reveHalf!=NULL){
        if(reveHalf->val!=leftHalf->val) return false;
        reveHalf=reveHalf->next;
        leftHalf=leftHalf->next;
       }
       return true;

    }