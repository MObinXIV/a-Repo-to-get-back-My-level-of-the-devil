//https://leetcode.com/problems/word-ladder/description/
#include<bits/stdc++.h>
using namespace std;
/**
 * keep changing chars to find if the string is in the set 
 * if find it erase it 
 * mark as visited when U elminate it from the set
 * store the steps by increasing the steps of it
 */
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        // mark as visited 
        st.erase(beginWord);
        while(!q.empty()){
            string node = q.front().first;
            int steps=q.front().second;
            q.pop();
            if(node==endWord) return steps;
            for(int i = 0 ; i<node.size();i++)
            {
                char original= node[i];
                for(char c = 'a';c<='z';c++)
                {
                    node[i]=c;
                    if(st.find(node)!=st.end())
                    {
                        // mark as visited 
                        st.erase(node);
                        q.push({node,steps+1});
                    }
                    // make the word back to it's original to keep checking 
                    node[i]=original;
                }

            }
        }
        return 0;
    }