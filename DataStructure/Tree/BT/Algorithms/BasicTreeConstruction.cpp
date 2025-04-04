#include<bits/stdc++.h> 
 using namespace std;
 struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
 };

 void printTree(Node*root){
    if(root == NULL)
    return;
    cout<<root->data<<" ";
    printTree(root->left);
    printTree(root->right);
 }

 int main() 
 {    
    Node*root= new Node(1);
    root->left= new Node(2);
    root->right= new Node(5);
    root->left->right= new Node(9);
    printTree(root);
 }
