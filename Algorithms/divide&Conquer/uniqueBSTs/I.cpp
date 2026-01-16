//https://leetcode.com/problems/unique-binary-search-trees/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    unordered_map<int,int>memo;
public:
    int numTrees(int n) {
        
        // base case , case we became empty or only there's exist a single node 
        if(n==0 || n==1) return 1;

        //dp check 
        if(memo.find(n)!=memo.end()) return memo[n];
        int total=0;
        // total ways of construction from 1->n as root for each
        for(int i =1; i<=n;i++)
        {
            // construct left subtree & right subtree (number of ways to construct left & right)
            int left=numTrees(i-1);
            int right = numTrees(n-i);
            // total combination with i as root 
            total+=left*right;
        }
        return memo[n]=total;
    }
};