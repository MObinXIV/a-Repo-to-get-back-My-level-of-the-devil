//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
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
 string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode*>q;
        q.push(root);
        string s ="";
        while(!q.empty()){
            TreeNode*node= q.front();
            q.pop();
            // the node is null
           if(node==NULL) s+="#,";
           else s.append(to_string(node->val)+',');
           // in case I'm not null I'll push my left & right even if they nulls I handle it 
           if(node!=NULL)
           {
            q.push(node->left);
            q.push(node->right);
           }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream ss(data);
        string str;
        getline(ss,str,',');//it makes it iterate over the string using the separtor
        TreeNode* root = new TreeNode(stoi(str)); // create the root node 
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            getline(ss,str,',');
            //get the left code 
            if(str=="#") node->left=NULL;
            else{
                TreeNode*leftNode=new TreeNode(stoi(str));
                node->left=leftNode;
                q.push(leftNode);
            }
            // go to the next one as my 
            getline(ss,str,',');
            if(str=="#") node->right=NULL;
            else{
                TreeNode*rightNode= new TreeNode(stoi(str));
                node->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }