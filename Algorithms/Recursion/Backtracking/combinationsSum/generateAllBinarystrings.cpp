//https://www.geeksforgeeks.org/problems/generate-all-binary-strings/0
#include<bits/stdc++.h> 
using namespace std;

void generateBinaryStrings(int n ,string str, vector<string>&res)
{
  if(n==0)
  {
    res.push_back(str);
    return;
  }
  
  generateBinaryStrings(n-1,str+'0',res);
  if (str.empty() || str.back() != '1')
  generateBinaryStrings(n-1,str+'1',res);
}
vector<string> generateBinaryStrings(int num) {
  vector<string>res;
  generateBinaryStrings(num,"",res);
  return res;
}
int main() 
 {    
   vector<string>res = generateBinaryStrings(3);
   for(auto&it:res) cout<<it<<" ";
 }