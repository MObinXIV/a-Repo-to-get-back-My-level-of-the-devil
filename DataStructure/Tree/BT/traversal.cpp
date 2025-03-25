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
  // Root/Left/Right
 void preOrder(TreeNode*root){
    if (root == NULL)
        return;
        cout<<root->val<<" ";
        preOrder(root->left);
        preOrder(root->right);
 }

 void inOrder(TreeNode*root){
    if (root==NULL)
    return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
 }

 void postOrder(TreeNode*root){
    if(root ==NULL)
    return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
 }

 int main() 
 {    
    TreeNode*root=new TreeNode(10);
    root->left= new TreeNode(5);
    root->right= new TreeNode(15);
    root->left->left= new TreeNode(3);
    root->left->left->left= new TreeNode(1);
    root->left->right= new TreeNode(7);

    root->left->right->left= new TreeNode(6);
    root->right->left= new TreeNode(13);
    root->right->right= new TreeNode(18);
    postOrder(root);
    
 }
