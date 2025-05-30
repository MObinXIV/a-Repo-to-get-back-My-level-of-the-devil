//https://leetcode.com/problems/search-in-a-binary-search-tree/description/
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
 TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) return NULL;
        if(root->val==val)
        return root;
        if(root->val <val) return searchBST(root->right,val);
        else return searchBST(root->left,val);
 }