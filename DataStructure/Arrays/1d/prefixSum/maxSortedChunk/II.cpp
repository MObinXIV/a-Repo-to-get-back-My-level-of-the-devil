//https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
#include <bits/stdc++.h>
using namespace std;
/**
 * We aim to maximize the number of chunks 
 * in case we increasing in order this gives us more valid chunks to add 
 * otherwise we pop from the monoStack till we merge the current guy with valid element
 * also we keep the top guy to push it again in the stack as we guarantee it's the maximum one
 */
//using monotonic stack 
 int maxChunksToSorted(vector<int>& arr) {
      int n =arr.size();
      stack<int>monoStack;
      for(int i=0;i<n;i++){
        // in case the current element is bigger than the larger element in the satck
        if(monoStack.empty() || arr[i]>monoStack.top()) // in case we got an element greater than the maxim
        // push to the stack to start new chunk
        monoStack.push(arr[i]);
        else{
            // in this case we keep pop till we merge chunks 
            
            // get the maxElement on the top 
            int maxElement=monoStack.top();
            // Pop until current value fits the ordering,
            // merging all violated chunks.
            while(!monoStack.empty() && arr[i]<monoStack.top()) monoStack.pop();
            // push it as it the current maximum element of our chunk
            monoStack.push(maxElement);
        }
      }
      return monoStack.size();  
    }