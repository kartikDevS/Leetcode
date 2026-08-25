bool isSame(struct TreeNode*l,struct TreeNode*r){
    if(l==NULL && r==NULL)return true;
    if(l==NULL || r==NULL)return false;

    return (l->val==r->val) && isSame(l->right,r->right) && isSame(l->left,r->left);
}
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if(root==NULL)return false;

    if(isSame(root,subRoot))return true;

    return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
}