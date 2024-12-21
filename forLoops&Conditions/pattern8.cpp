// The pattern
/*
    *
   * *
  *   *
 *     *
*********
*/
// Intuition -> same ass the full triangle with only the case of printing full 1st line and last line with all stars and others print only first and last star
#include<iostream>
using namespace std;
int main()
{
   int height;
   cin>>height;
   
   int stars = 1;
   int spaces = height -1;
   for(int i =0;i<height;i++)
   {
      for(int j =0;j<spaces;j++)
      cout<<" ";
      
   
      for(int k=0;k<stars;k++)
      {
         if(i==0 ||i==height-1|| k==0 || k==stars-1)
         cout<<"*";
         else
         cout<<" ";
      }
      
      cout<<endl;
       stars+=2;
      spaces--;
   }

     
}