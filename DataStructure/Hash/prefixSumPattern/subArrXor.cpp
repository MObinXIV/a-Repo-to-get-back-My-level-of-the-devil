//https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
#include<bits/stdc++.h> 
 using namespace std;
 long subarrayXor(vector<int> &arr, int k) {
  if(arr.size()==0) return 0 ;
  int cnt =0;
  int xori=0;
  unordered_map<int,int>mp;
  for(int&it:arr)
  {
    xori^=it;
    if(xori==k)
    cnt++;
    if(mp.find(xori ^ k) != mp.end())
    cnt += mp[xori ^ k];
    mp[xori]+=1;
  }
  return cnt;
}
 int main() 
 {    
   vector<int>v={4, 2, 2, 6, 4};
   cout<<subarrayXor(v,6)<<endl;
    
 }