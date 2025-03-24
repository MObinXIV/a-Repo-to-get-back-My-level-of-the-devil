//https://leetcode.com/problems/string-to-integer-atoi/description/

#include<bits/stdc++.h> 
 using namespace std;
 int myAtoi(string s) {
    int i=0;
    // handling spaces
    while(s[i]==' ')
    {
        i++;
    }
    // handling sign
    int sign=1;
    if(s[i]=='-')
    {
        sign=-1;
        i++;
    }
    else if(s[i]=='+')
    {
        i++;
    }

    // handling numbers
    long long int num=0;
    while(s[i]>='0'&&s[i]<='9'){
        // adding the number to the num variable
        num=num*10+(s[i]-'0');
        // checking if the number is within the range of int
        if(num*sign>INT_MAX)
        {
            return INT_MAX;
        }
        if(num*sign<INT_MIN)
        {
            return INT_MIN;
        }
        i++;

    }
    return num*sign;
 }   

  // recursive version
  int myAtoiHelper(const string &s, int i, int sign, long long num) {
    // Base case: end of string or non-digit character
    if (i >= s.size() || !isdigit(s[i])) {
        return num * sign;
    }
    // Update num with the current digit
    num = num * 10 + (s[i] - '0');
    // Check for overflow and underflow
    if (num * sign > INT_MAX) return INT_MAX;
    if (num * sign < INT_MIN) return INT_MIN;
    // Recursive call with the next index
    return myAtoiHelper(s, i + 1, sign, num);
}

int myAtoi(string s) {
    int i = 0;
    // Handling spaces
    while (i < s.size() && s[i] == ' ') {
        i++;
    }
    // Handling sign
    int sign = 1;
    if (i < s.size() && s[i] == '-') {
        sign = -1;
        i++;
    } else if (i < s.size() && s[i] == '+') {
        i++;
    }
    // Handling numbers
    return myAtoiHelper(s, i, sign, 0);
}
 int main() 
 {     
    cout<<myAtoi("0-1")<<endl;
 }
