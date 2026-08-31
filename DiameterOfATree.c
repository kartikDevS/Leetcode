int findDiamter(struct TreeNode*node,int *d){
    if(node==NULL)return 0;
    int left=findDiamter(node->left,d);
    int right=findDiamter(node->right,d);

    if(left+right>*d){
        *d=left+right;
    }
    return 1+(left>right?left:right);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int diameter=0;
    findDiamter(root,&diameter);
    return diameter;
}