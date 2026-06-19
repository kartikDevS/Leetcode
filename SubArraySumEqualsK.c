// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2
 

// Constraints:

// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -107 <= k <= 107



int subarraySum(int* nums, int numsSize, int k) {
    typedef struct {
        int val;       
        int freq;             
        UT_hash_handle hh;
    } Hash;
    Hash *table = NULL, *entry;
    int sum = 0, result = 0;

    entry = malloc(sizeof(Hash));
    entry->val = 0;
    entry->freq = 1;
    HASH_ADD_INT(table, val, entry);

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];

        int key = sum - k;
        HASH_FIND_INT(table, &key, entry);
        if (entry) {
            result += entry->freq;  
        }

       
        HASH_FIND_INT(table, &sum, entry);
        if (entry) {
            entry->freq++;
        } else {
            entry = malloc(sizeof(Hash));
            entry->val = sum;
            entry->freq = 1;
            HASH_ADD_INT(table, val, entry);
        }
    }

  
    Hash *tmp;
    HASH_ITER(hh, table, entry, tmp) {
        HASH_DEL(table, entry);
        free(entry);
    }

    return result;
}
