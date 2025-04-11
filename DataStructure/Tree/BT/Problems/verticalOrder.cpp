//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
#include<bits/stdc++.h> 
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

 vector<vector<int>> verticalTraversal(TreeNode* root) {
    // Map to store nodes grouped by their vertical (x) and level (y)
    // Format: map<x, map<y, multiset of node values>>
        map<int,map<int,multiset<int>>>nodes; // vertical level multi nodes 
            // Queue for BFS traversal: stores {TreeNode*, {x, y}}
        queue<pair<TreeNode*,pair<int,int>>> q; // used to get the node & it's vertical & level
        q.push({root,{0,0}}); // push the first level 
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int x = p.second.first , y = p.second.second; // get the verticals 
            // get the node 
            TreeNode*node = p.first;
            // push the node into the myltiset
            nodes[x][y].insert(node->val);

            if(node->left)
            q.push({node->left,{x-1,y+1}});
            if (node->right)
            q.push({node->right,{x+1,y+1}});
        }

        vector<vector<int>>ans;
        for(auto p :nodes){
            vector<int>col;
            for(auto it:p.second)
            col.insert(col.end(),it.second.begin(),it.second.end());
            ans.push_back(col);
        }
        return ans;
 }
 
 int main() 
 {    

    TreeNode*root = new TreeNode(3);
    root->left=new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    vector<vector<int>>ans = verticalTraversal(root);
    for (const auto& v : ans) {  // Iterate through levels
      for (int num : v) {  // Print elements in the level
          cout << num << " ";
      }
      cout << endl; // Move to next line for next level
  }
    
 }