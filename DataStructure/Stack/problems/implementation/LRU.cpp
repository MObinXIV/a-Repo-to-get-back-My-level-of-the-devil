//https://leetcode.com/problems/lru-cache/description/
#include<bits/stdc++.h>
using namespace std;
class node {
      public:
        int key;
      int val;
      node * next;
      node * prev;
      node(int _key, int _val) {
        key = _key;
        val = _val;
      }
    };
class LRUCache {
    node*tail;
    node*head;
    int capacity;
    unordered_map<int,node*>mp;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new node(-1,-1);
        tail=new node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void addNode(node*newNode){
        node*tmp=head->next;
        newNode->next=tmp;
        newNode->prev=head;
        head->next=newNode;
        tmp->prev=newNode;
    }
    // only we link previous guy of node to it's next one 
     void deletenode(node * delnode) {
    node * delprev = delnode -> prev;
    node * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
  }
    int get(int key) {
        // if it's found in the map we get it & put it in the front
        if(mp.find(key)!=mp.end()){
            node*getNode= mp[key];
            int data=getNode->val;
            mp.erase(key);
            deletenode(getNode);
            addNode(getNode);
            mp[key]=head->next;//store the new value node reference
            return data;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // in case we find we update & move forward 
        if(mp.find(key)!=mp.end()){
            node*existingNode=mp[key];
            mp.erase(key);
            deletenode(existingNode);
        }
        // if we exceed we eliminate the least task & insert in the front
        if(mp.size()==capacity)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addNode(new node(key,value));
        mp[key]=head->next;
    }
};
