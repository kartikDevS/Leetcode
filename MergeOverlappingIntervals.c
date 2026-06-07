/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    int cmp(const void*a,const void*b){
        int* x=*(int**)a;
        int* y=*(int**)b;
        return x[0]-y[0];
    }
    qsort(intervals,intervalsSize,sizeof(int*),cmp);

    int** result=malloc(intervalsSize*sizeof(int*));
    *returnColumnSizes=malloc(intervalsSize*sizeof(int));
    *returnSize=0;

    int start=intervals[0][0];
    int end=intervals[0][1];

    for(int i=1;i<intervalsSize;i++){
        if(intervals[i][0]<=end){
            if(intervals[i][1]>end){
                end=intervals[i][1];
            }
        }
        else{
            result[*returnSize]=malloc(2*sizeof(int));
            result[*returnSize][0]=start;
            result[*returnSize][1]=end;
            (*returnColumnSizes)[*returnSize]=2;
            (*returnSize)++;

            start=intervals[i][0];
            end=intervals[i][1];
        }
    }
    result[*returnSize]=malloc(2*sizeof(int));
    result[*returnSize][0]=start;
    result[*returnSize][1]=end;
    (*returnColumnSizes)[*returnSize]=2;
    (*returnSize)++;

    return result;
}