// The pattern
/*
*
**
***
****
*****
****
***
**
*
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
  
   int height;
   cin>>height;
   for(int i =0;i<height+1;i++)
   {
      for(int j=0;j<i;j++)
      cout<<"*";
      cout<<endl;
   }
   for(int i=height-1;i>0;i--)
   {
      for(int j = 0;j<i;j++)
      cout<<"*";
      cout<<endl;
   }
  
    
}