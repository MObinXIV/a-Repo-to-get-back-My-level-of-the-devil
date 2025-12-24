//https://leetcode.com/problems/max-chunks-to-make-sorted/description/
#include <bits/stdc++.h>
using namespace std;
/**
 * as we got a premutation from 0->n
 * so we guarantee numbers is same from 0->n & in in array 
 * in case the sum of i elements matches prefixSum of array this means ,we now form a valid sorted chunk
 */
int maxChunksToSorted(vector<int>& arr) {
        int n =arr.size();
       int chunks=0,prefixSum=0,sortedSum=0;
       // go & check 
       for(int i =0;i<n;i++){
        sortedSum+=i;
        prefixSum+=arr[i];
        if(sortedSum==prefixSum)chunks++;
       }
       return chunks;
    }
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int maxElement =0 , chunks=0;
       // go & check 
       for(int i =0;i<n;i++){
        // get the maximum element in the current chunk 
        maxElement=max(maxElement,arr[i]);
        // in case it's sorted valid , the max element in the chunk equals the current i
        if(maxElement==i) chunks++;
       }
       return chunks;
    }