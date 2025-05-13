//https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
#include <bits/stdc++.h>
using namespace std;
int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i =1,j=0;//get i with 1 to start from the second arrival train
        int platformNeeded=1,platForms=1;
        while(i<arr.size()&& j<dep.size())
        {
            if(arr[i]<=dep[j])
            {
                platformNeeded++;
                i++;
            }
            else {
                platformNeeded--;
                j++;
            }
            platForms=max(platForms,platformNeeded);
        }
        return platForms;
        
    }