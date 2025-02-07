#ifndef BIGINT_H
#define BIGINT_H
#include <iostream>
#include <string>
using namespace std;
class BigInt {
private:
string internalNumber;  

bool isSmaller(string n1 , string n2 ){
    int l1=n1.size(),l2=n2.size();
    if(l1<l2) return true;
    if(l1>l2) return false;
    // if they are in the same length let's compare digit by digit from the biggest digit
    for(int i = 0; i <l1;i++){
        if(n1[i]<n2[i]) return true;
        if(n1[i]>n2[i]) return false;
    }

    return false;
}

string subtractNumbers(string n1,string n2){
    bool negSign=false;
    if(isSmaller(n1,n2)){
        negSign=true;
        swap(n1,n2); // keep the first number bigger
    }
    int l1 =n1.size();
    int l2 = n2.size();
    while(l2<l1){
        n2.insert(n2.begin(),0);
        l2++;
    }
    
    string res="";
    bool borrow=false;
    for(int i = n1.size()-1;i>=0;i--){
        int c1= n1[i]-'0';
        int c2= n2[i]-'0';
        if(borrow){
            if(c1>0){ c1--;
                borrow=false;}
            else
            c1=9;// borrow from the next digit
        }
        if(c1<c2){
            c1+=10;
          borrow = true;
        }
        int sub = c1-c2;
        res.insert(res.begin(),sub+'0');

    }
     // Remove leading zeros
     int start = 0;
     while (start < res.size() && res[start] == '0') {
         start++;
     }
     
     if (start == res.size()) {
         return "0"; // If result is all zeros, return "0"
     }
     res= res.substr(start);

     return negSign ? "-"+res : res;
}
string addNumbers(string n1 , string n2){
    int l1=n1.size();
    int l2 = n2.size();
    // insert 0's in the end of the number to do the remaining of the adding after one of the 2 numbers get exhausted
    if(l1>l2){
        for(int i = 0 ; i<l1-l2;i++){
            n2.insert(0,"0");
        }
    }
    else if (l2>l1){
        for(int i = 0 ; i<l2-l1;i++){
            n1.insert(0,"0");
        }
    }
    int remainder=0;
    string result="";
    for(int i = n1.size()-1;i>=0;i--){
        // add the current 2 digits in forms of numbers 
         int c1=n1[i]-'0';
         int c2=n2[i]-'0'; 
         // do the normal elementary sum by adding the 2 digits with the previous remainder
         int total = c1+c2+remainder; // always below 20
          // get the remainder digit 
         remainder = total/10;
          // get the digit 
         char digit = (total%10+'0');  
         // add it to the result 
         result.insert(result.begin(),digit);
    }
    // see if I still got remainder 
    if(remainder>0){
        result.insert(result.begin(),'1');
    }
    return result;
}
public:
    BigInt(){
        internalNumber ="0";
    }
    BigInt(string s ){
        internalNumber=s;
    } 
    BigInt (int i ){
        internalNumber=to_string(i);
    }
    string sub(string s){
        return subtractNumbers(internalNumber,s);
    }
    string add(string s ){
        return addNumbers(internalNumber,s);
    }
    // operator overloading 
    BigInt operator+(BigInt i) {
        return BigInt(addNumbers(internalNumber, i.internalNumber)); 
    }
     BigInt operator-(BigInt i){
        return BigInt(subtractNumbers(internalNumber,i.internalNumber));
     }
    /*
    * in general operator overloading takes only one parameter 
    *by making the function as friend we tricky solve this problem
    */
   // when You mee on the left of (<<) ostream & on the right of it BigInt 
   // when the compiler see so use ostream type to print the number on the screen
    friend ostream&operator<<(ostream&out,BigInt i){
        out<<i.internalNumber;
        return out;
    }

    // Unary operator 
    BigInt& operator++(int){
        internalNumber= addNumbers(internalNumber,"1");
        return (*this);
    }
    BigInt& operator++(){
        internalNumber= addNumbers(internalNumber,"1");
        return (*this);
    }
    
};

#endif // BIGINT_H
