// https://leetcode.com/problems/linked-list-cycle-ii/description/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  //O(n) solution
ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next==NULL) return NULL;
         unordered_map<ListNode*,int>mp;
    ListNode*tmp=head;
    while(tmp!=NULL){
     if(mp.find(tmp)!=mp.end()) return tmp;
     mp[tmp]=1;
     tmp=tmp->next;

    }
    return NULL;

    }


  /**
   * 
   * if at any moment slow & fast meets this indicates finding a cycle in linkedList
   * 
   */

//O(n)
ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next==NULL) return NULL;

        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
          fast=fast->next->next;
          slow=slow->next;
          // Keep start standing in the collsion postition
          if(fast==slow) // Hered I detect there's a cycle but I'mnot sure it's the first occurence to cycle
          {
            slow=head;
            while(slow!=fast){
              slow = slow->next;
              fast=fast->next;
            }
            return slow;
          }
        }
        return NULL;
    }
