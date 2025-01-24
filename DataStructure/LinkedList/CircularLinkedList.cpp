// Circular Linked List
#include<bits/stdc++.h>
using namespace std;

template <typename T>
struct Node {
  T date;
  Node*next;
  Node (T&val):data(val),next(NULL){}
};

template <typename T>
class CircularLinkedList{

private:
Node<T>*head;
int size;
public:
CircularLinkedList():head(NULL),size(0){}
~CircularLinkedList(){
clear();
}
void clear(){
  while(head!=NULL){
    Node<T*>tmp=head;
    head=head->next;
    delete head;
  }
  size=0;
}
/*
*If the list is empty, sets head to the new node and makes it point to itself (creating a circular link).
*If the list is not empty, finds the last node and makes it point to the new node. The new node then points to the head.
*/
void insertBack(T&value){
Node*newNode=new Node(value);
if(head==NULL) {
  head=newNode;
  newNode->next=head;
}
else{
  Node<T*>cur=head;
  while (cur->next!=head){
    cur=cur->next;
  }
  cur->next=newNode;
  newNode->next=head;
}
size++;
}

void insertBack(T&val){
Node<T*>newNode= new Node(val);
if(head==NULL){
  head=newNode;
  newNode->next=head;
}

else{
  Node<T*>tmp=head;
  while(tmp->next!=head){
    tmp=tmp->next;
  }
  newNode->next=head; 
  tmp->next=newNode;
  head=newNode;
}
size++;
}

void deleteBack(){
  if(head==NULL){
    cout<<"The list is already emtpy \n";
    return;
  }

  else if (head->next==head){
    delete head;
    head = NULL;
    return;
  }
  Node<T*>tmp=head;
  Node<T*>prev=NULL;
  while(tmp->nexy!=head){
    prev=tmp;
    tmp=tmp->next;
  }
  prev->next=head;
  delete tmp;
  size--;
}

void deleteFront(){
  if(head==NULL){
    cout<<"The list is already emtpy \n";
    return;
  }

  else if (head->next==head){
    delete head;
    head = NULL;
    return;
  }
  Node<T*>tmp=head;
  while(tmp->next != head){
    tmp=tmp->next;
  }
  Node<T*>newNode=head;
  head=head->next;
  tmp->next=head;
  delete newNode;

  size--;
}

int size_of_linkedList() {
  return size;
}

};
