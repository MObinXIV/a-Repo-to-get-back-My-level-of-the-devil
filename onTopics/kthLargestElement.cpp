//https://leetcode.com/problems/kth-largest-element-in-an-array/description/
#include<bits/stdc++.h> 
 using namespace std;
 // O(nlogn) time complexity
 int findKthLargest(vector<int>& nums, int k) {
    int n =nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        return nums[k-1];
    }
    int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for (auto num : nums) {
        pq.push(num);
        }
        int res;
        while (k--) {
            res = pq.top();
            pq.pop();
        }
        return res;
    }
 int main() 
 {    
    vector<int> nums={3,2,3,1,2,4,5,5,6};
    int k=4;
    cout<<findKthLargest(nums,k);
    return 0;
    
 }
