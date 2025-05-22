//https://leetcode.com/problems/word-ladder-ii/
#include<bits/stdc++.h>
using namespace std;
 vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
     unordered_set<string>st(wordList.begin(),wordList.end());
     queue<vector<string>>q;
     q.push({beginWord});
     vector<string>usedOnLevel;
     usedOnLevel.push_back(beginWord);
     int level=0;
     vector<vector<string>>ans;
     while(!q.empty()){
        vector<string>vec=q.front();
        q.pop();
        // erase all words that has been 
        // used in the previous level to transform
        if(vec.size()>level){
            level++;
            for(auto it:usedOnLevel)
            st.erase(it);
            usedOnLevel.clear();
        }
        string word =vec.back();// the last word in that sequence
        if(word==endWord){
            if(ans.size()==0) ans.push_back(vec);
            else if (ans[0].size()==vec.size()) ans.push_back(vec);
        }
        for(int i = 0 ; i<word.size();i++)
        {
            char original = word[i];
            for(char c='a';c<='z';c++)
            {
                word[i]=c;
                if(st.count(word)>0){

                    vec.push_back(word);
                    q.push(vec);
                    // mark as visited on the level to erase it in the future from the set
                    usedOnLevel.push_back(word);
                    // to keep generating with same vector in this level
                    vec.pop_back();
                }
            }
            word[i]=original;
        }
     }
     return ans;
    }

    // for Cp , not interviews 
class Solution {
    unordered_map<string,int>mpp;
    vector<vector<string>>ans;
    string b ; 
private:
    void dfs(string word,vector<string>&seq){
        if(word==b)
        {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());

            return ;
        }
        int steps=mpp[word];
        int sz=word.size();
        for(int i =0 ;i<sz;i++){
                char original = word[i];
                for(char c ='a';c<='z';c++){
                    word[i]=c;
                    if(mpp.find(word)!=mpp.end() && mpp[word]+1==steps)
                    {
                        seq.push_back(word);
                        dfs(word,seq);
                        seq.pop_back();
                    }
                }
                 word[i]=original;
            }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        b=beginWord;
        q.push(beginWord);
        unordered_set<string>st(wordList.begin(),wordList.end());
        mpp[beginWord]=1;
        int sz=beginWord.size();
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front();
            int steps = mpp[word];
            q.pop();
            if(word==endWord) break;
            for(int i =0 ;i<sz;i++){
                char original = word[i];
                for(char c ='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)){
                        st.erase(word);
                        q.push(word);
                        mpp[word] = steps+1;
                    }
                }

                word[i]=original;
            }
        }
        if(mpp.find(endWord)!=mpp.end()){
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        } 
            
        return ans;
    }
};