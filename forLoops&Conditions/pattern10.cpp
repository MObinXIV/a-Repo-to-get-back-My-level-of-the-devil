// The pattern
/*
if row index is even we start with 1 else we start with 0
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
  
   int height;
   cin>>height;
   int f=1;
   for(int i =0;i<height;i++)
   {
    if (i%2==0)f=1;
      else
         f=0;
      for(int j=0;j<=i;j++)
      {
       cout<<f;
       f=1-f;
      }
      cout<<endl;
   }  
}