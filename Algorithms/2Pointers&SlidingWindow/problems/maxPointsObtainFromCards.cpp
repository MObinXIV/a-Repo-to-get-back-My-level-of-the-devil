//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
#include<bits/stdc++.h> 
using namespace std;
int maxScore(vector<int>& cardPoints, int k) {
       int n = cardPoints.size();
       int lSum=0;
       // getting the sum 
       for(int i=0;i<k;i++)
       lSum+=cardPoints[i];

       int maxi=lSum;
       int rightSum = 0;
       int rightInd=n-1;
       for(int i = k-1;i>=0;i--)
       {
        lSum-=cardPoints[i];
        rightSum+=cardPoints[rightInd];
        maxi=max(maxi,rightSum+lSum);
        rightInd--;
       }

       return maxi;
}

int main() 
 {    
    vector<int>v={9,7,7,9,7,7,9};
    cout<<maxScore(v,7)<<endl;
    
 }