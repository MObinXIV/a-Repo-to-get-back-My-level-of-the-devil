//https://leetcode.com/problems/next-greater-element-ii/description/
#include<bits/stdc++.h> 
using namespace std;
// Nge Algorithm using monotonic stack 
vector<int> nextGreaterElements(vector<int>&nums)
{
  int n = nums.size();
  stack<int> st;
  vector<int>nge(n,-1);
  // circular traversing
  for(int i = 2*n-1;i>=0;i--)
  {
    while(!st.empty()&&st.top()<=nums[i%n])
    st.pop();
    //we only fill the result for original indices (not the second, virtual pass).

    if(i<n)
    if(!st.empty()) nge[i]=st.top();
    st.push(nums[i%n]);
  }
  return nge;
}


int main() 
 {    
    vector<int> v = {1,2,1};
    vector<int> res= nextGreaterElements(v);
    for(int&it:res)
    cout<<it<<" ";
 }