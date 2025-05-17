//https://leetcode.com/problems/insert-into-a-binary-search-tree/description/
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
 // Helper function to find the minimum value in a subtree (inorder successor)
 TreeNode*min(TreeNode*node){
    TreeNode*cur=node;
    while(cur && cur->left) cur=cur->left;
    return cur;

 }
 TreeNode* deleteNode(TreeNode* root, int key) {
        if (root==NULL) return NULL;
        else if (key<root->val) root->left=deleteNode(root->left,key);
        else if (key>root->val)
            root->right=deleteNode(root->right,key);
            else{
                if(root->left==NULL && root->right==NULL)
                {
                    delete root;
                    root=NULL;
                }
                else if (root->left==NULL)
                {
                    TreeNode*t=root;
                    root=root->right;
                    delete t;
                }
                else  if (root->right==NULL)
            {
            TreeNode*t=root;
                root=root->left;
                delete t;
            }
            else{
                TreeNode*tmp= min(root->right);// get the minimum right guy in the left subtree
                root->val=tmp->val;
                // delete from the right tree 
                root->right=deleteNode(root->right,tmp->val);// Recursively delete successor node
            }
            }
            return root;     
    }
