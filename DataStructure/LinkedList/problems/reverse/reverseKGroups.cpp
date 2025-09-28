//https://leetcode.com/problems/reverse-linked-list-ii/description/
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode*getKthNode(ListNode*tmp,int k){
    k-=1;
    while(tmp!=NULL && k--)
    {
        tmp=tmp->next;
    }
    return tmp;
}  
 ListNode* reverseList(ListNode* head) {
        ListNode*cur=head;
        ListNode*prev=NULL;
        ListNode*next;
        while(cur!=NULL){
           next=cur->next;
           cur->next=prev;
           prev=cur;
           cur=next;
        }
        return prev;
    }
ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*tmp=head;
        ListNode*prevNode=NULL ; // to catch the  sublist end
        while(tmp!=NULL){
            ListNode*kthNode= getKthNode(tmp,k);// get the kth node
            if(kthNode==NULL) // I'm now can't genarate new k groups 
            {
                if(prevNode) prevNode->next=tmp; // link with the new head
                break;//get out the loop 
            }
            ListNode*nextNode = kthNode->next; // to get the remaining list using the tmp
            
            // let's start our reversing work 
            kthNode->next=NULL;
            // let's call the reverse function to reverse this 
           ListNode*newHead= reverseList(tmp);

            // if it's the first sublist
            if(tmp==head)
            head=newHead;//the new head after the reversal
            else
            prevNode->next=newHead;// connect after reversal

            prevNode=tmp;

            tmp=nextNode;
        }
        return head;
    }

/**
 * go 
 * reverse like normally linked list 
 * repeat with next
 * return the prev guy as it 'll hold the new head 
 */
ListNode* reverseKGroup(ListNode* head, int k){
    if(!head || k==1) return head;

    ListNode*tmp=head;
    for(int i =0;i<k;i++){
        if(!tmp) return head;
        tmp=tmp->next;
    }

    // reverse 
    ListNode*cur=head;
    ListNode*prev=NULL;
    ListNode*next=NULL;
    int cnt=0;
    while(cur!=NULL && cnt<k){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        cnt++; 
    }

    // after reversing head is the tail in this group
    head->next=reverseKGroup(next,k);

    return prev;
}    