//https://www.geeksforgeeks.org/problems/distinct-coloring--170645/1
// House painting
#include<bits/stdc++.h>
using namespace std;
// for each index we have 3 options we move according to this 
long long f(int ind , int color, int r[],int g[],int b[],vector<vector<long long>>&dp)
{
    if(ind==0)
    {
        // we return one of the 3 options
        if(color==0) return r[0];
        else if (color==1) return g[0];
        return b[0];
    }
    if(dp[ind][color]!=-1) return dp[ind][color];

    if(color==0) return dp[ind][color] = r[ind]+min(f(ind-1,1,r,g,b,dp),f(ind-1,2,r,g,b,dp));//take the mini between 2 colors
    else if(color==1) return dp[ind][color]=g[ind]+min(f(ind-1,0,r,g,b,dp),f(ind-1,2,r,g,b,dp));
    else return dp[ind][color]=b[ind]+min(f(ind-1,0,r,g,b,dp),f(ind-1,1,r,g,b,dp));
}
long long int distinctColoring(int n, int r[], int g[], int b[]) {
       // changing parameters is ind & color 
       vector<vector<long long>> dp(n, vector<long long>(3, -1));
        // choose the minimum cose between the 3 options 
        return min(f(n-1,0,r,g,b,dp),min(f(n-1,1,r,g,b,dp),f(n-1,2,r,g,b,dp)));
    }
    long long int distinctColoring(int n, int r[], int g[], int b[]) {
       // changing parameters is ind & color 
       vector<vector<long long>> dp(n, vector<long long>(3, 0));
       dp[0][0] = r[0];
    dp[0][1] = g[0];
    dp[0][2] = b[0];
       for(int ind =1;ind<n;ind++)
       {
        dp[ind][0] = r[ind]+min(dp[ind-1][1],dp[ind-1][2]);//take the mini between 2 colors
     dp[ind][1]=g[ind]+min(dp[ind-1][0],dp[ind-1][2]);
   dp[ind][2]=b[ind]+min(dp[ind-1][0],dp[ind-1][1]);

       }
       return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    }

    long long int distinctColoring(int n, int r[], int g[], int b[]) {
    // Base case for the first house
    long long prevRed = r[0], prevGreen = g[0], prevBlue = b[0];

    for (int i = 1; i < n; ++i) {
        long long currRed   = r[i] + min(prevGreen, prevBlue);
        long long currGreen = g[i] + min(prevRed, prevBlue);
        long long currBlue  = b[i] + min(prevRed, prevGreen);

        // Update previous values for the next iteration
        prevRed = currRed;
        prevGreen = currGreen;
        prevBlue = currBlue;
    }

    return min({prevRed, prevGreen, prevBlue});
}