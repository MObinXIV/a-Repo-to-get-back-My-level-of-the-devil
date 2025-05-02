//https://leetcode.com/problems/trapping-rain-water/description/
#include<bits/stdc++.h> 
using namespace std;
// The amount of water in every buliding can be indicated by getting the minimum between the highest value on it's left & the one on it's right - it's height
int trap(vector<int>& height) {
  int n = height.size();
  // let's get the maximum left guy for each building
  vector<int> prefixHeight(n);
  prefixHeight[0]= height[0];// starting height 
  for(int i =1;i<n;i++)
  {
    // assign the maximum left building for each element
    prefixHeight[i] = max(prefixHeight[i-1],height[i]);
  }      
  // Assigning the maximum right building for each builiding 
   vector<int> suffixHeight(n);
   suffixHeight[n-1] = height[n-1];
   for(int i =n-2;i>=0;i--)
   {
    // assgin the max right guy for each building 
    suffixHeight[i]= max(suffixHeight[i+1],height[i]);
   }  

   // calculate the water which trapped for each building 
   int totalWater=0;
   for(int i = 0 ;i<n;i++)
   {
    // see how much water can trapped in the current height by subtracting it's height from the minimum height between his left & right
      totalWater+= min(suffixHeight[i],prefixHeight[i]) - height[i];
   }

   return totalWater;

}
// 2 pointer approach 
int trap(vector<int>& height) {

  int n = height.size();
  int l = 0 , r = n-1;
  int maxL=0,maxR=0;
  int res=0;
  while(l<=r){
    if(maxL<=maxR)
    {
      if(height[l]>=maxL) maxL=height[l];
      else
      res+=maxL-height[l];
      l++;
    }
    else{
      if(height[r]>=maxR) maxR=height[r];
      else
      res+=maxR-height[r];
      r--;
    }
  }
  return res;
}

int main() 
 {    
    vector<int>height={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap(height)<<endl;
 }