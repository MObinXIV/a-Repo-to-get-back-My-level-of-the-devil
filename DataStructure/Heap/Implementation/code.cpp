//Heap(priority Queue)
#include <bits/stdc++.h>
using namespace std;

template <class T>
class Heap {
private:
    vector<T> arr;

    int parent(int index) {
        return (index - 1) / 2;
    }

    int left(int index) {
        return 2 * index + 1;
    }

    int right(int index) {
        return 2 * index + 2;
    }

    void heapifyUp(int index) {
        if (index == 0) return;
        int parentIdx = parent(index);
        if (arr[index] < arr[parentIdx]) {
            swap(arr[index], arr[parentIdx]);
            heapifyUp(parentIdx);
        }
    }

    void heapifyDown(int index) {
    int leftIdx = left(index);       // Left child index = 2 * index + 1
    int rightIdx = right(index);     // Right child index = 2 * index + 2
    int smallest = index;            // Assume current node is smallest

    // If left child exists and is smaller than current
    if (leftIdx < arr.size() && arr[leftIdx] < arr[smallest])
        smallest = leftIdx;

    // If right child exists and is even smaller than the smallest so far
    if (rightIdx < arr.size() && arr[rightIdx] < arr[smallest])
        smallest = rightIdx;

    // If either child was smaller, swap and continue heapifying down
    if (smallest != index) {
        swap(arr[index], arr[smallest]);
        heapifyDown(smallest); // Recurse down the heap
    }
}

public:
    Heap() {}

    void insert(T value) {
        arr.push_back(value);
        heapifyUp(arr.size() - 1);
    }

    void pop() {
        if (arr.empty()) return;
        arr[0] = arr.back();
        arr.pop_back();
        heapifyDown(0);
    }

    bool empty() {
        return arr.empty();
    }

    T top() {
        if (arr.empty()) throw out_of_range("Heap is empty");
        return arr[0];
    }
};

vector<int> heapSort(const vector<int>& arr) {
    Heap<int> h;
    for (int val : arr)
        h.insert(val);

    vector<int> sorted;
    while (!h.empty()) {
        sorted.push_back(h.top());
        h.pop();
    }
    return sorted;
}

int main() {
    vector<int> arr = {5, 3, 8, 4, 1, 2};
    vector<int> sorted = heapSort(arr);

    cout << "Sorted: ";
    for (int val : sorted) {
        cout << val << " ";
    }
    cout << endl;

}
