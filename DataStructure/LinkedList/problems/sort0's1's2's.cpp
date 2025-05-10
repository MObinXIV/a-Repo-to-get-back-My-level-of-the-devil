//https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1
#include<bits/stdc++.h> 
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
      data = x;
      next = NULL;
  }};
  Node* segregate(Node* head) {
    if (!head || !head->next) return head;
    Node* zeroD = new Node(0);
    Node* oneD = new Node(0);
    Node* twoD = new Node(0);
    
    Node* zero = zeroD;
    Node* one = oneD;
    Node* two = twoD;
    
    Node* curr = head;
    while(curr)
    {
      if(curr->data==0)
      {
        zero ->next=curr;
        zero = zero->next;
      }
      else if (curr->data==1){
        one->next = curr;
            one = one->next;
      }
      else{
        two->next=curr;
        two=two->next;
      }
      curr=curr->next;
    }
    zero->next = (oneD->next) ? oneD->next : twoD->next;
    one->next = twoD->next;
    two->next = NULL;
    Node* newHead = zeroD->next;
    delete zeroD;
    delete oneD;
    delete twoD;
    
    return newHead;
}