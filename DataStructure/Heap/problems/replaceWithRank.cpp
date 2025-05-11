//https://www.naukri.com/code360/problems/replace-each-element-of-array-with-its-corresponding-rank_975384
#include <bits/stdc++.h>
using namespace std;
 vector<int> replaceWithRank(vector<int> &arr) {
    priority_queue<int,vector<int>,greater<int>>pq;
    int n =arr.size();
    for(int&it:arr)
    pq.push(it);

    unordered_map<int, int> valueToRank;
    int rank = 1;

    // Extract from max to min, assigning rank (smallest gets 0)
    while (!pq.empty()) {
        int top = pq.top();
        pq.pop();
        // to not repeat the same rank again
        if (valueToRank.count(top) == 0) {
            valueToRank[top] = rank++;
        }
    }

    // Replace array elements with their rank
    for (int i = 0; i < n; i++) {
        arr[i] = valueToRank[arr[i]];
    }

    return arr;

}
int main() {
  vector<int>arr={4, 7, 2, 90};
  vector<int>res= replaceWithRank(arr);
  for(int&it:res)
  cout<<it<<" ";
}
