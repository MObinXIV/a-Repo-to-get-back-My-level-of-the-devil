#include<bits/stdc++.h>
using namespace std;
void merge(vector<pair<int,int>>& arr, int l, int mid, int r, vector<int>& count) {
    vector<pair<int,int>> temp; // temporary array for merged result
    int i = l;                  // pointer for left half
    int j = mid + 1;            // pointer for right half
    int rightCount = 0;         // number of smaller elements encountered from right side

    // ⚙️ Merge both halves
    while (i <= mid && j <= r) {
        // If right element smaller than left → contributes to count
        if (arr[i].first > arr[j].first) {
            rightCount++;              // we found one smaller number to the right
            temp.push_back(arr[j]);    // push smaller right element
            j++;
        } else {
            // For current left element, all previously moved right elements
            // are smaller than it → add them to its count
            count[arr[i].second] += rightCount;
            temp.push_back(arr[i]);
            i++;
        }
    }

    //  If left elements remain, add the remaining rightCount to them
    while (i <= mid) {
        count[arr[i].second] += rightCount; // all right smaller already seen
        temp.push_back(arr[i]);
        i++;
    }

    //  Add any remaining right elements
    while (j <= r) {
        temp.push_back(arr[j]);
        j++;
    }

    // 🧩 Copy merged part back into original array
    for (int k = l; k <= r; k++)
        arr[k] = temp[k - l];
}

//  Recursive merge sort that divides and merges
void mergeSort(vector<pair<int,int>>& arr, int l, int r, vector<int>& count) {
    if (l >= r) return;                 // base case: single element
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid, count);      // sort left half
    mergeSort(arr, mid + 1, r, count);  // sort right half
    merge(arr, l, mid, r, count);       // merge both halves and count
}

//  Main function
vector<int> countSmaller(vector<int>& nums) {
    int n = nums.size();
    vector<int> count(n, 0);             // result array
    vector<pair<int,int>> arr;           // pair: {value, original index}

    //  Store each number with its index
    for (int i = 0; i < n; i++)
        arr.push_back({nums[i], i});

    // Run modified merge sort
    mergeSort(arr, 0, n - 1, count);
    return count;
}


vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n,0);
        for(int i =0;i<n;i++)
        {
            int cnt=0;
            for(int j = i+1;j<n;j++)
            {
                if(nums[j]<nums[i]) cnt++;
            }
            res[i]=cnt;
        }
        return res;
    }