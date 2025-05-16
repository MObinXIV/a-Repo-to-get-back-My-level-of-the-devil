//https://leetcode.com/problems/maximum-binary-tree/
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int data){
        this->data=data;
        left=right=NULL;
    }
 };
 TreeNode*buildTree(vector<int>&nums,int left,int right){
    if(left>right) return NULL;
    int maxIdx=left;
    for(int i = left+1;i<=right;i++)
    {
        if(nums[i]>nums[maxIdx])
        {
            maxIdx=i;
        }
        
    }
    // construct the maximum node 
    TreeNode * root = new TreeNode(nums[maxIdx]);
    root->left = buildTree(nums,left,maxIdx-1);
    root->right= buildTree(nums,maxIdx+1,right);
    return root;
 }
 // Divide & conquer 
 TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
     return buildTree(nums,0,nums.size()-1); 
    }