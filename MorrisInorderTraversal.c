struct TreeNode* IP(struct TreeNode*root){
    struct TreeNode*curr=root->left;
    while(curr->right!=NULL && curr->right!=root){
        curr=curr->right;
    }
    return curr;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *result=malloc(sizeof(int)*100);
    *returnSize=0;
    struct TreeNode*curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            result[(*returnSize)++]=curr->val;
            curr=curr->right;
        }
        else{
            struct TreeNode*pre=IP(curr);
            if(pre->right==NULL){
                pre->right=curr;
                curr=curr->left;
            }
            else{
                pre->right=NULL;
                result[(*returnSize)++]=curr->val;
                curr=curr->right;
            }
        }
    }
    return result;
}