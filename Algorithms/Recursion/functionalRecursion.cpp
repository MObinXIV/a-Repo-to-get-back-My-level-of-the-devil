// Sum of first n natural numbers using recursion
/*
go to the end of the recursion and then start adding the values back to the top
*/
#include<bits/stdc++.h> 
 using namespace std;
 // functional way to print the sum
 int sum2n(int n){
    if(n==0) return 0;
    return n+sum2n(n-1);
 }
 int main() 
 {     
     cout<<sum2n(5)<<endl;
 }

