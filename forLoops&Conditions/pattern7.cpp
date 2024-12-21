// The pattern
/*
 
*********
 *******
  *****
   ***
    *
*/
/*
-- The intuition
1- we observe that we get the stars by this formula -> int stars = (height-1)*2
2- The spaces -> the spaces starts with no space then in each level increases by one
*/
#include<iostream>
using namespace std;
int main()
{
   int height;
   cin>>height;
   
   int stars = (height-1)*2;
   for(int i =0;i<height;i++)
   {
      for(int j =0;j<i;j++)
      cout<<" ";
      for(int k=0;k<=stars;k++)
      cout<<"*";
      cout<<endl;
      stars-=2;
   }

}