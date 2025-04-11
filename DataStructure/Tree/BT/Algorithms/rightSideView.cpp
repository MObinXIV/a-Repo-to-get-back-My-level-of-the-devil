//https://leetcode.com/problems/binary-tree-right-side-view/
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

 // We use I value level as a flag , we compare it with the size of the ans 
 // if we take it before the ans size 'll be bigger than the guy in the left

 void f(TreeNode*root, int level,vector<int>&res){
    if(root==NULL) return;

    if(level==res.size())
    res.push_back(root->val);
    f(root->right,level+1,res);
    f(root->left,level+1,res);
    
 }

 vector<int> rightSideView(TreeNode* root) {
       vector<int>res;
       f(root,0,res);
       return res;
 }
 int main() 
 {    

    TreeNode*root = new TreeNode(1);
    root->left=new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(5);
    vector<int> res = rightSideView(root);
    for(int&it:res)
    cout<<it<<" ";
    
 }