//https://leetcode.com/problems/sort-characters-by-frequency/description/
#include<bits/stdc++.h> 
 using namespace std;

 static bool comp(pair<char,int>a, pair<char,int>b) {return a.second>b.second;}

 // O(n +k log(k))
 string frequencySort(string s) {
        map<char,int> mp ;
        for(auto&it:s)
        mp[it]++;
        vector<pair<char,int>>v;
        for(auto&it:mp)
        v.emplace_back(it.first,it.second);
        sort(v.begin(),v.end(),comp);
        string res="";
        for(int i = 0 ; i<v.size();i++)
        {
            int t = v[i].second;
            while(t--)
            res+=v[i].first;
        }
        
        return res;
 }
 int main() 
 {    
    string s = "tttree";
    cout<<frequencySort(s)<<endl;
 }

 