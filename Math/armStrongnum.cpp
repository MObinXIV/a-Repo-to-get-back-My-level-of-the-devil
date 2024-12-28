//https://www.naukri.com/code360/problems/armstrong-number_1462443?leftPanelTabValue=PROBLEM
#include<bits/stdc++.h> 
 using namespace std; 
 int main() 

 {     
       int num;
       cin>>num;
       string s=to_string(num);
       int n = s.length();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=pow(s[i]-'0',n);
        }
        if(sum==num)
        {
            // cout<<"Yes";
            return true;
        }
        else
        {
            // cout<<"No";
            return false;
        }

        // digit base solution -> same but works with digite instead of loopin in string
        
  

 }
 