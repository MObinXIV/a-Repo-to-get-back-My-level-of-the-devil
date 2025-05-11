//https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
#include <bits/stdc++.h>
using namespace std;
class MedianFinder {
    // pq to keep get the max left half guy 
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>>right;
public:
    MedianFinder() {
        
    }
    /**
     * butting maximum guy in the left in the left array
     * butting the minimum guy in the right in the right array 
     * keep balancig for even & odd purpose 
     */
    void addNum(int num) {  
        left.push(num);
        right.push(left.top());
        left.pop();
        if(left.size()<right.size())
        {
            left.push(right.top());
            right.pop();
        }
        
    }
    
    double findMedian() {
        if(right.size()==left.size())
        return (left.top()+right.top())/2.0;
        else 
        return left.top(); 
    }
};