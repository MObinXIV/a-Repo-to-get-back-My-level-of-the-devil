#include <bits/stdc++.h>
using namespace std;

template <class T>
class ArrayList {
private:
    T *internalMemory;
    int capacity; // Total allocated capacity
    int size;     // Number of actual elements

    void expand() {
        // Expand memory by 10 more slots
        T *temp = new T[capacity + 10];

        for (int i = 0; i < size; i++)
            temp[i] = internalMemory[i];

        delete[] internalMemory;
        internalMemory = temp;
        capacity += 10;
    }

public:
    // Default Constructor
    ArrayList() {
        capacity = 10;
        size = 0;
        internalMemory = new T[capacity]; // Fix: Allocate with capacity
    }

    // Constructor with custom initial capacity
    ArrayList(int capacity) {
        this->capacity = capacity;
        size = 0;
        internalMemory = new T[capacity];
    }

    // Add an element to the list
    void add(T element) {
        if (size == capacity) {
            expand();
        }
        internalMemory[size] = element;
        size++;
    }

    // Remove an element at a given index
    void remove(int index) { // Fix: Changed parameter name
        if (index < 0 || index >= size) {
            throw out_of_range("Index is out of range");
        }

        for (int i = index; i < size - 1; i++) {
            internalMemory[i] = internalMemory[i + 1]; // Shift left
        }

        size--; // Reduce the count of valid elements
    }

    // Access elements safely
    T& operator[](int ind) {
        if (ind < 0 || ind >= size) { // Fix: Validate against size
            throw out_of_range("Index is out of range");
        }
        return internalMemory[ind];
    }

    // Get the number of actual elements
    int getSize() {
        return size; // Fix: Return size instead of capacity
    }

    // Display the elements
    void display() {
        for (int i = 0; i < size; i++) {
            cout << internalMemory[i] << " ";
        }
        cout << endl;
    }

    // Insert an item at a specific index
    void insertItemAt(int index, T item) {
        if (index < 0 || index > size) {
            throw out_of_range("Index is out of range");
        }

        if (size == capacity) {
            expand();
        }

        // Shift elements to the right
        for (int i = size; i > index; i--) {
            internalMemory[i] = internalMemory[i - 1];
        }

        internalMemory[index] = item; // Insert new item
        size++;
    }

    // Clear the list
    void clear() {
        delete[] internalMemory;
        capacity = 10;
        size = 0;
        internalMemory = new T[capacity]; // Fix: Allocate with capacity
    }

    // Destructor to free memory
    ~ArrayList() {
        delete[] internalMemory;
    }
};

int main() {
    ArrayList<int> list;

    for (int i = 0; i < 10; i++) {
        list.add(i);
    }

    cout << "Original List: ";
    list.display();

    list.insertItemAt(3, 99); // Insert 99 at index 3
    cout << "After inserting 99 at index 3: ";
    list.display();

    list.remove(5); // Remove element at index 5
    cout << "After removing index 5: ";
    list.display();

    cout << "Element at index 3: " << list[3] << endl;
    cout << "Size of list: " << list.getSize() << endl;

    list.clear();
    cout << "After clearing list: ";
    list.display();

    return 0;
}
