//https://www.naukri.com/code360/problems/complete-string_2687860
#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node*links[26];
    bool flag=false;
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
    void setEnd(){
    flag=true;//when I reach to the last reference I always make it true 
}
bool isEnd(){return flag;}
};
class Trie {
    Node*root;
public:
    Trie() {
        root = new Node();// create a root of new node
    }
    //O(len)
    void insert(string word) {
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!(node->containsKey(word[i])))
            {
                // put it 
                node->put(word[i],new Node());
            }
            // go to the reference next trie
            node=node->get(word[i]); // move to the reference trie
        }
        // when I reach the last node 
        node->setEnd();
    }
    
    bool checkAllPrefixes(string word){
        Node*node=root;
        for(int i = 0 ;i<word.size();i++)
        {
            if(!node->containsKey(word[i])) return false;
            node=node->get(word[i]);
            if(!node->isEnd()) return false;
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    Trie trie;
    for(string word:a)
    trie.insert(word);
    string longest="";
    for(string word:a)
    {
        if(trie.checkAllPrefixes(word))
        {
            if(word.size()>longest.size())
            longest=word;
            else if (word.size() == longest.size() && word < longest) {
                    longest = word;
                }
        }
    }
    return longest.empty() ? "None" : longest;
}