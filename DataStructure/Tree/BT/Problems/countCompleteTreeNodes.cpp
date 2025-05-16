//https://leetcode.com/problems/count-complete-tree-nodes/description/
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
 int countNodes(TreeNode* root) {
    if(root == NULL) return 0;
    // 1 for the current node + nodes in left subtree + nodes in right subtree
    return 1 + countNodes(root->left) + countNodes(root->right);
}