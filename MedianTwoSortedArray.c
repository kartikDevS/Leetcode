double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *result=malloc(sizeof(int)*(nums1Size+nums2Size));
    int k=0;
    int i=0,j=0;
    while(i<nums1Size && j<nums2Size){
        if(nums1[i]<nums2[j]){
            result[k++]=nums1[i++];
        }
        else{
            result[k++]=nums2[j++];
        }
    }
    while(i<nums1Size){
        result[k++]=nums1[i++];
    }
    while(j<nums2Size){
        result[k++]=nums2[j++];
    }
    int len=nums1Size+nums2Size;
    if(len%2==0){
        double ans= (result[(len/2)]+result[((len/2)-1)])/2.0;
        free(result);
        return ans;
    }
    else{
        int a=result[len/2];
        free(result);
        return a;
    }
}