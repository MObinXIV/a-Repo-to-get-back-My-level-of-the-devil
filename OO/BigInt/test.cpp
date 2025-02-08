#include<bits/stdc++.h>
#include "BigInt.hpp"
using namespace std;

int main()
{
   BigInt num1("12345678900");
    BigInt num2("987654321");

    BigInt sum = num1 + num2; // Should do numerical addition, not concatenation
         sum++;
         ++sum;
    cout<<"Sum is : "<<sum<<endl;
      BigInt b("4");
     BigInt a("3");
     BigInt c = b-a;
     cout<<c<<endl;
     BigInt b1("4") , b2("5");
     BigInt d=b1*b2;
     cout<<d<<endl;
}