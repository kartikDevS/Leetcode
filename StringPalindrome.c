// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.
 

// Constraints:

// 1 <= s.length <= 2 * 105

bool isPalindrome(char* s) {
    int n=strlen(s);
    char arr[n+1];
    int j=0;
    for(int i=0;s[i]!='\0';i++){
        if(isalnum(s[i])){
            arr[j++]=tolower(s[i]);
        }
    }
    for(int left=0,right=j-1;left<right;left++,right--){
        if(arr[left]!=arr[right])return false;
    }
    return true;
}