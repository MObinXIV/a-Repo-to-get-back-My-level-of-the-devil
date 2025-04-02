//https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
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

 void f(TreeNode*root,int cnt , int& maxi){
   if(root==NULL)
   {
      if(cnt>maxi)
      maxi = cnt;
      cnt=0;
      return;
   }
   f(root->left,cnt+1,maxi);
   f(root->right,cnt+1,maxi);
   
 }
 int maxDepth(TreeNode* root) {
        int maxi=0,cnt=0;
        f(root,cnt,maxi);
        return maxi;
 }
 int maxDepth(TreeNode* root) {
        
   if (root ==NULL)
       return 0;
       int l=maxDepth(root->left);
       int r=maxDepth(root->right);
       return max(l,r)+1;
   
   }
 int main() 
 {    
    TreeNode*root=new TreeNode(3);
    root->left= new TreeNode(9);
    root->right= new TreeNode(20);
    
    root->right->left= new TreeNode(15);
    root->right->right= new TreeNode(7);
    cout<<maxDepth(root);
   
    
 }

 