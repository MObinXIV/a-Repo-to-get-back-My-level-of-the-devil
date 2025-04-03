//https://leetcode.com/problems/balanced-binary-tree/description/
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
Whenever the tree got unbalancing , we stop traverse 
O(n)
 */
 int maxDepth(TreeNode* root) {
        
   if (root ==NULL)
       return 0;
       int l=maxDepth(root->left);
      //  cout<<"left is "<<l<<endl;
       if(l==-1) return -1;
       int r=maxDepth(root->right);
      //  cout<<"right is "<<r<<endl;
      if(r==-1) return -1;
      // check to stop before we reach to the other one
      if(abs(l-r)>1) return -1 ;
       return max(l,r)+1;
   
   }
 bool isBalanced(TreeNode* root) {
  return maxDepth(root)!=-1;
}
 int main() 
 {    
    TreeNode*root=new TreeNode(1);
    root->left= new TreeNode(2);
    root->right= new TreeNode(2);
    
    root->left->left= new TreeNode(2);
    root->left->right= new TreeNode(3);
    root->left->left->left= new TreeNode(3);
    root->left->left->right= new TreeNode(3);
    root->left->left->right->left= new TreeNode(4);
    root->left->left->right->right= new TreeNode(4);


    cout<<"The tree is "<<isBalanced(root)<<" balanced"<<endl;
  
    
 }