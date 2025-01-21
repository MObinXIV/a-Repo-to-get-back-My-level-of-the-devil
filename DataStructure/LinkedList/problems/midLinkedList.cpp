//https://leetcode.com/problems/middle-of-the-linked-list/description/
#include<bits/stdc++.h>
using namespace std;
//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  // Brute force O(n) solution
class Solution {
    int size;
    
public:
    Solution(){
    
        size=0;
    }
    int get_size(ListNode* head){
        while(head!=NULL) {size++;head=head->next;}
        return size;
    }
    ListNode* middleNode(ListNode* head) {
        int s= this->get_size(head);
        int i =0; 
        ListNode*tmp=head;
        while(i<s/2){
            tmp=tmp->next;
            i++;
        }
        return tmp;
    }
};

// Tortoise & hare algorithm 
//O(n/2)
ListNode* middleNode(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL &&fast->next!=NULL){
           
            slow=slow->next;
             fast=fast->next->next;
        }
        return slow;
    }
