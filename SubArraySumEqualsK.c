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
