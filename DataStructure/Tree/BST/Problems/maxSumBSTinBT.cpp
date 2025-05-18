//https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        left = right = NULL;
    }
};

// Structure to store information about a subtree
struct NodeValue {
    int minNode;  // minimum value in the subtree
    int maxNode;  // maximum value in the subtree
    int sum;      // sum of all nodes if it's a valid BST
    
    NodeValue(int minNode, int maxNode, int sum) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->sum = sum;
    }
};

/*
how to validate ?
if the largest element in the left subtree is < root & smallest element in the
right subtree is bigger than root then we valid
*/
class Solution {
private:
    int maxSum = 0;

    // Helper function to do postorder traversal and collect info from children
    NodeValue helper(TreeNode* root) {
        if (root == NULL)
            return NodeValue(INT_MAX, INT_MIN, 0);

        // Recursively get info from left and right subtrees
        auto left = helper(root->left);
        auto right = helper(root->right);

        // Check if the current subtree is a BST
        if (left.maxNode < root->val && root->val < right.minNode) {
            // It is a valid BST, calculate the sum
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, currSum);  // update maxSum if current is greater

            // Return updated min, max and total sum
            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                currSum
            );
        }

        // Not a BST: return invalid range and keep max sum among children
        return NodeValue(INT_MIN, INT_MAX, max(left.sum, right.sum));
    }

public:
    int maxSumBST(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};