//https://leetcode.com/problems/maximum-width-of-binary-tree/description/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int val){
        this->val=val;
        left=right=NULL;
    }
 };

 struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long>>q;
        q.push({root,1});
        unsigned long long maxWidth=1;
        while(!q.empty()){
            int size=q.size();
            // get the left index of the current level 
            unsigned long long leftIndex = q.front().second;// Index of the leftmost node at this level
            unsigned long long rightIndex=leftIndex;//intialize the rightmostidx
            for(int i = 0 ; i<size;i++){
                auto it =q.front();
                q.pop();
                // get the index of the parent
                unsigned long long index = it.second;
                TreeNode*node=it.first;
                // keep assinging the right index as we move right 
                rightIndex=index;
                if(node->left!=NULL) q.push({node->left,index*2});// assign the left child formula
                if(node->right!=NULL) q.push({node->right,index*2+1});//assign the right child formula
            }
            maxWidth=max(maxWidth,rightIndex-leftIndex+1);
            
        }
        return maxWidth;
    }