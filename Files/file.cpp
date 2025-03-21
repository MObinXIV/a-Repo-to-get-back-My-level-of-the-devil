#include<bits/stdc++.h>
#include <fstream>
using namespace std;

int main()
{   
   ifstream in("in.txt");
   ofstream out("out.txt", ios::app);
   int x , y;
   while(!in.eof())
   {in>>x>>y;
   out<<x+y<<endl;}
}
    