struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct{
    struct TreeNode*node;
    int index;
} Point;

int *bottomview(struct TreeNode*root,int*returnSize){
    Point Queue[1000];int front=0;int rear=0;
    typedef struct{
        int i;
        int value;
        UT_hash_handle hh;
    } Hash;
    Hash*entry,*table=NULL;
    Queue[rear].node=root;
    Queue[rear].index=0;
    rear++;
    int min=INT_MAX,max=INT_MIN;
    while(front!=rear){
        Point curr=Queue[front++];
        int x=curr.index;
        HASH_FIND_INT(table,&x,entry);
        if(entry){
            entry->value=curr.node->val;
        }
        else{
            entry=malloc(sizeof(Hash));
            entry->value=curr.node->val;
            entry->i=curr.index;
            HASH_ADD_INT(table,i,entry);
        }
        if(curr.node->left!=NULL){
            Queue[rear].node=curr.node->left;
            Queue[rear].index=curr.index-1;
            rear++;
        }
        if(curr.node->right!=NULL){
            Queue[rear].node=curr.node->right;
            Queue[rear].index=curr.index+1;
            rear++;
        }
        if (curr.index < min) min = curr.index;
        if (curr.index > max) max = curr.index;
    }
    int *result=malloc(sizeof(int)*(max-min+1));
    *returnSize=0;
    for(int i=min;i<=max;i++){
        HASH_FIND_INT(table,&i,entry);
        if(entry)result[(*returnSize)++]=entry->value;
    }
    return result;
}