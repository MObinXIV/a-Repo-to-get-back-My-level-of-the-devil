//powerSet Algorithm
#include<bits/stdc++.h> 
using namespace std;
 vector<vector<int>>generateAllSubSets(vector<int>&arr){
  int n = arr.size();
  int length= pow(2,n);
  vector<vector<int>>res;
  for(int i = 0;i<length;i++)
  {
    vector<int>ds;
    for(int j = 0;j<n;j++)
    {
      if(i&(1<<j))
      ds.push_back(arr[j]);
    }
    res.push_back(ds);
  }
  return res;
 }
int main() 
 {
  vector<int>arr={1,2,3};
    vector<vector<int>>res=generateAllSubSets(arr);
    for(vector<int> v:res)
    {
      for(int&it:v)
      cout<<it<<" ";
      cout<<endl;
    }
 }