#include<bits/stdc++.h> 
 using namespace std;
int fact(int n)
{
    if(n==1) return n;
    return n*fact(n-1);
}

 int main() 
 {     
    cout<<fact(4)<<endl;
 }

