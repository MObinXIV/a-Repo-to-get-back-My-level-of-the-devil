#include<bits/stdc++.h>

using namespace std;

vector<int>prefixSum(vector<int>&arr){
    int n = arr.size();
    vector<int>prefixS(n);
    prefixS[0]=arr[0];
    for(int i = 1;i<n;i++)
    {
        prefixS[arr[i]]= prefixS[i-1] + prefixS[i];
    }
    return prefixS;
}