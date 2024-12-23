/*
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
     int height;
   cin>>height;
   
   int stars = 1;
   int spaces = height -1;
   // int ind;
   int x;
   for(int i =0;i<height;i++)
   {
      for(int j =0;j<spaces;j++)
      cout<<" ";
      int breakPoint=(2*i+1)/2;
      char ch='A';
     for(int  j=0;j<stars;j++)
     {
      cout<<ch;
      if(j<breakPoint)ch++;
      else
      ch--;
     }
        
      cout<<endl;
       stars+=2;
      spaces--;
   }
    
}