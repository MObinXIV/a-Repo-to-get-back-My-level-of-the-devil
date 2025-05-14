//https://leetcode.com/problems/diameter-of-binary-tree/
#include<bits/stdc++.h> 
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
int maxDepth(TreeNode*root , int&diameter){
    if(root==NULL) return 0 ; 
    
    int lh= maxDepth(root->left,diameter);
    int rh=maxDepth(root->right,diameter);
    // get the diameter for every node while traversing
    diameter = max(diameter,lh+rh);

    return 1+max(lh,rh);
 }
 int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
         maxDepth(root,diameter);
                  return diameter;

 }