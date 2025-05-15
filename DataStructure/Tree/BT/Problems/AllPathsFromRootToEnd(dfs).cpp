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

 struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// gfg one 

class Solution {
  public:
    void dfs (Node*root,vector<int>&path,vector<vector<int>>&res)
{
    if(root==NULL) return;
   path.push_back(root->data);
   if(!root->left && !root->right)
   res.push_back(path);
   
   dfs(root->left,path,res);
   dfs(root->right,path,res);
   //bactrack
   path.pop_back();
}
 vector<vector<int>> Paths(Node* root) {
       vector<vector<int>> res;
        vector<int> path;
        dfs(root, path, res);
        return res;   
    }
};
// leetcode one 
void dfs (TreeNode*root,string path,vector<string>&res)
{
    if(root==NULL) return;
    if(!path.empty()) path+="->";
   path+=to_string(root->val);
   if(!root->left && !root->right)
   {
    res.push_back(path);
        return;
    }
   
   dfs(root->left,path,res);
   dfs(root->right,path,res);
}
 vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
 