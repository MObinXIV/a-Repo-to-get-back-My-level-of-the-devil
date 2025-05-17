//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
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
 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root==p || root==q) return root;
        TreeNode*left=lowestCommonAncestor(root->left,p,q);
        TreeNode*right = lowestCommonAncestor(root->right,p,q);
        if(left==NULL) return right;
        if(right==NULL) return left;
        return root;

    }
    //O(h)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val <p->val && root->val <q->val) // if my nodes lies in the left part (BST properities)
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        // see if both if them lies on the left 
        if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left,p,q);
        // neither this nor that I can define this node as my LCA
        return root;
    }