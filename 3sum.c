// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.
 

// Constraints:

// 3 <= nums.length <= 3000
// -105 <= nums[i] <= 105


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
