#include<bits/stdc++.h>
using namespace std;
/**
 * approach
 * we simply do a combinations k in array or subsets sum II in array problem
 * but here we don't got an array
 * our array is the numbers from 1->n
 */
void f(int ind , int k , int n , vector<int>&ds,vector<vector<int>>&ans){
    // base case 
    if(k==0){
        ans.push_back(ds);
        return;
    }
    for(int i=ind;i<=n;i++)
    {
        ds.push_back(i);
        f(i+1,k-1,n,ds,ans);
        ds.pop_back();
    }

}
vector<vector<int>> combine(int n, int k) {
        vector<int>ds;
        vector<vector<int>>ans;
        f(1,k,n,ds,ans);
        return ans;
    }


void combine(int i,int n , vector<int>&ds,vector<vector<int>>&ans,int k)
{
    if(i>n) // if I cross the line
    {
        if(k==0)
        ans.push_back(ds);
        return;
    }
    ds.push_back(i);
    combine(i+1,n,ds,ans,k-1);
    ds.pop_back();
    combine(i + 1, n, ds, ans, k);
}
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ans;
    vector<int> ds;
    combine(1,n,ds,ans,k);
    return ans;
}    