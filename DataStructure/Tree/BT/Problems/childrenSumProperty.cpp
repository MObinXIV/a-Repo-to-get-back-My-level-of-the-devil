//https://www.geeksforgeeks.org/problems/children-sum-parent/1
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

 struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
//O(n)
int isSumProperty(Node *root) {
        if(root==NULL) return 1;//empty tree
        // check for leafs 
        if(root->right==NULL && root->left==NULL) return 1 ;
        int left=  (root->left)?root->left->data :0;
        int right = (root->right)?root->right->data:0;
        return (right+left==root->data)&&isSumProperty(root->left)&&isSumProperty(root->right);
    }