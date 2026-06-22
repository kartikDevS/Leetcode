int compare(const void*a,const void*b){   //a and b are void pointers i.e void means not known whether its a int or char pointer
    int x=*(int*)a;                      // this tells that (int*) treat it as an integer pointer and
    int y=*(int*)b;          // get the value stored in this pointer *(int*)a
    return a-b; // if a-b <0 then it means a should come before b so if u want in descending order do return b-a
}

qsort(nums,numsSize,sizeof(int),compare); 

