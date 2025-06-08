//https://leetcode.com/problems/maximal-rectangle/description/
#include<bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n),right(n);
        stack<int>st;
        // PSE
        //Find nearest smaller to the left for each bar
        for(int i = 0 ; i<n;i++)
        {
            while(!st.empty()&& heights[st.top()]>=heights[i]) st.pop();
            // If stack is not empty, nearest smaller is at top + 1
            if (!st.empty())
            left[i] = st.top() + 1;
        else
            left[i] = 0;// No smaller on left → can go to index 0
            st.push(i);
        }
        while(!st.empty()) st.pop();
        //NSE
        // Find nearest smaller to the right for each bar
        for(int i = n-1;i>=0;i--)
        {   
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
             if (!st.empty())// If stack is not empty, nearest smaller is at top - 1
            right[i] = st.top() - 1;
        else
            right[i] = n - 1; // No smaller on right → go till end
            st.push(i);
        }
            int maxArea = 0;
            for (int i = 0; i < n; i++) {
             int width = right[i] - left[i] + 1; // Total width
                maxArea = max(maxArea, heights[i] * width); // Area = height * width
                 }
            return maxArea;
    }
// we only apply the previous algorithm
int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()|| matrix[0].empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>heights(m,0);
        int maxRect=0;
        for(int i = 0 ; i<n;i++)
        {
            for(int j = 0 ; j<m;j++)
            {
                if(matrix[i][j]=='1')
                heights[j]+=1;
                else
                heights[j]=0;
            }
            maxRect=max(maxRect,largestRectangleArea(heights));
        }
        return maxRect;
    }