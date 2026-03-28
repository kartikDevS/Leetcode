void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p1=m-1;int p2=n-1;int idx=n+m-1;
    while(p1>=0 && p2>=0){
        if(nums1[p1]>nums2[p2]){
            nums1[idx]=nums1[p1];
            p1--;
            idx--;
        }
        else{
            nums1[idx]=nums2[p2];
            p2--;
            idx--;
        }
    }
    while(p1>=0){
        nums1[idx]=nums1[p1];
        p1--;
        idx--;
    }
    while(p2>=0){
        nums1[idx]=nums2[p2];
        p2--;
        idx--;
    }
}