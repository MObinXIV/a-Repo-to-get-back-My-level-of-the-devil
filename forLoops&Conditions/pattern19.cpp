/*
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********

*/
#include<bits/stdc++.h>
using namespace std;
void f(int i)
{
  
      
    for(int  j=0;j<=i;j++)
     {
         cout<<"*";
     }
}
void f2(int i)
{
   for(int j =0;j<=i;j++)
      {
        cout<<"*";
       
      }
}
int main()
{
     int height;
   cin>>height;
   int s=0;
   int s2=2*(height-1);///Very important formula
   for(int i =height-1;i>=0;i--)
    {
      
      f(i);
     for(int i=0;i<s;i++)
     cout<<" ";
     f(i);

     
       cout<<endl;
       s+=2;
    }
    

for(int i =0;i<height;i++)
    {
      f2(i);
         for(int j=0;j<s2;j++)
        cout<<" ";
       f2(i);
      s2-=2;
      cout<<endl;
    }



   
    
}