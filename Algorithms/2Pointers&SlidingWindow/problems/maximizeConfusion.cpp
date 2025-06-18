//https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/
#include<bits/stdc++.h>
using namespace std;
//O(n)
int maxLength(string&s,int k , char target){
    int n = s.size();
    int left=0,right=0,maxLen=0,cntK=0;
    while(right<n)
    {
        // in case not equality 
        if(s[right]!=target)
        // increase the count
        cntK++;
        // If number of flips exceeds 'k', shrink window from the left
        while(cntK>k)
        {
            // If the left character was also a flip candidate, reduce the count
           if(s[left]!=target)
           cntK--;
            // move the left pointer tell it's valid
            left++;
        }
        maxLen=max(maxLen,right-left+1);
        right++;
    }
    return maxLen;
}
int maxConsecutiveAnswers(string answerKey, int k) {
    // Try converting to all 'T' and all 'F', take the max of both
        return max(maxLength(answerKey,k,'T'),maxLength(answerKey,k,'F'));
    }