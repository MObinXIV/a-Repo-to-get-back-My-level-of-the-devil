//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
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
 /*
 Bfs normally 
 the tip is to  reverse indexint in every level 
 */
 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL) return res;
        queue <TreeNode*>q;
        bool f= true;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>level(size);

          for ( int i = 0 ; i< size;i++){
            TreeNode*node=q.front(); // get the nodes of the level 
            // pop it from the queue
            q.pop();
            int ind = (f) ? i : (size-1-i);
            level[ind]= node->val;
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
          }
          f=!f;
          res.push_back(level);
        }

         return res;
 }
 int main() 
 {    
    TreeNode*root=new TreeNode(3);
    root->left= new TreeNode(9);
    root->right= new TreeNode(20);
    
    root->right->left= new TreeNode(15);
    root->right->right= new TreeNode(7);
    vector<vector<int>>ans=zigzagLevelOrder(root);
    for (const auto& v : ans) {  // Iterate through levels
      for (int num : v) {  // Print elements in the level
          cout << num << " ";
      }
      cout << endl; // Move to next line for next level
  }
    
 }



