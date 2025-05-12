//https://leetcode.com/problems/lemonade-change/description/
#include <bits/stdc++.h>
using namespace std;
bool lemonadeChange(vector<int>& bills) {
       int five=0, ten=0;
       for(int&it:bills)
       {
        if(it==5){
            five++;
        }
        else if(it==10)
        {
            if(five==0) return false;
            ten++;
            five--;
        }
        else{
            if(ten>0 && five>0){
                ten--;
                five--;
            }
            else if (five>=3){
                five-=3;
            }
            else return false;
        }
       }
       return true;
    }
int main() {
  vector<int>bills={5,5,10,10,20};
  cout<<lemonadeChange(bills)<<endl;
}