//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
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
void makeParent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parentTrack)
{
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode*node=q.front();
        q.pop();
        if(node->left)
        {
            parentTrack[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            parentTrack[node->right]=node;
            q.push(node->right);
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parentTrack;
        makeParent(root,parentTrack);//now I got parent for each node 
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        // start with target 
        q.push(target);
        // mark it as visited 
        visited[target]=true;
        int cur_level=0;
        while(!q.empty())
        {
            int size=q.size();
            // in case I satisfied k no now we break
            if(cur_level==k) break;
            cur_level++;
            for(int i=0;i<size;i++){
                TreeNode*cur=q.front();
                q.pop();
                if(cur->left && !visited[cur->left])
                {
                    q.push(cur->left);
                    visited[cur->left]=true;
                }
                if(cur->right && !visited[cur->right])
                {
                    q.push(cur->right);
                    visited[cur->right]=true;
                }
                // check for the parent 
                if(parentTrack[cur]&&!visited[parentTrack[cur]])
                {
                    q.push(parentTrack[cur]);
                    visited[parentTrack[cur]]=true;
                }

            }
        }
        vector<int>res;
        while(!q.empty()){
            TreeNode*cur=q.front();
            q.pop();
            res.push_back(cur->val);
        }
        return res;
    }