//https://www.naukri.com/code360/problems/count-distinct-substrings_985292
#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node*links[26];
    bool containsKey(char c)
    {
        return (links[c-'a']!=NULL);//that means that character does exist don't insert it
    }
    void put(char ch , Node*node){
        // for this char save reference node to it 
        links[ch-'a'] = node;// point to new trie
    }
    // where this points to 
    Node*get(char ch)
    {
        return links[ch-'a'];
    }
    
};
int countDistinctSubstrings(string &s)
{
    int cnt=0;
    Node*root= new Node();
    for(int i = 0 ;i<s.size();i++)
    {
        Node*node=root;
        // go across all substrings 
        for(int j =i ;j<s.size();j++)
        {
            if(!node->containsKey(s[j]))
            {
                cnt++;
                node->put(s[j],new Node());
            }
            node=node->get(s[i]);
        }
    }
    return cnt;
}