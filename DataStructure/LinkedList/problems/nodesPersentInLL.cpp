//https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());  // nums = set(nums)
    ListNode* dummy = new ListNode(0, head);         // dummy = ListNode(next=head)
    ListNode* cur = dummy;

    while (cur->next) { 
        // in case the next node counts we keep removing                             
        if (s.count(cur->next->val)) {              
            cur->next = cur->next->next; 
        } 
        // other way we move 
        else {
            cur = cur->next;                         
        }
    }

    return dummy->next; 
    }