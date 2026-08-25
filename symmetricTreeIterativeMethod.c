//  What the problem asks
// Check if a binary tree is a mirror of itself (symmetric around its center).  
// For every pair of nodes, the left child of one should match the right child of the other.  

// Iterative Idea
// Instead of recursion, you use a **queue** to store pairs of nodes that should be mirrors.  

// Steps:
// 1. Put `(root->left, root->right)` into the queue.  
// 2. While the queue isn’t empty:
//    - Pop a pair `(a, b)`.  
//    - If both are `NULL`, continue.  
//    - If one is `NULL` and the other isn’t, return false.  
//    - If their values differ, return false.  
//    - Push their children in mirror order:  
//      - `(a->left, b->right)`  
//      - `(a->right, b->left)`  
// 3. If you finish without mismatches, return true.  


bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root->left;
    queue[rear++] = root->right;

    while (front < rear) {
        struct TreeNode* a = queue[front++];
        struct TreeNode* b = queue[front++];

        if (a == NULL && b == NULL) continue;
        if (a == NULL || b == NULL) return false;
        if (a->val != b->val) return false;

        // Push children in mirror order
        queue[rear++] = a->left;
        queue[rear++] = b->right;
        queue[rear++] = a->right;
        queue[rear++] = b->left;
    }

    return true;
}