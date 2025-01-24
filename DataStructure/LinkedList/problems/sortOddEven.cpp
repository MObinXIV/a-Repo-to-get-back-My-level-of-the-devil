//https://leetcode.com/problems/odd-even-linked-list/description/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

// The idea is simple we move pointer the the odd indexes & other to even indexes , position head of even 
// link by it 

// O(n) solution
  ListNode* oddEvenList(ListNode* head) {
    // EdgeCase 
      if (head == nullptr || head->next == nullptr) {
        return head; 
    }
        
        ListNode*oddTmp=head;
        ListNode*evenTmp=head->next;
        // store the head of the even index  
        ListNode*tmpEven = evenTmp;
        while(oddTmp->next && evenTmp->next){
          oddTmp->next=oddTmp->next->next;
          evenTmp->next=evenTmp->next->next;
          oddTmp=oddTmp->next;
          evenTmp=evenTmp->next;
        }
        oddTmp->next=tmpEven;
        return head;
    }