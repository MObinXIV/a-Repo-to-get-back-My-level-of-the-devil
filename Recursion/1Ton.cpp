//https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1
#include<bits/stdc++.h> 
 using namespace std;
void printNos(int n) {
    if(n==0)return; 
     printNos(n-1);
     cout<<n<<endl;
}
 int main() 

 {     
      printNos(64);
 }