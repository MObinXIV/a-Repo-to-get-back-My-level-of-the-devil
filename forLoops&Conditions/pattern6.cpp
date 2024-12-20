// The pattern

/*
    *
   ***
  *****
 *******
*********
*/
#include<iostream>
using namespace std;
int main()
{
   int height;
   cin>>height;
   int k =1;
   for (int i=1;i<=height;i++)
   {
      for (int h=height;h>i;h--)
      cout<<" ";
      for(int j=1;j<=k;j++)
      cout<<"*";
      cout<<endl;
      k+=2;
   }

}