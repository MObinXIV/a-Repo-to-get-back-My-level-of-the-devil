//https://leetcode.com/problems/unique-binary-search-trees-ii/description/
#include <bits/stdc++.h>
using namespace std;
/**
 * using divide & conquer with dp 
 * try every possible root from 1->n
 * construct left subtree & right subtree
 * combine the left subtree & right subtree with root 
 * cash the key(start,end) in map with the result which include the root value 
 */
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
private:
    map<pair<int,int>,vector<TreeNode*>>memo;
public:

    vector<TreeNode*>generateTrees(int st, int end){
        pair<int,int>key={st,end};
        if(memo.find(key)!=memo.end()) return memo[key];
        vector<TreeNode*>result;
        if(st>end){
            result.push_back(NULL);
            return result;
        }
        for(int i = st; i<=end;i++){
            // divide left subtree 
            vector<TreeNode*>left=generateTrees(st,i-1);
            vector<TreeNode*>right=generateTrees(i+1,end);
            // combine 
            for(TreeNode*l:left)
            {
                for(TreeNode*r:right){
                    // the root is the current i 
                    TreeNode*root=new TreeNode(i);
                    // construct the left subtree 
                    root->left=l;
                    // construct the right subtree
                    root->right=r;
                    // push the root to result
                    result.push_back(root);
                }
            }
        }
        return memo[key]=result;
    }
     vector<TreeNode*> generateTrees(int n) {
       if(n==0) return {};
       return generateTrees(1,n);
    }
};  