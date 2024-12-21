/*

1          1
12        21
123      321
1234    4321
12345  54321
123456654321


*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
     int height;
   cin>>height;
   int s=2*(height-1);
   for(int i =1;i<=height;i++)
   {

      for(int j =1;j<=i;j++)
      {
        cout<<j;
       
      }
         for(int j=0;j<s;j++)
        cout<<" ";
        for(int k= i;k>=1;k--) cout<<k;
        
        cout<<endl;
             s-=2;
   }

}