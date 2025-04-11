//https://leetcode.com/problems/roman-to-integer/
#include<bits/stdc++.h> 
 using namespace std;
 struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int val){
        this->val=val;
        left=right=NULL;
    }
 };

 int romanToInt(string s) {
        unordered_map<char,int>mp={
            {'I',1},{'V',5},{'X',10}
            , {'L',50} , {'C',100},{'D',500}
            ,{'M',1000}
        };
        int res = 0;
        int n = s.size();
        for(int i = 0 ;i<n;i++)
        {
            if(i+1<n&&mp[s[i]]<mp[s[i+1]])
             res-= mp[s[i]];
             else
             res+=mp[s[i]];
        }
        return res;
 }
 int main() 
 {    

    cout<<romanToInt("MCMXCIV")<<endl;
    
 }