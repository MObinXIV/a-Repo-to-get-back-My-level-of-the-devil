TreeNode* makeParent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parentTrack,int start)
{
    TreeNode*startNode=NULL;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode*node=q.front();
        q.pop();
        if(node->val==start) startNode = node;
        if(node->left)
        {
            parentTrack[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            parentTrack[node->right]=node;
            q.push(node->right);
        }
    }
    return startNode;
}
// Same kDistance idea 
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parentTrack;
        unordered_map<TreeNode*,bool>visited;
    TreeNode* startNode = makeParent(root, parentTrack, start);
        queue<TreeNode*>q;
        q.push(startNode);
        visited[startNode]=true;
        int time=-1;
        while(!q.empty()){
            int size=q.size();
            time++;
            for(int i =0 ;i<size;i++){
                TreeNode*node=q.front();
                q.pop();
                /*
                infect them all the way
                */
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parentTrack[node]&&!visited[parentTrack[node]])
                {
                    q.push(parentTrack[node]);
                    visited[parentTrack[node]]=true;
                }
                
            }
        }
        return time;
    }
