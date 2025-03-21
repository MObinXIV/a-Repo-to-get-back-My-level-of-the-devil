#include<bits/stdc++.h>
#include <stdexcept>
using namespace std;
int Division(int x , int y){
    if(y!=0) return x/y;
    else 
    {throw runtime_error("can't divide by 0!");}
}
int main()
{   
   try{
    cout<<Division(20,0)<<endl;
   }catch(const exception& e){
    cout << "Error: " << e.what() << '\n';
   }
}
    