int count=0;

int merge(int nums[],int left,int mid,int right,int temp[]){
    int count=0;
    int j=mid+1;
    for(int i=left;i<=mid;i++){
        while(j<=right && nums[i]>2*(long long)nums[j]){
            j++;
        }
        count+=(j-(mid+1));
    }
    int p1=left,p2=mid+1;
    int idx=left;
    while(p1<=mid && p2<=right){
        if(nums[p1]<=nums[p2]){
            temp[idx]=nums[p1];
            idx++;
            p1++;
        }
        else{
            temp[idx]=nums[p2];
            idx++;
            p2++;
        }
    }
    while(p1<=mid){
        temp[idx]=nums[p1];
        idx++;
        p1++;
    }
    while(p2<=right){
        temp[idx]=nums[p2];
            idx++;
            p2++;
    }
    for(int i=left;i<=right;i++){
        nums[i]=temp[i];
    }
    return count;
}

int mergesort(int nums[],int left,int right,int temp[]){
    if(left>=right)return 0;
    int count=0;
    int mid=left+(right-left)/2;
    count+=mergesort(nums,left,mid,temp);
    count+=mergesort(nums,mid+1,right,temp);
    count+=merge(nums,left,mid,right,temp);
    return count;
}

int reversePairs(int* nums, int numsSize) {
    if(numsSize<=1)return 0;
    int *temp=malloc(numsSize*sizeof(int));
    long long totalPairs= mergesort(nums,0,numsSize-1,temp);
    free(temp);
    return (int)totalPairs;
} 