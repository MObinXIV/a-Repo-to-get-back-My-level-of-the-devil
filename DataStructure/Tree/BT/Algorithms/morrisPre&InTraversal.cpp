//Morris Traversal
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
 vector<int>getInorder(TreeNode*root){
    vector<int>inorder;
    TreeNode*cur=root;
    while(cur!=NULL)
    {
        if(cur->left==NULL){
            inorder.push_back(cur->val);
            cur=cur->right;
        }
        // go to the right most element in the left subtree
        else{
            TreeNode*prev=cur->left;
            while(prev->right &&prev->right!=cur){
                prev=prev->right;
            }
            if(prev->right==NULL)// link thread with the cur 
            {
                prev->right=cur;
                // move the cur to the left portion of the tree
                cur=cur->left;
            }
            else{
                // we remove the thread again 
                prev->right=NULL;
                inorder.push_back(cur->val);//it's the root now
                cur=cur->right;
            }
        }
        return inorder;
    }
 }

 vector<int>getPreorder(TreeNode*root){
    vector<int>preorder;
    TreeNode*cur=root;
    while(cur!=NULL)
    {
        if(cur->left==NULL){
            preorder.push_back(cur->val);
            cur=cur->right;
        }
        // go to the right most element in the left subtree
        else{
            TreeNode*prev=cur->left;
            while(prev->right &&prev->right!=cur){
                prev=prev->right;
            }
            if(prev->right==NULL)// link thread with the cur 
            {
                prev->right=cur;
                // move the cur to the left portion of the tree
                preorder.push_back(cur->val);//it's the root now
                cur=cur->left;
            }
            else{
                // we remove the thread again 
                prev->right=NULL;
                cur=cur->right;
            }
        }
        return preorder;
    }
 }
