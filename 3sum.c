#include <stdlib.h>

int cmp(const void *a, const void *b) {
return (*(int*)a - *(int*)b);             // you can keep (and actually we kept it inside) inside ur threesum on leetcode it uses - 
                                         // LeetCode uses a GCC-based environment (GNU Compiler Collection).- GCC supports a non-standard extension called nested functions.
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    qsort(nums,numsSize,sizeof(int),cmp);

    int capacity=numsSize*numsSize;
    int **result=malloc(capacity*sizeof(int*));
    *returnColumnSizes=malloc(capacity*sizeof(int));
    *returnSize=0;

    for(int i=0;i<numsSize;i++){
        int left=i+1, right=numsSize-1;
        if(i>0 && nums[i]==nums[i-1])continue;
        while(left<right){
            int sum=nums[i]+nums[left]+nums[right];
            if(sum==0){
                result[*returnSize]=malloc(3*sizeof(int));
                result[*returnSize][0]=nums[i];
                result[*returnSize][1]=nums[left];
                result[*returnSize][2]=nums[right];
                (*returnColumnSizes)[*returnSize]=3;
                (*returnSize)++;
                while(left<right && nums[left]==nums[left+1])left++;
                while(left<right && nums[right]==nums[right-1])right--;
                left++;
                right--;
            }
            else if(sum<0)left++;
            else{
                right--;
            }
        }
    }
    return result;
}
