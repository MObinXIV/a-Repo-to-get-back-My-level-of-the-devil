//https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1
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
 struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
 int inOrderSuccessor(Node *root, Node *x) {
        Node*successor=NULL;
        while(root!=NULL)
        {
            if(x->data>=root->data)
            {   
                root=root->right;
            }
            else{
                successor=root;
                root=root->left;
            }
        }
        return successor ? successor->data : -1;
    }
