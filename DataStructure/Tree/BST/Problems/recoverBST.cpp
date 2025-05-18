//https://leetcode.com/problems/recover-binary-search-tree/description/
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
 class Solution {
private:
TreeNode*first;
TreeNode*prev;
TreeNode*middle;
TreeNode*last;
private:
void inorder(TreeNode*root){
    if(root==NULL) return;

    inorder(root->left);
    if(prev!=NULL&& root->val<prev->val){
        // if it's the first violation 
        if(first==NULL)
        {
            // let's store 
            first=prev;
            middle=root;
        }
        // case the nodes are n't adjacent & I got second violation
        else
        last=root;
    }
    prev=root;
    inorder(root->right);
}
public:
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        // in case the aren't adjacent 
        if(first&&last) swap(first->val,last->val);
        else if(first && middle) swap(first->val,middle->val);
    }
};