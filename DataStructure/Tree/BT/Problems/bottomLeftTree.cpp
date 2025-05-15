//https://leetcode.com/problems/find-bottom-left-tree-value/description/
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
 // keep getting the first node in each level 
 int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        int leftNode= root->val;
        q.push(root);
        while(!q.empty()){
            leftNode=q.front()->val;
            int size=q.size();
            for(int i = 0 ; i<size;i++)
            {
                TreeNode*node=q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
        }
        return leftNode;
    }