//https://leetcode.com/problems/reorder-list/description/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  
  void reorderList(ListNode* head) {

    if (!head || !head->next) return;

    // go till the middle 
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse second half
    ListNode* cur = slow->next;
    slow->next = NULL; // split into 2 halves
    ListNode* prev = NULL;
    while (cur) {
        ListNode* nex = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nex;
    }

    // merge both halves
    ListNode* p1 = head, *p2 = prev;
    while (p1 && p2) {
        ListNode* next1 = p1->next;
        ListNode* next2 = p2->next;
        p1->next = p2;
        if (!next1) break;
        p2->next = next1;
        p1 = next1;
        p2 = next2;
    }
    }