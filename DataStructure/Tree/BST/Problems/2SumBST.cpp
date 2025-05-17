//https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1
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
 bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>mp;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode*node=q.front();
            q.pop();
            if(mp.find(k-node->val)!=mp.end()) return true;
            if(node->left)
            q.push(node->left);
            if(node->right) q.push(node->right);
            mp[node->val]++;
        }
        return false;
    }
    // use the sorted inorder property
    bool findTarget(TreeNode* root, int k) {
    vector<int> inorder;

    // Inorder traversal to get sorted elements
    function<void(TreeNode*)> dfs = [&](TreeNode* node) {
        if (!node) return;
        dfs(node->left);
        inorder.push_back(node->val);
        dfs(node->right);
    };

    dfs(root);

    // Two pointer search
    int left = 0, right = inorder.size() - 1;
    while (left < right) {
        int sum = inorder[left] + inorder[right];
        if (sum == k) return true;
        else if (sum < k) left++;
        else right--;
    }

    return false;
}