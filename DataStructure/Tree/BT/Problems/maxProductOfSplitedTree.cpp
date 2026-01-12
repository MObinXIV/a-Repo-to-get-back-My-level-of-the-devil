//https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/
#include <bits/stdc++.h>
using namespace std;
/*At each node:
    "What if I cut the edge above THIS subtree?"
    product = subtree × rest
*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
// the sum of the tree 
long long  sumOfTheTree(TreeNode*root){
    if(root==NULL) return 0;
    return root->val+sumOfTheTree(root->left)+sumOfTheTree(root->right);
  
}
long long  f(TreeNode*root,long long  sum , long long &maxi){
    if(root==NULL) return 0;
    long long  left = f(root->left,sum,maxi);
    long long  right = f(root->right,sum,maxi);
    long long subTreeSum=root->val+left+right;
    // (sum-subTreeSum) -> remaing sum * subTreeSum
     maxi = max(maxi,(sum-subTreeSum)*subTreeSum);
     return subTreeSum;
}
int maxProduct(TreeNode* root) {
        long long  sumOfTree= sumOfTheTree(root);
        long long  maxi=0;
        int mod = 1e9+7;
        f(root,sumOfTree,maxi);
        return maxi%mod;
    } 