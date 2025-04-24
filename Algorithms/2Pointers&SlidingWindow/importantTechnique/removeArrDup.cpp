//https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
#include<bits/stdc++.h> 
 using namespace std;

// O(nlogn)
    int removeDuplicates(vector<int>& arr) {
       int ind=0;
    set<int>st;
    for(auto it:arr)
    {st.insert(it);// I got only unique elements
    }
    int j = 0;
  for (int x: st) {
    arr[j++] = x;
  }
    return st.size();
    }
    // O(n)
    int removeDuplicates(vector<int>& arr) {
        int l =1;
    for(int i=1;i<arr.size();i++)
    {
      if(arr[i]!=arr[i-1]) // If I find the unique element I push it into my l index
      {
         arr[l++]=arr[i];
      }
      // in case of duplicate I keep moving forward only 
    }
    return l;
    }


 int main() 
 {    
   // fake index
    vector<int>arr={0,0,1,1,1,2,2,3,3,4};
    cout<<removeDuplicates(arr)<<endl;
    
    
    
 }
