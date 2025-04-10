// https://leetcode.com/problems/intersection-of-two-arrays/
#include<bits/stdc++.h> 
 using namespace std;
 
 vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int>st1,st2;

for (auto it:nums1)
st1.emplace(it);

for (auto it : nums2)
st2.emplace(it);

vector<int>res;

for(auto it:st1)
{
if(st2.count(it))
res.push_back(it);
}

return res;
}
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<bool>dict(1000,0);
    vector<int>res;
    for(int&it:nums1)
    dict[it]=1;

    for(int&it:nums2)
    {
        if(dict[it]==1)
        {
            res.push_back(it);
            dict[it]=0;
        }
    }
    return res;
}
 int main() 
 {    
   vector<int>nums1={1,2,2,1},nums2={2,2};
   vector<int>res= intersection(nums1,nums2);
   for(int&it:res)
   cout<<it<<endl;
 }