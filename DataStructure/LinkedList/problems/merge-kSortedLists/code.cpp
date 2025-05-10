//https://leetcode.com/problems/merge-k-sorted-lists/description/
#include <bits/stdc++.h>
using namespace std;
  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

//O(nlogn),O(k)
ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;
        // get all the values sorted inside pq 
        for(auto v:lists)
        {
            ListNode*tmp=v;
            while(tmp!=NULL)
            {
                pq.push(tmp->val);
                tmp=tmp->next;
            }
        }
         ListNode* dummy = new ListNode(0);
         ListNode* cur = dummy;

    // Step 3: Pop values from min-heap and create new nodes in sorted order
        while (!pq.empty()) {
            cur->next = new ListNode(pq.top()); // Create new node from top value
            pq.pop();
            cur = cur->next; // Move to the newly added node
    }
        return dummy->next;
    }

    ListNode*merge2Lists(ListNode*l1,ListNode*l2)
    {
        ListNode*dummy=new ListNode(0);
        ListNode*tmp = dummy;
        while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                tmp->next=l1;
                l1=l1->next;
            }
            else{
                tmp->next=l2;
                l2=l2->next;
            }
            tmp=tmp->next;
        }
        // Attach remaining nodes (only one of these will be non-null)
    tmp->next = l1 ? l1 : l2;

    return dummy->next;
    }
ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        while(lists.size()>1){
            vector<ListNode*> mergedLists;
            // keep merging the pairs 
            for(int i = 0 ; i<lists.size();i+=2)
            {
                if(i+1<lists.size())
                mergedLists.push_back(merge2Lists(lists[i],lists[i+1]));
                else
                mergedLists.push_back(lists[i]);
            }
            // update the lists
            lists=mergedLists;
        }

        return lists[0];
    }