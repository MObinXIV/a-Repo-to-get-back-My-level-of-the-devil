//https://leetcode.com/problems/path-sum/description/
#include<bits/stdc++.h>
using namespace std;
 string simplifyPath(string path) {
        stack<string>st;
        string res;
        for(int i = 0 ;i<path.size();i++){
            // don't need it as I 'll attach it to the end 
            if(path[i] == '/')    
                continue;
            string temp;
			// iterate till we doesn't traverse the whole string and doesn't encounter the last / in the string
            while(i < path.size() && path[i] != '/')
            {
				// add path to temp string
                temp += path[i];
                ++i;
            }
            // skip the .
            if(temp == ".")
                continue;
                // delete my prev guy in case .. 
                else if(temp == "..")
            {
                if(!st.empty())
                    st.pop();
            }
            // push to the stack
            else st.push(temp);
        }
        // take the result from stack 
        while(!st.empty()){
            res = "/"+st.top()+res;
            st.pop();
        }
        if(!res.size()) return "/";
        return res;
    }