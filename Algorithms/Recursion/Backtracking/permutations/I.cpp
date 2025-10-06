//https://leetcode.com/problems/permutations/description/
#include<bits/stdc++.h>
using namespace std;
void permute(int ind , vector<int>&arr, vector<vector<int>>&res){
    if(ind==arr.size()){
        res.push_back(arr);
        return;
    }
    for(int i =ind;i<arr.size();i++){
        swap(arr[ind],arr[i]);
        permute(ind+1,arr,res);
        swap(arr[ind],arr[i]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        permute(0,nums,res);
        return res;
    }