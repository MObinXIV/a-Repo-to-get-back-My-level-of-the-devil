//https://leetcode.com/problems/container-with-most-water/description/
#include<bits/stdc++.h>
using namespace std;
int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0 , r=n-1;
        int mx =0;
        while(l<=r)
        {
            int area=(r-l)*min(height[l],height[r]);
            mx=max(mx,area);
            if(height[l]<height[r]) l++;
            else
            r--;
        }
        return mx;
    }
