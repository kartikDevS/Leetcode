// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.


void reverse(char* str, int left, int right){
    while(left<right){
        char temp=str[left];
        str[left++]=str[right];
        str[right--]=temp;
    }
}

char* reverseWords(char* s) {
    int i=0,j=0;
    int n=strlen(s);
    char *c=malloc((n+1)*sizeof(char));
    while(i<n && s[i]==' ')i++;
    while(i<n){
        while(i<n && s[i]!=' '){
            c[j++]=s[i++];
        }
        while (i<n && s[i]==' ')i++;
        if(i<n) c[j++]=' ';
    }
    c[j]='\0';

    reverse(c,0,j-1);

    int start=0;
    for(int k=0;k<=j;k++){
        if(c[k]==' '||c[k]=='\0'){
            reverse(c,start,k-1);
            start=k+1;
        }
    }
    return c;
}