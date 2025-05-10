//https://www.naukri.com/code360/problems/minimise-max-distance_7541449?leftPanelTabValue=PROBLEM
#include<bits/stdc++.h> 
using namespace std;
int requiredStations(vector<int>&arr,double mid  ){
  int  count =0; // count the number of stations allowed to replace 
  for(int i = 1; i<arr.size();i++)
  {
    // Distance between 2 gas stations 
    double gap = arr[i]-arr[i-1];
    // number of stations we can  place between the current 2 stations 
    count+= (gap/mid);
  }
  return count;
}

double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
  double low = 0 ;
  /*
  . The largest gap we might need to divide is between the first and last station 
  — so arr[n - 1] - arr[0] is the maximum possible distance between any two stations.
  */
   // End of binary search range — maximum possible distance is the longest gap between first and last station
   double high = arr[n - 1] - arr[0];
  // Precision threshold for binary search on floating-point numbers
  double eps = 1e-6;
  while((high-low)>eps)
  {
    double mid = (low+high)/2.0;
   int numOfStations=requiredStations(arr,mid);
    
    if(numOfStations>k)
    {
      // keep minimizing
      low=mid;
    }
    else
    high=mid;
  }
  return high;
}
int main() 
 {
      vector<int>arr= {1,2,3,4,5,6,7};
      cout<<minimiseMaxDistance(arr,6)<<endl;

 }
