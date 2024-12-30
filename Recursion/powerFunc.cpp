//https://leetcode.com/problems/powx-n/
#include<bits/stdc++.h> 
 using namespace std;


 // O(n) solution
// double myPow(double x, int n) {
//         if(n==0)return 1;
//         // handling negative n case
//         if(n<0) return 1/myPow(x,-n); //return 1/func and modify the sign
//         if(n==1) return x;
//         return x*myPow(x,n-1);
//     }

    //O(logn) solution -> divide the power in 2 halfs exponentiation by squaring
double myPow(double x, int n){
    if(n==0)return 1;

    // handling negative calls;
    if(n<0){
        x=1/x;
        n=-n;
    }
    // calculating the half of power 
    double half=myPow(x,n/2);
    if(n%2==0)
    return half*half;
    else
    return x*half*half;
}

 
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