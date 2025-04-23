//https://leetcode.com/problems/add-two-numbers/description/
#include<bits/stdc++.h> 
 using namespace std;

  struct ListNode {
      int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*dummyNode= new ListNode();
        // handle if the one of the 2 linked lists is bigger than the other one 
        ListNode*h1=l1,*h2=l2;
        
    
        ListNode *mov= dummyNode;
        int remainder=0;
        while(l1!=NULL || l2!=NULL){
           int sum =0 ; 
           // get the value of the first node if it's exist 
           if(l1!=NULL)
           {
            sum+=l1->val;
            l1=l1->next;
           }
           if(l2!=NULL)
           {
            sum+=l2->val;
         l2 = l2->next;
           }
           sum+=remainder;
           remainder = sum/10;
           // get the single number inside the node 
           ListNode*nodeValue= new ListNode(sum%10);
           mov->next = nodeValue;
           mov=mov->next;
        }

        // Check if there still node to be add 
        if (remainder > 0) {
            mov->next = new ListNode(remainder);
        }
        return dummyNode->next;

 }