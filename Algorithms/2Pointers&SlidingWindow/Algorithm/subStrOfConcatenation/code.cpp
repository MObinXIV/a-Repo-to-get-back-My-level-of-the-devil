//https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
#include <bits/stdc++.h>
using namespace std;
vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>res;
        if(words.empty()|| s.empty()) return res;
        int n = s.size();//size of the string 
        int numWords=words.size();// size of the words list 
        int k = words[0].size();// size of single word as all words have the same size
        int windowSize= numWords*k;// the whole window size
        unordered_map<string, int>hash;// to store the hash of words
        for(string&it:words) hash[it]++;
       // try every possible offest within word length
       // why k =>(as all words of size k we can't miss one k) We loop offset < k so that we cover all alignments of substrings with word boundaries, without cutting through words.
       for(int offset=0;offset<k;offset++){
        int l =offset,r=offset;// our 2 pointers 
        unordered_map<string,int>seen;// our seen map 
        int cnt=0;// the counter 
        // check the possibilitie list in the string 
        while(r+k<=n){
            string word=s.substr(r,k);// got a size k word
            r+=k; // go to the next pointer after the current string
            // in case we count in the list 
            if(hash.find(word)!=hash.end()){ // check if we found 
                seen[word]++;// fill the seen 
                cnt++;// increase the counter
                // in case we overloaded we decrease & shring the window
                while(seen[word]>hash[word]){
                    string leftWord=s.substr(l,k);// keep get the window from the left
                    seen[leftWord]--;// decrease the occurence of the string
                    l+=k;// move by k 
                    cnt--;// decrease the counter
                }
                //get valid window
                if(cnt==numWords){
                    res.push_back(l);
                    // move left by one word for next possible window
                    string leftWord= s.substr(l,k);
                    seen[leftWord]--;
                    l+=k;
                    cnt--;
                }
            }
            // in case we can't get valid permuatation
            else{
            seen.clear();
            cnt=0;
            l=r;
            }
        }
       }
        return res;
    }