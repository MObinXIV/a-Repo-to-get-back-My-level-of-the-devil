//https://www.naukri.com/code360/problems/nearly-sorted_982937
#include <bits/stdc++.h>
using namespace std;
// every element is sorted at most k
vector < int > nearlySorted(vector < int > arr,int k) {
   vector<int>res;
   priority_queue<int ,vector<int>,greater<int>> minHeap;
   for (int i = 0; i <= k && i < arr.size(); ++i)
        minHeap.push(arr[i]);
        for(int i = k+1;i<arr.size();i++)
        {
            res.push_back(minHeap.top());
             minHeap.pop();                   // remove it
            minHeap.push(arr[i]);            // add current element
        }

        while(!minHeap.empty())
        {
            res.push_back(minHeap.top());
            minHeap.pop();
        }

        return res;
}

int main() {
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    vector<int> sorted = nearlySorted(arr, k);

    cout << "Sorted array: ";
    for (int val : sorted)
        cout << val << " ";
    cout << endl;
}