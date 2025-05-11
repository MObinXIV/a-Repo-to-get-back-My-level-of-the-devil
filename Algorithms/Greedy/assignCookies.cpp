//https://leetcode.com/problems/assign-cookies/description/
#include <bits/stdc++.h>
using namespace std;
// O(N logN + M logM + M)
int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt=0;
        int l1 =0 , l2=0;
        int r1=g.size()-1,r2=s.size()-1;
        while(l2<=r2 && l1<=r1)
        {
            if(g[l1]<=s[l2])
            l1++;
           
            l2++;
        }
        return l1;
    }
int main() {
  vector<int> g ={1,2} , s ={1,2,3};
  cout<<findContentChildren(g,s)<<endl;
}