int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int*result=malloc(sizeof(int)*100);
    *returnSize=0;
    if(root==NULL)return result;
    struct TreeNode *arr1[100],*arr2[100];
    int top1=-1,top2=-1;

    arr1[++top1]=root;
    while(top1!=-1){
        struct TreeNode* node=arr1[top1--];
        arr2[++top2]=node;
        if(node->left!=NULL)arr1[++top1]=node->left;
        if(node->right!=NULL)arr1[++top1]=node->right;
    }
    while(top2!=-1){
        result[(*returnSize)++]=arr2[top2--]->val;
    }
    return result;
}