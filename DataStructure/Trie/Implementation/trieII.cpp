//https://www.naukri.com/code360/problems/implement-trie_1387095
#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
struct Node {
    Node* links[26];
    int cntPrefix = 0;
    int endWith = 0;
    
    bool containsKey(char c) {
        return (links[c-'a'] != NULL);
    }
    
    void put(char ch, Node* node) {
        links[ch-'a'] = node;
    }
    
    Node* get(char ch) {
        return links[ch-'a'];
    }
    
    void increaseEnd() {
        endWith++;
    }
    
    void increasePrefix() {
        cntPrefix++;
    }
    
    void deleteEnd() {
        endWith--;
    }
    
    void reducePrefix() {
        cntPrefix--;
    }
    
    int getEnd() {
        return endWith;
    }
    
    int getPrefix() {
        return cntPrefix;
    }
};

class Trie {
    Node* root;
    
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string &word) {
        // First check if the word exists
        if(countWordsEqualTo(word) == 0) return;
        
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            node = node->get(word[i]);
            node->reducePrefix();
        }
        node->deleteEnd();
    }
};