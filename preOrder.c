int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int *result=malloc(sizeof(int)*100);
    *returnSize=0;
    struct TreeNode* arr[100];
    int top=-1;
    if(root)arr[++top]=root;
    while(top!=-1){
        struct TreeNode*node=arr[top--];
        if(node)result[(*returnSize)++]=node->val;
        if(node && node->right) arr[++top]=node->right;
        if(node && node->left) arr[++top]=node->left;
    }
    return result;
}