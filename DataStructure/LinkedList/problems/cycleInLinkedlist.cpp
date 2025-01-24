#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


  // O(n) soltuion

  bool hashCycle(ListNode*head){
    unordered_map<ListNode*,int>mp;
    ListNode*tmp=head;
    while(tmp!=NULL){
     if(mp.find(tmp)!=mp.end()) return true;
     mp[tmp]=1;
     tmp=tmp->next;

    }
    return false;
  }

  /**
   * 
   * if at any moment slow & fast meets this indicates finding a cycle in linkedList
   * 
   */

bool hasCycle(ListNode *head) {
        if(head == NULL || head->next==NULL) return false;

        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
          fast=fast->next->next;
          slow=slow->next;
          if(fast==slow) return true;
        }
        return false;
    }
