//https://leetcode.com/problems/next-greater-element-i/description/
#include<bits/stdc++.h> 
using namespace std;
// Nge Algorithm using monotonic stack 

// O(n^2)
// vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //   vector<int> res;
    //   for (int i = 0; i < nums1.size(); ++i) {
        //       int found = false;
        //       bool greaterFound = false;
        //       for (int j = 0; j < nums2.size(); ++j) {
            //           if (nums2[j] == nums1[i]) found = true;
            //           if (found && nums2[j] > nums1[i]) {
                //               res.push_back(nums2[j]);
                //               greaterFound = true;
                //               break;
                //           }
                //       }
                //       if (!greaterFound) res.push_back(-1);
                //   }
                //   return res;
                // }
                
                // using monotonic stack to find NGE
                vector<int> nextGreaterElement(vector<int>&nums)
                {
                  int n = nums.size();
                  stack<int> st;
                  vector<int>nge(n,-1);
                  for(int i = n-1;i>=0;i--)
                  {
                    while(!st.empty()&&st.top()<=nums[i])
                    st.pop();
                    if(!st.empty()) nge[i]=st.top();
                    st.push(nums[i]);
                  }
                  return nge;
                }
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
  // we use the fact that num1 is subset of num2 
  vector<int> nge= nextGreaterElement(nums2);
  unordered_map<int, int> indexMap;

  // indexing the values 
  for (int i = 0; i < nums2.size(); i++) {
      indexMap[nums2[i]] = i;
  }

  vector<int> res;
  for (int &it : nums1)
      res.push_back(nge[indexMap[it]]); // Use index from map

  return res;
}
int main() 
 {    
    vector<int> v = {4,12,5,3,1,2,1,2,5,3,1,2,4,6};
    vector<int> res= nextGreaterElement(v);
    for(int&it:res)
    cout<<it<<" ";
 }