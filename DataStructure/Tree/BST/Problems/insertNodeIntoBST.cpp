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
 
 TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        if(val<root->val)
        root->left=insertIntoBST(root->left,val);
        else
        root->right=insertIntoBST(root->right,val);
        return root;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        TreeNode*cur=root;
        while(true){
            if(cur->val<val)
            {
                // move 
                if(cur->right != NULL) cur=cur->right;
                else
                {
                    cur->right= new TreeNode(val);
                    break;
                }
            }
            else{
                if(cur->left!=NULL) cur=cur->left;
                else{
                    cur->left=new TreeNode(val);
                }
            }
        }
        return root;
    }