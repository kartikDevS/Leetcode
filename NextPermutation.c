void nextPermutation(int* nums, int numsSize) {
    int i=numsSize-2;
    while(i>=0 && nums[i]>=nums[i+1])i--;
    if(i>=0){
        int j=numsSize-1;
        while(nums[j]<=nums[i])j--;
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    int left=i+1,right=numsSize-1;
    while(left<right){
        int temp=nums[left];
        nums[left]=nums[right];
        nums[right]=temp;
        left++;
        right--;
    }
}
//so the steps are 1. find pivot i.e move from right
//  to left and find the first element that is smaller to
//   its right element i.e nums[i]<nums[i+1] 2. then swap 
//   it with the rightmost element (that is bigger than the pivot)
//    so for that u make j pointer to the rightmost and start 
//    moving it towards left until u find element greater 
//    than pivot and the u swap the jth element with pivot
//     , 3. now just one thing that is the elements right 
//     to the pivot are all in decreasing order so just 
//     change that to increasing by swapping them 

