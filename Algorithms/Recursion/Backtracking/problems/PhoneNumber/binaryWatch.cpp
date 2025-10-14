//https://leetcode.com/problems/binary-watch/description/
#include<bits/stdc++.h>
using namespace std;
/**
 * Try every possible way using 
 * recursion 
 * like letterPhoneNumber problem 
 */
vector<int> hourBits={8,4,2,1};
vector<int> minuteBits ={32, 16, 8, 4, 2, 1};

void f(int ind,int ledsOn,int turnedOn,int hour,int minute,vector<string>&res){

    if(ledsOn==turnedOn){
        // Add valid time only if within the watch limits
        if(hour<12 && minute<60){
            string timeStr= to_string(hour)+":"+ (minute < 10 ? "0" : "") + to_string(minute);
            res.push_back(timeStr);
        }
        return;
    }

    // boundary all leds 'll be on 
    if(ind==10) return;

    if(ind<4){
        //it's an hour bit value
        f(ind+1,ledsOn+1,turnedOn,hour+hourBits[ind],minute,res);
    }
    else{
        // it's a minutes
        f(ind+1,ledsOn+1,turnedOn,hour,minute+minuteBits[ind-4],res);//ind-4 as we need to traverse 0 based starting from 4 ind in the recursion
    }

    // not pick 
    f(ind+1,ledsOn,turnedOn,hour,minute,res);
}
vector<string> readBinaryWatch(int turnedOn) {
    vector<string> res;
    
    // Edge case: no LEDs on means 0:00
    if (turnedOn == 0) return {"0:00"};
    
    // Start DFS from LED index 0, with 0 LEDs on, and time = 0:00
    f(0, 0, turnedOn, 0, 0, res);
    return res;
    }