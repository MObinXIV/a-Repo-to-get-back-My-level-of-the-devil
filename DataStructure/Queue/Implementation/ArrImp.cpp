// Queue Array Implementation
#include<bits/stdc++.h>
using namespace std;
// FIFO work
template<typename T>
class Queue{
private:
T*arr;
int capacity;// Maximum capacity of the queue
int front;
int rear;
int size; // Current number of elements in the queue
public:

Queue(){
    capacity=1000;
    arr= new int[capacity];
    front=-1;
    rear=-1;
    size=0;
}

Queue(int capacity){
    this->capacity=capacity;
    arr= new int[capacity];
    front=0;
    rear=-1;
    size=0;
}

 ~Queue() {
        delete[] arr;
    }

    bool isFull(){ return size==capacity;}
    bool isEmpty(){return size==0;}

    void enqueue (T val){
        if (isFull()) {
            cout << "Queue Overflow! Cannot add more elements.\n";
            return;
        }
        if (rear==-1){
            rear=0;
            front=0;
        }
        else
        rear= (rear+1)%capacity;
        arr[rear]=val;
        size++;
    }

    T dequeue(){
        if (isEmpty()) {
            cout << "Queue Underflow! No elements to remove.\n";
            return T();  // Return default value of T
        }
        T value= arr[front];
        front = (front + 1) % capacity;  // Circularly adjust the front pointer
        size--;
        return value;
    }
     T peek() {
        if (isEmpty()) {
            cout << "Queue is empty! No front element.\n";
            return T();  // Return default value of T
        }
        return arr[front];
    }

    // Function to get the current size of the queue
    int getSize() {
        return size;
    }
};


int main()
{
    Queue<int> q(5);

    // Add elements to the queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Front element: " << q.peek() << endl;  // Should print 10

    cout << "Dequeued element: " << q.dequeue() << endl;  // Should print 10
    cout << "Dequeued element: " << q.dequeue() << endl;  // Should print 20

    cout << "Front element after dequeue: " << q.peek() << endl;  // Should print 30

    // Add more elements to the queue
    q.enqueue(50);
    q.enqueue(60);

    cout << "Front element after adding more elements: " << q.peek() << endl;  // Should print 30
    cout << "Queue size: " << q.getSize() << endl;  // Should print 3
}
