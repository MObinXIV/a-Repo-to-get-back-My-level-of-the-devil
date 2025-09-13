//https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
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

    bool searchWord(string&word , int i , Node*node){
        if(i==word.size()) return node->isEnd();
        if(word[i]=='.') 
        {
            for(int k = 0 ; k<26;k++){
                if(node->links[k] && searchWord(word,i+1,node->links[k])) return true;
            }
            return false;
        }
        if(!node->containsKey(word[i])) return false;
        return searchWord(word,i+1,node->get(word[i]));
    }
    
    bool search(string word) {
        return searchWord(word,0,root);
    }
    
    bool startsWith(string prefix) {
        Node*node=root;
        for(int i = 0 ; i<prefix.size();i++)
        {
            if(!node->containsKey(prefix[i])) return false;
            node=node->get(prefix[i]);
        }
        return true;
    }
};
class WordDictionary {
    Trie*trie;
public:
    WordDictionary() {
        trie= new Trie();
    }
    
    void addWord(string word) {
        trie->insert(word);
    }
    
    bool search(string word) {
        return trie->search(word);
    }
};
