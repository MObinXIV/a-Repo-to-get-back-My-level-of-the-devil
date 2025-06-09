//https://leetcode.com/problems/lfu-cache/description/
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int key, value, cnt;
    Node *next; 
    Node *prev;
    Node(int _key, int _value) {
        key = _key;
        value = _value; 
        cnt = 1; 
    }
}; 

struct List
{
    int size;
    Node*head;
    Node*tail;

    List()
    {
        head= new Node(0,0);
        tail= new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;

    }
    void addFront(Node *node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++; 
    }
    
    void removeNode(Node* delnode) {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--; 
    }
};

class LFUCache {
    map <int , Node*>keyNode; // Assign keys & refernces 
    map<int, List*> freqMap;// Assign freq lists
    int maxSize;
    int minFreq;
    int curSize;
public:
    LFUCache(int capacity) {
        maxSize=capacity ; 
        minFreq=0;
        curSize=0;
        
    }

    void updateFreqListMap(Node* node)
    {
        keyNode.erase(node->key);// Remove from the keu map
        freqMap[node->cnt]->removeNode(node);//Remove it from frequency map

        // check if the min count list is exhausted 
        if(node->cnt == minFreq && freqMap[node->cnt]->size == 0) {
            minFreq++; 
        }

        List*higherNewList= new List();

        if(freqMap .find(node->cnt+1)!=freqMap.end())
        {
            // I 'll get the previous map into the current one 
            higherNewList=freqMap[node->cnt+1];
        }
        node->cnt+=1;//Increase the node count 
        higherNewList->addFront(node);// Put the node in the beginning of the list 

        // Assign the list to the frequency map 

        freqMap[node->cnt]=higherNewList;

        keyNode[node->key] = node; // Assign the reference 


    }
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end())
        {
            Node*temp=keyNode[key];
            int val=temp->value;
            updateFreqListMap(temp);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (maxSize == 0) {
            return;
        }

        if(keyNode.find(key)!=keyNode.end()) // Here I will only update the value & update freq 
        {
            Node*temp=keyNode[key];
            temp->value=value;
            updateFreqListMap(temp);
        }
        else 
        {
            if(curSize==maxSize)
            {
                // Erase the prev to last ele node 
                List*list=freqMap[minFreq]; // Get the least freq list 
                keyNode.erase(list->tail->prev->key);
                freqMap[minFreq]->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;

            minFreq=1; // As the new value assure that I get min freq with 1 
            List*listFreq=new List();
            // Check for exisitence 
            if(freqMap.find(minFreq)!= freqMap.end())
            listFreq=freqMap[minFreq];

            Node*node= new Node(key,value); // Make new node 

            listFreq->addFront(node);

            keyNode[key]=node; // assign node in the key 

            freqMap[minFreq] = listFreq;// push the list after update it 
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */