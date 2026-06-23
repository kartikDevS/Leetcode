/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct{
    int *arr;
    int front,rear,size;
} dq;

dq *create(int capacity){
    dq* dequeue=malloc(sizeof(dq));
    dequeue->arr=malloc(capacity*sizeof(int));
    dequeue->front=0;
    dequeue->rear=-1;
    dequeue->size=0;
    return dequeue;
}

void push(dq* dequeue,int x){
    dequeue->rear++;
    dequeue->arr[dequeue->rear]=x;
    dequeue->size++;
}
void popF(dq* dequeue){
    dequeue->front++;
    dequeue->size--;
}
void popR(dq *dequeue){
    dequeue->rear--;
    dequeue->size--;
}

int frontP(dq* dequeue){
    return dequeue->arr[dequeue->front];
}

int rearP(dq* dequeue){
    return dequeue->arr[dequeue->rear];
}

int empty(dq* dequeue){
    return dequeue->size==0;
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int *result=malloc((numsSize-k+1)*sizeof(int));
    *returnSize=0;
    dq* DD=create(numsSize);
    for(int i=0;i<numsSize;i++){
        if(!empty(DD) && frontP(DD)<=i-k){
            popF(DD);
        }
        while(!empty(DD) && nums[rearP(DD)]<nums[i]){
            popR(DD);
        }
        push(DD,i);

        if(i>=k-1){
            result[(*returnSize)++]=nums[frontP(DD)];
        }
    }
    return result;
}