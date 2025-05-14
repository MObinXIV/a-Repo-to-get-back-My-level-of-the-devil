//https://leetcode.com/problems/candy/ 
#include <bits/stdc++.h>
using namespace std;
int candy(vector<int>& ratings) {
        //greedly got the left max & right max distripution
        int n = ratings.size();
        vector<int>l(n,1),r(n,1);
        // we know always the first guy is 1 
        for(int i =1;i<n;i++)
        {
            // slightly bigger neighbor 
            if(ratings[i]>ratings[i-1])
            l[i]=1+l[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            r[i]=1+r[i+1];
        }
        int sum=0;
        for(int i = 0 ; i<n;i++)
        sum+=max(l[i],r[i]);
        return sum;
    }
    // slope method
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum=1,i=1;
        while(i<n){
            //flat surface 
            if(ratings[i]==ratings[i+1]) {
                sum+=1;
                i++;
                continue;
            }
            // check for increasing slopes 
            int peak = 1 ;
            while(i<n && ratings[i-1]<ratings[i])
            {
                // keep increasing the peek guy 
                peak++;
                sum+=peak;
                i++;
            }

            // decreasing slopes 
            int down = 1 ;
            while(i<n && ratings[i-1]>ratings[i]){
                sum+=down;
                down++;
                i++;
            }
            if(down>peak) sum+=(down-peak);
        }
        return sum;
    }