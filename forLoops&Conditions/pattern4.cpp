// The pattern

/*
1
12
123
1234
12345
*/
#include<iostream>
using namespace std;
int main()
{
   int height;
   cin>>height;
   for(int i=1 ; i<=height;i++)
   {
      for(int j=1;j<=i;j++)
      {
         cout<<i;
      }
      cout<<endl;
   }

}
