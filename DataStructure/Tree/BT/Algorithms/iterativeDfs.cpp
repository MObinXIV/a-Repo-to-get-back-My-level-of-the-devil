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
vector<int>preOrder(TreeNode*root){
   vector<int>preOrder;
   if (root ==NULL) return preOrder;

   stack<TreeNode*>st;
   st.push(root);
   while(!st.empty()){
      root=st.top();
      st.pop();
      preOrder.push_back(root->val);
      if(root->right!=NULL)
      st.push(root->right);
      if(root->left!=NULL)
      st.push(root->left);
   }
   return preOrder;
}

vector<int>inOrder(TreeNode*root){
   stack<TreeNode*>st;
   vector<int>inOrder;
   TreeNode*node=root;
   while(true){
      // go left as long as U can 
      if(node!=NULL)
      {
         st.push(node);
         node=node->left;
      }
      else{
         if(st.empty()) break;
         node=st.top(); // get the last node entered
         st.pop();
         inOrder.push_back(node->val);
         // move right 
         node = node->right;
      }
   }
   return inOrder;
}


vector<int> postOrder(TreeNode* root) {
   // Vector to store
   // postorder traversal
   vector<int> postorder;

   // If the tree is empty,
   // return an empty traversal
   if(root == NULL){
       return postorder;
   }

   // Two stacks for
   // iterative traversal
   stack<TreeNode*> st1, st2;

   // Push the root node
   // onto the first stack
   st1.push(root);

   // Iterative traversal to populate
   // st2 with nodes in postorder
   while(!st1.empty()){
       // Get the top node from st1
       root = st1.top();
       st1.pop();

       // Push the node onto st2
       st2.push(root);

       // Push left child onto st1 if exists
       if(root->left != NULL){
           st1.push(root->left);
       }

       // Push right child onto st1 if exists
       if(root->right != NULL){
           st1.push(root->right);
       }
   }

   // Populate the postorder traversal 
   // vector by popping st2
   while(!st2.empty()){
       postorder.push_back(st2.top()->val);
       st2.pop();
   }

   // Return the
   // postorder traversal
   return postorder;
}

vector<int>  pstOrdr(TreeNode*root){
   stack<TreeNode*>st;
   TreeNode*cur=root;
   vector<int>post;
   while(cur!=NULL || !st.empty()){
      if(cur!=NULL)
      {
         st.push(cur);
         cur=cur->left;
      }
      else{
         TreeNode*tmp=st.top()->right; // got the guy of the right of my last left node
         if(tmp==NULL) // If I got none in the right of my last left guy 
         {
            tmp=st.top();
            st.pop();
            post.push_back(tmp->val);
            while(!st.empty() && tmp==st.top()->right){
               tmp=st.top();
               st.pop();
               post.push_back(tmp->val);
            }
         }
         else
         cur=tmp;
      }
   }
   return post;
}

 int main() 
 {    
    TreeNode*root=new TreeNode(3);
    root->left= new TreeNode(9);
    root->right= new TreeNode(20);
    
    root->right->left= new TreeNode(15);
    root->right->right= new TreeNode(7);
    vector <int>v=pstOrdr(root);
    for(int&it:v)
    cout<<it<<" ";
   
    
 }

