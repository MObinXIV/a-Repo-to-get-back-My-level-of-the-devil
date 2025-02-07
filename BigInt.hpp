#ifndef BIGINT_H
#define BIGINT_H
#include <iostream>
#include <string>
using namespace std;
class BigInt {
private:
string internalNumber;  
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
    string add(string s ){
        return addNumbers(internalNumber,s);
    }

    
    
};

#endif // BIGINT_H
