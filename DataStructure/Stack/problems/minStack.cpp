//https://leetcode.com/problems/min-stack/description/
#include<bits/stdc++.h>
using namespace std;


// keep stack that 'll works normally & keep one for min values 
class MinStack {
private:
    stack<int> st;       // Main stack to store elements
    stack<int> minStack; // Stack to keep track of the minimum element

public:
    // Constructor
    MinStack() {
        // No initialization needed, as stacks are empty at the start
    }

    // Push a value onto the stack
    void push(int val) {
        st.push(val); // Push the value onto the main stack
        
        // If minStack is empty or the new value is <= the current min, push it onto minStack
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    // Pop the top element from the stack
    void pop() {
        if (st.empty()) return; // Ensure stack is not empty before popping

        // If the top of minStack is the same as the top of st, pop from minStack as well
        if (st.top() == minStack.top()) {
            minStack.pop();
        }
        st.pop();
    }

    // Get the top element of the stack
    int top() {
        return st.top(); // Return the top element of the main stack
    }

    // Get the minimum element in the stack
    int getMin() {
        return minStack.top(); // The top of minStack is always the minimum element
    }
};

class MinStack {
   stack<long long> st; // Store stack values, might include encoded values
   long long mini;      // Track the minimum value

public:
    MinStack() {
        mini = INT_MAX;  // Initialize mini with the maximum possible value
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        } else {
            if (val < mini) {
                st.push(2LL * val - mini); // Encoded value to track previous minimum
                mini = val;
            } else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;

        long long topElement = st.top();
        st.pop();

        // If we pop a transformed value, we need to restore the previous `mini`
        if (topElement < mini) {
            mini = 2 * mini - topElement;
        }

        // If stack becomes empty, reset mini
        if (st.empty()) {
            mini = INT_MAX;
        }
    }
    
    int top() {
        if (st.empty()) return -1;

        long long topElement = st.top();
        return (topElement < mini) ? mini : topElement; // Fix top() logic
    }
    
    int getMin() {
        return mini;
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main()
{
    MinStack* obj = new MinStack();
    obj->push(5);
    obj->push(3);
    obj->push(7);
    cout << "Minimum: " << obj->getMin() << endl; // Output: 3
    obj->pop();
    cout << "Top: " << obj->top() << endl;       // Output: 3
    obj->pop();
    cout << "Minimum: " << obj->getMin() << endl; // Output: 5

    delete obj; // Free memory
}
