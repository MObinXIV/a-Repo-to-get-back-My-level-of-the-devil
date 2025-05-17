//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
 
 TreeNode* buildTree(vector<int>&arr,int&i,int bound){
    if(i==arr.size()||arr[i]>bound) return NULL;
    TreeNode*root= new TreeNode(arr[i++]);// create the node & move yourself to the next index
    // construct the left tree 
    root->left= buildTree(arr,i,root->val);
    root->right = buildTree(arr,i,bound);
    return root;
 }

  TreeNode* bstFromPreorder(vector<int>& preorder) {
       int i=0;
        return buildTree(preorder,i,INT_MAX);
    }