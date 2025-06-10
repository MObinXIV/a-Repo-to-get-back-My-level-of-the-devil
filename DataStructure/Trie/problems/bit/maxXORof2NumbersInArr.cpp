//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node*links[2];//0 or 1 
    bool containsKey(int bit)
    {
        return (links[bit]!=NULL);
    }
    void put(int bit,Node*node)
    {
        links[bit]=node;
    }
     Node*get(int bit){return links[bit];}
};
class Trie{
 private:
    Node*root;
public:
    Trie()
    {
        root=new Node();
    }
    void insertNum(int num)
    {
        Node*node=root;
        for(int i =31;i>=0;i--)
        {
            int bit = (num>>i)&1;
            if(!node->containsKey(bit))
            {
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int getMax(int num)
    {
        Node*node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--)
        {
            int bit= (num>>i)&1;
            // keep maximizing the xor 
            if(node->containsKey(1-bit)) // We check for the opposite parity node 
            {
                maxNum=maxNum|(1<<i);//As we set the max num with 32-bit 0's 
                node=node->get(1-bit);
            }
            else 
            node=node->get(bit);
        }
        return maxNum;
    }
};

int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int it:nums) trie.insertNum(it);
        int maxi=0;
        for(int it:nums) maxi=max(maxi,trie.getMax(it));
        return maxi;
    }