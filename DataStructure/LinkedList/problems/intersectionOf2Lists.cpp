//https://leetcode.com/problems/intersection-of-two-linked-lists/description/
#include<bits/stdc++.h> 
 using namespace std;

 struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
     };

     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        unordered_map<ListNode*,int>mp;
        ListNode*tmp= headA;
        while(tmp!=NULL){
            mp[tmp]=1;
            tmp=tmp->next;
        }
        tmp=headB;
        while(tmp!=NULL){
            if(mp.find(tmp)!=mp.end()) return tmp;
            tmp=tmp->next;
        }
        return NULL;
     }
     int getDifference(ListNode*h1,ListNode*h2){
        int cnt1 =0 , cnt2=0;
        while(h1!=NULL || h2!=NULL){
           if(h1!=NULL){
            ++cnt1;
            h1=h1->next;
           }
           if(h2!=NULL)
           {
            ++cnt2;
            h2=h2->next;
           }
           
        }
        return cnt1-cnt2;
     }

     // force to start in the same postion solutoin
     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        ListNode*h1 = headA;
        ListNode*h2= headB;
        int diff = getDifference(h1,h2);
        // means h2 is longer 
        if(diff<0)
            // so we need to move the pointer in the second list by diff postions 
            while(diff++!=0) h2=h2->next;

        else while(diff--!=0) h1=h1->next;

        while(h1!=NULL)
        {
            if(h2==h1) return h1;
            h1=h1->next;
            h2=h2->next;
        }
        return h1;
     }

     /*
     - Optimal solution 
     - we keep moving the 2 pointers 
     - once one of them reach the end 
     - we postion him in the beginning position of the other guy 
     - in some step they 'll meet 
     */

     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode*h1=headA;
        ListNode*h2=headB;
        // tell they eqaul 
        while(h1!=h2){
            h1= h1==NULL ? headB : h1->next;
            h2 = h2 == NULL ? headA : h2->next;
        }
        return h1;
     }

 