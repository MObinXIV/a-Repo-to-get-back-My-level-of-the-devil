//https://leetcode.com/problems/binary-tree-paths/description/
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

/**
 We recursively traverse the tree to find nodes p and q.

If the current node is NULL, we return NULL.

If the current node is either p or q, we return that node.

Then we check the left and right subtrees.

If both sides return non-null, that means p is in one subtree and q is in the other — so current node is the LCA.

If only one side is non-null, return that side.
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: If root is NULL, return NULL
    if (root == NULL) return NULL;

    // If current node is p or q, return root (we found one target node)
    if (root == p || root == q) return root;

    // Recur on the left subtree to find p or q
    TreeNode* left = lowestCommonAncestor(root->left, p, q);

    // Recur on the right subtree to find p or q
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If left is NULL, the answer lies in the right subtree
    if (left == NULL) return right;

    // If right is NULL, the answer lies in the left subtree
    else if (right == NULL) return left;

    // If both left and right are non-null, current node is the LCA
    else return root;
        
    }