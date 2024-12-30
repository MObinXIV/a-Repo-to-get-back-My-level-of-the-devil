//https://leetcode.com/problems/powx-n/
#include<bits/stdc++.h> 
 using namespace std;


 // O(n) solution
double myPow(double x, int n) {
        if(n==0)return 1;
        // handling negative n case
        if(n<0) return 1/myPow(x,-n); //return 1/func and modify the sign
        if(n==1) return x;
        return x*myPow(x,n-1);
    }
 int main() 

 {     
     cout<<myPow(2,-2)<<endl;
 }