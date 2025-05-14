//AllInOneTraversal
#include <bits/stdc++.h>
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
vector<vector<int>>preInPostTraversal(Node*root){
    stack<pair<Node*,int>>st;
    st.push({root,1});
    vector<int>pre,in,post;
    if(root == NULL) return;
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        if(it.second==1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);// save for the in
            if(it.first->left!=NULL){
                st.push({it.first->left,1});
            }
        }
        else if (it.second==2){
            in.push_back(it.first->data);
            it.second++;
            if(it.first->right!=NULL)
            {
                st.push({it.first->left,1});
            }
        }
        else{
            pre.push_back(it.first->data);
        }
    }
}