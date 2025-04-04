//https://leetcode.com/problems/same-tree/
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

 int maxDepth(TreeNode*root , int&maxi){
    if(root==NULL) return 0 ; 
    
    int lh = max(0,maxDepth(root->left,maxi));
    int rh=max(0,maxDepth(root->right,maxi));
    maxi = max(maxi,rh+lh+root->val);
    return root->val+max(lh,rh);
 }
 bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==NULL || q==NULL)return (p==q);  // if both null or not        
    return (p->val==q->val)&& isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
           
     }

 int main() 
 {    
    
    TreeNode*root=new TreeNode(1);
    root->left= new TreeNode(2);
    root->right= new TreeNode(3);

    TreeNode*root1=new TreeNode(1);
    root1->left= new TreeNode(2);
    root1->right= new TreeNode(3);

    cout<<isSameTree(root1,root)<<endl;
    
 }
