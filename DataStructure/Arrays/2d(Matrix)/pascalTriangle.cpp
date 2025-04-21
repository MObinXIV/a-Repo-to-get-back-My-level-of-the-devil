//https://leetcode.com/problems/pascals-triangle/description/
#include<bits/stdc++.h> 
 using namespace std;

 vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;  // don't preallocate

    for (int i = 0; i < numRows; i++) {
        vector<int> row(i + 1, 1);  // all values are 1 initially

        for (int j = 1; j < i; j++) {
            row[j] = res[i - 1][j - 1] + res[i - 1][j];  // standard Pascal rule
        }

        res.push_back(row);  // grow as needed
    }

    return res;
 }