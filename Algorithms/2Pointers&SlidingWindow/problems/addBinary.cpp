//https://leetcode.com/problems/add-binary/
#include<bits/stdc++.h>
using namespace std;
string addBinary(string a, string b) {
        int i= a.size()-1;
        int j = b.size()-1;
        int carry=0;
        string res="";
        while(i>=0 || j>=0||carry!=0){
            int sum=carry;
            if(i>=0)
            {
                sum+=(a[i]-'0');
                i--;
            }
            if(j>=0)
            {
                sum+=(b[j]-'0');
                j--;
            }
            // get the current bit
            int currBit= sum%2;
            carry=sum/2;

            // append the current bit to the result guy 
            res.push_back(char('0'+currBit));
        }

        reverse(res.begin(),res.end());
        return res;
    }