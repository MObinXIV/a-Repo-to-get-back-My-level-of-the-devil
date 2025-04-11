// https://leetcode.com/problems/can-place-flowers/description/
#include<bits/stdc++.h> 
 using namespace std;
 /*
 I'm in the begin & my right is empty 
 I'm in  0 my left is empty m right is empty 
 I'm in the end & my left is empty 
 */
 bool canPlaceFlowers(vector<int>& flowerbed, int n) {
   if (n == 0) {
       return true;
   }
   for (int i = 0; i < flowerbed.size(); i++) {
       if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size()-1 || flowerbed[i+1] == 0)) {
           flowerbed[i] = 1;
           n--;
           if (n == 0) {
               return true;
           }
       }
   }
   return false;
}
 int main() 
 {    
   vector<int>flowerBed={1,0,0,0,0,1};

   cout<<canPlaceFlowers(flowerBed,2);
    
 }
