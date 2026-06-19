// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false

 

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.

bool isAnagram(char* s, char* t) {
    int a=strlen(s),b=strlen(t);
    if(a!=b)return false;

    typedef struct{
        char c;
        int count;
        UT_hash_handle hh;
    } hash;
    
    hash *table=NULL,*entry,*tmp;

    for(int i=0;s[i]!='\0';i++){
        HASH_FIND(hh,table,&s[i],sizeof(char),entry);
        if(!entry){
            entry=malloc(sizeof(hash));
            entry->c=s[i];
            entry->count=1;
            HASH_ADD(hh,table,c,sizeof(char),entry);
        }
        else{entry->count++;}
    }
    for(int i=0;t[i]!='\0';i++){
        HASH_FIND(hh,table,&t[i],sizeof(char),entry);
        if(!entry){
            HASH_ITER(hh,table,entry,tmp){
                HASH_DEL(table,entry);
                free(entry);
            }
            return false;
        }
        entry->count--;
        if(entry->count<0){
            HASH_ITER(hh,table,entry,tmp){
                HASH_DEL(table,entry);
                free(entry);
            }
            return false;
        }
    }
    HASH_ITER(hh,table,entry,tmp){
        HASH_DEL(table,entry);
        free(entry);
    }
    return true;
}