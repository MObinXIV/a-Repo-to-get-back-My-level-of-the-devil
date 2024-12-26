//https://leetcode.com/problems/count-the-digits-that-divide-a-number/description/
#include<bits/stdc++.h> 
 using namespace std; 
 // O(N)
int countDigits(int num) {
    int cnt=0;
    int x=num;
    while (x!=0)
    {
        int l=x%10;
        if(!(num%l))cnt++;
        x/=10;
    }
   return cnt;
    }
 int main() 

 {     
    int n ;
    cin>>n;
    cout<<countDigits(n)<<endl;
 }
 