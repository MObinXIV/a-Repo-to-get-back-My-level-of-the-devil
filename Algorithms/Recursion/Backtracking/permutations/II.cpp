//https://leetcode.com/problems/permutations-ii/description/
#include<bits/stdc++.h>
using namespace std;
void f(int ind , vector<int>arr,vector<vector<int>>&res)
{
    if(ind==arr.size()){
        res.push_back(arr);
        return;
    }

    for(int i = ind ;i<arr.size();i++)
    {
        if(i!=ind && arr[i]==arr[ind]) continue;
        swap(arr[i],arr[ind]);
        f(ind+1,arr,res);
        // swap(arr[ind],arr[i]);
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums){
    sort(nums.begin(),nums.end());
    vector<vector<int>>res;
    f(0,nums,res);
    return res;
}

void backtrack(int ind , vector<int>&arr,vector<vector<int>>&res){
    if(ind==arr.size()){
        res.push_back(arr);
        return;
    }
    // let's track using set 
    unordered_set<int>st;
    for(int i = ind;i<arr.size();i++){
        // check if , we 've seen this before
        if(st.count(arr[ind])) continue;
        st.insert(arr[ind]);
        swap(arr[ind],arr[i]);
        backtrack(ind+1,arr,res);
        swap(arr[ind],arr[i]);
    }
}