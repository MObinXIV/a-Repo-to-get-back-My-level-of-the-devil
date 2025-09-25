//https://leetcode.com/problems/word-search-ii/
#include <bits/stdc++.h>
using namespace std;
//O(N × M × L + Σ |word|)
struct Node {
    Node* links[26];
    bool flag = false;
    string word = ""; // store word when it's complete

    bool containsKey(char c) {
        return (links[c - 'a'] != NULL);
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
    Node* get(char ch) {
        return links[ch - 'a'];
    }
    void setEnd(string &w) {
        flag = true;
        word = w;  // store the complete word at this node
    }
    bool isEnd() { return flag; }
};

class Trie {
public:
    Node* root;
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;
        for (char c : word) {
            if (!(node->containsKey(c))) {
                node->put(c, new Node());
            }
            node = node->get(c);
        }
        node->setEnd(word);
    }
};

void dfs(vector<vector<char>>& board,int i , int j , Node*node,string&path,unordered_set<string>&result ){
    // Boundary check
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return;

    char c = board[i][j];
    // check for visited 
    if(c=='$'||!node->containsKey(c)) return;

    node = node->get(c);// move the trie

    path.push_back(c);

    // if we reach the end of the node we get one valid word 
    if(node->isEnd())
    {
        result.insert(node->word);
    }

    board[i][j]='$';
    dfs(board, i+1, j, node, path, result);
    dfs(board, i-1, j, node, path, result);
    dfs(board, i, j+1, node, path, result);
    dfs(board, i, j-1, node, path, result);
    board[i][j]=c;
    path.pop_back();

}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
   Trie trie;
   for(string&w:words)
   trie.insert(w);
    unordered_set<string> result; // avoid duplicates
   string path = "";

   for (int i = 0; i < board.size(); i++) {
       for (int j = 0; j < board[0].size(); j++) {
           dfs(board, i, j, trie.root, path, result);
       }
   }

   return vector<string>(result.begin(), result.end());
}