// Queue Array Implementation
#include<bits/stdc++.h>
using namespace std;
// FIFO work
template<typename T>
class Queue{
private:
struct Node{
T data;
Node*next;
};
Node*front;
Node*rear;
int size=0;
public:

Queue(){
    front=NULL;
    rear=NULL;
    size++;
}
 ~Queue() {
        while(!isEmpty())
        dequeue();
    }
    bool isEmpty(){return front==NULL;}

    void enqueue (T val){
        Node*tmp=new Node();
        tmp->data=val;
        if(front==NULL){
            front = rear = tmp;
            return;
        }
        rear->next=tmp;
        rear=tmp;
        size++;
    }

    T dequeue(){
        if (isEmpty()) {
            cout << "Queue Underflow! No elements to remove.\n";
            return T();  // Return default value of T
        }
        Node*tmp=front;
        T x=tmp->data;
        front = front->next;
        if (front == NULL) {
            rear = NULL;  // If the queue is empty, set rear to nullptr
        }
        delete tmp;
        return x;
    }
     T peek() {
         if (isEmpty()) {
            cout << "Queue is Empty\n";
            return T();  // Return default value of T
        }
        return front->data;
    }

    // Function to get the current size of the queue
    int getSize() {
        return size;
    }
};


int main()
{
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << "Front element: " << q.peek() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Front element after dequeue: " << q.peek() << endl;
    return 0;
}
