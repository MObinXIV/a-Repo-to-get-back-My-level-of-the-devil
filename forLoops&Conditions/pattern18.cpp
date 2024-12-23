/*
E
DE
CDE
BCDE
ABCDE
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
     int height;
   cin>>height;
   for(int i =height-1;i>=0;i--)
    {
      char ch='A'+i;
    for(int  j=height;j>i;j--)
     {
         cout<<ch;
         ch++;
     }
       cout<<endl;
       
    }
    
}