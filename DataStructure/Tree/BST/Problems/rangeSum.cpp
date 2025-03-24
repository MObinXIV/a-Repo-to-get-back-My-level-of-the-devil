//https://leetcode.com/problems/range-sum-of-bst/description/
#include<bits/stdc++.h> 
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

 void f(TreeNode*root , int low , int high , int&sum){
    if(root==NULL) return;
    if(root->data>= low && root->data<=high)
    {
        cout<<root->data<<endl;
        sum+=root->data;}

    f(root->left,low,high,sum);
    f(root->right,low,high,sum);


 }
 int rangeSumBST(TreeNode* root, int low, int high) {
        int sum =0 ;
        f(root,low,high,sum);
        return sum;
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
    
    cout<<rangeSumBST(root,6,10)<<endl;
 }
