//https://leetcode.com/problems/remove-nodes-from-linked-list/description/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  // return all the nodes which have no next greater than it 
ListNode* removeNodes(ListNode* head) {
        //[5,2,13,3,8]
        ListNode*cur= head;
        stack<ListNode*>st;
        while(cur){
            while(!st.empty()&&st.top()->val <cur->val)st.pop();
            st.push(cur);
            cur=cur->next;
        }
        ListNode*next=NULL;
        while(!st.empty()){
            st.top()->next=next;
            next=st.top();
            st.pop();
        }
        return next;
    }

 ListNode* removeNodes(ListNode* head) {

    if(head==NULL ||head->next==NULL){
        return head;
    }
    
    ListNode*nextNode = removeNodes(head->next);

    // case the right node is bigger than the current node 
    if(nextNode->val>head->val)
    {
        // we don't return the current one as it's not valid , we return only the next one 
        return nextNode;
    }

    // in case not we join 
    head->next=nextNode;
    return head;
 }  