// Example 1:

// Input: nums = [1,1,2,2,2,3]
// Output: [3,1,1,2,2,2]
// Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
// Example 2:

// Input: nums = [2,3,1,3,2]
// Output: [1,3,3,2,2]
// Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
// Example 3:

// Input: nums = [-1,1,-6,4,5,-6,1,4,1]
// Output: [5,-1,4,4,-6,-6,1,1,1]
 

// Constraints:

// 1 <= nums.length <= 100
// -100 <= nums[i] <= 100


    typedef struct {
        int val;
        int freq;
        UT_hash_handle hh;
    } hash;
    static hash*table=NULL;

    int compare(const void*x,const void*y){
        int a=*(int*)x;
        int b=*(int*)y;
        
        hash*EntryA,*EntryB;
        HASH_FIND_INT(table,&a,EntryA);
        HASH_FIND_INT(table,&b,EntryB);
        if(EntryA->freq!=EntryB->freq){
            return EntryA->freq-EntryB->freq;
        }
        else{
            return b-a;
        }
    }
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* frequencySort(int* nums, int numsSize, int* returnSize) {
    hash*entry,*tmp;

    for(int i=0;i<numsSize;i++){
        HASH_FIND_INT(table,&nums[i],entry);
        if(!entry){
            entry=malloc(sizeof(hash));
            entry->val=nums[i];
            entry->freq=1;
            HASH_ADD_INT(table,val,entry);
        }
        else{
            entry->freq++;
        }
    }

    qsort(nums,numsSize,sizeof(int),compare);

    HASH_ITER(hh, table, entry, tmp) {
        HASH_DEL(table, entry);
        free(entry);
    }

    *returnSize=numsSize;
    return nums;
}