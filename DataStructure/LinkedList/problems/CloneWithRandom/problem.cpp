class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node*ptr=head;
        while(ptr!=NULL)
        {
            mp[ptr] = new Node(ptr->val);
            ptr=ptr->next;
        }        

        ptr=head;
        while(ptr)
        {
            mp[ptr]->next=mp[ptr->next];// the copy next is pointing to the original next 
            mp[ptr]->random=mp[ptr->random];// the copy random is poiting to the original random
            ptr=ptr->next;
        }
        return mp[head];
    }
    void insertInBetween(Node*head){
        Node*tmp=head;
        // assing next
        while(tmp!=NULL){
            Node*copyNode= new Node(tmp->val);
            // linke the copy node 
            copyNode->next=tmp->next;
            // link the tmp with copy
            tmp->next=copyNode;
            tmp=tmp->next->next;// move the tmp to the next node 
        }
    }

    void connectRandomPointers(Node*head){
        Node*tmp=head;
        // assign randoms
        while(tmp!=NULL){
            Node*copyNode=tmp->next; // get the copy node 
            if (tmp->random != NULL)  // Check if tmp->random is not NULL
            copyNode->random = tmp->random->next;
        else
            copyNode->random = NULL; 
            tmp= tmp->next->next;
        }
    }

    Node*getDeepCopy(Node*head){
    Node*dNode= new Node(-1);
        Node*res= dNode;
        Node*tmp=head;
        while(tmp!=NULL){
            res->next=tmp->next; // your next node is the 
            // now link the temp with the original next node in the list 
            tmp->next= tmp->next->next;
            // move 
            res=res->next;
            tmp=tmp->next;

        }
        return dNode->next;
    }
     Node* copyRandomList(Node* head) {
        insertInBetween(head);
        connectRandomPointers(head);
        return getDeepCopy(head);
     }