//https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
#include <bits/stdc++.h>
using namespace std;
class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq; // Min-heap
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.emplace(val);
        if(pq.size()>k) pq.pop();
        return pq.top();
    }
};