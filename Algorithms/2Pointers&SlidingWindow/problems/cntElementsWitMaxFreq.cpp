//https://leetcode.com/problems/count-elements-with-maximum-frequency/description/
#include<bits/stdc++.h>
using namespace std;
 int maxFrequencyElements(vector<int>& nums) {
        int mx= 1;
        unordered_map<int,int>mp;
        for(int&it:nums){
            mp[it]++;
            if(mp[it]>mx) mx=mp[it];
        }

        int res=0;
       for(auto it:mp)
       {
        if(it.second==mx) res+=mx;
       }
       return res;
    }
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> frequencies;
        int maxFrequency = 0;
        int totalFrequencies = 0;

        // Find the frequency of each element
        // Determine the maximum frequency
        // Calculate the total frequencies of elements with the maximum frequency
        for (int num : nums) {
            frequencies[num]++;
            int frequency = frequencies[num];

            // If we discover a higher frequency element
            // Update maxFrequency
            // Re-set totalFrequencies to the new max frequency
            if (frequency > maxFrequency) {
                maxFrequency = frequency;
                totalFrequencies = frequency;
                // If we find an element with the max frequency, add it to the total
            } else if (frequency == maxFrequency) {
                totalFrequencies += frequency;
            }
        }
        return totalFrequencies;
    }