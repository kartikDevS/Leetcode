//some doubts that u will think of while going through sol are here but first go through sol
// you will think what if c doesnt come in s1 but comes in s2 so now a of both matches
//and b matches but c doesnt and becoz of this it will return both are not equal 
//but what if s1='abd' and s2='cdba' so in this case u will think we only care about 
//abd why to check for c and get rejected but the think is when we did put the values in
//count 1 and count2 from the first for loop there the size is n1 so only n1 characters could
//come or there frequency could changed so now if s1 was 'abd' and s2='cdba' inside 
//count1 and count2 only 3 characters could come so eventually if c was in count2
//that definitely proves that d wont be in count2 cause the size is only 3 and if u think
//what if both had s1=abdd s2=abcd then both have same length but here u see when it will check
//for the frequency of d that would be different in both so eventually if it fails on c
//thats good cause it would have failed on d cause though all characters of s1 in s2 but
//different frequency


bool checkInclusion(char* s1,char* s2){
    int n1=strlen(s1),n2=strlen(s2);
    if(n1>n2)return false;

    int count1[26]={0}; int count2[26]={0};
    for(int i=0;i<n1;i++){
        count1[s1[i]-'a']++;
        count2[s2[i]-'a']++;
    }

    if(memcmp(count1,count2,sizeof(count1))==0)return true;

    for(int i=n1;i<n2;i++){
        count2[s2[i]-'a']++;         // adding an element to the window (from right)
        count2[s2[i-n1]-'a']--;     // removing an element from window (from left)
        if(memcmp(count1,count2,sizeof(count1))==0)return true;
    }
    return false;
}

// whats this memcmp its an builtin string lib function 


// int memcmp(const void *ptr1, const void *ptr2, size_t num) {
//     const unsigned char *p1 = (const unsigned char *)ptr1;
//     const unsigned char *p2 = (const unsigned char *)ptr2;

//     for (size_t i = 0; i < num; i++) {
//         if (p1[i] != p2[i]) {
//             return (p1[i] - p2[i]);  // difference at first mismatch
//         }
//     }
//     return 0;  // all bytes equal
// }
