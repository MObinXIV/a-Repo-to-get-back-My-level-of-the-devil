//https://leetcode.com/problems/fibonacci-number/
#include<bits/stdc++.h> 
 using namespace std;
int fib(int n) {
        if(n==0||n==1) return n;
        return fib(n-1)+fib(n-2);
    }

 int main() 
 {     
    cout<<fib(4)<<endl;
 }
