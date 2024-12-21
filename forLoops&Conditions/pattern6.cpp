// The pattern

/*
    *
   ***
  *****
 *******
*********
*/
/*
---- Intuition
1- we first print spaces
2- we observe that we have in the first line (height -1) stars and in each line the spaces decreases by 1
3- we observe the stars begins by number 1 increases by 2 in each line
--- Now lets code that  
*/
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
      cout<<"*";
   
      cout<<endl;
       stars+=2;
      spaces--;
   }

   // int height;
   // cin>>height;
   // int stars=1;// the stars in the first line
   // for(int i =0;i<height;i++) // loop for the all height
   // {
   //    for(int h=height-1;h>i;h--)// the spaces loop
   //    cout<<" ";
   //    for(int j=stars;j>0;j--)
   //    cout<<"*";
   //    cout<<endl;
   //   stars+=2;
   // }
   // int height;
   // cin>>height;
   // int k =1;
   // for (int i=1;i<=height;i++)
   // {
   //    for (int h=height;h>i;h--)
   //    cout<<" ";
   //    for(int j=1;j<=k;j++)
   //    cout<<"*";
   //    cout<<endl;
   //    k+=2;
   // }

}