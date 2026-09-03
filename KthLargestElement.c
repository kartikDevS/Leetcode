void swap(int *a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapifyDown(int *heap,int size,int i){
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<size && heap[left]<heap[smallest])smallest=left;
    if(right<size && heap[right]<heap[smallest])smallest=right;
    if(smallest!=i){
        swap(&heap[smallest],&heap[i]);
        heapifyDown(heap,size,smallest);
    }
}

void heapifyUp(int *heap,int i){
    int parent=(i-1)/2;
    while(i>0 && heap[i]<heap[parent]){
        swap(&heap[i],&heap[parent]);
        i=parent;
        parent=(i-1)/2;
    }
}

typedef struct {
    int k;
    int *heap;
    int size;
} KthLargest;

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest*obj=malloc(sizeof(KthLargest));
    obj->size=0;
    obj->k=k;
    obj->heap=malloc(sizeof(int)*(k+1));

    for(int i=0;i<numsSize;i++){
        int val=nums[i];
        if(obj->size<obj->k){
            obj->heap[obj->size++]=nums[i];
            heapifyUp(obj->heap,obj->size-1);
        }
        else if(val>obj->heap[0]){
            obj->heap[0]=val;
            heapifyDown(obj->heap,obj->size,0);
        }
    }
    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if(obj->size<obj->k){
        obj->heap[obj->size++]=val;
        heapifyUp(obj->heap,obj->size-1);
    }
    else if(val>obj->heap[0]){
        obj->heap[0]=val;
        heapifyDown(obj->heap,obj->size,0);
    }
    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}

/**
 * Your KthLargest struct will be instantiated and called as such:
 * KthLargest* obj = kthLargestCreate(k, nums, numsSize);
 * int param_1 = kthLargestAdd(obj, val);
 
 * kthLargestFree(obj);
*/