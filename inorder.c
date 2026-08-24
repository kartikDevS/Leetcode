int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *result=malloc(sizeof(int)*100);
    *returnSize=0;
    if(root==NULL)return result;

    struct TreeNode* arr[100];
    int top=-1;
    arr[++top]=root;
    struct TreeNode*node=root->left;
    while(top!=-1 || node){
        while(node){
            arr[++top]=node;
            node=node->left;
        }
        struct TreeNode* tmp=arr[top--];
        result[(*returnSize)++]=tmp->val;
        node=tmp->right;
    }
    return result;
}