// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

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