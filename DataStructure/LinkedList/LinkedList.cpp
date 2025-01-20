//https://leetcode.com/problems/design-linked-list/description/
/**
 *Liked List -
 * Linked lists provide dynamic size, 
 * efficient insertions/deletions,
 * and better memory utilization.
 */
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data; // Data stored in the node
    Node* next; // Pointer to the next node

    // Constructor to initialize a node using an initialization list
    Node(int val) : data(val), next(nullptr) {}
};

// Define the MyLinkedList class
class MyLinkedList {
private:
    Node* head; // Pointer to the head of the list
    int size; // Size of the list

public:
    // Constructor to initialize an empty list
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }

    // Function to get the value at a specific index
    int get(int index) {
        if (index >= size || index < 0) return -1; // Check for invalid index
        Node* cur = head;
        int i = 0;
        while (i < index) {
            cur = cur->next;
            i++;
        }
        return cur->data;
    }

    // Function to add a node at the head
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        ++size;
    }

    // Function to add a node at the tail
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* tmp = head;
            while (tmp->next != nullptr) {
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }
        ++size;
    }

    // Function to add a node at a specific index
    void addAtIndex(int index, int val) {
        if (index > size || index < 0) return; // Check for invalid index
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* cur = head;
        for (int i = 0; i < index - 1; ++i) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        ++size;
    }

    // Function to delete a node at a specific index
    void deleteAtIndex(int index) {
        if (index >= size || index < 0) return; // Check for invalid index

        Node* cur = head;

        if (index == 0) { // Special case: deleting the head node
            head = head->next;
            delete cur;
        } else {
            for (int i = 0; i < index - 1; ++i) {
                cur = cur->next;
            }
            Node* nodeToDelete = cur->next;
            cur->next = cur->next->next;
            delete nodeToDelete;
        }
        --size;
    }
    Node*convertArrToLL(vector<int>&arr){
      
        int n =arr.size();
        head->data=arr[0];
        Node*prev=head;
        for(int i =1;i<n;i++ )
        {
            Node*newNode=new Node(arr[i]);
            prev->next=newNode;
            prev=newNode;
        }
        return head;
    }
    int getSize() {return size;}
    // Destructor to clean up dynamically allocated memory
    ~MyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main()
{
  Node*y=new Node(5);
  cout<<y<<endl;
  cout<<y->data<<endl;
  cout<<y->next<<endl;
}  
