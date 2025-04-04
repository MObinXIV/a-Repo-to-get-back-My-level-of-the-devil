//https://leetcode.com/problems/binary-tree-maximum-path-sum/
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

 int maxDepth(TreeNode*root , int&maxi){
    if(root==NULL) return 0 ; 
    
    int lh = max(0,maxDepth(root->left,maxi));
    int rh=max(0,maxDepth(root->right,maxi));
    maxi = max(maxi,rh+lh+root->val);
    return root->val+max(lh,rh);
 }
 // O(N) solution
 int maxPathSum(TreeNode* root) {
    int m=INT_MIN;
    maxDepth(root,m);
    return m;
 }

 int main() 
 {    
    
    TreeNode*root=new TreeNode(1);
    root->left= new TreeNode(2);
    root->right= new TreeNode(3);
    cout<<maxPathSum(root)<<endl;
    
 }
