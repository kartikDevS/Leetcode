int lengthOfLongestSubstring(char* s) {
    typedef struct{
        char c;
        UT_hash_handle hh;
    } hash;

    hash *table=NULL,*entry,*tmp;
    int maxlen=0,left=0;
    
    for(int right=0;s[right]!='\0';right++){
        HASH_FIND(hh,table,&s[right],sizeof(char),entry);
        if(!entry){
            entry=malloc(sizeof(hash));
            entry->c=s[right];
            HASH_ADD(hh,table,c,sizeof(char),entry);
        }
        else{
            while(s[left]!=s[right]){
                HASH_FIND(hh,table,&s[left],sizeof(char),tmp);
                HASH_DEL(table,tmp);
                free(tmp);
                left++;
            }
            left++;
        }
        maxlen=((right-left+1)>maxlen)?right-left+1:maxlen;
    }
    HASH_ITER(hh,table,entry,tmp){
        HASH_DEL(table,entry);
        free(entry);
    }

    return maxlen;
}