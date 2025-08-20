//https://leetcode.com/problems/subtree-of-another-tree/description/
#include<bits/stdc++.h>
using namespace std;
/*
we use same tree logic to solve this problem
we only keep tracking the subtrees of the main tree recursivly 
instead of  only compare 2 trees as the main same tree problem , by 
the way we use the same tree function to solve
*/
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  bool isSameTree(TreeNode*root1, TreeNode*root2){
    if(root1==NULL || root2==NULL) return (root1==root2);

    return (root1->val==root2->val) && isSameTree(root1->left,root2->left) && isSameTree(root1->right,root2->right);
  }

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;
        // case identical both 
        if(isSameTree(root,subRoot)) return true;
        // check left & right guys possiblities 
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }