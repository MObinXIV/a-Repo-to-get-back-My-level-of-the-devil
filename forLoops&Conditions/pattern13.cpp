/*

A 
A B 
A B C 
A B C D 
A B C D E 

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
     int height;
   cin>>height;
   for(int i=0;i<height;i++)
   {
    for(char j='A';j<'A'+i;j++) // start of me is A and the end is the ith char
    {
        cout<<j<<" ";
    }
    cout<<endl;
   }

}