// //https://www.lintcode.com/problem/878
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
 left->leafs, right in a reversed order 
 */
class Solution {
 // left boundary 
 void leftBoundry(TreeNode*root , vector<int>&res){
    // if it's a leaf 
    if (!root || (!root->left && !root->right)) return;

    res.push_back(root->val);
    if (root->left) 
    leftBoundry(root->left, res);
    else 
    leftBoundry(root->right, res);
 }

 // leaf boundary 
 void leafBoundry(TreeNode*root , vector<int>&v){
    if(root==NULL) return;
    if(!root->left && !root->right)
    {v.push_back(root->val); return;}
    leafBoundry(root->left,v);
    leafBoundry(root->right,v);
 }
 void rightBoundary(TreeNode*root, vector<int>&res){
    if (!root || (!root->left && !root->right)) return;
    if (root->right) 
    rightBoundary(root->right, res);
    else 
    rightBoundary(root->left, res);
    res.push_back(root->val);

 }
 vector<int> boundaryOfBinaryTree(TreeNode *root) {
    vector<int>res;
    res.push_back(root->val);
    leftBoundry(root->left,res);
   //  leafBoundry(root->left,res);
   //  leafBoundry(root->right,res);
   //  rightBoundary(root->right,res);
    return res;
}};

bool isLeaf(TreeNode*root){
   return !root->left && !root->right;
}

void leftBoundry(TreeNode*root , vector<int>&res){
    TreeNode*cur= root->left;
    while(cur){
     if(!isLeaf(cur))res.push_back(cur->val);
     if(cur->left) cur=cur->left;
     else
     cur=cur->right;
      
    }
}

void rightBoundry(TreeNode*root , vector<int>&res){
   TreeNode*cur= root->right;
   vector<int> temp;

   while(cur){
    if(!isLeaf(cur))temp.push_back(cur->val);
    if(cur->right) cur=cur->right;
    else
    cur=cur->left;
     
   }
   for (int i = temp.size() - 1; i >= 0; --i) {
      res.push_back(temp[i]);
  }
}

void leafBoundry(TreeNode*root , vector<int>&v){
   if(root==NULL) return;
   if(isLeaf(root))
   {v.push_back(root->val); return;}
   leafBoundry(root->left,v);
   leafBoundry(root->right,v);
}

vector<int> boundaryOfBinaryTree(TreeNode *root) {
   vector<int>res;
   res.push_back(root->val);
   leftBoundry(root,res);
   leafBoundry(root,res);
   rightBoundry(root,res);
   return res;
}
 int main() 
 {    
        TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right->left = new TreeNode(6);
    root->right->left->left = new TreeNode(9);
    root->right->left->right = new TreeNode(10);

    // Getting the boundary of the binary tree
    vector<int> boundary = boundaryOfBinaryTree(root);

    // Printing the boundary
    for (int num : boundary) 
        cout << num << " ";
    
 }
