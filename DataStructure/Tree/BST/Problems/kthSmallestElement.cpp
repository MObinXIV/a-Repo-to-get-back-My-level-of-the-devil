//https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
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
 void fillPQ(TreeNode* root, priority_queue<int, vector<int>, greater<int>>& pq) {
    if (!root) return;
    pq.push(root->val);
    fillPQ(root->left, pq);
    fillPQ(root->right, pq);
}

int kthSmallest(TreeNode* root, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    fillPQ(root, pq);
    while (--k > 0) {
        pq.pop();
    }
    return pq.top();
}
// other solution with using the consept of sorting inorder in getting the sorted tree 
void inorderTraversal(TreeNode*root,int&cnt,int&res,int k)
{
    if(root==NULL) return;
    inorderTraversal(root->left,cnt,res,k);
    // increase the count when U back 
    cnt++;
    if(cnt==k)
    {
        res=root->val;
    }
    inorderTraversal(root->right,cnt,res,k);

}
int kthSmallest(TreeNode* root, int k) {
    int cnt=0,res=-1;
    inorderTraversal(root,cnt,res,k);
    return res;
}