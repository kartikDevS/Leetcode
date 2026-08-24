void dfs(struct TreeNode*root,int level,int **result,int*returnSize,int *returnColumnSizes){
    if(root==NULL)return;
    if(level==*returnSize){
        result[level]=malloc(sizeof(int)*10000);
        returnColumnSizes[level]=0;
        (*returnSize)++;
    }
    result[level][returnColumnSizes[level]++]=root->val;

    dfs(root->left,level+1,result,returnSize,returnColumnSizes);
    dfs(root->right,level+1,result,returnSize,returnColumnSizes);
}


int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int **result=malloc(sizeof(int*)*10000);
    *returnColumnSizes=malloc(sizeof(int)*10000);
    *returnSize=0;

    dfs(root,0,result,returnSize,*returnColumnSizes);
    return result;
}