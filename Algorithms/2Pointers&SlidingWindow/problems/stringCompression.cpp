//https://leetcode.com/problems/string-compression/description/
#include<bits/stdc++.h>
using namespace std;
int compress(vector<char>& chars) {
        int i =0 , res=0;
        while(i<chars.size()){
            int grpLength=1;
            while(i+grpLength<chars.size()&&chars[i+grpLength]==chars[i]){
                grpLength++;
            }
            chars[res++]=chars[i];
            if(grpLength>1){
                for(char c:to_string(grpLength)) chars[res++]=c;
                
            }

            i+=grpLength;
        }
        return res;
    }