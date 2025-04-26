//https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
#include<bits/stdc++.h> 
 using namespace std;
 vector<int> findLeaders(vector<int> &elements) {
  vector<int>res;
  int n = elements.size();
  // the first element is always the last element 
  int maxFromRight=elements[n-1];
    res.push_back(maxFromRight);
    for(int i=n-2;i>=0;i--)
    {
      // if I got any element bigger than the maximum one in the right I add it 
      if(elements[i]>=maxFromRight)
      {
        maxFromRight = elements[i];
        res.push_back(maxFromRight);
      }
    }
    return res;
}
 int main() 
 {    
    vector<int> v ={10, 4, 2, 4, 1};
    vector<int>res = findLeaders(v);
    for(int&it:res)
    cout<<it<<" ";
 }