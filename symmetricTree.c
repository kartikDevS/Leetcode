bool mirror(struct TreeNode*t1,struct TreeNode*t2){
    if(t1==NULL && t2==NULL)return true;
    if(t1==NULL || t2==NULL)return false;
    return (t1->val==t2->val) && mirror(t1->left,t2->right) && mirror(t1->right,t2->left);
}
bool isSymmetric(struct TreeNode* root) {
    if(root==NULL)return true;
    return mirror(root->left,root->right);
}