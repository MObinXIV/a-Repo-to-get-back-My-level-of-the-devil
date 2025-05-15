//Bottom view 
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
 // same vertical traversal , but to get the top view we only push the last seen node in the level 
vector<int>bottomView(TreeNode*root){
    vector<int>ans;
    if(root==NULL) return ans;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    map<int,int>mp;// a map to trace vertical with values  
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode*node=it.first;
        int level = it.second;
         mp[level]=node->val;
       //  normal bfs 
       if(node->left!=NULL) q.push({node->left,level-1});
       if(node->right!=NULL) q.push({node->right,level+1});
    }
    for(auto&it:mp)
    ans.push_back(it.second);
}