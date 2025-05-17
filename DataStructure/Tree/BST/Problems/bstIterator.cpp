//https://leetcode.com/problems/binary-search-tree-iterator/description/
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
class BSTIterator {
    private:
    stack<TreeNode*>st;
    void pushToLeft(TreeNode*node)
    {
        while(node!=NULL)
        {
            st.push(node);
            node=node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushToLeft(root);
    }
    // Return the next smallest element 
    int next() {
        // get the top value of the stack & start get the right subtree 
        TreeNode*curr=st.top();
        st.pop();
        // If there is a right subtree, push all its left children
        if(curr->right!=NULL)
        pushToLeft(curr->right);
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};