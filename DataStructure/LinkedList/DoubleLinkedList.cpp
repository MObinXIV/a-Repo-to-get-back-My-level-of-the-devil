//Doubly LinkedList
#include<bits/stdc++.h>
using namespace std;

 template <typename T>
  struct Node  {
      T val;
      Node *next;
      Node*prev;
      Node(T& x) : val(x), prev(NULL),next(NULL) {}
  };
  template<typename T>
class DoublyLinkedList {
private:
Node<T>*head;
Node<T>*tail;
int size;
public:

DoublyLinkedList(){
    head=NULL;
    tail=NULL;
    size=0;
}
void pushFront(T val){
    Node<T>*newNode=new Node(val);
    // In the first insertion case
    if(head==NULL){
        head=tail=newNode;
    }
    else{
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    }
    size++;
}

void popFront(){
    if(head==NULL){
        cout<<"List is already empty \n";
        return;
    }
  Node<T>*temp=head;
  head=head->next;
  if (head == nullptr) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }

        delete temp;
  size--;
}

void pushBack(int val){
    Node<T>*newNode=new Node(val);
    if(tail==NULL){
        head=tail=newNode;
    }
    else{
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
    size++;
}

void popBack(){
    if(tail==NULL){
        cout<<"list is already empty \n";
        return;
    }
    Node<T>*tmp=tail;
    tail=tail->prev;
    if (tail == nullptr) {
            head = nullptr;
        } else {
            tail->next = nullptr;
        }

        delete tmp;
    size--;
}

T&front(){
    if(head==NULL)throw std::runtime_error("List is empty");
    return head->val;
}
T& back() {
        if (tail == nullptr) {
            throw std::runtime_error("List is empty");
        }
        return tail->val;
    }
     int  getSize() const {
        return size;
    }
    bool isEmpty() const {
        return size == 0;
    }
~DoublyLinkedList(){
    clear();
}
void clear(){
  
  while(head!=NULL){
    Node<T>*tmp=head;
    head=head->next;
    delete tmp;
  }
  tail = nullptr;
  size = 0;
}
    
};
int main()
{
    DoublyLinkedList<int> list;

    list.pushBack(1);
    list.pushFront(2);
    list.pushBack(3);

    cout << "Front: " << list.front() << endl;
    cout << "Back: " << list.back() << endl;
    cout << "Size: " << list.getSize() << endl;

    list.popFront();
    list.popBack();

    cout << "Front: " << list.front() <<endl;
    cout << "Back: " << list.back() << endl;
    cout << "Size: " << list.getSize() << endl;

    list.clear();
}  
