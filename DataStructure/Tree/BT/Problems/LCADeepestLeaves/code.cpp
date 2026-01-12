//https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/
#include <bits/stdc++.h>
using namespace std;
/**
* LCA -> Node who has in both sides deepest leaves who has the same depth 
* Post-order DFS: Process children before parent
 * Return two values: {LCA node, depth}
 * Three cases at each node:
    -Equal depths → current node is LCA
    -Left deeper → LCA is in left subtree
    -Right deeper → LCA is in right subtree
 */
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

pair<TreeNode*,int>dfs(TreeNode*root){
    if(!root) return {NULL,0};

    // go recursively search for LCA 
    auto left = dfs(root->left);
    auto right = dfs(root->right);

    // find the depths of left & right 
    int depthLeft = left.second;
    int depthRight = right.second;
    // If the depth of left & right same this is maybe LCA 
    if(depthLeft==depthRight) return {root,depthLeft+1}; // the node with +1 for the current level
    else if(depthLeft>depthRight) // here we go to search in the left side for lca
    return {left.first,depthLeft+1};
    else return {right.first,depthRight+1}; // otherwise we go right
}
