//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
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
 TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    map<int, int>& inMap) {
    if (inStart > inEnd || preStart > preEnd) return NULL;
    // Step 1: The current root is the first element in preorder
    TreeNode* root = new TreeNode(preorder[preStart]);
    // Step 2: Get index of root in inorder traversal
    int inRoot = inMap[root->val];
    // Step 3: Calculate number of nodes in left subtree
    int numsLeft = inRoot - inStart;
    // Do the same by indexing the new left preorder & the new inorder foir the left guys & also the right guys
    root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
}