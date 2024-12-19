// The pattern

/*
*****
*****
*****
*****
*****
*/

// intuition -> we print x stars in each line with x height
#include<iostream>
using namespace std;
int main()
{
   int height;
   cout<<"enter the triangle height\n";
   cin>>height;
   for(int i=0 ; i<height;i++)
   {
      for(int j=0;j<height;j++)
      {
         cout<<"*";
      }
      cout<<endl;
   }

}
