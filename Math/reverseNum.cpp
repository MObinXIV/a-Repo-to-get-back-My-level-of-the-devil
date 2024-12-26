//https://leetcode.com/problems/reverse-integer/description/
#include<bits/stdc++.h> 
 using namespace std; 
 
 int main() 

 {     
    
    int n ;
    cin>>n;
    int rev=0;
    while(n!=0)
    {
        int pop=n%10;
        n/=10;
        if(rev>INT_MAX/10 || (rev==INT_MAX/10 && pop>7))return 0; // Check for overflow
        if(rev<INT_MIN/10 || (rev==INT_MIN/10 && pop<-8))return 0;
        rev=rev*10+pop;
    }
    cout<<rev<<endl;  
 }
 