


typedef struct {
    int n;
    int maxPow;
    int **up;
    
} TreeAncestor;


TreeAncestor* treeAncestorCreate(int n, int* parent, int parentSize) {
    TreeAncestor*obj=malloc(sizeof(TreeAncestor));
    obj->n=n;
    int maxPow=0;
    while((1<<maxPow)<=n){
        maxPow++;
    }
    obj->maxPow=maxPow;

    obj->up=malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        obj->up[i]=malloc(sizeof(int)*obj->maxPow);
        memset(obj->up[i],-1,obj->maxPow*sizeof(int));
    }
    for(int i=0;i<n;i++){
        obj->up[i][0]=parent[i];
    }
    for(int j=1;j<obj->maxPow;j++){
        for(int i=0;i<n;i++){
            int prev=obj->up[i][j-1];
            obj->up[i][j]=(prev==-1)?-1:obj->up[prev][j-1];
        }
    }
    return obj;
}

int treeAncestorGetKthAncestor(TreeAncestor* obj, int node, int k) {
    if((k>>obj->maxPow)>0){
        return -1;
    }
    for(int j=0;j<obj->maxPow && node!=-1 ;j++){
        if((k>>j) & 1){
            node=obj->up[node][j];
        }
    }
    return node;
}

void treeAncestorFree(TreeAncestor* obj) {
    for(int i=0;i<obj->n;i++){
        free(obj->up[i]);
    }
    free(obj->up);
    free(obj);
}

/**
 * Your TreeAncestor struct will be instantiated and called as such:
 * TreeAncestor* obj = treeAncestorCreate(n, parent, parentSize);
 * int param_1 = treeAncestorGetKthAncestor(obj, node, k);
 
 * treeAncestorFree(obj);
*/