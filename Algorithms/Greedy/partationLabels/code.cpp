//https://leetcode.com/problems/partition-labels/description/
#include<bits/stdc++.h>
using namespace std;
vector<int> partitionLabels(string s) {
        // use the last occurence method 
        vector<int>last_index(26,0);
        // keep tracking the last index of each character to end 
        for(int i =0;i<s.size();i++)
        last_index[s[i]-'a']=i;

        int l = 0 , r =0;
        vector<int>partation_indecies;
        for(int i = 0;i<s.size();i++){
            // get the maximum end of the character 
            r=max(r,last_index[s[i]-'a']);
            // in case this is the last possible occurence of the character 
            if(i==r)
            {
                // get a valid window 
                partation_indecies.push_back(i-l+1);
                // move to new paratation
                l=i+1;
            }
        }
        return partation_indecies;
    }