bool isPalindrome(char*s,int left,int right){
    while(left<right){
        if(s[left]!=s[right])return false;
        left++;
        right--;
    }
    return true;
}

void backtracking(char* s,char***result, int* returnSize, 
    int** returnColumnSizes,char**path,int pathSize,int start){
        int n=strlen(s);
        if(start==n){
            result[*returnSize]=malloc(sizeof(char*)*pathSize);  //i have a doubt why do i have to use (char*)*pathSize here instead of char**
            for(int i=0;i<pathSize;i++){
                result[*returnSize][i]=strdup(path[i]);
                (*returnColumnSizes)[*returnSize]=pathSize;
            }
            (*returnSize)++;
            return;
        }

        for(int end=start;end<n;end++){
            if(isPalindrome(s,start,end)){
                int len=end-start+1;
                char*substr=malloc(sizeof(char)*(len+1));
                strncpy(substr,s+start,len);
                substr[len]='\0';
                path[pathSize]=strdup(substr);
                backtracking(s,result,returnSize,returnColumnSizes,path,pathSize+1,end+1);
                free(substr);
            }
        }
     }

     char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
        char***result=malloc(sizeof(char**)*40000);
        (*returnColumnSizes)=malloc(sizeof(int)*40000);
        *returnSize=0;

        char **path=malloc(sizeof(char*)*strlen(s));
        backtracking(s,result,returnSize,returnColumnSizes,path,0,0);
        free(path);
        return result;
     }