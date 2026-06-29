typedef struct{
    char *key;
    char **words;
    int count;
} Group;

void sortString(char *s){
    int n = strlen(s);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(s[i]>s[j]){
                char temp=s[j];
                s[j]=s[i];
                s[i]=temp;
            }
        }
    }
}

int findWord(Group* groups,char*key,int groupCount){
    for(int i=0;i<groupCount;i++){
        if(strcmp(groups[i].key,key)==0)return i;
    }
    return -1;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    Group *groups=malloc(sizeof(Group)*strsSize);
    int groupCount=0;
    for(int i=0;i<strsSize;i++){
        char *copy=strdup(strs[i]);
        sortString(copy);
        int idx = findWord(groups,copy,groupCount);
        if(idx==-1){
            groups[groupCount].key=copy;
            groups[groupCount].words=malloc(sizeof(char*)*strsSize);
            groups[groupCount].words[0]=strs[i];
            groups[groupCount].count=1;
            groupCount++;
        }
        else{
            groups[idx].words[groups[idx].count++]=strs[i];
            free(copy);
        }
    }

    char ***result=malloc(sizeof(char**)*groupCount);
    *returnSize=groupCount;
    *returnColumnSizes=malloc(sizeof(int)*groupCount);
    for(int i=0;i<groupCount;i++){
        *returnColumnSizes[i]=groups[i].count;
        result[i]=malloc(sizeof(char*)*groups[i].count);
        for(int j=0;j<groups[i].count;j++){
            result[i][j]=groups[i].words[j];
        }
    }
    return result;
}