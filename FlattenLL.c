struct node {
    int val;
    struct node*next;
    struct node*prev;
    struct node*child;
};

struct Node* flatten(struct Node* head) {
    struct node*curr=head;
    while(curr!=NULL){
        if(curr->child!=NULL){
            struct node* nextNode=curr->next;
            struct node* childHead=flatten(curr->child);

            curr->next=childHead;
            childHead->prev=curr;
            curr->child=NULL;

            struct node*childTail=childHead;
            while(childTail->next!=NULL){
                childTail=childTail->next;
            }

            if(nextNode!=NULL){
                childTail->next=nextNode;
                nextNode->prev=childTail;
            }
        }
        curr=curr->next;
    }
    return head;
}