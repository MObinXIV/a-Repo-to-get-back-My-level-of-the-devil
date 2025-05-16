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
 TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd,
                    vector<int>& postorder, int postStart, int postEnd,
                    unordered_map<int, int>& inMap) {
    if (inStart > inEnd || postStart > postEnd) return NULL;
    // Step 1: The current root is the last element in postorder
    TreeNode* root = new TreeNode(postorder[postEnd]);
    // Step 2: Get index of root in inorder traversal
    int inRoot = inMap[root->val];
    // Step 3: Calculate number of nodes in right subtree
    int rightSize = inEnd - inRoot;
    // Do the same by indexing the new left preorder & the new inorder for the left guys & also the right guys
    root->right = buildTree(inorder,inRoot+1, inEnd, postorder, postEnd -rightSize, postEnd-1, inMap);
    root->left = buildTree(inorder, inStart, inRoot - 1,postorder, postStart, postEnd- rightSize - 1, inMap);

    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    return buildTree(inorder, 0, inorder.size() - 1,postorder, 0, postorder.size() - 1, inMap);
    }