//https://leetcode.com/problems/all-possible-full-binary-trees/description/
#include <bits/stdc++.h>
using namespace std;
/**]
 * in every root must be odd number of nodes to the left & also right 
 * so even n's not even valid 
 * for each iteration we do normally left & right then combine
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
    map<int,vector<TreeNode*>>memo;
public:
    
    vector<TreeNode*> allPossibleFBT(int n) {
        if(memo.find(n)!=memo.end()) return memo[n];
        vector<TreeNode*>res;
        // in case n is even we can't genarate 
        if(n%2==0) return res;
        
        // case we got single node 
        if(n==1){
            res.push_back(new TreeNode(0));
            return res;
        }
        // try every possible valid count the count must be odd in both sides 
        for(int leftCnt=1;leftCnt<n;leftCnt+=2){
            int rightCnt=n-leftCnt-1;
            if(rightCnt%2==0) continue; // this is not possible 
            // now normally genarate left & right them combine results 

            // split left & right 
            vector<TreeNode*>left=allPossibleFBT(leftCnt);
            vector<TreeNode*>right=allPossibleFBT(rightCnt);
            // now combine 
            for(TreeNode*l:left){
                for(TreeNode*r:right){
                    TreeNode*root= new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    res.push_back(root);
                }
            }

        }
        return memo[n]=res;
        }
};