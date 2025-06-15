//https://leetcode.com/problems/count-good-nodes-in-binary-tree/
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

// DFS Traversal to count good nodes
void dfs(TreeNode* root, int mx , int&cnt) {
    if (root == NULL) return;

    if (root->val >= mx) {
        cnt++;
        mx = root->val;
    }

    dfs(root->left, mx,cnt);
    dfs(root->right, mx,cnt);
}

int goodNodes(TreeNode* root) {
    int cnt = 0; 
    dfs(root, root->val,cnt); 
    return cnt;
}