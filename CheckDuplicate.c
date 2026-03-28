#include <stdbool.h>
#include "uthash.h"

bool containsDuplicate(int* nums, int numsSize) {
    typedef struct  {
        int value;
        UT_hash_handle hh;
    } Hashentry;

    Hashentry*table=NULL,*entry,*tmp;

    for(int i=0;i<numsSize;i++){
        HASH_FIND_INT(table,&nums[i],entry);
        if(entry){
            return true;
        }
        else{
            entry=malloc(sizeof(Hashentry));
            entry->value=nums[i];
            HASH_ADD_INT(table,value,entry);
        }
    }

    HASH_ITER(hh,table,entry,tmp){
        HASH_DEL(table,entry);
        free(entry);
    }

    return false;

}