//https://leetcode.com/problems/fruit-into-baskets/description/
#include<bits/stdc++.h> 
using namespace std;
int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int uniqueCnt=0;
        int l = 0  , r = 0 ; 
        unordered_map<int,int>mp;
        int len=0;
        while(r<n)
        {
          mp[fruits[r]]++;
          while(mp.size()>2)
          {
            // decrement the occurence of the current element
            mp[fruits[l]]--;
            // if it reachs 0 I tend to eleminate it from the map
            if(mp[fruits[l]]==0)
            mp.erase(fruits[l]);
            // move the window forward till U hit the element 'll be reduced
            l++;
          }
          len=max(len,r-l+1);
          r++;
        }
        return len;
}
int main() 
 {
    vector<int>fruits={0,1,2,2};
    cout<<totalFruit(fruits);
 }