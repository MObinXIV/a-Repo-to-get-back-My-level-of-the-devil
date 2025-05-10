//https://leetcode.com/problems/largest-odd-number-in-string/description/
#include<bits/stdc++.h> 
using namespace std;
//traverse from end 
string largestOddNumber(string num) {
        int n = num.size();
       string res="";
       int i = n-1;
        for( i ;i>=0;i--){
          if((num[i]-'0')%2)
          break;
        }
        
      for (int j =0;j<=i;j++)
      res.push_back(num[j]);
  return res;

}
string largestOddNumber(string num) {
  int n = num.size();
  for (int i = n - 1; i >= 0; --i) {
      if ((num[i] - '0') %2) {
          return num.substr(0, i + 1);
      }
  }
  return "";
}
int main() 
 {    
 cout<<largestOddNumber("35427")<<endl;
 }