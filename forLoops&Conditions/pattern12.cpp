/*

1 
2 3 
4 5 6 
7 8 9 10 
11 12 13 14 15 
16 17 18 19 20 21 
22 23 24 25 26 27 28 

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
     int height;
   cin>>height;
   int k;
   for (int i =1;i<=height;i++)
   {
    if(i==1)
    k=i;
    for(int j=i;j>0;j--)
    {
        
      cout<<k<<" ";
      k++;
    
    }
    
    cout<<endl;
   }

}