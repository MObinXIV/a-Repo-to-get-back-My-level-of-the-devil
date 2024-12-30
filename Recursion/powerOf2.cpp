//https://leetcode.com/problems/power-of-two/
#include<bits/stdc++.h> 
 using namespace std;
 // O(n) solution
bool isPowerOfTwo(int n) {
    if(n<=0) return false;
        bool f=true;
        while(n>1)
        {
            if(n%2)
            {
                f=false;
                break;
            }
            n/=2;  
        }
        if (f) return true;
        else return false;
}

 int main() 
 {     
    cout<<isPowerOfTwo(2)<<endl;
 }