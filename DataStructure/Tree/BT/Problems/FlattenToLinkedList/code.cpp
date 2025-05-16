//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
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
    TreeNode*prev;
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        // get the current nodes right
        root->right=prev;
        // flat by eleminate the left 
        root->left=NULL;
        // store the current node for the next bactrack
        prev=root;
    }
};

void flatten(TreeNode* root) {
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode*node=st.top();
        st.pop();
        if(node->right)
        st.push(node->right);
        if(node->left) st.push(node->left);
        // flatten
        if(!st.empty())
        {
            node->right=st.top();
        }
        node->left=NULL;
    }
}

void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr) {
            if (curr->left) {
                TreeNode* pred = curr->left;
                while (pred->right) {
                    pred = pred->right;
                }

                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
